#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int a[100];
    srand(time(NULL));

    for (int i=100;i--;a[i]=rand()%1000);
    selection_sort(a, 100, sizeof(int), cmp);
    for (int i=~0;i++^99;printf("%d ", a[i]));

    return 0;
}
