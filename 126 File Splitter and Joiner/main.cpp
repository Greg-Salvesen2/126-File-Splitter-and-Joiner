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
    FileSplitter splitter;
    splitter.splitFileIntoParts("/Users/gregsalvesen/Documents/Split", "Large Image.jpg", 3);
    
    return 0;
}
