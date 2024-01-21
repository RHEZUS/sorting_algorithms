#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - A function that sorts an array of integers in ascending order
 * @array: array of the function
 * @size: size of the funtion
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t lud;
	int sorting = 0, big;

	if (!array || size < 2)
		return;

	while (sorting == 0)
	{
		sorting = 1;
		for (lud = 0; lud < size; lud++)
		{
			if (array[lud - 1] > array[lud])

			{
				sorting = 0;
				big = array[lud];
				array[lud] = array[lud - 1];
				array[lud - 1] = big;
				print_array(array, size);
			}
		}

	}
}

