#ifndef CLIST_H
#define CLIST_H

#include <stdbool.h>
#include <stdlib.h>

struct clist_node {
	void			  *data;
	struct clist_node *next;
};

struct clist {
	size_t			   size;
	struct clist_node *head;
	struct clist_node *tail;
};

typedef struct clist list;

/**
 * @brief Initializes a new list.
 *
 * @return A pointer to the new list.
 * @return NULL if the list could not be initialized.
 *
 * @note The returned list must be freed using list_destroy().
 */
list *list_init() __attribute__((warn_unused_result));

/**
 * @brief Destroys a list.
 *
 * @param l The list to destroy.
 * @param destructor A function pointer to a function that will be called on
 * each element in the list.
 *
 * @note If the destructor is NULL, the elements will not be freed.
 */
void list_destroy(list *l, void (*destructor)(void *data));

/**
 * @brief Appends an element to the list.
 *
 * @param l The list to append the element to.
 * @param data The element to append.
 *
 * @return 0 if the element was appended successfully.
 * @return -1 if the element could not be appended.
 *
 * @note data must be dynamically allocated.
 */
int list_append(list *l, void *data) __attribute__((warn_unused_result));

/**
 * @brief Prepends an element to the list.
 *
 * @param l The list to prepend the element to.
 * @param data The element to prepend.
 *
 * @return 0 if the element was prepended successfully.
 * @return -1 if the element could not be prepended.
 *
 * @note data must be dynamically allocated.
 */
int list_prepend(list *l, void *data) __attribute__((warn_unused_result));

/**
 * @brief Removes an element from the list.
 *
 * @param l The list to remove the element from.
 * @param data The element to remove.
 *
 * @return 0 if the element was removed successfully.
 * @return -1 if the element could not be removed.
 */
int list_remove(list *l, void *data) __attribute__((warn_unused_result));

/**
 * @brief Checks if the list is empty.
 *
 * @param l The list to check.
 *
 * @return true if the list is empty.
 * @return false if the list is not empty.
 */
bool list_is_empty(list *l);

/**
 * @brief Gets the size of the list.
 *
 * @param l The list to get the size of.
 *
 * @return The size of the list.
 */
size_t list_size(list *l);

/**
 * @brief Clears the list.
 *
 * @param l The list to clear.
 * @param destructor A function pointer to a function that will be called on
 * each element in the list.
 *
 * @note If the destructor is NULL, the elements will not be freed.
 */
void list_clear(list *l, void (*destructor)(void *data));

#endif // CLIST_H