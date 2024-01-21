#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: The function uses the Shell Sort algorithm to sort the array
 * in ascending order. It prints the array after each swap.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

		if (array == NULL || size < 2)
			return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
