#pragma once

#include "insl/common.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

  struct hlist_node
  {
    struct hlist_node *next, **pprev;
  };

  struct hlist_head
  {
    struct hlist_node* first;
  };

  void INSL_PUBLIC hlist_init(struct hlist_head* h);

  void INSL_PUBLIC hlist_init_node(struct hlist_node* n);

  void INSL_PUBLIC hlist_add_head(struct hlist_node* n, struct hlist_head* h);

  void INSL_PUBLIC hlist_add_before(struct hlist_node* n,
                                    struct hlist_node* curr);

  void INSL_PUBLIC hlist_add_after(struct hlist_node* curr,
                                   struct hlist_node* n);

  void INSL_PUBLIC hlist_del(struct hlist_node* n);

  bool INSL_PUBLIC hlist_empty(struct hlist_head* h);

#define hlist_entry(ptr, type, member) container_of(ptr, type, member)

#define hlist_for_each(pos, head)                                              \
  for ((pos) = (head)->first; pos; (pos) = (pos)->next)

#ifdef __cplusplus
}
#endif
