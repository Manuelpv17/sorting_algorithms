#include "sort.h"

/**
 * bitonic_merge - merge
 * @array: Array to be sorted
 * @size: Size of Array
 */
void bitonic_merge(int *array, size_t low, size_t s, int dir)
{
	size_t k, i;
	int aux;

	if (s > 1)
	{
		k = s / 2;
		for (i = low; i < low + k; i++)
		{
			if (dir == (array[i] > array[i + k]))
			{
				aux = array[i];
				array[i] = array[i + k];
				array[i + k] = aux;
			}
		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

void bitonic_recursion(int *array, size_t size, size_t low, size_t s, int dir)
{
	size_t cut = 0;

	if (s > 1)
	{
		if (dir == 1)
			printf("Merging [%ld/%ld] (UP):\n", s, size);
		else
			printf("Merging [%ld/%ld] (DOWN):\n", s, size);

		print_array(array + low, s);

		cut = s / 2;
		bitonic_recursion(array, size, low, cut, 1);
		bitonic_recursion(array, size, low + cut, cut, 0);

		bitonic_merge(array, low, s, dir);

		if (dir == 1)
			printf("Result [%ld/%ld] (UP):\n", s, size);
		else
			printf("Result [%ld/%ld] (DOWN):\n", s, size);
		print_array(array + low, s);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * size will be equal to 2^k, where k >= 0
 * @array: Array to be sorted
 * @size: Size of Array
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	bitonic_recursion(array, size, 0, size, 1);
}
