#include "sort.h"
#include <stddef.h>

void swap(int *array, unsigned long index_1, unsigned long index_2);

/**
 * bubble_sort - c implementation of bubble sort algorithm
 * @array: pointer to array of integers
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long i;
	unsigned long j;
	int sorted;

	/* Null array parameter */
	if (!array)
		return;

	/* Array contains one or no elements */
	if (size < 2)
		return;

	/* Implement bubble sort */
	for (i = 1; i < size; i++)
	{
		sorted = 1;

		for (j = 0; j < size - i; j++)
		{
			/* Swap array memeber */
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				sorted = 0;

				/* Print array after swap */
				print_array(array, size);
			}
		}

		if (sorted)
			return;
	}
}

/**
 * swap - swaps the elements in an array
 * @index_1: index of first element
 * @index_2: index of first second
 *
 * return: void
 */
void swap(int *array, unsigned long index_1, unsigned long index_2)
{
	int temp;

	temp = array[index_1];
	array[index_1] = array[index_2];
	array[index_2] = temp;
}
