#include "sort.h"

/**
 * counting_sort - 
 * 
 * 
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j;
	int k;
	int *p = NULL;
	int aux[size];

	k = 0;
	for (i = 0; i < size; i++)
	{
		aux[i] = array[i];
		if (array[i] > k)
			k = array[i];
	}
	k = k + 1;
	p = malloc(sizeof(int) * k);
	if (p == NULL)
		return;

	for (i = 0; i < size; i++)
		p[array[i]]++;

	for (j = 1; j < k; j++)
		p[j] += p[j - 1];
	print_array(p, k);

	for (i = 0; i < size; i++)
		array[p[aux[i]] - 1] = aux[i];

	free(p);
}
