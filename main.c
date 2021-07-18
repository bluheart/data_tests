#include <stdio.h>
#include "data/set.h"

int int_ascending(const void *a, const void *b) {
  long left = *((long *)a), right = *((long *)b);
  return left - right;
}

void action(const void *nodep, VISIT which, UNUSED int depth) {
    int *datap;
    switch (which) {
        case preorder:
            break;
        case postorder:
            datap = *(int **) nodep;
            printf("%d\n", (*datap));
            break;
        case endorder:
            break;
        case leaf:
            datap = *(int **) nodep;
            printf("%d\n", (*datap));
            break;
    }

}
void action2(const void *nodep, VISIT which, UNUSED int depth) {
    int *datap;
    switch (which) {
        case preorder:
            break;
        case postorder:
            datap = *(int **) nodep;
            *datap = (*datap)*3;
            break;
        case endorder:
            break;
        case leaf:
            datap = *(int **) nodep;
            *datap = (*datap)*3;
            break;
    }

}

int main() {
    Set *set = set_initialize(int_ascending);
    const int a[] = {50, -1, 80, 0, -60, 3, 70, -9, 20, 4};
    size_t n;
    for (size_t i = 0; i < 10; i++) {
        n = set_size(set);
        printf("%ld\n", n);
        set_insert(set, &a[i]);
        n = set_size(set);
        printf("%ld\n", n);
    }
    puts("conjunto cheio");
    twalk(set->tree, action2);
    twalk(set->tree, action);
    set_destroy(set);   
    return 0;
}
