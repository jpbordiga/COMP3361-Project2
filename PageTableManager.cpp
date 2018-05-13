#include "PageTableManager.hpp"


#include <iostream>
#include <string>

using namespace mem;

PageTableManager::PageTableManager(mem::MMU &memory, MemoryAllocator &mA){ // scope?

    // switch to kernel page table
    // perform intended purpose
    
    const Addr kKernelPageTableBase = 1 * kPageSize; //
    
    PageTable kernel_page_table;
    Addr num_pages = memory.get_frame_count();  // size of physical memory
    
    for (Addr i = 0; i < num_pages; ++i) {
        kernel_page_table.at(i) = (i << kPageSizeBits) | kPTE_PresentMask | kPTE_WritableMask;
    }
   
    Addr pt_addr = 0x0; //
    memory.put_bytes(pt_addr, kPageTableSizeBytes, &kernel_page_table); // do something with MemoryAllocator
    
    PMCB kernel_pmcb(kKernelPageTableBase);
    memory.set_PMCB(kernel_pmcb);
    memory.enter_virtual_mode();
    
    
    // switch to Process page table
    
    
    
}

void PageTableManager::map(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory){

    // switch to kernel page table
    
    
    // perform intended purpose
    
    
    // switch to Process page table
    
    
   
}
  
void PageTableManager::CmdPerm(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory){

    // switch to kernel page table
    
    
    // perform intended purpose
    
    
    // switch to Process page table
    

}
 
Addr PageTableManager::create_process_page_table(mem::MMU &memory, mem::Addr vaddr){ // values of const vars?

    const Addr kKernelPageTableBase = vaddr * kPageSize;  // base of kernel page table
    const Addr kPageTableBase = vaddr * kPageSize;
    const Addr kVAddrStart = vaddr * kPageSize; //
    const Addr kPhysStart = vaddr * kPageSize; //
  
    // switch to kernel page table
    
    
    // perform intended purpose
    
    
    
    // switch to Process page table
    
    
    
    
    
    
    
    PageTable page_table; // page table for the individual Process
    Addr pt_offset = (kVAddrStart >> kPageSizeBits) & kPageTableIndexMask;
    page_table.at(pt_offset) = kPhysStart | kPTE_PresentMask | kPTE_WritableMask;
    memory.put_bytes(kPageTableBase, kPageTableSizeBytes, &page_table);
  
    PMCB vm_pmcb(kPageTableBase); // load to start virtual mode
    memory.set_PMCB(vm_pmcb);
    memory.FlushTLB();
    
}