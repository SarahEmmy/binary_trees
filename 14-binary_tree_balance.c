#include "binary_trees.h"
/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: Height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (tree == NULL)
	{
		return (0);
	}

	h_left = binary_tree_height(tree->left);
	h_right = binary_tree_height(tree->right);

	if (h_left > h_right)
	{
		return (h_left + 1);
	}

	else
	{
		return (h_right + 1);
	}
}
/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 * Return: Balance factor of the binary tree.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
