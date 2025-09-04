#include <stdio.h>
#include <stdlib.h>

struct node{

int data;
struct node * link;

};

void main(){

struct node *temp;
int choice;
int pos;

printf("CIRCULAR LINKED LIST");

struct node *head = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF STARTING NODE
struct node *sec = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF SECOND NODE
struct node *thi = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF THIRD NODE
struct node *fou = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF FOURTH NODE
struct node *fif = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF FIFTH NODE

struct node *newnode;
struct node *befpos;

head->data = 100;
head->link = sec;

sec->data = 200;
sec->link = thi;

thi->data = 300;
thi->link = fou;

fou->data = 400;
fou->link = fif;

fif->data = 500;
fif->link = head;

printf("\nPRINTING THE HARDCODED LINKED LIST:\n");

temp = head; //ASSIGNING THE HEAD TO TEMP;

while(temp->link != head){

    printf("\t%d", temp->data);
    temp = temp->link;
}
printf("\t%d", temp->data);

printf("\n\nTYPE");
printf("\n1 FOR INSERTION AT BEGINNING");
printf("\n2 FOR INSERTION AT SPECIFIED POSITION");
printf("\n3 FOR INSERTION AT END\n");

scanf("%d", &choice);

newnode = (struct node*) malloc(sizeof(struct node));

printf("\nENTER DATA TO BE STORED:\n");
scanf("%d", &newnode->data);

switch(choice){

case 1: newnode->link = head;
        while(temp->link != head){
        temp = temp->link;
        }
        temp->link = newnode;
        head = newnode;
        break;

case 2: printf("\nENTER THE POSITION AT WHICH NEW NODE IS TO BE INSERTED:\n");
        scanf("%d", &pos);

        temp = head; //START FROM HEAD

    if (pos <= 1) {  // HANDLE BEGINNING INSERT
        newnode->link = head;
        while (temp->link != head) { //FINDING LAST NODE
            temp = temp->link;
        }
        temp->link = newnode; // OLD LAST ASSIGNED TO new node
        head = newnode;      // NEW NODE BECOMES head
        break;
    }

    for (int i = 1; i < pos; i++) {           // MOVE TO THE POSITION BEFORE temp
        befpos = temp;
        temp = temp->link;
    }
    befpos->link = newnode;
    newnode->link = temp;
    break;

case 3: while(temp->link != head){
        temp = temp->link;
        }
        temp->link = newnode;
        newnode->link = head;
        break;

}

temp = head; //INITIALIZING TEMP AGAIN

printf("\n\nNOW PRINTING THE MODIFIED LINKED LIST:\n");

while(temp->link != head){

    printf("\n%d", temp->data);
    temp = temp->link;
}
printf("\n%d", temp->data);

printf("\n\n");
}


