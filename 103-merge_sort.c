#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the top-down Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of Array
 */
void merge_sort(int *array, size_t size)
{
	int *copy = NULL;
	size_t i;

	if (size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	top_down_merge(array, copy, 0, size);

	free(copy);
}

/**
 * top_down_merge - recursion top down
 * @array: Array to be sorted
 * @copy: copy of array
 * @low: inferior limit
 * @high: superior limit
 */
void top_down_merge(int *array, int *copy, size_t low, size_t high)
{
	size_t middle, i, j, k;

	if (high - low < 2)
		return;

	middle = (high + low) / 2;

	top_down_merge(array, copy, low, middle);
	top_down_merge(array, copy, middle, high);

	j = middle;
	k = low;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&array[low], middle - low);
	printf("[right]: ");
	print_array(&array[middle], high - middle);
	for (i = low; i < high; i++)
	{
		if ((copy[j] <= copy[k] && j < high) || k >= middle)
		{
			array[i] = copy[j];
			j++;
		}
		else
		{
			array[i] = copy[k];
			k++;
		}
	}
	printf("[Done]: ");
	print_array(&array[low], high - low);
	for (i = low; i < high; i++)
		copy[i] = array[i];
}
