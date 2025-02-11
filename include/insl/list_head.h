#pragma once

#include "insl/common.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

  struct list_head
  {
    struct list_head *next, *prev;
  };

  void INSL_PUBLIC list_init(struct list_head* head);

  void INSL_PUBLIC list_add(struct list_head* new, struct list_head* head);

  void INSL_PUBLIC list_add_tail(struct list_head* new, struct list_head* head);

  void INSL_PUBLIC list_del(struct list_head* entry);

  bool INSL_PUBLIC list_empty(struct list_head* head);

#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define list_for_each(pos, head)                                               \
  for ((pos) = (head)->next; (pos) != (head); (pos) = (pos)->next)

#ifdef __cplusplus
}
#endif
