#include "insl/list_head.h"

void
list_init(struct list_head* head)
{
  head->next = head;
  head->prev = head;
}

void
list_add(struct list_head* new, struct list_head* head)
{
  new->next = head->next;
  new->prev = head;
  head->next->prev = new;
  head->next = new;
}

void
list_add_tail(struct list_head* new, struct list_head* head)
{
  new->next = head;
  new->prev = head->prev;
  head->prev->next = new;
  head->prev = new;
}

void
list_del(struct list_head* entry)
{
  entry->prev->next = entry->next;
  entry->next->prev = entry->prev;
}

bool
list_empty(struct list_head* head)
{
  return head->next == head;
}
