#ifndef __SIZE_TYPE__
typedef int size_t;
#endif
typedef int(*__cmp_fn_t)(const void*, const void*);
void bubble_sort(void *base, size_t __nmemb, 
                 size_t __size, __cmp_fn_t cmp);
void selection_sort(void *base, size_t __nmemb, 
                 size_t __size, __cmp_fn_t cmp);
void insertion_sort(void *base, size_t __nmemb, 
                 size_t __size, __cmp_fn_t cmp);

