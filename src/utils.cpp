//
// Created by Shikang Xu on 2020/6/5.
//

#include <iostream>
#include <fstream>

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
//        cerr << "PathError: In Path: " << folder << endl;
//        cerr << "No Such File like " << filter << endl;
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

string & utils::replace(string &s, const string& replaced, const string& to_be_replace) {
    auto found = s.find(replaced);
    while (found != string::npos){
        s.replace(found, to_be_replace.length(), to_be_replace);
        found = s.find(replaced);
    }
    return s;
}

string utils::getAbsolutePath(const string& folder, const string& name) {
    return utils::formatFolder(folder) + name;
}

