//
// Created by Xu_Sh on 2020/6/6.
//
#include <iostream>
#include <fstream>

#include "File.h"

#include "utils.h"

SourceFile::SourceFile(const string &_name, const string &_folder) :
        File(_name, _folder), isModified(false) {}

void SourceFile::modify() {
    // todo: 对不支持VS/DevC++的源代码文件中的语句进行修改
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

HeaderFile::HeaderFile(const string &_name, const string &_folder) :
        File(_name, _folder), isModified(false) {}

void HeaderFile::modify() {
    // todo: 对不支持VS/DevC++的源代码文件中的语句进行修改
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

File::File(const string &_name, const string &_folder) :
        name(_name), folder(_folder) {}

string File::getName() {
    return name;
}

string File::getAbsolutePath() {
    return utils::formatFolder(folder) + name;
}
