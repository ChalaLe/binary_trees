#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: The number of nodes with at least 1 child in the tree,
 *         or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  node = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		node += ((tree->left || tree->right) ? 1 : 0);
		node += binary_tree_nodes(tree->left);
		node += binary_tree_nodes(tree->right);
		return (node);
	}
}
