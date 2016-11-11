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

// Takes in the needed information, and splits the files into new files
void FileSplitter::splitFile(std::ifstream *file, int numFiles, long fileSize, std::string directory, std::string fileName) {
    
    std::cout << numFiles << std::endl;
    std::cout << fileSize << std::endl;
    
    char buffer[fileSize];
    
    file->seekg(0, std::ifstream::end);
    long origFileSize = file->tellg();
    file->seekg(0);
    
    
    long lastFileSize = fileSize - ((numFiles - 1) * origFileSize);
    
    // Read in the correct number of bytes into the buffer array, and then saves the new file
    for(int i = 0; i < numFiles; i++) {
        long size = sizeof(buffer);
        if(i == numFiles - 1) {
            size = lastFileSize;
        }
        file->read(buffer, size);
        std::stringstream ss;
        ss << (i + 1);
        std::ofstream newFile(directory + "/New " + fileName + " " + ss.str(), std::ofstream::binary);
        
        if (newFile.is_open()) {
            newFile << buffer;
            newFile.close();
        } else {
            std::cout << "Unable to open file";
        }
    }
}

// Splits the file into a specified number of smaller files

void FileSplitter::splitFileIntoParts(std::string directory, std::string fileName, int numFiles) {
    
    // Open the binary contents of the file that will be split
    std::ifstream file(directory + "/" + fileName, std::ifstream::binary);
    
    if(!file.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        return;
    }
    
    // Get the size of the entire file
    file.seekg(0, std::ifstream::end);
    long fileSize = file.tellg();
    file.seekg(0);
    
    // Get the size of each new file
    long newFileSizes = ceil(fileSize / numFiles);

    splitFile(&file, numFiles, newFileSizes, directory, fileName);
    
    file.close();
    
}

//Splits the file into a number of smaller files, each of a specified size

void FileSplitter::splitFileIntoSizes(std::string directory, std::string fileName, int sizeOfFiles) {
    // Open the binary contents of the file that will be split
    std::ifstream file(directory + "/" + fileName, std::ifstream::binary);
    
    if(!file.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        return;
    }
    
    // Get the size of the entire file
    file.seekg(0, std::ifstream::end);
    long fileSize = file.tellg();
    file.seekg(0);
    
    // Get the number of files
    int numFiles = ceil(fileSize / sizeOfFiles);
    
    splitFile(&file, numFiles, sizeOfFiles, directory, fileName);
    
    file.close();
}