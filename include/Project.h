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
    vector<SourceFile> sourceFiles;
    vector<HeaderFile> headerFiles;
    string projectName, projectPath;
public:
    Project(const string& _name, const string& _folder);
    void searchFiles();
    void modifySourceFiles();
    void generateAllConfigFiles();
    void generateConfigFile(const string & fileEnd);
    string getProjectName();
};


#endif //VSASSISTANT_PROJECT_H
