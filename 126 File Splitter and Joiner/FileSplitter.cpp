//
//  FileSplitter.cpp
//  126 File Splitter and Joiner
//
//  Created by Greg Salvesen on 11/7/16.
//  Copyright © 2016 DVS. All rights reserved.
//

#include "FileSplitter.hpp"
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

FileSplitter::FileSplitter() {
    
}

FileSplitter::~FileSplitter() {
    
}

// Splits the file into a specified number of smaller files

void FileSplitter::splitFileIntoParts(std::string directory, std::string fileName, int numFiles) {
    
    // Open the binary contents of the file that will be split
    std::ifstream file(directory + "/" + fileName, std::ifstream::binary);
    
    // Get the size of the entire file
    file.seekg(0, std::ifstream::end);
    long fileSize = file.tellg();
    file.seekg(0);
    
    // Get the size of each new file
    long newFileSizes = ceil(fileSize / numFiles);
    
    // Create a char array which will take in the information for each new file
    char buffer[numFiles][newFileSizes];

    // Read in the correct number of bytes into the buffer array, and then saves the new file
    for(int i = 0; i < numFiles; i++) {
        file.read(buffer[i], sizeof(buffer[i]));
        std::stringstream ss;
        ss << (i + 1);
        std::ofstream newFile(directory + "/New " + fileName + " " + ss.str(), std::ofstream::binary);
        
        if (newFile.is_open()) {
            newFile << buffer[i];
            newFile.close();
        } else {
            std::cout << "Unable to open file";
        }
    }
    
    file.close();
    
}

//Splits the file into a number of smaller files, each of a specified size

void FileSplitter::splitFileIntoSizes(std::string directory, std::string fileName, int sizeOfFiles) {
    
}