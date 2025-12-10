/** Display functions for all **/

/** 1.SINGLY LINKED LIST **/


void display()
{
    temp = head;
    if(temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d %s -> ",temp->data,temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}


/** 2.DOUBLY LINKED LIST **/


void display()
{
    temp = head;
    if(temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    printf("NULL");
    while(temp != NULL)
    {
        printf(" <- %d %s -> ",temp->data,temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}


/** 3.CIRCULAR LINKED LIST **/


void display()
{
    if(tail == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    else
    {
        temp = tail ->next;
        while(temp ->next != tail ->next)
        {
            printf("%d %s->",temp ->data,temp->name);
            temp = temp ->next;
        }

        printf("%d %s->",temp ->data,temp ->name);
    }
}


/** 4.DOUBLY CIRCULAR LINKED LIST **/


void display()
{
    if(head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    else
    {
        temp = head;
        while(temp != tail)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
}
