#include <iostream>
#include "utils.h"
#include "algorithm.h"

using namespace std;

int main(int argc, char *argv[])
{

    int i = 0xFF000000;
    izutils::EndianSwap<int> es;
    int j = es(i);

    int size = 0;
    char** str = izutils::split(",,,,,.,.,,.,.,.,.,.,.,,,,,..,.,oiausioam,2,12,32l,329032,,32323,2,23,023,232",
                                ',', &size);
    for(int i=0; i < size; ++i) {
        std::cout << str[i] << std::endl;
    }

    return 0;
}
