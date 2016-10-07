#ifndef ALGORITHM_H
#define ALGORITHM_H

namespace izutils {

struct point
{
    float x;
    float y;
};

template <typename T> void swap_in_place(T* arr, int a, int b)
{
    T tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

template <typename T> int partition(T* arr, int l, int r)
{
    T pivot = arr[r];
    int i = l-1;
    int j;
    for(j = l; j < r; j++) {
        if (arr[j] < pivot) {
            swap_in_place<T>(arr, ++i, j);
        }
    }
    swap_in_place<T>(arr, ++i, r);
    return i;
}

template <typename T> void qsort(T* arr, int l, int r)
{
    if (l  < r ) {
        int pivot = partition<T>(arr, l, r);
        qsort(arr, l, pivot-1);
        qsort(arr, pivot+1, r);
    }
}

template <typename T> T divide_n_conquer(T* arr, int l, int r)
{
    if (l == r) {
        return arr[l];
    }

    T mid = (l+r)/2;
    T x = divide_n_conquer(arr, l, mid);
    T y = divide_n_conquer(arr, mid+1, r);
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

float distance(struct point a, struct point b);

char** split(const char* str, char delimiter, int* ret_size);


}
#endif // ALGORITHM_H
