#include "sort.h"

void swap(int *x, int *y);
void merge_bitonic_sequence(int *arr, size_t size,
size_t start, size_t seq, char direction);
void build_bitonic_sequence(int *arr, size_t size,
size_t start, size_t seq, char direction);
void bitonic_sort_algorithm(int *arr, size_t size);

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
 * merge_bitonic_sequence - Sort a bitonic
 * sequence within an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in the array to sort.
 * @seq: The size of the sequence to sort.
 * @direction: The direction to sort in.
 */
void merge_bitonic_sequence(int *arr, size_t size,
size_t start, size_t seq, char direction)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((direction == 0 && arr[i] > arr[i + jump]) ||
			(direction == 1 && arr[i] < arr[i + jump]))
				swap(arr + i, arr + i + jump);
		}
		merge_bitonic_sequence(arr, size, start, jump, direction);
		merge_bitonic_sequence(arr, size, start + jump, jump, direction);
	}
}

/**
 * build_bitonic_sequence - Convert an
 * array of integers into a bitonic sequence.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @direction: The direction to sort the bitonic sequence block in.
 */
void build_bitonic_sequence(int *arr, size_t size,
size_t start, size_t seq, char direction)
{
	size_t cut = seq / 2;
	char *str = (direction == 0) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(arr + start, seq);

		build_bitonic_sequence(arr, size, start, cut, 0);
		build_bitonic_sequence(arr, size, start + cut, cut, 1);
		merge_bitonic_sequence(arr, size, start, seq, direction);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(arr + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                          order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (i.e., size is equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	build_bitonic_sequence(array, size, 0, size, 0);
}
