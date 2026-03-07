#include "apc.h"

int main(int argc, char *argv[])
{
	node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

	int postive_flag1 = 0;
	int negative_flag1 = 0;

	int postive_flag2 = 0;
	int negative_flag2 = 0;

	// Validation
	if (argc != 4)
	{
		return FAILURE;
	}

	if (!isdigit(argv[1][0]))
	{
		if ((argv[1][0]) == '+')
			postive_flag1 = 1;
		if ((argv[1][0]) == '-')
			negative_flag1 = 1;
	}

	if (!isdigit(argv[3][0]))
	{
		if ((argv[3][0]) == '+')
			postive_flag2 = 1;
		if ((argv[3][0]) == '-')
			negative_flag2 = 1;
	}

	for (int i = (postive_flag1 || negative_flag1); argv[1][i] != '\0'; i++)
	{

		if (!(isdigit(argv[1][i])))
		{
			printf(":( Operand 1 has non numberic values\n");
			return FAILURE;
		}
	}

	for (int j = (postive_flag2 || negative_flag2); argv[3][j] != '\0'; j++)
	{
		if (!(isdigit(argv[3][j])))
		{
			printf(":( Operand 2 has non numberic values\n");
			return FAILURE;
		}
	}

	// Create 2 lists of operands
	int len1 = strlen(argv[1]);
	int len2 = strlen(argv[3]);

	// inserting node one by one
	for (int i = (postive_flag1 || negative_flag1); i < len1; i++)
	{
		int digit = argv[1][i] - '0';
		insert_last(&head1, &tail1, digit);
	}

	for (int i = (postive_flag2 || negative_flag2); i < len2; i++)
	{
		int digit = argv[3][i] - '0';
		insert_last(&head2, &tail2, digit);
	}

	// Remove pre zeros

	remove_pre_zeros(&head1);
	remove_pre_zeros(&head2);

	char oper = argv[2][0];

	switch (oper)
	{
	case '+':
	{
		/* +A + +B */
		if (!negative_flag1 && !negative_flag2)
		{
			addition(tail1, tail2, &headR, &tailR);
			print_list(headR);
		}

		/* -A + -B = -(A + B) */
		else if (negative_flag1 && negative_flag2)
		{
			printf("-");
			addition(tail1, tail2, &headR, &tailR);
			print_list(headR);
		}

		/* +A + -B = A - B */
		else if (!negative_flag1 && negative_flag2)
		{
			if (compare_list(head1, head2) == OPERAND1)
			{
				subtraction(tail1, tail2, &headR, &tailR);
			}
			else if (compare_list(head1, head2) == OPERAND2)
			{
				subtraction(tail2, tail1, &headR, &tailR);
				printf("-");
			}
			else
			{
				printf("0\n");
				return SUCCESS;
			}

			print_list(headR);
		}

		/* -A + B = B - A */
		else if (negative_flag1 && !negative_flag2)
		{
			if (compare_list(head2, head1) == OPERAND1)
			{
				subtraction(tail2, tail1, &headR, &tailR);
			}
			else if (compare_list(head2, head1) == OPERAND2)
			{
				subtraction(tail1, tail2, &headR, &tailR);
				printf("-");
			}
			else
			{
				printf("0\n");
				return SUCCESS;
			}

			print_list(headR);
		}

		break;
	}

	case '-':
	{
		/* +A - +B */
		if (!negative_flag1 && !negative_flag2)
		{
			if (compare_list(head1, head2) == OPERAND1)
			{
				subtraction(tail1, tail2, &headR, &tailR);
			}
			else if (compare_list(head1, head2) == OPERAND2)
			{
				subtraction(tail2, tail1, &headR, &tailR);
				printf("-");
			}
			else
			{
				printf("0\n");
				return SUCCESS;
			}
		}

		/* -A - -B  ->  B - A */
		else if (negative_flag1 && negative_flag2)
		{
			if (compare_list(head2, head1) == OPERAND1)
			{
				subtraction(tail2, tail1, &headR, &tailR);
			}
			else if (compare_list(head2, head1) == OPERAND2)
			{
				subtraction(tail1, tail2, &headR, &tailR);
				printf("-");
			}
			else
			{
				printf("0\n");
				return SUCCESS;
			}
		}

		/* +A - -B  ->  A + B */
		else if (!negative_flag1 && negative_flag2)
		{
			addition(tail1, tail2, &headR, &tailR);
		}

		/* -A - +B  ->  -(A + B) */
		else if (negative_flag1 && !negative_flag2)
		{
			printf("-");
			addition(tail1, tail2, &headR, &tailR);
		}

		print_list(headR);
		break;
	}

	case 'x':
	case 'X':
		if ((negative_flag1 && !negative_flag2) || (!negative_flag1 && negative_flag2))
		{
			printf("-");
		}
		multiplication(tail1, tail2, &headR, &tailR);
		print_list(headR);
		break;

	case '/':
		if ((negative_flag1 && !negative_flag2) || (!negative_flag1 && negative_flag2))
		{
			printf("-");
		}

		division(head1, head2, tail2, &headR, &tailR);
		print_list(headR);
		division(head1, head2, tail2, &headR, &tailR);
		print_list(headR);
		break;

	default:
		printf("Invalid operator\n");
	}
}
