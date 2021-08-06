#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * swap_node - Swap nodes.
 *
 * @root: Pointer to the root of the tree
 * @value: New value to insert in the tree
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
	return node;
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
	// Check if the root node exists
	if (root == NULL)
		return (NULL);
	
	if (head == NULL) 
	{
		new_node = binary_tree_node(head, value);
		*root = new_node;
		return *root;
	}
	//check if the node has to children and move to the next depending
	if (head->left != NULL && head->right != NULL)
	{
		heap_insert(&head->left, value);
	}// insert the node in the right position, according complete binary tree concept
	else if (head->left != NULL)
	{
		new_node = binary_tree_node(head->right, value);
		//swap and return pointer to the inserted node
		inserted_node = swap_node(new_node, value, 1);
	}
	else
	{
		new_node = binary_tree_node(head->left, value);
		//swap and return pointer to the inserted node
		inserted_node = swap_node(new_node, value, 1);
	}
	return (inserted_node);

	// compare value with the parent node's value
	// If the the value is bigger than parent's value, swap nodes until the condition doesnt fit anymore
}