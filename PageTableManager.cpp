#include "PageTableManager.hpp"

#include <iostream>
#include <string>

using namespace mem;

void PageTableManager::map(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs, mem::MMU &memory){

    uint32_t pages = cmdArgs.at(0);
    //memory = std::make_unique<mem::MMU>((pages + kPageSize - 1) / kPageSize); //
   
}
  
//void PageTableManager::diff(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs){
//
//    
//    
//}
//    
//void PageTableManager::store(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs){
//
//    
//    
//}
//    
//void PageTableManager::replicate(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs){
//
//    
//    
//}
//    
//void PageTableManager::duplicate(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs){
//
//    
//    
//}
//    
//void PageTableManager::print(const std::string &line, const std::string &cmd, std::vector<uint32_t> &cmdArgs){
//
//    
//    
//}
 