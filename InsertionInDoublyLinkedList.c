#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node* prv;
struct node* link;
};

void main(){

struct node *head = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF STARTING NODE
struct node *sec = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF SECOND NODE
struct node *thi = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF THIRD NODE
struct node *fou = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF FOURTH NODE
struct node *fif = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF FIFTH NODE

struct node *newnode;
struct node *lstnode = fif; //TO KEEP TRACK OF LAST NODE

struct node* temp;
int choice, tchoice;
struct node* befpos = NULL;
int pos;

head->prv = NULL;
head->data = 100;
head->link = sec;

sec->prv = head;
sec->data = 200;
sec->link = thi;

thi->prv = sec;
thi->data = 300;
thi->link = fou;

fou->prv = thi;
fou->data = 400;
fou->link = fif;

fif->prv = fou;
fif->data = 500;
fif->link = NULL;

printf("PRINTING THE HARDCODED LINKED LIST:\n");

temp = head; //ASSIGNING THE HEAD TO TEMP;

while(temp != NULL){

    printf("\t%d", temp->data);
    temp = temp->link;
}

printf("\n\nTYPE 1 TO INSERT A NODE AT THE BEGINNING");
printf("\n\nTYPE 2 TO INSERT A NODE AT THE SPECIFIED POSITION");
printf("\n\nTYPE 3 TO INSERT A NODE AT THE END\n");
printf("\nENTER: ");
scanf("%d", &choice);

newnode = (struct node*) malloc(sizeof(struct node));

printf("\nENTER DATA TO BE STORED:\n");
scanf("%d", &newnode->data);

temp = head;

switch(choice){

case 1: newnode->link = head;
        newnode->prv = NULL;
        head->prv = newnode;
        head = newnode;
        break;

case 2: printf("\nENTER THE POSITION AT WHICH NEW NODE IS TO BE INSERTED:\n");
        scanf("%d", &pos);

        for(int i = 1; i< pos; i++){
        befpos = temp;
        temp = temp->link;
        }

        befpos->link = newnode; //CHANGES WILL BE MADE TO THREE NODES

        newnode->link = temp;
        newnode->prv = befpos;

        temp->prv = newnode;
        break;

case 3: while(temp != NULL){
        befpos = temp;
        temp = temp->link;}

        befpos->link = newnode; //CHANGES WILL BE MADE TO TWO NODES
        newnode->link = NULL;
        newnode->prv = befpos;

        lstnode = newnode; //INITILIZING lstnode AGAIN
        break;

}

printf("\nTYPE 1 FOR STRAIGHT TRAVERSAL");
printf("\nTYPE 2 FOR REVERSE TRAVERSAL\n");
scanf("%d", &tchoice);

printf("\nNOW PRINTING THE LIST....\n");

struct node *curr;

if(tchoice == 1){

curr = head; //TO START FROM THE BEGINNIG OF THE LIST

while(curr != NULL){

    printf("\n%d", curr->data);
    curr = curr->link;
}

printf("\n\n");}

if(tchoice == 2){

curr = lstnode; //TO START FROM THE BOTTOM OF THE LIST

while(curr != NULL){

    printf("\n%d", curr->data);
    curr = curr->prv;
}

printf("\n\n");

}
}
