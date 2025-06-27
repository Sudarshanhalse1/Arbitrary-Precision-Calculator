#include "apc.h"

//int lenght1, lenght2;

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) {
    unsigned long int count = 0;

    // checkinng the op2 should not be zero
    if (is_zero(*head2)) 
	{
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    // // if len of op1(dividend) is less than op2(divisor)
    // if (lenght1 < lenght2) 
	// {
    //     insert_data(headR, tailR, 0);
    //     print_data(*headR);
    //     return SUCCESS;
    // }
	int lenght1, lenght2;
    while (1) 
	{
        // calculating the lenghts
        lenght1 = calculate_length(*head1);
        lenght2 = calculate_length(*head2);

        // if len of op1(dividend) is less than op2(divisor)
        if (lenght1 < lenght2) 
			break;

        // if len of op1(dividend) is equal to op2(divisor)
        if (lenght1 == lenght2) 
		{
            Dlist *temp1 = *head1, *temp2 = *head2;
            int is_greater = 0;
            while (temp1 != NULL && temp2 != NULL) 
			{
                if (temp1->data > temp2->data) 
				{
                    is_greater = 1;
                    break;
                } else if (temp1->data < temp2->data) 
				{
                    is_greater = -1;
                    break;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if (is_greater == -1) /*If divisor is greate r than dividend then */
				break;
        }

        // Subtract divisor from dividend
        subtraction(head1, tail1, head2, tail2, headR, tailR);
        count++;

        // Check if subtraction result is valid
        // if (*headR == NULL) 
		// 	break;

        // Free old dividend and replace with result
        Dlist *temp = *head1;
        while (temp != NULL) 
		{
            Dlist *next = temp->next;
            free(temp);
            temp = next;
        }

        // Update dividend to the result of subtraction
        *head1 = *headR;
        *tail1 = *tailR;
        *headR = *tailR = NULL;
    }

    // Store the final count (quotient)
    // insert_data(headR, tailR, count);
    // print_data(*headR);
	printf("Result is %lu\n", count);
    return SUCCESS;

}
int calculate_length(Dlist *head) 
{
    int len = 0;
    while (head != NULL) 
	{
        len++;
        head = head->next;
    }
    return len;
}
// Function to check if the list represents the number 0
int is_zero(Dlist *head) 
{
    while (head) 
	{
        if (head->data != 0) 
            return 0; // The number is not zero
        head = head->next;
    }
    return 1; // The number is zero
}