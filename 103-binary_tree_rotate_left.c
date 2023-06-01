#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 *
 * Description: If tree is NULL or the tree has no right child, the function
 *              returns the original root node without performing any rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pivot = tree->right;
	tree->right = pivot->left;
	if (pivot->left != NULL)
	{
		pivot->left->parent = tree;
	}
	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}
