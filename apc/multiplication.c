#include "apc.h"
 
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR, Dlist** headR2, Dlist**tailR2)
{
	/* Definition goes here */
	int count = 0;
	Dlist* temp2 = *tail2, *temp1;
	int result, carry = 0;
	while (temp2) // loop is running upto the temp2 will not reach the NULL
	{
		carry = 0;	
		temp1 = *tail1;
		while (temp1) // for each digit it will run untill the list one not reach to the NULL
		{
			result = temp1->data * temp2->data + carry; // finding the result
			carry = 0;
			 // making shore carry will be zero after using the carry variable 

			if(result>9) // generating the carry and result if result is more than the 1 digit
			{
				carry = result/10;
				result %=10;
			}
			if((count==0)) // when count is zero then only we are adding the result to R1
			{
				insert_data(headR, tailR, result); 
			}
			else 
			{
				insert_data(headR2, tailR2, result);
			}
			temp1 = temp1->prev; // increamenting list1
		}

		if (carry && (count == 0)) // only at first time need to add the data to the R1 list
		{
			insert_data(headR, tailR, carry);
		}
		else if(carry && (count>0)) // for every time adding data in list two
		{
			insert_data(headR2, tailR2, carry);
		}
		if(count>0)
			addition(headR, tailR, headR2, tailR2, headR, tailR); // calling the addition only when the 
		
		if(count>0) // clearing the result 2
		{
			temp1 = *tailR2;
			while(temp1->next != NULL)
			{
				temp1 = temp1->next;
				free(temp1->prev);
			}
			free(temp1);
			*headR2 = *tailR2 = NULL;
		}
		
		temp2 = temp2->prev; // incrementing the temp 2
		count++; // incrementing the count
		for(int i=0; i<count; i++) 
			insert_data(headR2, tailR2, 0);
	}
	// Dlist* temp = *head1;
	
}
