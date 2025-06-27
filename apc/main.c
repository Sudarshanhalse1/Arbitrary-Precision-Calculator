#include "apc.h"
extern int flag;
int main(int argc, char* argv[])
{
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL, *tailR=NULL;
	Dlist* headR2= NULL, *tailR2 = NULL;

	//Validation
	if(digit_to_list(&head1,&tail1,&head2,&tail2,argv, argc)==FAILURE)
		return FAILURE;
	char operator=argv[2][0];
		switch (operator)
		{
			case '+':
                                
				/* call the function to perform the addition operation */
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				print_data(head1);
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				print_data(headR);
				break;
			case 'X':	
				/* call the function to perform the multiplication operation */
				multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR, &headR2, &tailR2);
				print_data(headR);
				break;
			case '/':
				division(&head1, &tail1, &head2, &tail2, &headR, &tailR);	
				/* call the function to perform the division operation */
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
	return 0;
}
void print_data(Dlist* temp)
{
	printf("\nResult is = ");
	if(flag == 1)
		putchar('-');
	while(temp!= NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	putchar('\n');
}
