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

/*
 * 项目类，描述了一个项目的组成
 */
class Project : public File {
    // 存放源文件(.c/.cpp)的容器
    vector<SourceFile> sourceFiles;
    // 存放头文件的容器
    vector<HeaderFile> headerFiles;
    // 项目名，项目文件夹 + 项目名
    string projectName, projectPath;
public:
    // 构造函数，生成项目结构
    Project(const string &_name, const string &_folder);

    // 查找目录下的cpp/c/h文件
    void searchFiles();

    // 修改项目源文件, 先读出再重写
    void modifySourceFiles();

    // 生成全部配置文件
    void generateAllConfigFiles();

    // 生成单个配置文件
    void generateConfigFile(const string &fileEnd);

    string getProjectName(){ return this->projectName;}
};


#endif //VSASSISTANT_PROJECT_H
