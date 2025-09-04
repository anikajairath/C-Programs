#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{

int data;
struct node *link;

}*head, *newnode, *temp;

void main(){

int choice = 0;
int f;
int pos = 0;
bool flag = false;

head = NULL;

printf("\t\t\t\t\tLINEAR SEARCH IN LINKED LIST");

do{
newnode = (struct node*) malloc(sizeof(struct node)); //ALWAYS DEFINE NEWNODE INSIDE THE LOOP
printf("\n\nENTER A NODE\n");
scanf("%d", &newnode->data);
newnode->link = NULL;

if(head == NULL){
    head = newnode;
    temp = newnode; //INITIALIZE TEMP ALSO FOR CORRECT LINKING IN NXT ROUND
}
else{

     temp->link = newnode; //STORE ADDRESS OF NEW NODE IN OLD NODE (POINTED BY TEMP AT THE MOMENT) LINK PART
     temp = newnode;
}

printf("\nENTER 0 TO CONTINUE OR 1 TO EXIT\n");
scanf("%d", &choice);

}while(choice == 0);

printf("\nENTER THE ELEMENT TO SEARCH:\n");
scanf("%d", &f);

temp = head; //ALWAYS INITIALIZE TEMP AT THE END AS HEAD HAS BEEN SET

while(temp != NULL){

    pos++;

    if(temp->data == f){

        printf("\n%d Present At Position %d\n", f, pos);
        flag = true;
        break;
    }

    else{
    temp = temp->link;
    }
}

if(flag == false){
    printf("\nElement Not Present In The List!\n");
}
}
