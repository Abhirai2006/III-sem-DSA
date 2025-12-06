#include <stdio.h>
#include <stdlib.h>

int main() {

    // -------- ARRAY --------
    int arr[100], n = 0, pos, val, i;

    // -------- LINKED LIST --------
    struct node {
        int data;
        struct node *next;
    };
    struct node *head = NULL, *temp, *newnode;

    // -------- DOUBLY LINKED LIST --------
    struct dnode {
        int data;
        struct dnode *prev, *next;
    };
    struct dnode *dhead = NULL, *dtemp, *dnew;

    // -------- CIRCULAR LINKED LIST --------
    struct cnode {
        int data;
        struct cnode *next;
    };
    struct cnode *chead = NULL, *ctemp, *cnew;

    // -------- STACK --------
    int stack[100], top = -1;

    // -------- QUEUE --------
    int queue[100], front = -1, rear = -1;

    int choice, ds_choice;

    while (1) {
        printf("\n==== MAIN MENU ====\n");
        printf("1. Array\n");
        printf("2. Singly Linked List\n");
        printf("3. Doubly Linked List\n");
        printf("4. Circular Linked List\n");
        printf("5. Stack\n");
        printf("6. Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ds_choice);

        if (ds_choice == 7) break;

        switch(ds_choice) {

        // ================================================================
        // ARRAY OPERATIONS
        // ================================================================
        case 1:
            while(1) {
                printf("\n--- ARRAY MENU ---\n");
                printf("1. Insert at Beginning\n");
                printf("2. Insert at End\n");
                printf("3. Insert at Position\n");
                printf("4. Delete at Beginning\n");
                printf("5. Delete at End\n");
                printf("6. Delete at Position\n");
                printf("7. Display Array\n");
                printf("8. Length of Array\n");
                printf("9. Back\n");
                scanf("%d", &choice);

                if (choice == 9) break;

                if (choice <= 3) {
                    printf("Enter value: ");
                    scanf("%d", &val);
                }

                switch(choice) {
                case 1: // insert at beginning
                    for (i=n; i>0; i--) arr[i] = arr[i-1];
                    arr[0] = val;
                    n++;
                    break;

                case 2: // insert at end
                    arr[n++] = val;
                    break;

                case 3: // insert at pos
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    for (i=n; i>=pos; i--) arr[i] = arr[i-1];
                    arr[pos-1] = val;
                    n++;
                    break;

                case 4: // delete begin
                    for (i=0;i<n-1;i++) arr[i] = arr[i+1];
                    n--;
                    break;

                case 5: // delete end
                    n--;
                    break;

                case 6: // delete pos
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    for (i=pos-1;i<n-1;i++) arr[i] = arr[i+1];
                    n--;
                    break;

                case 7: // display
                    printf("Array: ");
                    for(i=0;i<n;i++) printf("%d ", arr[i]);
                    printf("\n");
                    break;

                case 8:
                    printf("Length = %d\n", n);
                    break;
                }
            }
            break;

        // ================================================================
        // SINGLY LINKED LIST
        // ================================================================
        case 2:
            while(1){
                printf("\n--- LINKED LIST MENU ---\n");
                printf("1. Insert at Beginning\n");
                printf("2. Insert at End\n");
                printf("3. Insert at Position\n");
                printf("4. Delete at Beginning\n");
                printf("5. Delete at End\n");
                printf("6. Delete at Position\n");
                printf("7. Display\n");
                printf("8. Length\n");
                printf("9. Back\n");
                scanf("%d", &choice);

                if(choice == 9) break;

                if(choice <= 3){
                    printf("Enter value: ");
                    scanf("%d",&val);
                }

                switch(choice){
                case 1: // insert beginning
                    newnode = malloc(sizeof(struct node));
                    newnode->data = val;
                    newnode->next = head;
                    head = newnode;
                    break;

                case 2: // insert end
                    newnode = malloc(sizeof(struct node));
                    newnode->data = val;
                    newnode->next = NULL;
                    if(head == NULL) head = newnode;
                    else {
                        temp = head;
                        while(temp->next != NULL) temp=temp->next;
                        temp->next = newnode;
                    }
                    break;

                case 3: // insert pos
                    printf("Enter position: ");
                    scanf("%d",&pos);
                    newnode = malloc(sizeof(struct node));
                    newnode->data = val;
                    if(pos == 1){
                        newnode->next = head;
                        head = newnode;
                    } else {
                        temp=head;
                        for(i=1;i<pos-1;i++) temp=temp->next;
                        newnode->next = temp->next;
                        temp->next = newnode;
                    }
                    break;

                case 4: // delete begin
                    temp=head;
                    head=head->next;
                    free(temp);
                    break;

                case 5: // delete end
                    temp=head;
                    while(temp->next->next != NULL) temp=temp->next;
                    free(temp->next);
                    temp->next=NULL;
                    break;

                case 6: // delete pos
                    printf("Enter position: ");
                    scanf("%d",&pos);
                    temp=head;
                    if(pos ==1){
                        head=head->next;
                        free(temp);
                    } else {
                        for(i=1;i<pos-1;i++) temp=temp->next;
                        struct node *del = temp->next;
                        temp->next = del->next;
                        free(del);
                    }
                    break;

                case 7: // display
                    temp=head;
                    printf("Linked List: ");
                    while(temp){
                        printf("%d ", temp->data);
                        temp=temp->next;
                    }
                    printf("\n");
                    break;

                case 8: // length
                    temp=head;
                    i=0;
                    while(temp){ i++; temp=temp->next; }
                    printf("Length = %d\n", i);
                    break;
                }
            }
            break;

        // ================================================================
        // DOUBLY LINKED LIST
        // ================================================================
        case 3:
            while(1){
                printf("\n--- DOUBLY LINKED LIST MENU ---\n");
                printf("1. Insert at Beginning\n");
                printf("2. Insert at End\n");
                printf("3. Insert at Position\n");
                printf("4. Delete at Beginning\n");
                printf("5. Delete at End\n");
                printf("6. Delete at Position\n");
                printf("7. Display\n");
                printf("8. Length\n");
                printf("9. Back\n");
                scanf("%d", &choice);

                if(choice==9) break;

                if(choice<=3){
                    printf("Enter value: ");
                    scanf("%d",&val);
                }

                switch(choice){
                case 1: // insert begin
                    dnew = malloc(sizeof(struct dnode));
                    dnew->data = val;
                    dnew->prev = NULL;
                    dnew->next = dhead;
                    if(dhead) dhead->prev = dnew;
                    dhead = dnew;
                    break;

                case 2: // insert end
                    dnew = malloc(sizeof(struct dnode));
                    dnew->data = val;
                    dnew->next = NULL;
                    if(dhead == NULL){
                        dnew->prev=NULL;
                        dhead=dnew;
                    } else {
                        dtemp=dhead;
                        while(dtemp->next) dtemp=dtemp->next;
                        dtemp->next=dnew;
                        dnew->prev=dtemp;
                    }
                    break;

                case 3: // insert pos
                    printf("Enter position: ");
                    scanf("%d",&pos);
                    dnew = malloc(sizeof(struct dnode));
                    dnew->data = val;

                    if(pos==1){
                        dnew->next=dhead;
                        dnew->prev=NULL;
                        if(dhead) dhead->prev=dnew;
                        dhead=dnew;
                    } else {
                        dtemp=dhead;
                        for(i=1;i<pos-1;i++) dtemp=dtemp->next;
                        dnew->next=dtemp->next;
                        dnew->prev=dtemp;
                        if(dtemp->next) dtemp->next->prev=dnew;
                        dtemp->next=dnew;
                    }
                    break;

                case 4: // delete begin
                    dtemp=dhead;
                    dhead=dhead->next;
                    if(dhead) dhead->prev=NULL;
                    free(dtemp);
                    break;

                case 5: // delete end
                    dtemp=dhead;
                    while(dtemp->next) dtemp=dtemp->next;
                    if(dtemp->prev) dtemp->prev->next=NULL;
                    else dhead=NULL;
                    free(dtemp);
                    break;

                case 6: // delete pos
                    printf("Enter position: ");
                    scanf("%d",&pos);
                    dtemp=dhead;
                    if(pos==1){
                        dhead=dhead->next;
                        if(dhead) dhead->prev=NULL;
                        free(dtemp);
                    } else {
                        for(i=1;i<pos;i++) dtemp=dtemp->next;
                        dtemp->prev->next = dtemp->next;
                        if(dtemp->next) dtemp->next->prev = dtemp->prev;
                        free(dtemp);
                    }
                    break;

                case 7: // display
                    dtemp=dhead;
                    printf("Doubly List: ");
                    while(dtemp){
                        printf("%d ", dtemp->data);
                        dtemp=dtemp->next;
                    }
                    printf("\n");
                    break;

                case 8:
                    dtemp=dhead; i=0;
                    while(dtemp){ i++; dtemp=dtemp->next; }
                    printf("Length = %d\n",i);
                    break;
                }
            }
            break;

        // ================================================================
        // CIRCULAR LINKED LIST
        // ================================================================
        case 4:
            while(1){
                printf("\n--- CIRCULAR LINKED LIST MENU ---\n");
                printf("1. Insert at Beginning\n");
                printf("2. Insert at End\n");
                printf("3. Insert at Position\n");
                printf("4. Delete at Beginning\n");
                printf("5. Delete at End\n");
                printf("6. Delete at Position\n");
                printf("7. Display\n");
                printf("8. Length\n");
                printf("9. Back\n");
                scanf("%d",&choice);

                if(choice==9) break;

                if(choice<=3){
                    printf("Enter value: ");
                    scanf("%d",&val);
                }

                switch(choice){
                case 1:
                    cnew = malloc(sizeof(struct cnode));
                    cnew->data = val;
                    if(chead == NULL){
                        chead = cnew;
                        cnew->next = chead;
                    } else {
                        ctemp = chead;
                        while(ctemp->next != chead) ctemp=ctemp->next;
                        cnew->next = chead;
                        ctemp->next = cnew;
                        chead = cnew;
                    }
                    break;

                case 2:
                    cnew = malloc(sizeof(struct cnode));
                    cnew->data = val;
                    if(chead == NULL){
                        chead = cnew;
                        cnew->next = chead;
                    } else {
                        ctemp = chead;
                        while(ctemp->next != chead) ctemp=ctemp->next;
                        ctemp->next = cnew;
                        cnew->next = chead;
                    }
                    break;

                case 3:
                    printf("Enter position: ");
                    scanf("%d",&pos);
                    cnew = malloc(sizeof(struct cnode));
                    cnew->data = val;

                    if(pos==1){
                        ctemp=chead;
                        while(ctemp->next!=chead) ctemp=ctemp->next;
                        cnew->next=chead;
                        ctemp->next=cnew;
                        chead=cnew;
                    } else {
                        ctemp=chead;
                        for(i=1;i<pos-1;i++) ctemp=ctemp->next;
                        cnew->next=ctemp->next;
                        ctemp->next=cnew;
                    }
                    break;

                case 4:
                    ctemp=chead;
                    while(ctemp->next!=chead) ctemp=ctemp->next;
                    struct cnode *del = chead;
                    chead = chead->next;
                    ctemp->next = chead;
                    free(del);
                    break;

                case 5:
                    ctemp=chead;
                    while(ctemp->next->next!=chead) ctemp=ctemp->next;
                    del=ctemp->next;
                    ctemp->next=chead;
                    free(del);
                    break;

                case 6:
                    printf("Enter position: ");
                    scanf("%d",&pos);
                    ctemp=chead;
                    if(pos==1){
                        while(ctemp->next!=chead) ctemp=ctemp->next;
                        del=chead;
                        chead=chead->next;
                        ctemp->next=chead;
                        free(del);
                    } else {
                        for(i=1;i<pos-1;i++) ctemp=ctemp->next;
                        del=ctemp->next;
                        ctemp->next=del->next;
                        free(del);
                    }
                    break;

                case 7:
                    ctemp=chead;
                    printf("Circular List: ");
                    do{
                        printf("%d ", ctemp->data);
                        ctemp=ctemp->next;
                    } while(ctemp!=chead);
                    printf("\n");
                    break;

                case 8:
                    ctemp=chead; i=0;
                    do{
                        i++;
                        ctemp=ctemp->next;
                    } while(ctemp!=chead);
                    printf("Length = %d\n", i);
                    break;
                }
            }
            break;

        // ================================================================
        // STACK
        // ================================================================
        case 5:
            while(1){
                printf("\n--- STACK MENU ---\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Display\n");
                printf("4. Length\n");
                printf("5. Back\n");
                scanf("%d",&choice);

                if(choice==5) break;

                switch(choice){
                case 1:
                    printf("Enter value: ");
                    scanf("%d",&val);
                    stack[++top]=val;
                    break;

                case 2:
                    top--;
                    break;

                case 3:
                    printf("Stack: ");
                    for(i=top;i>=0;i--) printf("%d ", stack[i]);
                    printf("\n");
                    break;

                case 4:
                    printf("Length = %d\n", top+1);
                    break;
                }
            }
            break;

        // ================================================================
        // QUEUE
        // ================================================================
        case 6:
            while(1){
                printf("\n--- QUEUE MENU ---\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display\n");
                printf("4. Length\n");
                printf("5. Back\n");
                scanf("%d",&choice);

                if(choice==5) break;

                switch(choice){
                case 1:
                    printf("Enter value: ");
                    scanf("%d",&val);
                    if(front==-1) front=0;
                    queue[++rear]=val;
                    break;

                case 2:
                    front++;
                    if(front>rear) front=rear=-1;
                    break;

                case 3:
                    printf("Queue: ");
                    for(i=front;i<=rear;i++) printf("%d ", queue[i]);
                    printf("\n");
                    break;

                case 4:
                    if(front==-1) printf("Length = 0\n");
                    else printf("Length = %d\n", rear-front+1);
                    break;
                }
            }
            break;

        } // switch end
    } // while end

    return 0;
}
