//
// Created by Shikang Xu on 2020/6/4.
//
#include "Args.h"
#include "utils.h"

using namespace std;

const int BEFORE_LINE_WIDTH = 8;

Args::Args(int argc, char *args[]) {
    if (argc < 2) {
        Args::help();
    }
    string first_arg = string(args[1]);
    if (first_arg == "--help") {
        Args::help();
    }
    for (int i = 1; i < argc; i += 2) {
        if (i + 1 >= argc)
            break;
        auto is_success = arguments.insert(pair<string, string>(args[i], args[i + 1]));
        if (!is_success.second) {
            // 重复参数
            cerr << "Arguments error! Can't two argument name " << args[i] << endl;
            Args::help();
        }
    }
    this->checkAndGetArgument();
}

void Args::help() {
    showUsage();
    cout << "\t" << std::left << setw(BEFORE_LINE_WIDTH) << "--help" << "\tShow help messages" << endl
         << "\t" << std::left << setw(BEFORE_LINE_WIDTH) << "--source"
         << "\tThe folder where you want to build Visual Studio Solution" << endl
         << "\t" << std::left << setw(BEFORE_LINE_WIDTH) << "--target"
         << "\tThe folder where you want to put the Visual Studio Solution, Default is modified in place" << endl;
    exit(-1);
}

void Args::show() {
    for (const auto &item: arguments) {
        cout << "\t" << setw(BEFORE_LINE_WIDTH) << item.first << "\t" << item.second << endl;
    }
}

void Args::showUsage() {
    cout << "\t" << std::left << setw(BEFORE_LINE_WIDTH) << "Usage:"
         << "VSAssistant [--help] [--source <source folder>]" << endl
         << "\t" << std::left << setw(BEFORE_LINE_WIDTH) << " " << "[--target <target folder>]" << endl;
}

void Args::checkAndGetArgument() {
    auto source_flag = arguments.find("--source");
    auto target_flag = arguments.find("--target");
    if (source_flag == arguments.end()) {
        cerr << "Without --source, the program can't run!!" << endl;
        this->help();
    } else {
        this->sourceFolder = utils::formatFolder(source_flag->second);
    }
    if (target_flag != arguments.end()) {
        this->targetFolder = utils::formatFolder(target_flag->second);
    }
}

