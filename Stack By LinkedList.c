#include <stdio.h>
#include <stdlib.h>
//In Stack push and pop both happen from the top

struct node{

int data;
struct node* link;
}*top, *head, *temp;

void push(){

    struct node* newnode;

    newnode = (struct node*) malloc(sizeof(struct node));

    printf("ENTER DATA\n");
    scanf("%d", &newnode->data);
    newnode->link = NULL;

    if(head == NULL){ //FIRST NODE
    head = newnode;
    top = newnode;}

    else{
    top->link = newnode; //STORE ADDRESS OF NEW NODE IN OLD NODE (POINTED BY TEMP AT THE MOMENT) LINK PART
    top = newnode; //UPDATE TEMP TO POINT TO NEW NODE NOW
    }

printf("\nELEMENT PUSHED SUCCESSFULLY");


}

void pop(){

if(top == NULL){
    printf("STACK UNDERFLOW");
}

else{

    struct node* befpos;
    temp = head;

    for(int i = 1; temp->link!= NULL; i++){ //WE WANT TO STOP A NODE BEFORE THE END SO THE MIDDLE CONDITION IS FULFILLED
        befpos = temp;
        temp = temp->link;
        }
        befpos->link = NULL;
        top = befpos;
        printf("\nELEMENT POPPED SUCCESSFULLY");
}
}

void peek(){

if(top == NULL){
    printf("STACK UNDERFLOW");
}

else{

printf("\nTHE LAST MOST ELEMENT = %d\n", top->data);
}
}

void display(struct node *curr){

    if(curr == NULL){
        return;
    }

    display(curr->link);
    printf("\n%d", curr->data);

}

void main(){

    int choice = 0;

    head = NULL;

    do{

    printf("\nENTER:\n");
    printf("1 TO PUSH AN ELEMENT\n");
    printf("2 TO POP AN ELEMENT\n");
    printf("3 TO DISPLAY LAST MOST ELEMENT\n"); //Display but not delete top
    printf("4 TO DISPLAY COMPLETE STACK\n");

    scanf("%d", &choice);

    switch(choice){

    case 1: push();
    break;

    case 2: pop();
    break;

    case 3: peek();
    break;

    case 4: if(head == NULL){printf("EMPTY STACK");}
            else {printf("\nPRINTING THE STACK...\n");
            display(head);}
    break;

    default: printf("\nCHOOSE A VALID OPTION\n");
    break;
    }


printf("\n\nENTER 0 TO CONTINUE AND 1 TO EXIT\n");
scanf("%d", &choice);

}while(choice == 0);

}
