/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Process.h
 * Author: jpbordiga
 *
 * Created on May 4, 2018, 10:56 PM
 */

#ifndef PROCESS_H
#define PROCESS_H

#include "MMU.h"
#include "PageTableManager.hpp"

#include <fstream>
#include <memory>
#include <string>
#include <vector>

class Process {
public:
  /**
   * Constructor - open trace file, initialize processing
   * 
   * @param file_name_ source of trace commands
   */
  //Process(std::string file_name_);
  Process(mem::MMU &memory, PageTableManager &pTM, std::string file_name_);
  
  /**
   * Destructor - close trace file, clean up processing
   */
  virtual ~Process(void);

  // Other constructors, assignment
  Process(const Process &other) = delete;
  Process(Process &&other) = delete;
  Process operator=(const Process &other) = delete;
  Process operator=(Process &&other) = delete;
  
  /**
   * Run - read and process commands from trace file
   * 
   */
  void Run(mem::MMU &memory, PageTableManager &pTM);
  
private:
  // Trace file
  std::string file_name;
  std::fstream trace;
  long line_number;

  // Memory contents
  
  // get rid of this?
  
  //std::unique_ptr<mem::MMU> memory;
  
  /**
   * ParseCommand - parse a trace file command.
   *   Aborts program if invalid trace file.
   * 
   * @param line return the original command line
   * @param cmd return the command name
   * @param cmdArgs returns a vector of argument bytes
   * @return true if command parsed, false if end of file
   */
  bool ParseCommand(std::string &line, std::string &cmd, std::vector<uint32_t> &cmdArgs);
  
  /**
   * Command executors. Arguments are the same for each command.
   *   Form of the function is CmdX, where "X' is the command name, capitalized.
   * @param line original text of command line
   * @param cmd command, converted to all lower case
   * @param cmdArgs arguments to command
   */
  //void CmdMemSize(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs);
  
  void CmdDiff(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory);
  
  void CmdStore(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory);
  
  void CmdRepl(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory);
  
  void CmdDupl(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory);
  
  void CmdPerm(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory);
  
void CmdPrint(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory);
};

#endif /* PROCESS_H */

