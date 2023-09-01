#include "binary_trees.h"

/**
 * array_to_avl - Constructs an AVL tree from an array.
 *
 * @array: Pointer to the first element of the array for conversion.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, jndex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (jndex = 0; jndex < index; jndex++)
		{
			if (array[jndex] == array[index])
				break;
		}
		if (jndex == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
