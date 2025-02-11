#include "insl/list_head.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>

struct int_list
{
  struct list_head list;
  int value;
};

struct int_list*
int_list_create(int value)
{
  struct int_list* new = malloc(sizeof(struct int_list));
  list_init(&new->list);
  new->value = value;
  return new;
}

void
int_list_destroy(struct int_list* list)
{
  list_del(&list->list);
  free(list);
}

void
test_list_init(void)
{
  struct list_head head;
  list_init(&head);
  assert(head.next == &head);
  assert(head.prev == &head);
}

void
test_list_add(void)
{
  struct list_head head;
  list_init(&head);

  struct list_head node1;
  list_init(&node1);

  struct list_head node2;
  list_init(&node2);

  list_add(&node1, &head);
  list_add(&node2, &head);

  assert(head.next == &node2);
  assert(head.prev == &node1);
  assert(node2.next == &node1);
}

void
test_list_add_tail(void)
{
  struct list_head head;
  list_init(&head);

  struct list_head node1;
  list_init(&node1);

  struct list_head node2;
  list_init(&node2);

  list_add_tail(&node1, &head);
  list_add_tail(&node2, &head);

  assert(head.next == &node1);
  assert(head.prev == &node2);
  assert(node1.next == &node2);
}

void
test_list_del(void)
{
  struct list_head head;
  list_init(&head);

  struct list_head node1;
  list_init(&node1);

  struct list_head node2;
  list_init(&node2);

  list_add(&node1, &head);
  list_add(&node2, &head);

  list_del(&node1);

  assert(head.next == &node2);
  assert(head.prev == &node2);
  assert(node2.next == &head);
  assert(node2.prev == &head);
}

void
test_list_empty(void)
{
  struct list_head head;
  list_init(&head);

  assert(list_empty(&head) == true);

  struct list_head node1;
  list_init(&node1);

  list_add(&node1, &head);

  assert(list_empty(&head) == false);
}

void
test_list_entry(void)
{
  struct int_list* ilist = int_list_create(42);
  assert(list_entry(&ilist->list, struct int_list, list) == ilist);
  int_list_destroy(ilist);
}

void
test_list_for_each(void)
{
  struct list_head head;
  list_init(&head);

  struct list_head node1;
  list_init(&node1);

  struct list_head node2;
  list_init(&node2);

  list_add(&node1, &head);
  list_add(&node2, &head);

  struct list_head* pos = NULL;
  list_for_each(pos, &head)
  {
    assert(pos == &node1 || pos == &node2);
  }
}

int
main(void)
{
  test_list_init();
  test_list_add();
  test_list_add_tail();
  test_list_del();
  test_list_empty();
  test_list_entry();
  test_list_for_each();
}
