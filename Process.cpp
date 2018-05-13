#include "Process.h"
#include "MMU.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>

using mem::Addr;
using mem::kPageSize;
using std::cin;
using std::cout;
using std::cerr;
using std::getline;
using std::istringstream;
using std::string;
using std::vector;

Process::Process(mem::MMU &memory, PageTableManager &pTM, std::string file_name_) {
    
    // Open the trace file.  Abort program if can't open.
    file_name = file_name_;
    trace.open(file_name, std::ios_base::in);
    
    if (!trace.is_open()) {
        cerr << "ERROR: failed to open trace file: " << file_name << "\n";
        exit(2);
    }
    
    //Run(memory, pTM);
    
}

Process::~Process() { //
    trace.close();
}

void Process::Run(mem::MMU &memory, PageTableManager &pTM) {
  
    // Read and process commands
    string line;                // text line read
    string cmd;                 // command from line
    vector<uint32_t> cmdArgs;   // arguments from line

    // Select the command to execute
    while (ParseCommand(line, cmd, cmdArgs)) {
        
        if (cmd == "map" ) {
          pTM.map(line, cmd, cmdArgs, memory);    // map to a page
        } else if (cmd == "diff") {
          CmdDiff(line, cmd, cmdArgs, memory);  // get and compare multiple bytes
        } else if (cmd == "store") {
          CmdStore(line, cmd, cmdArgs, memory);      // put bytes
        } else if (cmd == "replicate") {
          CmdRepl(line, cmd, cmdArgs, memory);     // fill bytes with value
        } else if (cmd == "duplicate") {
          CmdDupl(line, cmd, cmdArgs, memory);     // copy bytes to dest from source
        } else if (cmd == "print") {
          CmdPrint(line, cmd, cmdArgs, memory);     // dump byte values to output
        } else if (cmd == "permission") {
          //CmdPerm(line, cmd, cmdArgs, memory);     // change read/write permission
            pTM.CmdPerm(line, cmd, cmdArgs, memory);
        }else if (cmd != "#") {
          cerr << "ERROR: invalid command\n";
          exit(2);
        }
        
    }
    
}

bool Process::ParseCommand(string &line, string &cmd, vector<uint32_t> &cmdArgs) {
    cmdArgs.clear();
    line.clear();
  
    // Read next line
    if (std::getline(trace, line)) {
      
        ++line_number;
        cout << std::dec << line_number << ":" << line << "\n";

        // No further processing if comment or empty line
        if (line.size() == 0 || line[0] == '#') {
            cmd = "#";
            return true;
        }

        // Make a string stream from command line
        istringstream lineStream(line);

        // Get command
        if (!(lineStream >> cmd)) {
            // Blank line, treat as comment
            cmd = "#";
            return true;
        }

        // Get arguments
        uint32_t arg;
        while (lineStream >> std::hex >> arg) {
          cmdArgs.push_back(arg);
        }
        
        return true;
        
    } else if (trace.eof()) {
        return false;
    } else {
        cerr << "ERROR: getline failed on trace file: " << file_name << "at line " << line_number << "\n";
        exit(2);
    }
}

//void Process::CmdMemSize(const string &line, const string &cmd, vector<uint32_t> &cmdArgs) {
//    // Allocate the specified memory size
//    //memory = std::make_unique<mem::MMU>((cmdArgs.at(0) + kPageSize - 1) / kPageSize);
//}

void Process::CmdDiff(const string &line, const string &cmd, vector<uint32_t> &cmdArgs, mem::MMU &memory) {
  
    uint32_t addr = cmdArgs.back();

    // Compare specified byte values
    int count = cmdArgs.size() - 1;
    
    for (int i = 0; i < count; ++i) {
        
        uint8_t b;
        memory.get_byte(&b, addr);
        if(b != cmdArgs.at(i)) {
          cout << "diff error at address " << std::hex << addr << ", expected " << static_cast<uint32_t>(cmdArgs.at(i)) << ", actual is " << static_cast<uint32_t>(b) << "\n";
        }
        
        ++addr;
        
    }
}

void Process::CmdStore(const string &line, const string &cmd, vector<uint32_t> &cmdArgs, mem::MMU &memory) {
  
    // Store multiple bytes starting at specified address
    Addr addr = cmdArgs.back();
    cmdArgs.pop_back();

    // Build buffer
    uint8_t buffer[cmdArgs.size()];
    for (size_t i = 0; i < cmdArgs.size(); ++i) {
      buffer[i] = cmdArgs[i];
    }

    // Write to MMU
    memory.put_bytes(addr, cmdArgs.size(), buffer);
    
}

void Process::CmdDupl(const string &line, const string &cmd, vector<uint32_t> &cmdArgs, mem::MMU &memory) {
  
    // Duplicate specified number of bytes to destination from source
    Addr dst = cmdArgs.at(2);
    Addr src = cmdArgs.at(1);
    uint32_t count = cmdArgs.at(0);
    uint8_t b;
    
    while (count-- > 0) {
      memory.get_byte(&b, src++);
      memory.put_byte(dst++, &b);
    }
    
}

void Process::CmdRepl(const string &line, const string &cmd, vector<uint32_t> &cmdArgs, mem::MMU &memory) {
  
    // Replicate specified value in destination range
    uint8_t value = cmdArgs.at(0);
    uint32_t count = cmdArgs.at(1);
    uint32_t addr = cmdArgs.at(2);
    
    for (int i = 0; i < count; ++i) {
      memory.put_byte(addr++, &value);
    }
    
}

void Process::CmdPrint(const string &line, const string &cmd, vector<uint32_t> &cmdArgs, mem::MMU &memory) {
  
    uint32_t addr = cmdArgs.at(1);
    uint32_t count = cmdArgs.at(0);

    // Output the address
    cout << std::hex << addr;

    // Output the specified number of bytes starting at the address
    uint8_t b;
    
    for(int i = 0; i < count; ++i) {
        
        if((i % 16) == 0) {  // line break every 16 bytes
          cout << "\n";
        }
        
        memory.get_byte(&b, addr++);
        cout << " " << std::setfill('0') << std::setw(2) << static_cast<uint32_t> (b);
        
    }
    
    cout << "\n";
    
}

