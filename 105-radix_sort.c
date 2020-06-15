#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 *  using the LSD Radix sort algorithm
 * @array: Array to be sorted
 * @size: Size of Array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	long int e, max;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (e = 1; max / e > 0; e = e * 10)
	{
		counting_sort_radix(array, size, e);
		print_array(array, size);
	}
}

/**
 * counting_sort_radix - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * print your counting array once it is set up
 * @array: Array to be sorted
 * @size: Size of Array
 * @e: 10^n n=0,1..., number of digits of max number
 */
void counting_sort_radix(int *array, size_t size, long int e)
{
	size_t i;
	long int j, k = 0;
	int *count = NULL, *aux = NULL;

	aux = malloc(sizeof(int) * size);
	if (aux == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		aux[i] = array[i];
		if (array[i] > k)
			k = array[i];
	}
	k = k + 1;

	count = malloc(sizeof(int) * k);
	if (count == NULL)
	{
		free(aux);
		return;
	}
	for (i = 0; i < size; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / e) % 10]++;

	for (j = 1; j < k; j++)
		count[j] += count[j - 1];

	for (j = size - 1; j >= 0; j--)
	{
		array[count[(aux[j] / e) % 10] - 1] = aux[j];
		count[(aux[j] / e) % 10]--;
	}

	free(count);
	free(aux);
}
