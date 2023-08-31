#include "binary_trees.h"

/**
 * scale - Auxillary function that measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: Height of the binary tree. Returns 0 if tree is NULL.
 */
int scale(const binary_tree_t *tree)
{
	int ll = 1;
	int lr = 1;

	if (tree == NULL)
	{
		return (-1);
	}
	ll += scale((*tree).left);
	lr += scale((*tree).right);
	if (lr > ll)
	{
		return (lr);
	}
	return (ll);
}

/**
 * print_level - Auxillary function for level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * @level: Actual level.
 */
void print_level(binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree != NULL)
	{
		if (level == 0)
		{
			func((*tree).n);
		}
		else
		{
			print_level((*tree).left, level - 1, func);
			print_level((*tree).right, level - 1, func);
		}
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level, height;

	if (tree != NULL && func != NULL)
	{
		height = scale(tree) + 1;
/*		printf("Level: %i\n", height);*/
		for (level = 0; level < height; level++)
		{
			print_level((binary_tree_t *)tree, level, func);
		}
	}
}
