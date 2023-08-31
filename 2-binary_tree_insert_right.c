#include "binary_trees.h"
/**
 * binary_tree_insert_right - Inserts a new right-child node.
 * @parent: Pointer to the parent node.
 * @value: Value for the new node.
 * Return: Pointer to the new node, or NULL if unsuccessful.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_right = binary_tree_node(parent, value);
	if (!new_right)
	{
		return (NULL);
	}

	if (parent->right)
	{
		new_right->right = parent->right;
		parent->right->parent = new_right;
	}

	parent->right = new_right;

	return (new_right);
}
