#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	size_t i, j, aux = 0;
	size_t cont = 0, end = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - end; j++)
		{
			if (array[j - 1] > array[j])
			{
				aux = array[j];
				array[j] = array[j - 1];
				array[j - 1] = aux;
				cont = 0;
				print_array(array, size);
			}
			else
				cont++;
		}
		end += cont;
		cont = 0;
	}
}
