#include "sort.h"

/**
 * bubble_sort - implements the bubble algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swap;
	int flag = 1;

	while (flag == 1)
	{
		flag = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				print_array(array, size);
				flag = 1;
			}
		}
	}
}

