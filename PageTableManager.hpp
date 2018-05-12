/* 
 * File:   PageTableManager.hpp
 * Author: jpbordiga
 *
 * Created on May 4, 2018, 9:47 PM
 */

#ifndef PAGETABLEMANAGER_HPP
#define PAGETABLEMANAGER_HPP

#include "MMU.h"
#include <string>
#include <vector>


class PageTableManager { 

public:
    
    /**
    * Constructor - open trace file, initialize processing
    * 
    * @param TBD
    */
    PageTableManager(); // params TBD

    /**
    * Destructor - close trace file, clean up processing
    */
    virtual ~PageTableManager(void);

    // Other constructors, assignment
    PageTableManager(const PageTableManager &other) = delete;
    PageTableManager(PageTableManager &&other) = delete;
    PageTableManager operator=(const PageTableManager &other) = delete;
    PageTableManager operator=(PageTableManager &&other) = delete;
    
//    void map(uint32_t pages, mem::Addr vaddr);
//    
//    void diff(mem::Addr vaddr); //
//    
//    void store(mem::Addr vaddr);
//    
//    void replicate(uint8_t value, uint32_t count, mem::Addr vaddr);
//    
//    void duplicate(uint32_t count, mem::Addr source, mem::Addr dest);
//    
//    void print(uint32_t count, mem::Addr vaddr);
  
    
    void map(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory);
    
//    void diff(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs);
//    
//    void store(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs);
//    
//    void replicate(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs);
//    
//    void duplicate(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs);
//    
//    void print(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs);
    
private:
    
    
    
};










#endif /* PAGETABLEMANAGER_HPP */

