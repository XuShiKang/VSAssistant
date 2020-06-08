//
// Created by Xu_Sh on 2020/6/6.
//

#include "File.h"

#include "utils.h"

CppFile::CppFile(const string &_name, const string &_folder) :
        File(_name, _folder), isModified(false) {}

bool CppFile::modify() {
    // todo: 对不支持VS/DevC++的源代码文件中的语句进行修改
    return false;
}

CFile::CFile(const string &_name, const string &_folder):
File(_name, _folder), isModified(false) {}

bool CFile::modify() {
    // todo: 对不支持VS/DevC++的源代码文件中的语句进行修改
    return false;
}

HeaderFile::HeaderFile(const string &_name, const string &_folder) :
File(_name, _folder), isModified(false) {}

bool HeaderFile::modify() {
    // todo: 对不支持VS/DevC++的源代码文件中的语句进行修改
    return false;
}
