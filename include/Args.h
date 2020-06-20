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

/*
 * 命令行处理类，接受命令行参数，解析命令行内容
 */
class Args {
    // 存储命令行参数的map，将解析的命令行参数以key-value存储
    std::map<std::string, std::string> arguments;
    // 源文件夹
    // 目标文件夹
    string sourceFolder, targetFolder;
public:
    // 构造函数，接收并解析main函数的命令行参数
    Args(int argc, char *args[]);

    // 展示解析完成的命令行参数
    void show();

    // 展示帮助信息并退出程序
    static void help();

    // 展示程序用法
    static void showUsage();

    // 检查命令行参数
    void checkAndGetArgument();

    string getSourceFolder() { return this->sourceFolder; }

    string getTargetFolder() { return this->targetFolder; }
};


#endif //VSASSISTANT_ARGS_H
