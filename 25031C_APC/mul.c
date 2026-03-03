#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1;
    node *temp2 = tail2;

    node *headAR = NULL;
    node *tailAR = NULL;

    node *headR2 = NULL;
    node *tailR2 = NULL;

    int count = 0, carry = 0, flag = 0;

    while (temp2 != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            insert_first(&headR2, &tailR2, 0);
        }

        while (temp1 != NULL)
        {
            int mul = temp1->data * temp2->data + carry;
            int val = mul % 10;
            carry = mul / 10;
            if (!flag)
                insert_first(headR, tailR, val);
            else
                insert_first(&headR2, &tailR2, val);

            temp1 = temp1->prev;
        }
        flag = 1;
        if (*headR != NULL && headR2 != NULL)
        {
            addition(*tailR, tailR2, &headAR, &tailAR);
            delete_list(headR, tailR);
            delete_list(&headR2, &tailR2);
            *headR = headAR;
            *tailR = tailAR;

            headAR = tailAR = NULL;
        }

        temp2 = temp2->prev;
        temp1 = tail1;
        count++;
    }

    if (carry == 1)
    {
        insert_first(headR, tailR, 1);
    }
}
