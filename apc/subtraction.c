#include "apc.h"

int flag;

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) 
{
    Dlist *temp1 = *tail1, *temp2 = *tail2;
    int result;

    while (temp1 || temp2 ) 
    {
        if (temp2 == NULL) 
        {
            result = temp1->data;
            temp1 = temp1->prev;
        } 
        else
        {
            if (temp1->data >= temp2->data) 
            {
                result = temp1->data - temp2->data;
                temp1 = temp1->prev;
                temp2 = temp2->prev;
            } 
            else 
            {
                Dlist *temp = temp1->prev;

                while (temp != NULL && temp->data == 0) /*Traversing untill the non zero number will not found */
                {
                    temp->data = 9;
                    temp = temp->prev;
                }

                if (temp != NULL) 
                    temp->data = temp->data - 1;
                temp1->data = temp1->data + 10; 
					continue;
            }
        }
		// inserting the data at first
        insert_data(headR, tailR, result);
    }

    // removing extra zeros
    remove_zero(headR);
    return SUCCESS;
}

void remove_zero(Dlist **list) 
{
    if (*list == NULL) 
		return;

    Dlist *current = *list;
    while (current->next != NULL && current->data == 0) 
    {
        Dlist *temp = current;
        current = current->next;
        current->prev = NULL;
        free(temp);
    }

    *list = current;

    // at least one node should ne there even if it is 0
    if (*list == NULL) 
        insert_data(list, list, 0); 
}
