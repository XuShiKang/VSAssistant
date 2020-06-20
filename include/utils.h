//
// Created by Shikang Xu on 2020/6/5.
//

#ifndef VSASSISTANT_UTILS_H
#define VSASSISTANT_UTILS_H

#include <string>
#include <vector>
#include <io.h>

#include "File.h"

#ifdef PATH
    #define PROJECT_DIR PATH
#else
    #define PROJECT_DIR ""
#endif

using namespace std;

/*
 * 通用函数，实现了一些基本功能
 */
class utils {
public:
    // 获取字符串的最后一个字符
    static char getLastChar(const string &s);
    // 格式化文件夹路径，将`/`改成`\\`，末尾带`\\`
    static string formatFolder(string folder);
    // 获取文件夹下的文件列表
    static void getPathFiles(vector<string> &files, const string& folder, const string& filter, char type);
    // 字符串拼接
    static string join(std::initializer_list<string> values);
    // 通过拼接获取文件的绝对路径
    static string getAbsolutePath(const string& folder, const string& name);
    // 判断该文件夹是否存在
    static bool hasFolder(const string& folder);
    // 判断一个文件内是否有main函数
    static bool hasMainFun(const string& path);
    // 字符串替换函数
    static string replace(const string& s, const string& oldStr, const string& newStr);
    // 将一个文件夹复制到另一个目录
    static void copyDir(const string & sourceDir, const string & targetDir);
    // 将一个文件复制到另一个目录
    static void copyFile(const string & sourceFile, const string & targetDir);
    // 创建一个文件夹，已存在则不创建
    static void makeDir(const string & dir);
};



#endif //VSASSISTANT_UTILS_H
