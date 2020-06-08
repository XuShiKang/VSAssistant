//
// Created by Xu_Sh on 2020/6/6.
//

#ifndef VSASSISTANT_PROJECT_H
#define VSASSISTANT_PROJECT_H

#include <string>
#include <vector>

#include "utils.h"
#include "File.h"

using namespace std;

class Project: public File {
    ProjectType type;
    vector<CppFile> cppFiles;
    vector<CFile> cFiles;
    vector<HeaderFile> headerFiles;
public:
    Project(string _name, string _folder, ProjectType _type);
    void searchFiles();
    void modifySourceFiles();
    void generateConfigFiles();
};


#endif //VSASSISTANT_PROJECT_H
