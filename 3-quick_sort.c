#include "sort.h"

/**
 * quick_sort - sorts an array list of integers in ascending
 * order using the quick_sort lomuto algorithm
 * print the list after each
 *  time you swap two elements
 * @array: Array to be sorted
 * @size: Size of Array
 */
void quick_sort(int *array, size_t size)
{
	size_t low = 0, high = size - 1;

	if (high > low)
		quick_aux(array, size, low, high);
}

/**
 * quick_aux - recursion function in quick sort lomuto
 * @array: Array to be sorted
 * @size: Size of Array
 * @low: inferior limit of array
 * @high: Superior limit of array
 */
void quick_aux(int *array, size_t size, size_t low, size_t high)
{
	size_t i = low;
	size_t j = low;
	size_t aux = 0;

	if (low >= high)
		return;

	for (j = low; j < high + 1; j++)
	{
		if (array[j] < array[high])
		{
			if (array[i] != array[j])
			{
				aux = array[j];
				array[j] = array[i];
				array[i] = aux;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		aux = array[high];
		array[high] = array[i];
		array[i] = aux;
		print_array(array, size);
	}

	quick_aux(array, size, i + 1, high);
	if (i != 0)
		quick_aux(array, size, low, i - 1);
}
