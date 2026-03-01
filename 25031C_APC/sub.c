#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1;
    node *temp2 = tail2;
    int borrow_flag = 0;
    int digit1 = 0;
    int digit2 = 0;

    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 == NULL)
            digit1 = 0;
        else
            digit1 = temp1->data;

        if (temp2 == NULL)
            digit2 = 0;
        else
            digit2 = temp2->data;

        if (borrow_flag)
        {
            digit1 = digit1 - 1;
            borrow_flag = 0;
        }
        if (digit1 < digit2)
        {
            digit1 = digit1 + 10;
            borrow_flag = 1;
        }
        int val = digit1 - digit2;
        insert_first(headR, tailR, val);

        if (temp1 == NULL)
        {
            temp1 = NULL;
        }
        else
        {
            temp1 = temp1->prev;
        }

        if (temp2 == NULL)
        {
            temp2 = NULL;
        }
        else
        {
            temp2 = temp2->prev;
        }
    }
}
