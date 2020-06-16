#include <iostream>
#include <io.h>

#include "Args.h"
#include "utils.h"
#include "Solution.h"

using namespace std;

int main(int argc, char *args[]) {
    Args arguments(argc, args);
    string wordDir = arguments.getSourceFolder(), optionsDir;
    if(!arguments.getTargetFolder().empty()){
        utils::copyDir(arguments.getSourceFolder(), arguments.getTargetFolder());
        wordDir = arguments.getTargetFolder();
    }
    utils::makeDir(wordDir + ".vs");
    vector<string> folders;
    utils::getPathFiles(folders, wordDir, "*", _A_SUBDIR);
    for (const auto &folder : folders) {
        Solution solution(folder, wordDir);
        solution.generateSolution();
        optionsDir = wordDir + ".vs\\" + solution.getName() + "\\v16";
        utils::makeDir(optionsDir);
        utils::copyFile(PROJECT_DIR"/templates/.suo", optionsDir);
    }
    return 0;
}
