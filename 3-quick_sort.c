#include "sort.h"
#include <stdio.h>

void swap(int *array, unsigned long index_1, unsigned long index_2);
void sort(int *array, size_t size, int *array_main, size_t size_main);

/**
 * quick_sort - implementaion of quick sort algorith in cv
 * @array: pointer to integer array
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	sort(array, size, array, size);
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
 * sort - implementaion of quick sort algorith in cv
 * @array: pointer to partition integer array
 * @size: size of partition array
 * @array_main: pointer to main integer array
 * @size_main: size of main array
 *
 * Return: void
 */
void sort(int *array, size_t size, int *array_main, size_t size_main)
{
	/* Define p_index, i_index and pivot */
	int p_index, i_index, pivot;

	p_index = i_index = 0;
	pivot = size - 1;

	if (!array || size < 2)
		return;

	/* Iterate over partition and compare p_index and c to pivot */

	for (p_index = 0; p_index <= pivot; p_index++)
	{
		i_index = p_index;

		if (p_index == pivot)
		{
			sort(array, size - 1, array_main, size_main);
			return;
		}

		if (array[p_index] > array[pivot])
		{
			for (; i_index <= pivot; i_index++)
			{

				/* Partition */
				if (i_index == pivot)
				{
					swap(array, p_index, pivot);
					print_array(array_main, size_main);

					/*
					 * Sort right side of partition if
					 * right side is not out of range
					 */
					if (p_index + 1 < (int)size)
						sort(&array[p_index + 1], size - 1 - p_index, array_main, size_main);

					/*
					 * Sort left side of partition if
					 * left side isn't out of range
					 */
					if (p_index != 0)
						sort(&array[0], p_index, array_main, size_main);
				}
				else if (array[i_index] < array[pivot])
				{
					swap(array, p_index, i_index);
					print_array(array_main, size_main);
					break;
				}
			}
		}
	}
}
