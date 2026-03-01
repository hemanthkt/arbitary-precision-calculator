#include "apc.h"

// Function definitions

// function to insert nodes to the last
int insert_last(node **head, node **tail, int data)
{

    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    return SUCCESS;
}

// function to insert the elements to the first
int insert_first(node **head, node **tail, int data)
{

    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    new->next = *head;
    (*head)->prev = new;
    *head = new;
    return SUCCESS;
}

void print_list(node *head)
{
    while (head)
    {
        /* code */
        printf("%d", head->data);
        head = head->next;
    }
}