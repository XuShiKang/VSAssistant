//
// Created by Shikang Xu on 2020/6/5.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "utils.h"

using namespace std;

char utils::getLastChar(const string &s) {
    return s[s.length() - 1];
}

string utils::formatFolder(string folder) {
    if (utils::getLastChar(folder) == '\\') {
        return folder;
    } else {
        return folder + "\\";
    }
}

void utils::getPathFiles(vector<string> &files, const string &folder, const string &filter, char type) {
    // 查找文件函数结果接收结构体
    _finddata_t fileInfo{};
    if(!hasFolder(folder)){
        cerr << "PathError: No Such Path: " << folder << endl;
        exit(-1);
    }
    string filterPath = formatFolder(folder) + filter;
    long handle = _findfirst(filterPath.c_str(), &fileInfo);
    if (handle < 0) {
        _findclose(handle);
        return;
    }
    do {
        if ((fileInfo.attrib & type) && fileInfo.name[0] != '.') {
            files.emplace_back(fileInfo.name);
        }
    } while (_findnext(handle, &fileInfo) == 0);
    _findclose(handle);
}

string utils::join(std::initializer_list<string> values) {
    string result;
    for (const auto &item : values) {
        result += item;
    }
    return result;
}

bool utils::hasFolder(const string &folder) {
    _finddata_t fileInfo{};
    string filterPath = formatFolder(folder) + "*";
    long handle = _findfirst(filterPath.c_str(), &fileInfo);
    _findclose(handle);
    return handle > 0;
}

bool utils::hasMainFun(const string& path) {
    ifstream file(path);
    string line;
    while (getline(file, line)){
        if(line.find("main") != std::string::npos){
            return true;
        }
    }
    return false;
}

string utils::replace(const string &s, const string& oldStr, const string& newStr) {
    string res = s;
    auto found = res.find(oldStr);
    while (found != string::npos){
        res.replace(found, oldStr.length(), newStr);
        found = res.find(oldStr);
    }
    return res;
}

string utils::getAbsolutePath(const string& folder, const string& name) {
    return utils::formatFolder(folder) + name;
}

void utils::copyDir(const string &sourceDir, const string &targetDir) {
    string cmd = "xcopy " + sourceDir.substr(0, sourceDir.size() - 1) + " " + targetDir + " /c/e/r/y";
    cout<<"Start copy dictionary!"<<endl;
    if(system(cmd.c_str()) != 0){
        cout<<cmd<<endl;
        cerr<<"Dictionary copy error!"<<endl;
        exit(-1);
    }
    cout<<"Copy dictionary successfully!"<<endl;
}

void utils::makeDir(const string &dir) {
    string cmd = "mkdir " + dir;
    if(hasFolder(dir)){
        return;
    }
    if(system(cmd.c_str()) != 0){
        cout<<cmd<<endl;
        cerr<<"Dictionary copy error!"<<endl;
        exit(-1);
    }
    cout<<"Make dictionary successfully!"<<endl;
}

void utils::copyFile(const string &sourceFile, const string &targetDir) {
    string cmd = "xcopy " + replace(sourceFile, "/", "\\") + " " + replace(targetDir, "/", "\\") + " /c/e/r/y";
    if(system(cmd.c_str()) != 0){
        cout<<cmd<<endl;
        cerr<<"File copy error!"<<endl;
        exit(-1);
    }
    cout<<"Copy File successfully!"<<endl;
}

