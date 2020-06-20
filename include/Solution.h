//
// Created by Xu_Sh on 2020/6/6.
//

#ifndef VSASSISTANT_SOLUTION_H
#define VSASSISTANT_SOLUTION_H

#include <string>
#include <vector>

#include "Project.h"
#include "utils.h"

using namespace std;

/*
 * 解决方案类，描述了一个解决方案的组成
 */
class Solution : public File {
    // 组成解决方案的项目
    vector<Project> projects;
public:
    // 构造函数，查找文件夹下的项目
    Solution(const string &_name, const string &_folder);

    // 生成解决方案配置文件
    void generateSolution();
};


#endif //VSASSISTANT_SOLUTION_H
