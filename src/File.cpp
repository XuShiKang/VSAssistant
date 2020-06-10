//
// Created by Xu_Sh on 2020/6/6.
//

#include "File.h"

#include "utils.h"

SourceFile::SourceFile(const string &_name, const string &_folder) :
        File(_name, _folder), isModified(false) {}

bool SourceFile::modify() {
    // todo: 对不支持VS/DevC++的源代码文件中的语句进行修改
    return false;
}

HeaderFile::HeaderFile(const string &_name, const string &_folder) :
File(_name, _folder), isModified(false) {}

bool HeaderFile::modify() {
    // todo: 对不支持VS/DevC++的源代码文件中的语句进行修改
    return false;
}

File::File(const string& _name, const string& _folder):
        name(_name), folder(_folder) {}

string File::getName() {
    return name;
}

string File::getAbsolutePath() {
    return utils::formatFolder(folder) + name;
}
