#include <iostream>
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{

    int i = 0xFF000000;
    izutils::EndianSwap<int> es;
    int j = es(i);

    return 0;
}
