#include "binary_trees.h"
/**
* binary_tree_insert_left - Inserts a new left-child node.
* @parent: Pointer to the parent node.
* @value: Value for the new node.
* Return: Pointer to the new node, or NULL if unsuccessful.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_left = binary_tree_node(parent, value);
	if (!new_left)
	{
		return (NULL);
	}

	if (parent->left)
	{
		new_left->left = parent->left;
		parent->left->parent = new_left;
	}

	parent->left = new_left;

	return (new_left);
}
