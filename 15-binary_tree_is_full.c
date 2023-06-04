#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a tree has complete nodes
 * @tree: pointer to the root tree
 * @func: pointer to the function 
 * Return: 1 if full and 0 if not full 
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
