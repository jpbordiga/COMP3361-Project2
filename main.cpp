/* 
 * File:   main.cpp
 * Author: jpbordiga
 *
 * Created on May 4, 2018, 9:44 PM
 */

#include "Process.h"
#include "MemoryAllocator.h"
#include "MMU.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>

using namespace std;
using namespace mem;


int main(int argc, char** argv) {

    
    if (argc != 3) { // specified by number of input files
        std::cerr << "usage: Program2 input_file\n";
        exit(1);
    }
    
    for(int i = 0; i < argc; ++i){
        std::cout << argv[i] << "   " <<  i << "\n";
    }
    
    //std::ifstream iF;
    std::string file_name;
    file_name = argv[1];
    
//    iF.open(file_name, std::ios_base::in);
//    
//    if (!iF.is_open()) {
//        cerr << "ERROR: failed to open trace file: " << file_name << "\n";
//        exit(2);
//    }
    
    mem::MMU memory(0x40);
    PageTableManager pTM();
    MemoryAllocator mA(); // num page frames?
    
    //Process p1(memory, pTM, file_name);
    
    std::cout << "test build\n";
    
    return 0;
}

