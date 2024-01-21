#include "sort.h"
#include <stdlib.h>

int find_largest(int *arr, int n);
void radix_sort(int *arr, size_t n);
void LSD_radix_sort_step(int *arr, size_t n, int exp, int *buffer);

/**
 * find_largest - Find the largest element in an array of integers.
 * @arr: An array of integers.
 * @n: The size of the array.
 *
 * Return: The largest integer in the array.
 */
int find_largest(int *arr, int n)
{
	int largest = arr[0], i;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > largest)
			largest = arr[i];
	}

	return (largest);
}

/**
 * LSD_radix_sort_step - Perform one step of LSD radix sort on the array.
 * @arr: An array of integers.
 * @n: The size of the array.
 * @exp: The current exponent for the significant digit.
 * @buffer: A buffer to store the sorted array.
 */
void LSD_radix_sort_step(int *arr, size_t n, int exp, int *buffer)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10] += 1;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; (int)i >= 0; i--)
	{
		buffer[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10] -= 1;
	}

	for (i = 0; i < n; i++)
		arr[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *                  order using the LSD radix sort algorithm.
 * @array: An array of integers.
 * @n: The size of the array.
 */
void radix_sort(int *array, size_t n)
{
	int max, exp, *buffer;

	if (array == NULL || n < 2)
		return;

	buffer = malloc(sizeof(int) * n);
	if (buffer == NULL)
		return;

	max = find_largest(array, n);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		LSD_radix_sort_step(array, n, exp, buffer);
		print_array(array, n);
	}

	free(buffer);
}
