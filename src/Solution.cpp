//
// Created by Xu_Sh on 2020/6/6.
//
#include <iostream>
#include <fstream>

#include "Solution.h"

using namespace std;

Solution::Solution(const string &_name, const string &_folder) : File(_name, _folder) {
    vector<string> files;
    utils::getPathFiles(files, getAbsolutePath(), "*.c*", _A_ARCH);
    for (const auto &file: files) {
        string path = utils::getAbsolutePath(getAbsolutePath(), file);
        if (utils::hasMainFun(path)) {
            Project project(file, getAbsolutePath());
            projects.push_back(project);
        }
    }
}

void Solution::generateSolution() {
    // todo: 生成sln文件
    ifstream in(PROJECT_DIR"/templates/template.sln");
    ofstream out(getAbsolutePath() + ".sln");
    if(!in){
        cerr<<"Can't read template file: "<<PROJECT_DIR"/templates/template.sln"<<endl;
        exit(-1);
    }
    string line, projectLine;
    while (getline(in, line)) {
        if (line.find("{slnName}") == string::npos) {
            out << line << endl;
        } else {
            projectLine = utils::replace(line, "{slnName}", this->name);
            for (auto item : projects) {
                item.generateAllConfigFiles();
                item.modifySourceFiles();
                out << utils::replace(projectLine, "{projName}", item.getProjectName())<<endl;
            }
        }
    }
    cout << "Successfully generate " << getAbsolutePath() + ".sln" << endl;
}
