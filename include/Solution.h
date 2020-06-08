//
// Created by Xu_Sh on 2020/6/6.
//

#ifndef VSASSISTANT_SOLUTION_H
#define VSASSISTANT_SOLUTION_H

#include <string>
#include <vector>

#include "Project.h"

using namespace std;

class Solution: public File{
    vector<Project> projects;
public:
    Solution(const string& _name, const string &_folder);
    void generateSolution();
};


#endif //VSASSISTANT_SOLUTION_H
