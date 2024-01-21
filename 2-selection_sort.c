#include "sort.h"


/**
 * selection_sort - implements the selection_sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int swap;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
			{
				index = j;
				continue;
			}
		}

		if (index != i)
		{
			swap = array[index];
			array[index] = array[i];
			array[i] = swap;

			print_array(array, size);
		}
	}
}

