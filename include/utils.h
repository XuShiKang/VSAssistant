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

class utils {
public:
    static char getLastChar(const string &s);
    static string formatFolder(string folder);
    static void getPathFiles(vector<string> &files, const string& folder, const string& filter, char type);
    static string join(std::initializer_list<string> values);
    static string getAbsolutePath(const string& folder, const string& name);
    static bool hasFolder(const string& folder);
    static bool hasMainFun(const string& path);
    static string replace(const string& s, const string& oldStr, const string& newStr);
    static void copyDir(const string & sourceDir, const string & targetDir);
    static void copyFile(const string & sourceFile, const string & targetDir);
    static void makeDir(const string & dir);
};



#endif //VSASSISTANT_UTILS_H
