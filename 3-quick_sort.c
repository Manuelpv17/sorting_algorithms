#include "sort.h"

/**
 * 
 */
void quick_sort(int *array, size_t size)
{
	size_t low = 0, hight = size - 1;

	if (low < hight)
		quick_aux(array, size, low, hight);
}

void quick_aux(int *array, size_t size, size_t low, size_t high)
{
	size_t i = low;
	size_t j = low;
	size_t aux = 0;

	if (low >= high)
		return;

	for (j = low; j < high; j++)
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
