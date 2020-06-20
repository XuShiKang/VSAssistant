//
// Created by Xu_Sh on 2020/6/6.
//
#include <iostream>
#include <fstream>

#include "File.h"
#include "utils.h"

/*
 * 构造函数
 * @_name:   文件名
 * @_folder: 文件所在文件夹
 */
SourceFile::SourceFile(const string &_name, const string &_folder) :
        File(_name, _folder) {}

/*
 * 对不支持VS/DevC++的源代码文件中的语句进行修改
 */
void SourceFile::modify() {
    ifstream in;
    ofstream out;
    vector<string> lines;
    string line;
    in.open(this->getAbsolutePath());
    while (getline(in, line)) {
        lines.push_back(line);
    }
    out.open(this->getAbsolutePath());
    for (const auto &l: lines) {
        SourceFile::modifyByRules(out, l);
    }
}

/*
 * 构造函数
 * @_name:   文件名
 * @_folder: 文件所在文件夹
 */
HeaderFile::HeaderFile(const string &_name, const string &_folder) :
        File(_name, _folder) {}

/*
 * 对不支持VS/DevC++的源代码文件中的语句进行修改
 */
void HeaderFile::modify() {
    ifstream in;
    ofstream out;
    vector<string> lines;
    string line;
    in.open(this->getAbsolutePath());
    while (getline(in, line)) {
        lines.push_back(line);
    }
    out.open(this->getAbsolutePath());
    for (const auto &l: lines) {
        HeaderFile::modifyByRules(out, l);
    }
}

/*
 * 通过预先定义的规则修改文件
 * @out: 输出文件流
 * @l:   需要修改的源字符串
 */
void HeaderFile::modifyByRules(ofstream &out, const string &l) {
    if (l.find("<iomanip.h>") != string::npos) {
        out << utils::replace(l, "<iomanip.h>", "<iomanip>") << endl;
    } else if (l.find("<strstream.h>") != string::npos) {
        out << utils::replace(l, "<strstream.h>", "<sstream>") << endl;
    } else if (l.find("<sstream>") != string::npos) {
        out << utils::replace(l, "<sstream>", "<istrstream>") << endl;
    } else if (l.find("<ostrstream>") != string::npos) {
        out << utils::replace(l, "<ostrstream>", "<ostringstream>") << endl;
    } else {
        out << l << endl;
    }
}

/*
 * 通过预先定义的规则修改文件
 * @out: 输出文件流
 * @l:   需要修改的源字符串
 */
void SourceFile::modifyByRules(ofstream &out, const string &l) {
    if (l.find("<iostream.h>") != string::npos) {
        out << utils::replace(l, "<iostream.h>", "<iostream>") << endl;
        out << "using namespace std;" << endl;
    } else if (l.find("main") != string::npos) {
        out << utils::replace(l, "void", "int") << endl;
    } else if (l.find("<iomanip.h>") != string::npos) {
        out << utils::replace(l, "<iomanip.h>", "<iomanip>") << endl;
    } else if (l.find("<strstream.h>") != string::npos) {
        out << utils::replace(l, "<strstream.h>", "<sstream>") << endl;
    } else if (l.find("<sstream>") != string::npos) {
        out << utils::replace(l, "<sstream>", "<istrstream>") << endl;
    } else if (l.find("<ostrstream>") != string::npos) {
        out << utils::replace(l, "<ostrstream>", "<ostringstream>") << endl;
    } else {
        out << l << endl;
    }
}

/*
 * 构造函数
 * @_name: 文件名
 * @_folder: 文件所在文件夹
 */
File::File(const string &_name, const string &_folder) :
        name(_name), folder(_folder) {}

/*
 * 获取文件绝对路径
 */
string File::getAbsolutePath() {
    return utils::formatFolder(folder) + name;
}
