#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    // Temporary pointers to traverse both lists
    node *temp1 = tail1;
    node *temp2 = tail2;

    // Variable to store carry generated during addition

    int carry = 0;

    // Loop until both lists are fully traversed
    while (temp1 != NULL || temp2 != NULL)
    {
        // Variables to store digits from each list
        int digit1 = 0;
        int digit2 = 0;

        // Get digit from first list if available, else use 0
        if (temp1 == NULL)
        {
            digit1 = 0;
        }
        else
        {

            digit1 = temp1->data;
        }

        // Get digit from second list if available, else use 0
        if (temp2 == NULL)
        {
            digit2 = 0;
        }
        else
        {

            digit2 = temp2->data;
        }

        // Calculate sum of digits and carry
        int sum = digit1 + digit2 + carry;
        // Extract result digit
        int val = sum % 10;
        // Update carry
        carry = sum / 10;
        // Insert result digit at beginning of result list
        insert_first(headR, tailR, val);
        // Move to previous node in first list
        if (temp1 == NULL)
        {
            temp1 = NULL;
        }
        else
        {

            temp1 = temp1->prev;
        }
        // Move to previous node in second list
        if (temp2 == NULL)
        {
            temp2 = NULL;
        }
        else
        {

            temp2 = temp2->prev;
        }
    }

    if (carry)
    {
        insert_first(headR, tailR, carry);
    }

    return;
}
