//
// Created by Xu_Sh on 2020/6/6.
//

#ifndef VSASSISTANT_FILE_H
#define VSASSISTANT_FILE_H

#include <string>

#include "utils.h"

using namespace std;


class CppFile: public File{
    bool isModified;
public:
    CppFile(const string& _name, const string& _folder);
    bool modify();
};

class CFile: public File{
    bool isModified;
public:
    CFile(const string& _name, const string& _folder);
    bool modify();
};

class HeaderFile: public File{
    bool isModified;
public:
    HeaderFile(const string& _name, const string& _folder);
    bool modify();
};

#endif //VSASSISTANT_FILE_H
