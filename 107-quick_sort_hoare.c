#include "sort.h"

void quick_aux_hoare(int *array, size_t size, size_t low, size_t high);

/**
 * quick_sort_hoare - sorts an array list of integers in ascending
 * order using the quick_sort hoare algorithm
 * print the list after each
 *  time you swap two elements
 * @array: Array to be sorted
 * @size: Size of Array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size > 1)
		quick_aux_hoare(array, size, 0, size - 1);
}

/**
 * quick_aux_hoare - recursion function in quick sort hoare
 * @array: Array to be sorted
 * @size: Size of Array
 * @low: inferior limit of array
 * @high: Superior limit of array
 */
void quick_aux_hoare(int *array, size_t size, size_t low, size_t high)
{
	long int l = low - 1;
	long int r = high + 1;
	size_t aux;
	int current = array[high];

	if (low >= high)
		return;

	while (l < r)
	{
		l++;
		while (array[l] < current)
			l++;
		r--;
		while (array[r] > current)
			r--;

		if (l < r)
		{
			aux = array[l];
			array[l] = array[r];
			array[r] = aux;
			print_array(array, size);
		}
	}

	if (r - 1 >= 0)
		quick_aux_hoare(array, size, low, l - 1);
	quick_aux_hoare(array, size, l, high);
}
