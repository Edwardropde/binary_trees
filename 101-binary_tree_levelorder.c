#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates new levelorder_queue_t node
 * @node: Binary tree node for the new node to contain
 * Return: Pointer to new node or NULL if error occurs
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{

	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);
	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_queue - Frees levelorder_queue_t queue.
 * @head: Pointer to head of queue
 */

void free_queue(levelorder_queue_t *head)
{

	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pint_push - Runs function of specific binary tree node and pushes
 * children to levelorder queue
 * @node: Binary tree node to print and push.
 * @head: Double pointer to head of queue
 * @tail: Double pointer to tail of queue
 * @func: Pointer to function to call on node
 */

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{

	levelorder_queue_t *n;

	func(node->n);
	if (node->left != NULL)
	{
		n = create_node(node->left);
		if (n == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = n;
		*tail = n;
	}
	if (node->right != NULL)
	{
		n = create_node(node->right);
		if (n == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = n;
		*tail = n;
	}
}

/**
 * pop - Pops head of queue
 * @head: Double pointer to head of queue
 */

void pop(levelorder_queue_t **head)
{

	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Traverses binary tree using level-order traversal
 * @tree: Pointer of root node of tree to traverse
 * @func: Pointer to function to call for every node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	levelorder_queue_t *top, *bottom;

	if (tree == NULL || func == NULL)
		return;
	top = bottom = create_node((binary_tree_t *)tree);
	if (top == NULL)
		return;
	while (top != NULL)
	{
		pint_push(top->node, top, &bottom, func);
		pop(&top);
	}
}
