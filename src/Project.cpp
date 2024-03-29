//
// Created by Xu_Sh on 2020/6/6.
//
#include <iostream>
#include <fstream>

#include "Project.h"

/*
 * 构造函数，生成项目结构
 * @_name:   main函数所在文件名
 * @_folder: 项目所在文件夹
 */
Project::Project(const string &_name, const string &_folder) :
        File(_name, _folder) {
    this->projectName = _name.substr(0, _name.find('.'));
    this->sourceFiles.emplace_back(_name, _folder);
    this->projectPath = utils::formatFolder(folder) + projectName;
    this->searchFiles();
}

/*
 * 查找目录下的cpp/c/h文件
 */
void Project::searchFiles() {
    ifstream in(this->getAbsolutePath());
    string line, sourceName;
    while (getline(in, line)){
        if(line.find("#include \"") != string::npos){
            sourceName = utils::replace(line, "#include \"", "");
            sourceName = sourceName.substr(0, sourceName.find('\"'));
            this->headerFiles.emplace_back(sourceName, folder);
            this->sourceFiles.emplace_back(utils::replace(sourceName, ".h", ".cpp"), folder);
        }
    }
}

/*
 * 修改项目源文件, 先读出再重写
 */
void Project::modifySourceFiles() {
    ifstream in;
    ofstream out;
    vector<string> lines;
    string line;
    for (auto item: this->sourceFiles) {
        item.modify();
    }
    for (auto item: this->headerFiles) {
        item.modify();
    }
}

/*
 * 生成项目配置文件
 */
void Project::generateAllConfigFiles() {
    this->generateConfigFile(".vcxproj");
    this->generateConfigFile(".vcxproj.filters");
    this->generateConfigFile(".vcxproj.user");
}

/*
 * 以后缀生成单个配置文件
 * @fileEnd: 配置文件后缀
 */
void Project::generateConfigFile(const string &fileEnd) {
    ifstream in(PROJECT_DIR"/templates/template" + fileEnd);
    if (!in) {
        cerr << "Can't read template file: " << PROJECT_DIR"/templates/template"<< fileEnd << endl;
        exit(-1);
    }
    ofstream out(this->projectPath + fileEnd);
    string line, projectLine;
    while (getline(in, line)) {
        if (line.find("{cppName}") != string::npos) {
            for (auto item : this->sourceFiles) {
                out << utils::replace(line, "{cppName}", item.getName()) << endl;
            }
        } else if (line.find("{headerName}") != string::npos) {
            for (auto item : this->headerFiles) {
                out << utils::replace(line, "{headerName}", item.getName()) << endl;
            }
        } else {
            out << line << endl;
        }
    }
    cout << "Successfully generate " << projectPath << fileEnd << endl;
}
