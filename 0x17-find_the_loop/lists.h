#ifndef _LISTS_H_
#define _LISTS_H_

/* Header files */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* Structure */
/**
 * struct listint_s - singly linked list
 * 
 */
typedef struct listint_s
{
  int n;
  struct listint_s *next;
} listint_t;

/* Prototypes */
listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);

#endif /* _LISTS_H_ */
