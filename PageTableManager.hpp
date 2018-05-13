/* 
 * File:   PageTableManager.hpp
 * Author: jpbordiga
 *
 * Created on May 4, 2018, 9:47 PM
 */

#ifndef PAGETABLEMANAGER_HPP
#define PAGETABLEMANAGER_HPP

#include "MMU.h"
#include "MemoryAllocator.h"
#include <string>
#include <vector>


class PageTableManager { 

public:
    
    /**
    * Constructor - open trace file, initialize processing
    * 
    * @param TBD
    */
    PageTableManager(mem::MMU &memory, MemoryAllocator &mA);

    /**
    * Destructor - delete PageTableManager
    */
    virtual ~PageTableManager(void);

    // Other constructors, assignment
    PageTableManager(const PageTableManager &other) = delete;
    PageTableManager(PageTableManager &&other) = delete;
    PageTableManager operator=(const PageTableManager &other) = delete;
    PageTableManager operator=(PageTableManager &&other) = delete;
    
    
    void map(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory);
    
    void CmdPerm(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory);
    
    mem::Addr create_process_page_table(mem::MMU &memory, mem::Addr vaddr);
    
private:
    
    
    
};










#endif /* PAGETABLEMANAGER_HPP */

