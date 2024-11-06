#pragma once

#include "common.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief A Linux-like doubly linked list implementation but for usage out of
 * the Linux kernel.
 *
 */
struct list_head
{
  struct list_head *next, *prev;
};

/**
 * @brief Initialize(Create) a list head
 *
 * @param head The list head to initialize
 */
void LINUX_STL_CONTAINERS_PUBLIC
list_init(struct list_head* head);

/**
 * @brief Add a new entry after the head
 *
 * @param new The new entry to add
 * @param head The head to add the new entry after
 */
void LINUX_STL_CONTAINERS_PUBLIC
list_add(struct list_head* new, struct list_head* head);

/**
 * @brief Add a new entry to the tail of the list
 *
 * @param new The new entry to add
 * @param head The head to add the new entry to the tail of
 */
void LINUX_STL_CONTAINERS_PUBLIC
list_add_tail(struct list_head* new, struct list_head* head);

/**
 * @brief Delete an entry from the list, but not free it
 *
 * @param entry The entry to delete
 */
void LINUX_STL_CONTAINERS_PUBLIC
list_del(struct list_head* entry);

/**
 * @brief Check if the list is empty
 *
 * @param head The head of the list
 * @return true if the list is empty
 * @return false if the list is not empty
 */
bool LINUX_STL_CONTAINERS_PUBLIC
list_empty(struct list_head* head);

/**
 * @brief Get the first entry from the list
 *
 */
#define list_entry(ptr, type, member) container_of(ptr, type, member)

/**
 * @brief Iterate over the list
 *
 */
#define list_for_each(pos, head)                                               \
  for ((pos) = (head)->next; (pos) != (head); (pos) = (pos)->next)
