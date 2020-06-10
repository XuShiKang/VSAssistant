//
// Created by Xu_Sh on 2020/6/6.
//

#ifndef VSASSISTANT_FILE_H
#define VSASSISTANT_FILE_H

#include <string>

#include "utils.h"

using namespace std;

class File {
protected:
    string name;
    string folder;
public:
    File(const string& _name, const string& _folder);
    string getName();
    string getAbsolutePath();
};


class SourceFile: public File{
    bool isModified;
public:
    SourceFile(const string& _name, const string& _folder);
    bool modify();
};

class HeaderFile: public File{
    bool isModified;
public:
    HeaderFile(const string& _name, const string& _folder);
    bool modify();
};

#endif //VSASSISTANT_FILE_H
