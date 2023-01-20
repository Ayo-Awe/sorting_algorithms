#include "sort.h"
#include <stdio.h>

void swap(listint_t **list, listint_t *node_1, listint_t *node_2);

/**
 * insertion_sort_list - sorts a lists using insertion sort algorithm
 * @list: doubly linked list head
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *next = NULL;
	listint_t *tmp = NULL;

	/* Check for null pointer and empty list */
	if (!list || *list == NULL)
		return;

	/* Check for list with less than 2 elements i.e 1 element */
	if ((*list)->next == NULL)
		return;

	/* Insertion sort implementation */

	/* Set initial node */
	current = *list;

	/* Loop through each element in the list */
	while (current)
	{
		/* First element */
		if (current->prev == NULL)
		{
			current = current->next;
			continue;
		}

		tmp = current->prev;
		next = current->next;

		while (tmp)
		{

			if (tmp->n < current->n || tmp->n == current->n)
				break;

			swap(list, tmp, current);
			print_list(*list);

			tmp = current->prev;
		}

		current = next;
	}
}

/**
 * swap - swaps two nodes
 * @list: pointer to doubly linked list head
 * @left_node: pointer to node to swap
 * @right_node: pointer to node to swap
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *left_node, listint_t *right_node)
{
	listint_t *left_prev = NULL;
	listint_t *right_next = NULL;

	left_prev = left_node->prev;
	right_next = right_node->next;

	/* If left_node is head of list, make right_node new head of list*/
	if (!left_prev)
		*list = right_node;

	if (left_prev)
		left_prev->next = right_node;

	if (right_next)
		right_next->prev = left_node;

	left_node->prev = right_node;
	right_node->next = left_node;

	left_node->next = right_next;
	right_node->prev = left_prev;
}
