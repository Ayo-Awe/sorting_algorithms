#include "sort.h"
#include <stdio.h>

int main(void)
{
	int test_array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	print_array(test_array, 10);
	printf("\n");

	bubble_sort(test_array, 10);

	return (0);
}
