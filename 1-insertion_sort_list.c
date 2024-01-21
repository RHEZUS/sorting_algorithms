#include "sort.h"

/**
 * insertion_sort_list - implements the insertion sort algorithm
 * @list: the array to sort
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;



	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp;

			if (!temp->prev)
				*list = temp;

			temp->next->prev = temp;

			print_list(*list);
		}
	}
}

