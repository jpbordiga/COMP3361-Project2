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


using namespace std;
using namespace mem;


int main(int argc, char** argv) {

    if (argc != 2) {
        std::cerr << "usage: Program2 input_file\n";
        exit(1);
    }
    
    mem::MMU memory(0x40); 
    
    std::cout << "test build\n";
    
    return 0;
}

