#include "sort.h"

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

/**
 * bitonic_merge - merge
 * @array: Array to be sorted
 * @low: lower limit of sub seccion in the array
 * @s: size of sub seccion in the array
 * @dir: direction 1 for up, 0 for down
 */
void bitonic_merge(int *array, size_t low, size_t s, int dir)
{
	size_t k, i;
	int aux;

	if (s < 2)
		return;

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

/**
 * bitonic_recursion - aux function to do recursion
 * @array: Array to be sorted
 * @size: Size of Array
 * @low: lower limit of sub seccion in the array
 * @s: size of sub seccion in the array
 * @dir: direction 1 for up, 0 for down
 */
void bitonic_recursion(int *array, size_t size, size_t low, size_t s, int dir)
{
	size_t cut = 0;

	if (s < 2)
		return;

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
