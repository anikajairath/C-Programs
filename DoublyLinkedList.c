#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node* prv;
struct node* nxt;
};

void main(){

struct node *head; //TO POINT TO ADDRESS OF STARTING NODE
struct node *newnode; //TO POINT TO ADDRESS OF NEW NODE
struct node *temp; //TO POINT TO ADDRESS OF LAST NODE
head = NULL;
int choice, tchoice;

printf("\t\t\t\t\t DOUBLY LINKED LIST PROGRAM\n\n");


do{
newnode = (struct node*) malloc(sizeof(struct node));

printf("\nENTER DATA:\n");
scanf("%d", &newnode->data); //STORING DATA IN 'DATA' PART OF NEW NODE
newnode->prv = NULL;
newnode->nxt = NULL; //SETTING THE LINK PART TO 0

if(head == NULL){ //FIRST NODE
    head = newnode;
    temp = newnode;
    head->prv = NULL;
}

else{
    newnode->prv = temp; //STORE ADDRESS OF PRV NODE IN NEW NODE
    temp->nxt = newnode; //STORE ADDRESS OF NEW NODE IN OLD NODE (POINTED BY TEMP AT THE MOMENT) LINK PART
    temp = newnode; //UPDATE TEMP TO POINT TO NEW NODE NOW
}

printf("\nDO YOU WANT TO ENTER A NEW NODE?\nENTER 0 FOR YES AND 1 FOR NO\n");
scanf("%d", &choice);

}while(choice == 0);

printf("\nTYPE 1 FOR STRAIGHT TRAVERSAL");
printf("\nTYPE 2 FOR REVERSE TRAVERSAL\n");
scanf("%d", &tchoice);

printf("\nNOW PRINTING THE LIST....\n");

if(tchoice == 1){

struct node *curr = head;

while(curr != NULL){

    printf("\n%d", curr->data);
    curr = curr->nxt;
}

printf("\n\n");}

if(tchoice == 2){

struct node *curr = temp;

while(curr != NULL){

    printf("\n%d", curr->data);
    curr = curr->prv;
}

printf("\n\n");

}
}
