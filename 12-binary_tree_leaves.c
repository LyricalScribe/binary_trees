#include "binary_trees.h"

/**
 * binary_tree_leaves - calculates the leaves in a binary tree
 * @tree: pointer to the root node of the tree to 
 * calculate the number of leaves
 * @func: pointer to the function 
 * Return: number of leaves in a tree else 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	size_t left_leaves = binary_tree_leaves(tree->left);
	size_t right_leaves = binary_tree_leaves(tree->right);

	return (left_leaves + right_leaves);
}
