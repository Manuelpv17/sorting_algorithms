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
	long int l = low;
	long int r = high;
	size_t aux;
	int flag = 0;

	if (low >= high)
		return;

	while (l != r)
	{
		if (array[l] > array[r])
		{
			aux = array[l];
			array[l] = array[r];
			array[r] = aux;
			print_array(array, size);

			if (flag == 0)
				flag = 1;
			else
				flag = 0;
		}

		if (flag == 0)
			l++;
		else if (flag == 1)
			r--;
	}

	if (r - 1 > 0)
		quick_aux_hoare(array, size, low, r - 1);
	quick_aux_hoare(array, size, r + 1, high);
}
