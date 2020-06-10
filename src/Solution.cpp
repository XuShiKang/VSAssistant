//
// Created by Xu_Sh on 2020/6/6.
//
#include <iostream>

#include "Solution.h"

using namespace std;

Solution::Solution(const string &_name, const string &_folder) : File(_name, _folder) {
    vector<string> files;
    utils::getPathFiles(files, getAbsolutePath(), "*.c*", _A_ARCH);
    for (const auto& file: files) {
        string path = utils::getAbsolutePath(getAbsolutePath(), file);
        if(utils::hasMainFun(path)){
            projects.emplace_back(file, getAbsolutePath());
        }
    }
}

void Solution::generateSolution() {
    // todo: 生成sln文件
}
