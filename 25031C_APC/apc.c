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

void remove_pre_zeros(node **head)
{
    node *temp = *head;
    while (temp->data == 0 && temp->next != NULL)
    {
        node *del = temp;
        temp = temp->next;
        temp->prev = NULL;
        free(del);
    }

    *head = temp;
}

int compare_list(node *head1, node *head2)
{

    int list1_len = list_len(head1);
    int list2_len = list_len(head2);
    if (list1_len > list2_len)
    {
        return OPERAND1;
    }
    else if (list2_len > list1_len)
    {
        return OPERAND2;
    }
    else
    {
        node *temp1 = head1;
        node *temp2 = head2;
        while (temp1 != NULL)
        {
            if (temp1->data > temp2->data)
                return OPERAND1;
            else if (temp1->data < temp2->data)
                return OPERAND2;
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return SAME;
    }
}

int list_len(node *head)
{

    int count = 0;
    node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}