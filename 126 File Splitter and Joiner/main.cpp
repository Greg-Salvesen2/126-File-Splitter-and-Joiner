//
//  main.cpp
//  126 File Splitter and Joiner
//
//  Created by Greg Salvesen on 11/7/16.
//  Copyright © 2016 DVS. All rights reserved.
//

#include <iostream>
#include "FileSplitter.hpp"

int main(int argc, const char * argv[]) {
    FileSplitter::splitFileIntoParts("/Users/gregsalvesen/Documents", "Indirect interaction", 3);
    
    return 0;
}
