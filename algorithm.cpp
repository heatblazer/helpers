#include "algorithm.h"
#include <math.h>

namespace izutils {

float distance(point a, point b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt((dx*dx) + (dy*dy));
}

int aux_strlen(const char* str)
{
    int size = 0;
    while ( *str != '\0') {
        size++;
        str++;
    }
    return size;
}

char* aux_strchr(const char* str, char c)
{
    char* it = (char*) str;
    while ( *it != c && *it != '\0') {
        it++;
    }
    return it;

}

char* aux_slice(const char* str, char delimiter, const char** pRet)
{
    int size = 0;
    const char* begin = str;
    while (*begin != delimiter) {
        size++;
        begin++;
    }
    char* ret = new char[size];
    int i;
    for(i = 0; str[i] != delimiter; ++i) {
        ret[i] = str[i];
    }
    ret[i] = '\0';

    while (*begin == delimiter) {
        begin++;
    }
    // assign the new value of the
    // begin - now begin is the next
    // non-delimiter data
    (*pRet) = begin;

    return ret;
}

/// splits a huge string
/// by a delimiter
/// ver1
/// \brief split
/// \param str
/// \param delimiter
/// \param ret_size
/// \return
///
char **split(const char *str, char delimiter, int *ret_size)
{
    const char* begin = str;
    const char* end = &str[aux_strlen(str)-1];
    while (*begin == delimiter) begin++;
    while (*end == delimiter) end--;
    int splits = 0;
    int diff = (end - begin)+1;

    int i =0;
    while (i < diff) {
        if (begin[i] == delimiter) {
            while (begin[i] == delimiter) i++;
            splits++;
        }
        i++;
    }
    splits += 1; // +1 for the split

    *ret_size = splits; // number of strings after the split
    char** split_str = new char*[splits];
    for(int i=0; i < splits; ++i) {
        split_str[i] = aux_slice(begin, delimiter, &begin);
    }
    return split_str;
}


} // namespace izutils
