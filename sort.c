#include <stdio.h>
#include "sort.h"

#define __SWAP(a, b, l) do {                \
    char *__a = (a), *__b = (b), __tmp;     \
    size_t len = (l);                       \
    for (size_t __i = 0; __i != l; __i++) { \
        __tmp = __a[__i];                   \
        __a[__i] = __b[__i];                \
        __b[__i] = __tmp;                   \
    }                                       \
} while(0)

#define __IDX(base, idx, size) ((base) + (idx) * (size)) 

typedef int(*__cmp_fn_t)(const void*, const void*);

void bubble_sort(void *base, size_t __nmemb, 
                 size_t __size, __cmp_fn_t cmp) {

    char *lo = (char *) base;

    for (size_t i = 0; i != __nmemb; ++i) {
        for (size_t j = 0; j != __nmemb - i - 1; ++j) {
            char *a = __IDX(lo, j, __size);
            char *b = __IDX(lo, j + 1, __size);
            if (cmp(a, b) > 0) {
                __SWAP(a, b, __size);
            }
        }
    }
}

void selection_sort(void *base, size_t __nmemb,
                    size_t __size, __cmp_fn_t cmp) {
    char *lo = (char *) base;

    for (size_t i = 0; i != __nmemb; ++i) {
        int max = i;
        for (size_t j = i + 1; j != __nmemb; ++j) {
            char *a = __IDX(lo, max, __size);
            char *b = __IDX(lo, j, __size);
            if (cmp(a, b) > 0) {
                max = j;
            }
        }
        __SWAP(
            __IDX(lo, i, __size), 
            __IDX(lo, max, __size), 
            __size
        );
    }
}
