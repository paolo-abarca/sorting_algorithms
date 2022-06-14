#include "sort.h"

/**
 * swap_2 - Function that changes the nodes from right to left
 *
 * @head: is the start of the double linked list
 * @order: is the current node
 * Return: void
 */

void swap_2(listint_t **head, listint_t *order)
{
	listint_t *previous;
	listint_t *tmp;

	if (order->next != NULL)
	{
		previous = order->prev;
		tmp = order->next;

		previous->next = tmp;
		tmp->prev = previous;

		if (previous->prev != NULL)
		{
			previous->prev->next = order;
			order->prev = previous->prev;
			previous->prev = order;
			order->next = previous;
		}

		else
		{
			*head = order;
			order->prev = NULL;
			previous->prev = order;
			order->next = previous;
		}
	}

	else
	{
		previous = order->prev;
		order->prev = NULL;
		previous->next = NULL;
		previous->prev->next = order;
		order->prev = previous->prev;
		previous->prev = order;
		order->next = previous;
	}
}

/**
 * swap - Function that changes the nodes from left to right
 *
 * @head: is the start of the double linked list
 * @order: is the current node
 * Return: void
 */

void swap(listint_t **head, listint_t *order)
{
	listint_t *previous;
	listint_t *tmp;

	if (order->prev != NULL)
	{
		previous = order->prev;
		tmp = order->next;

		previous->next = tmp;
		tmp->prev = previous;

		if (tmp->next != NULL)
		{
			tmp->next->prev = order;
			order->next = tmp->next;
			tmp->next = order;
			order->prev = tmp;
		}

		else
		{
			tmp->next = order;
			order->prev = tmp;
			order->next = NULL;
		}
	}

	else
	{
		tmp = order->next;
		order->next = NULL;
		tmp->prev = NULL;
		tmp->next->prev = order;
		order->next = tmp->next;
		tmp->next = order;
		order->prev = tmp;
		*head = tmp;
	}
}

/**
 * cocktail_sort_list - is the shaker sorting algorithm
 *
 * @list: is the double linked list
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *order, *len;
	int flag = 1, i;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	len = *list;
	for (i = 0; len->next != NULL; i++)
		len = len->next;
	if (i < 2)
		return;
	order = *list;

	while (flag == 1)
	{
		flag = 0;
		while (order->next != NULL)
		{
			if (order->n > order->next->n)
			{
				swap(list, order);
				print_list(*list);
				flag = 1;
				order = order->prev;
			}
			order = order->next;
		}

		while (order->prev != NULL)
		{
			if (order->prev->n > order->n)
			{
				swap_2(list, order);
				print_list(*list);
				flag = 1;
				order = order->next; }
			order = order->prev; }
	}
}
