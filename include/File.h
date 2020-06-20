//
// Created by Xu_Sh on 2020/6/6.
//

#ifndef VSASSISTANT_FILE_H
#define VSASSISTANT_FILE_H

#include <string>

#include "utils.h"

using namespace std;

/*
 * 文件基类，用于继承
 */
class File {
protected:
    // 文件名
    string name;
    // 文件所在文件夹
    string folder;
public:
    File(const string &_name, const string &_folder);

    string getName(){ return name;}

    // 获取文件绝对路径
    string getAbsolutePath();
};

/*
 * 源文件类，描述.c/.cpp文件
 */
class SourceFile : public File {
public:
    SourceFile(const string &_name, const string &_folder);

    // 对不支持VS/DevC++的源代码文件中的语句进行修改
    void modify();

    // 通过预先定义的规则修改文件
    static void modifyByRules(ofstream &out, const string &l);
};

/*
 * 头文件类
 */
class HeaderFile : public File {
public:
    HeaderFile(const string &_name, const string &_folder);

    // 对不支持VS/DevC++的源代码文件中的语句进行修改
    void modify();

    // 通过预先定义的规则修改文件
    static void modifyByRules(ofstream &out, const string &l);
};

#endif //VSASSISTANT_FILE_H
