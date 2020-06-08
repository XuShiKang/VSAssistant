//
// Created by Shikang Xu on 2020/6/5.
//

#ifndef VSASSISTANT_UTILS_H
#define VSASSISTANT_UTILS_H

#include <string>
#include <vector>

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
    static bool hasFolder(const string& folder);
};

class File {
protected:
    string name;
    string folder;
public:
    File(const string& _name, const string& _folder);
    string getName();
    string getAbsolutePath();
};


#endif //VSASSISTANT_UTILS_H
