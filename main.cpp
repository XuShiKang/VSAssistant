#include <iostream>
#include <io.h>

#include "Args.h"
#include "utils.h"
#include "Solution.h"

using namespace std;

int main(int argc, char *args[]) {
    Args arguments(argc, args);
    vector<string> folders;
    utils::getPathFiles(folders, arguments.getSourceFolder(), "*", _A_SUBDIR);
    for (const auto &folder : folders) {
        Solution solution(folder, arguments.getSourceFolder());
        cout << solution.getAbsolutePath() << endl;
    }
    return 0;
}
