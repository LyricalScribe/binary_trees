#include "binary_trees.h"

/**
 * binary_tree_leaves - calculates the leaves in a binary tree
 * @tree: pointer to the root node of the tree to calculate the number of leaves
 * Return: count of leaves in a tree else 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int count = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (count + 1);

	count += binary_tree_leaves(tree->left);
	count += binary_tree_leaves(tree->right);

	return (count);
}
