//
// Created by Shikang Xu on 2020/6/5.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "utils.h"

using namespace std;

/*
 * 获取字符串的最后一个字符
 * @s: 源字符串
 */
char utils::getLastChar(const string &s) {
    return s[s.length() - 1];
}

/*
 * 格式化文件夹路径，将`/`改成`\\`，末尾带`\\`
 * @folder: 文件夹路径
 */
string utils::formatFolder(string folder) {
    folder = replace(folder, "/", "\\");
    if (utils::getLastChar(folder) == '\\') {
        return folder;
    } else {
        return folder + "\\";
    }
}

/*
 * 获取文件夹下的文件列表
 * @files:  存取文件名的容器
 * @folder: 需要搜索的目标文件夹
 * @filter: 过滤条件，使用正则表达式
 * @type:   文件类型
 */
void utils::getPathFiles(vector<string> &files, const string &folder, const string &filter, char type) {
    // 查找文件函数结果接收结构体
    _finddata_t fileInfo{};
    if (!hasFolder(folder)) {
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

/*
 * 字符串拼接
 * @values: 需要拼接的字符串列表
 * 调用方式为join({"a", "b", "c"})
 */
string utils::join(std::initializer_list<string> values) {
    string result;
    for (const auto &item : values) {
        result += item;
    }
    return result;
}

/*
 * 判断该文件夹是否存在
 * @folder: 文件夹路径
 */
bool utils::hasFolder(const string &folder) {
    _finddata_t fileInfo{};
    string filterPath = formatFolder(folder) + "*";
    long handle = _findfirst(filterPath.c_str(), &fileInfo);
    _findclose(handle);
    return handle > 0;
}

/*
 * 判断一个文件内是否有main函数
 * @path: 文件路径
 */
bool utils::hasMainFun(const string &path) {
    ifstream file(path);
    string line;
    while (getline(file, line)) {
        if (line.find("main") != std::string::npos) {
            return true;
        }
    }
    return false;
}

/*
 * 字符串替换函数
 * @s:      源字符串
 * @oldStr：需要被替代的字符串
 * @newStr: 新字符串
 * oldStr --> newStr
 */
string utils::replace(const string &s, const string &oldStr, const string &newStr) {
    string res = s;
    auto found = res.find(oldStr);
    while (found != string::npos) {
        res.replace(found, oldStr.length(), newStr);
        found = res.find(oldStr);
    }
    return res;
}

/*
 * 通过拼接获取文件的绝对路径
 * @folder: 文件夹路径
 * @name:   文件名
 */
string utils::getAbsolutePath(const string &folder, const string &name) {
    return utils::formatFolder(folder) + name;
}

/*
 * 将一个文件夹复制到另一个目录
 * @sourceDir: 源文件夹，要被复制的文件夹
 * @targetDir: 目标文件夹，要复制到的文件夹
 */
void utils::copyDir(const string &sourceDir, const string &targetDir) {
    string cmd = "xcopy " + sourceDir.substr(0, sourceDir.size() - 1) + " " + targetDir + " /c/e/r/y";
    cout << "Start copy dictionary!" << endl;
    if (system(cmd.c_str()) != 0) {
        cout << cmd << endl;
        cerr << "Dictionary copy error!" << endl;
        exit(-1);
    }
    cout << "Copy dictionary successfully!" << endl;
}

/*
 * 创建一个文件夹，已存在则不创建
 * @dir: 要创建的文件夹
 */
void utils::makeDir(const string &dir) {
    string cmd = "mkdir " + dir;
    if (hasFolder(dir)) {
        return;
    }
    if (system(cmd.c_str()) != 0) {
        cout << cmd << endl;
        cerr << "Dictionary copy error!" << endl;
        exit(-1);
    }
    cout << "Make dictionary successfully!" << endl;
}

/*
 * 将一个文件复制到另一个目录
 * @sourceFile: 源文件的绝对路径
 * @targetDir:  要复制到的目标文件夹
 */
void utils::copyFile(const string &sourceFile, const string &targetDir) {
    string cmd = "xcopy " + replace(sourceFile, "/", "\\") + " " + replace(targetDir, "/", "\\") + " /c/e/r/y";
    if (system(cmd.c_str()) != 0) {
        cout << cmd << endl;
        cerr << "File copy error!" << endl;
        exit(-1);
    }
    cout << "Copy File successfully!" << endl;
}

