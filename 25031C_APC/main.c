#include "apc.h"

int main(int argc, char *argv[])
{
	node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

	// Validation
	if (argc != 4)
	{
		return FAILURE;
	}

	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		if (!(isdigit(argv[1][i])))
		{
			printf(":( Operand 1 has non numberic values\n");
			return FAILURE;
		}
	}

	for (int i = 0; argv[3][i] != '\0'; i++)
	{
		if (!(isdigit(argv[3][i])))
		{
			printf(":( Operand 2 has non numberic values\n");
			return FAILURE;
		}
	}

	// Create 2 lists of operands
	int len1 = strlen(argv[1]);
	int len2 = strlen(argv[3]);

	// inserting node one by one
	for (int i = 0; i < len1; i++)
	{
		int digit = argv[1][i] - '0';
		insert_last(&head1, &tail1, digit);
	}

	for (int i = 0; i < len2; i++)
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
		addition(tail1, tail2, &headR, &tailR);
		print_list(headR);
		break;

	case '-':
		if (compare_list(head1, head2) == OPERAND1)
		{
			subtraction(tail1, tail2, &headR, &tailR);
			print_list(headR);
		}

		else if (compare_list(head1, head2) == OPERAND2)
		{

			subtraction(tail2, tail1, &headR, &tailR);
			printf("-");
			print_list(headR);
		}
		else
			printf("0\n");
		break;

	case 'x':
	case 'X':
		multiplication(tail1, tail2, &headR, &tailR);
		print_list(headR);
		break;

	case '/':
		break;

	default:
		printf("Invalid operator\n");
	}
}
