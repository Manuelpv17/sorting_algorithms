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

	if (size > 1)
		quick_aux(array, size, 0, size - 1);
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
	size_t j, i = low;
	size_t aux;

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

	if (high > i + 1)
		quick_aux(array, size, i + 1, high);
	if (i > low + 1)
		quick_aux(array, size, low, i - 1);
}
