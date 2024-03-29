#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
	/*
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
	*/

	add_nodeint_end(&head, 30);
	add_nodeint_end(&head, 31);
	add_nodeint_end(&head, 32);
    print_listint(head);

    printf("-----------------\n");

    insert_node(&head, 27);
    insert_node(&head, 29);
    insert_node(&head, 33);

    print_listint(head);

    free_listint(head);

    return (0);
}
