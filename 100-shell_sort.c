#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	size_t aux = 0;

	while (gap < size)
		gap = gap * 3 + 1;
	gap = gap / 3;

	while (gap != 0)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j; i >= gap; i = i - gap)
			{
				if (array[i] < array[i - gap])
				{
					aux = array[i];
					array[i] = array[i - gap];
					array[i - gap] = aux;
				}
			}
		}
		print_array(array, size);
		gap = gap / 3;
	}
}