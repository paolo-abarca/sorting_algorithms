#include "sort.h"

/**
 * shell_sort - function shellsort algorimth
 *
 * @array: is the array of numbers
 * @size: is the size of array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t n = 1;
	size_t gap;
	size_t i;
	size_t j;
	int temp;

	while (n < size)
		n = (n * 3) + 1;

	gap = (n - 1) / 3;

	for ( ; gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
