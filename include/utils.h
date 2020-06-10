//
// Created by Shikang Xu on 2020/6/5.
//

#ifndef VSASSISTANT_UTILS_H
#define VSASSISTANT_UTILS_H

#include <string>
#include <vector>
#include <io.h>

#include "File.h"

using namespace std;

enum ProjectType{
    C_PROJECT,
    CPP_PROJECT
};

class utils {
public:
    static char getLastChar(const string &s);
    static string formatFolder(string folder);
    static void getPathFiles(vector<string> &files, const string& folder, const string& filter, char type);
    static string join(std::initializer_list<string> values);
    static string getAbsolutePath(const string& folder, const string& name);
    static bool hasFolder(const string& folder);
    static bool hasMainFun(const string& path);
    static string & replace(string& s, const string& replaced, const string& to_be_replace);
};



#endif //VSASSISTANT_UTILS_H
