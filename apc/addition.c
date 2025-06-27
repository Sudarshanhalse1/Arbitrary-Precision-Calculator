#include "apc.h"
extern int flag;//, lenght1, lenght2;
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist* temp = *head1;
	int count1 = 0;
	int count2 = 0;
	while(temp!= NULL)
	{
		temp = temp->next;
		count1++;
	}
	temp = *head2;
	while(temp!= NULL)
	{
		temp = temp->next;
		count2++;
	}
	putchar('\n');
	if(count1<count2)
	{
		Dlist* temp = *head2;
		*head2 = *head1;
		*head1 = temp;
		temp = *tail2;
		*tail2 = *tail1;
		*tail1 = temp;
	}
	temp = *head1;
	Dlist* temp1 = *tail1;
	Dlist* temp2 = *tail2;
	int carry = 0, res;
	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp2 == NULL)
		{
			res = temp1->data + carry;
			if(res>9)
			{
				carry = 1;
				res = res%10;
			}
			else
			{
				carry = 0;
			}
			temp1->data = res;
			temp1 = temp1->prev;
			//continue;
			
		}
		else if(temp1 != NULL)
		{
			res = temp1->data + temp2->data + carry;
			if(res>9)
			{
				carry = 1;
				res = res%10;
			}
			else
				carry = 0;
			temp1->data = res;
			temp2 = temp2->prev;
			temp1 = temp1->prev; 
			
		}
	}
	if(carry)
	{
		insert_data(head1, tail1, carry);
	}
}

// validation + adding data to the list
int digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[], int argc)
{
	// checking number of arguments are exactly 4
	if(argc != 4)
	{
		puts("Syntax: ./a.out operand1 +-X/ operand2");
		return FAILURE;
	}
	if(strcmp(argv[2], "+")!=0 && strcmp(argv[2], "-")!=0 && strcmp(argv[2], "X")!=0 && strcmp(argv[2], "/")!=0)
	{
		puts("Syntax: ./a.out operand1 +-*/ operand2");
		return FAILURE;
	}
	int len;
	// checking only digit character present in the operand 1
	for(len=0; argv[1][len]>=48 && argv[1][len]<=57; len++);
	if(len != strlen(argv[1]))
	{
		puts("ERROR: operand must be Positive\n");
		return FAILURE;
	}
		
	int i;
	// checking only digit character present in the operand 3
	for(len=0; argv[3][len]>=48 && argv[3][len]<=57; len++);
	if(len != strlen(argv[3]))
	{
		puts("ERROR: operand must be Positive\n");
		return FAILURE;
	}
	if(strcmp(argv[2], "/")==0)
	{
		//lenght1 = strlen(argv[1]);
		//lenght2 = strlen(argv[3]);
		insert_list(head1, tail1, argv[1]);
		insert_list(head2, tail2, argv[3]);
		return SUCCESS;
	}
	if(strlen(argv[1]) > strlen(argv[3]))
	{
		insert_list(head1, tail1, argv[1]);
		insert_list(head2, tail2, argv[3]);
	}
	else if(strlen(argv[1]) < strlen(argv[3]))
	{
		
		flag = 1;
		insert_list(head1, tail1, argv[3]);
		insert_list(head2, tail2, argv[1]);
	}
	else
	{
		// checking both the numbers are same
		for(i=0; argv[1][i]; i++)
		{
			if(argv[1][i] > argv[3][i])
			{
				insert_list(head1, tail1, argv[1]);
				insert_list(head2, tail2, argv[3]);
				return SUCCESS;
			}
			else if(argv[1][i] < argv[3][i])
			{
				flag = 1;
				insert_list(head1, tail1, argv[3]);
				insert_list(head2, tail2, argv[1]);
				return SUCCESS;
			}
		}
	}
	if( i == strlen(argv[1]))
	{
		insert_list(head1, tail1, argv[1]);
		insert_list(head2, tail2, argv[3]);
	}
}

int insert_list(Dlist** head, Dlist **tail, char* argv)
{
	Dlist* new = malloc(sizeof(Dlist));
	if(new == NULL)
		return FAILURE;
	if(*head == NULL)
	{
		new->data = argv[0]-'0';
		new->prev = NULL;
		new->next = NULL;
		*head = *tail = new;
	}

	int len = strlen(argv);
	Dlist* temp = *head;
	for(int i=1; i<len; i++)
	{
		Dlist* new = malloc(sizeof(Dlist));
		if(new == NULL)
			return FAILURE;

		new->data = argv[i]-'0';
		new->prev = temp;
		new->next = NULL;
		temp->next = new;
		temp = temp->next;
	}
	*tail = temp;
	// printing for verification
	temp = *head;
	puts("list  is: ");
	while(temp!= NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	return SUCCESS;
}
int insert_data(Dlist** head, Dlist** tail, int data)
{
	Dlist* new = malloc(sizeof(Dlist));
	if(new == NULL)
		return FAILURE;
	new->data = data;
	new->next = NULL;
	new->prev = NULL;

	if(*head == NULL)
	{
		*head = *tail = new;
		return SUCCESS;
	}

	(*head)-> prev = new;
	new->next = *head;
	*head = new;
	return SUCCESS;
}
