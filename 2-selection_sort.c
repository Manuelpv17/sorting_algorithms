#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t aux = 0, m_i = 0;

	for (i = 0; i < size; i++)
	{
		m_i = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j] && array[m_i] > array[j])
				m_i = j;
		}
		if (m_i != i)
		{
			aux = array[i];
			array[i] = array[m_i];
			array[m_i] = aux;
			print_array(array, size);
		}
	}
}
