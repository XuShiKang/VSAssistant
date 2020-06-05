//
// Created by Shikang Xu on 2020/6/4.
//
#include "Args.h"

using namespace std;

const int BEFORE_LINE_WIDTH = 8;

Args::Args(int argc, char *args[]) {
    for (int i = 1; i < argc; i+=2) {
        auto is_success = arguments.insert(pair<string, string>(args[i], args[i + 1]));
        if(!is_success.second){
            cerr<<"Arguments error! Can't two argument name "<<args[i]<<endl;
            exit(-1);
        }
    }
    auto help_flag = arguments.find("-h");
    if(help_flag != arguments.end()){
        this->help();
    }
}

void Args::help() {
    showUsage();
    cout<<"\t"<<std::left<<setw(BEFORE_LINE_WIDTH)<<"-h"<<endl;
    cout<<"\t"<<std::left<<setw(BEFORE_LINE_WIDTH)<<"--help"<<"\tShow help message"<<endl;
    cout<<"\t"<<std::left<<setw(BEFORE_LINE_WIDTH)<<"-s"<<endl;
    cout<<"\t"<<std::left<<setw(BEFORE_LINE_WIDTH)<<"--source"<<"\tThe folder where you want to build Visual Studio Solution"<<endl;
    cout<<"\t"<<std::left<<setw(BEFORE_LINE_WIDTH)<<"-t"<<endl;
    cout<<"\t"<<std::left<<setw(BEFORE_LINE_WIDTH)<<"--target"<<"\tThe folder where you want to put the Visual Studio Solution, Default is modified in place"<<endl;
}

void Args::show() {
    for (const auto& item: arguments) {
        cout<<"\t"<<setw(BEFORE_LINE_WIDTH)<<item.first<<"\t"<<item.second<<endl;
    }
}

void Args::showUsage() {
    cout<<std::left<<setw(BEFORE_LINE_WIDTH)<<"Usage:"<<"VSAssistant [--help] [--source <source folder>]"<<endl;
    cout<<std::left<<setw(BEFORE_LINE_WIDTH)<<" "<<"[--target <target folder>]";
}
