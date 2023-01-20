#include "sort.h"
#include <stddef.h>

void swap(int *array, unsigned long index_1, unsigned long index_2);
int get_min(int *array, size_t size);

/**
 * selection_sort - c implementation of selection sort algorithm
 * @array: pointer to array of integers
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned long i;
	int min;

	/* Null array parameter */
	if (!array)
		return;

	/* Array contains one or no elements */
	if (size < 2)
		return;

	/* Implement selection sort */
	for (i = 0; i < size - 1; i++)
	{
		/* Get index of minimum value in subarray and calculate offsets */
		min = get_min((&array[i] + 1), size - i - 1) + i + 1;

		/* Swap array memebers */
		if (array[i] > array[min])
		{
			swap(array, i, min);
			/* Print array after swap */
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps the elements in an array
 * @index_1: index of first element
 * @array: pointer to array
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

/**
 * get_min - returns the index of the minimum value in
 * an array/subarray
 * @array: pointer to array
 * @size: size of array
 *
 * Return: index of minimum value in array
 */
int get_min(int *array, size_t size)
{
	int i;
	int min_index = 0;

	if (!array)
		return (-1);

	for (i = 0; i < (int)size; i++)
		if (array[i] < array[min_index])
			min_index = i;

	return (min_index);
}
