    #include "apc.h"

    void division(node *headL1, node *head_OPR2, node *tail_OPR2, node **headR, node **tailR)

    {
        node *head_OPR1 = NULL;
        node *tail_OPR1 = NULL;
        node *temp_L1 = headL1;
        int sub_count = 0;
        node *head_SR = NULL;
        node *tail_SR = NULL;

        insert_last(&head_OPR1, &tail_OPR1, temp_L1->data);

        while (compare_list(head_OPR1, head_OPR2) == OPERAND2)
        {
            temp_L1 = temp_L1->next;
            insert_last(&head_OPR1, &tail_OPR1, temp_L1->data);
        }

        while (temp_L1 != NULL)
        {
            sub_count = 0;
            while (compare_list(head_OPR1, head_OPR2) == OPERAND1 || compare_list(head_OPR1, head_OPR2) == SAME)
            {
                subtraction(tail_OPR1, tail_OPR2, &head_SR, &tail_SR);
                delete_list(&head_OPR1, &tail_OPR1);
                head_OPR1 = head_SR;
                tail_OPR1 = tail_SR;

                head_SR = tail_SR = NULL;
                sub_count++;
            }

            insert_last(headR, tailR, sub_count);
            temp_L1 = temp_L1->next;
            if (temp_L1 != NULL)
            {
                insert_last(&head_OPR1, &tail_OPR1, temp_L1->data);
            }
            remove_pre_zeros(&head_OPR1);
        }
    }
