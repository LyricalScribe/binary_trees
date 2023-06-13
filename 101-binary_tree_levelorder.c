#include "binary_trees.h"
#include <stdlib.h>

/**
 * linked_t - Structure for linked list node
 * @n: level of the node
 * @node: binary tree node
 * @next: pointer to next node
 */
typedef struct linked_t
{
	size_t n;
	const binary_tree_t *node;
	struct linked_t *next;
} linked_t;

/**
 * linked_node - creates a linked list node
 * @head: double pointer to the head of the linked list
 * @tree: node to store
 * @level: depth of node to store
 */
void linked_node(linked_t **head, const binary_tree_t *tree, size_t level)
{
	linked_t *new, *aux;

	new = malloc(sizeof(linked_t));
	if (new == NULL)
		return;

	new->n = level;
	new->node = tree;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return;
	}

	aux = *head;
	while (aux->next != NULL)
		aux = aux->next;

	aux->next = new;
}

/**
 * recursion - goes through the complete tree, each stores and each node
 * @head: double pointer to the head of the linked list
 * @tree: node to check
 */
void recursion(linked_t **head, const binary_tree_t *tree)
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
 * binary_tree_levelorder - prints node element in a level-order
 * @tree: root node
 * @func: function to use
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	linked_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
	head = NULL;
	recursion(&head, tree);

	while (count <= height)
	{
		aux = head;
		while (aux != NULL)
		{
			if (count == aux->n)
				func(aux->node->n);
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

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: binary tree to go through
 * Return: The height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_depth - depth of specified node
 * @tree: node to check the depth
 * Return: 0 if root or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
