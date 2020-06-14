#include "sort.h"

/**
 * insertion_sort_list - sorts an linked list of integers in ascending
 * order using the insertion_sort_list algorithm
 * print the list after each
 *  time you swap two elements
 * @list: List to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *f = NULL;
	listint_t *b = NULL;
	listint_t *aux = NULL;

	if (list == NULL || *list == NULL)
		return;

	for (f = *list; f != NULL; f = f->next)
	{
		for (b = f; b->prev != NULL;)
		{
			if (b->prev->n > b->n)
			{
				if (b->prev->prev != NULL)
					b->prev->prev->next = b;
				else
					*list = b;

				if (b->next != NULL)
					b->next->prev = b->prev;

				aux = b->prev->prev;

				b->prev->next = b->next;
				b->prev->prev = b;

				b->next = b->prev;
				b->prev = aux;

				print_list(*list);
			}
			else
				break;
		}
	}
}
