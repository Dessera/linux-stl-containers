#include "insl/hlist_head.h"

void
hlist_init(struct hlist_head* h)
{
  h->first = nullptr;
}

void
hlist_init_node(struct hlist_node* n)
{
  n->pprev = nullptr;
  n->next = nullptr;
}

void
hlist_add_head(struct hlist_node* n, struct hlist_head* h)
{
  struct hlist_node* first = h->first;
  n->next = first;
  if (first) {
    first->pprev = &n->next;
  }
  h->first = n;
  n->pprev = &h->first;
}

void
hlist_add_before(struct hlist_node* n, struct hlist_node* curr)
{
  n->pprev = curr->pprev;
  n->next = curr;
  curr->pprev = &n->next;
  *(n->pprev) = n;
}

void
hlist_add_after(struct hlist_node* curr, struct hlist_node* n)
{
  n->next = curr->next;
  n->pprev = &curr->next;
  curr->next = n;
  if (n->next) {
    n->next->pprev = &n->next;
  }
}

void
hlist_del(struct hlist_node* n)
{
  struct hlist_node* next = n->next;
  struct hlist_node** pprev = n->pprev;
  *pprev = next;
  if (next) {
    next->pprev = pprev;
  }
  n->next = nullptr;
  n->pprev = nullptr;
}

bool
hlist_empty(struct hlist_head* h)
{
  return h->first == nullptr;
}
