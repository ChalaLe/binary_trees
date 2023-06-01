#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to go through
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((l > r) ? l : r);
	}
}
/**
 * binary_tree_depth - depth of specified node from root
 * @tree: Pointer to the root node of the tree to check the depth
 * Return: 0 is it is the root or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - this function makes a linked list from depth level and node
 * @head: pointer to head of linked list
 * @tree: Pointer to the root node of the tree to store
 * @level: depth of node to store
 * Return: Nothing
 */
void linked_node(nlink_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *aux;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return;
	}
	new->n = level;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		new->next = NULL;
		aux->next = new;
	}
}
/**
 * recursion - goes through the complete tree and each stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: Pointer to the root node of the tree
 * Return: Nothing by default it affects the pointer
 */
void recursion(nlink_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	nlink_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		_pow_recursion(&head, tree);
		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->n);
				}
				aux = aux->next;
			}
			count++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}
