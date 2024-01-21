#include "sort.h"

void swap(int *x, int *y);
int partition_sort(int *arr, size_t size, int left, int right);
void recursive_sort(int *arr, size_t size, int left, int right);
void quick_sort_hoare(int *arr, size_t size);

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
 * partition_sort - Order a subset of an array of integers
 *                       using the Hoare partition scheme.
 * @arr: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int partition_sort(int *arr, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = arr[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (arr[above] < pivot);
		do {
			below--;
		} while (arr[below] > pivot);

		if (above < below)
		{
			swap(arr + above, arr + below);
			print_array(arr, size);
		}
	}

	return (above);
}

/**
 * recursive_sort - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void recursive_sort(int *arr, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = partition_sort(arr, size, left, right);
		recursive_sort(arr, size, left, partition - 1);
		recursive_sort(arr, size, partition, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                   order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_sort(array, size, 0, size - 1);
}
