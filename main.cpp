#include <iostream>

#include "Args.h"

int main(int argc, char *args[]) {
    Args arguments(argc, args);
    arguments.show();
    return 0;
}
