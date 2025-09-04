#include <stdio.h>
#include <stdlib.h>

struct node{

int data;
struct node * link;

};

void main(){

struct node *head; //TO POINT TO ADDRESS OF STARTING NODE
struct node *newnode; //TO POINT TO ADDRESS OF NEW NODE
struct node *temp; //TO POINT TO ADDRESS OF LAST NODE
head = NULL;
int choice;


do{
newnode = (struct node*) malloc(sizeof(struct node));

printf("\nENTER DATA:\n");
scanf("%d", &newnode->data); //STORING DATA IN 'DATA' PART OF NEW NODE
newnode->link = NULL; //SETTING THE LINK PART TO 0

if(head == NULL){ //FIRST NODE
    head = newnode;
    temp = newnode;
}

else{
    temp->link = newnode; //STORE ADDRESS OF NEW NODE IN OLD NODE (POINTED BY TEMP AT THE MOMENT) LINK PART
    temp = newnode; //UPDATE TEMP TO POINT TO NEW NODE NOW
}

printf("\nDO YOU WANT TO ENTER A NEW NODE?\nENTER 0 FOR YES AND 1 FOR NO\n");
scanf("%d", &choice);

}while(choice == 0);


struct node *curr = head;

printf("\nNOW PRINTING THE LIST....\n");

while(curr != NULL){

    printf("\n%d", curr->data);
    curr = curr->link;
}

printf("\n\n");

}

