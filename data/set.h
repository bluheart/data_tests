#ifndef set_h
#define set_h
#define _GNU_SOURCE
#define UNUSED __attribute__((unused))
#include <search.h>
#include <stddef.h>
#include <stdint.h>

typedef int (*Comparator)(const void *, const void *);
typedef struct {
    void *tree;
    size_t size;
    Comparator comparator;
} Set;  

Set *set_initialize(Comparator);
void set_destroy(Set *);
size_t set_size(const Set *);
int set_includes(const Set *, const void *);
void set_insert(Set *, const void *);
void set_remove(Set *, const void *);

#endif