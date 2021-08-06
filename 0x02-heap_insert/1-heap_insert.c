#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * swap_node - Swap nodes.
 *
 * @node: Pointer to the root of the tree
 * @value: New value to insert in the tree
 * @side: Number to validate if left or right side
 *
 * Return: pointer to the node swaped, or NULL on failure
 */
heap_t *swap_node(heap_t *node, int value, int side)
{
	heap_t *tmp = NULL;

	tmp = node->parent;
	if (node->parent->n <= node->n)
	{
		if (side == 0)
		{
			node->parent = tmp->parent;
			tmp->parent->left = node;
			tmp->left = NULL;
			tmp->parent = node;
			node->left = tmp;
		}
		else
		{
			node->parent = tmp->parent;
			tmp->parent->right = node;
			tmp->right = NULL;
			tmp->parent = node;
			node->right = tmp;
		}
		swap_node(node, value, side);
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Pointer to the root of the tree
 * @value: New value to insert in the tree
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *new_node = NULL, *inserted_node = NULL;

	heap_t *head = *root;

	if (root == NULL)
		return (NULL);

	if (head == NULL)
	{
		new_node = binary_tree_node(head, value);
		*root = new_node;
		return (*root);
	}
	if (head->left != NULL && head->right != NULL)
	{
		heap_insert(&head->left, value);
	}
	else if (head->left != NULL)
	{
		new_node = binary_tree_node(head->right, value);
		inserted_node = swap_node(new_node, value, 1);
	}
	else
	{
		new_node = binary_tree_node(head->left, value);
		inserted_node = swap_node(new_node, value, 1);
	}
	return (inserted_node);
}
