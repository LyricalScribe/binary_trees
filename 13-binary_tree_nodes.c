#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with atleast one child
 * @tree: the tree to count
 * @func: pointer to the function 
 * Return: number of nodes
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
		node += ((tree->left != NULL || tree->right != NULL) ? 1 : 0);
		node += binary_tree_nodes(tree->left);
		node += binary_tree_nodes(tree->right);
		return (node);
	}
}
