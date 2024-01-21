#include "sort.h"
#include <stdbool.h>

void swap_node_forward(listint_t **list, listint_t **tail,
listint_t **current);
void swap_node_backward(listint_t **list,
listint_t **tail, listint_t **current);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_forward - Swap a node in a listint_t doubly-linked list
 *                     with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the current swapping node.
 */
void swap_node_forward(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*current)->prev;
	(*current)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*tail = *current;

	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}

/**
 * swap_node_backward - Swap a node in a listint_t doubly-linked list
 *                      with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the current swapping node.
 */
void swap_node_backward(listint_t **list,
listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*current)->next;
	(*current)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;

	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (!shaken_not_stirred)
	{
		shaken_not_stirred = true;
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_forward(list, &tail, &current);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (current = current->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_backward(list, &tail, &current);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
