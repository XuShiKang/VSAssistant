//
// Created by Xu_Sh on 2020/6/6.
//

#include "Project.h"

Project::Project(string _name, string _folder, ProjectType _type):
File(_name, _folder){
    type = _type;
}

void Project::searchFiles() {
    // todo: 查找目录下的cpp/c文件
}

void Project::modifySourceFiles() {
    // todo: 修改项目源文件
}

void Project::generateConfigFiles() {
    // todo: 生成项目配置文件
}
