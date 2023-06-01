#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: Pointer to the node containing the value,
 * or NULL if not found or tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		found = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		found = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (found);
}
