#include <iostream>
#include <io.h>

#include "Args.h"
#include "utils.h"

using namespace std;

int main(int argc, char *args[]) {
    Args arguments(argc, args);
    vector<string> folders, files;
    utils::getPathFiles(folders, arguments.getSourceFolder(), "*.*", _A_SUBDIR);
    for (const auto &folder : folders) {
        cout << folder << endl;
        utils::getPathFiles(files, folder, "*.cpp", _A_ARCH);
        for (const auto& file: files) {
            cout << file << endl;
        }
        files.clear();
    }
    return 0;
}
