#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * print your counting array once it is set up
 * @array: Array to be sorted
 * @size: Size of Array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j;
	int k;
	int *p = NULL;
	int *aux = NULL;

	if (size < 2)
		return;
	aux = malloc(sizeof(int) * size);
	if (aux == NULL)
		return;
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
	{
		free(aux);
		return;
	}

	for (i = 0; i < size; i++)
		p[array[i]]++;

	for (j = 1; j < k; j++)
		p[j] += p[j - 1];
	print_array(p, k);

	for (i = 0; i < size; i++)
		array[p[aux[i]] - 1] = aux[i];

	free(p);
	free(aux);
}
