#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates new levelorder_queue_t node.
 * @node: Binary tree node for new node to contain.
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
 * @head: Pointer to head of queue.
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
 * push - Pushes node to back of levelorder_queue_t queue.
 * @node: Binary tree node to print and push.
 * @head: Double pointer to head of queue.
 * @tail: Double pointer to  tail of  queue.
 * Description: Upon malloc failure, exits with a status code of 1.
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{

	levelorder_queue_t *n;

	n = create_node(node);
	if (n == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = n;
	*tail = n;
}

/**
 * pop - Pops head of levelorder_queue_t queue.
 * @head: Double pointer to head of queue.
 */

void pop(levelorder_queue_t **head)
{

	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_is_complete - Checks if binary tree is complete.
 * @tree: Pointer to root node of  tree to traverse.
 * Return: 1 if tree is complete NULL or not complete, return 0.
 * Description: Upon malloc failure, exits with a status code of 1.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{

	levelorder_queue_t *h, *t;
	unsigned char f = 0;

	if (tree == NULL)
		return (0);
	h = t = create_node((binary_tree_t *)tree);
	if (h == NULL)
		exit(1);
	while (h != NULL)
	{
		if (h->node->left != NULL)
		{
			if (f == 1)
			{
				free_queue(h);
				return (0);
			}
			push(h->node->left, h, &t);
		}
		else
			f = 1;
		if (h->node->right != NULL)
		{
			if (f == 1)
			{
				free_queue(h);
				return (0);
			}
			push(h->node->right, h, &t);
		}
		else
			f = 1;
		pop(&h);
	}
	return (1);
}
