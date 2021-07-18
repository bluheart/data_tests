#include "set.h"


Set *set_initialize(Comparator comparator) {
  Set *set = (Set *) malloc(sizeof(Set));
  set->size = 0;
  set->tree = NULL;
  set->comparator = comparator;
  return set;
}

void free_node(UNUSED void* _node) {}

void set_destroy(Set *set) {
  tdestroy(set->tree, free_node);
  free(set);
}

size_t set_size(const Set *set) {
  return set->size;
}

int set_includes(const Set *set, const void *elem) {
  return tfind(elem, &set->tree, set->comparator) != NULL;
}

void set_insert(Set *set, const void *elem) {
  if (!tfind(elem, &set->tree, set->comparator))
    set->size++;
  tsearch(elem, &set->tree, set->comparator);
}

void set_remove(Set *set, const void *elem) {
  if (tdelete(elem, &set->tree, set->comparator))
    set->size--;
}

