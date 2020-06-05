//
// Created by Shikang Xu on 2020/6/4.
//

#ifndef VSASSISTANT_ARGS_H
#define VSASSISTANT_ARGS_H

#include <map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


class Args {
    std::map<std::string, std::string> arguments;
    string sourceFolder, targetFolder;
public:
    Args(int argc, char *args[]);

    void show();

    static void help();

    static void showUsage();

    void checkAndGetArgument();

    string getSourceFolder() { return this->sourceFolder; }

    string getTargetFolder() { return this->targetFolder; }
};


#endif //VSASSISTANT_ARGS_H
