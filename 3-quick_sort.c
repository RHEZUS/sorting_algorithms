#include "sort.h"

void swap(int *a, int *b);

int partition(int *array, size_t size, int low, int high);
void handle_quick_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

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
 * partition - Partitions a subset of an integer array using the Lomuto scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The low index of the subset to partition.
 * @high: The high index of the subset to partition.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot = array + high;
	int i, j;

	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * handle_quick_sort - Implements the quicksort algorithm using recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The low index of the array partition to sort.
 * @high: The high index of the array partition to sort.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void handle_quick_sort(int *array, size_t size, int low, int high)
{
	int partition_index;

	if (high - low > 0)
	{
		partition_index = partition(array, size, low, high);
		handle_quick_sort(array, size, low, partition_index - 1);
		handle_quick_sort(array, size, partition_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 * Prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	handle_quick_sort(array, size, 0, size - 1);
}

