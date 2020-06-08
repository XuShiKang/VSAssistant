//
// Created by Shikang Xu on 2020/6/5.
//

#include <io.h>
#include <iostream>

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
            files.push_back(join({formatFolder(folder), fileInfo.name}));
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

File::File(const string& _name, const string& _folder):
        name(_name), folder(_folder) {}

string File::getName() {
    return name;
}

string File::getAbsolutePath() {
    return utils::formatFolder(folder) + name;
}
