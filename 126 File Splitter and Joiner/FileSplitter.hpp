//
//  FileSplitter.hpp
//  126 File Splitter and Joiner
//
//  Created by Greg Salvesen on 11/7/16.
//  Copyright © 2016 DVS. All rights reserved.
//

#include <string>
#include <fstream>

class FileSplitter {
public:
    FileSplitter();
    ~FileSplitter();
    
    static void splitFileIntoParts(std::string directory, std::string filePath, int numFiles);
    static void splitFileIntoSizes(std::string directory, std::string filePath, int sizeOfFiles);
    
private:
    static void splitFile(std::ifstream *file, int numFiles, long fileSize, std::string directory, std::string fileName);
    
    

};