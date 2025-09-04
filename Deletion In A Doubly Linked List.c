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

struct node *lstnode = fif; //TO KEEP TRACK OF LAST NODE

struct node* temp;
int choice, tchoice;
int pos;
struct node* befpos = NULL;
struct node* aftpos = NULL;

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

printf("\n\nTYPE 1 TO DELETION OF A NODE AT THE BEGINNING");
printf("\n\nTYPE 2 TO DELETION OF A NODE AT THE SPECIFIED POSITION");
printf("\n\nTYPE 3 TO DELETION OF A NODE AT THE END\n");
printf("\nENTER: ");
scanf("%d", &choice);

temp = head; //ASSIGNING THE HEAD TO TEMP;

switch(choice){

case 1: {
        struct node* del = head;
        head = head->link;
        if (head != NULL) head->prv = NULL;
        free(del);
        break;
        }

case 2: printf("\nENTER THE POSITION AT WHICH NEW NODE IS TO BE DELETED:\n");
    scanf("%d", &pos);

    if (pos <= 1) { //DELETE HEAD
        struct node* del = head;
        head = head->link;
        if (head != NULL) head->prv = NULL;
        else lstnode = NULL; //LIST BECOMES EMPTY
        free(del);
        break;
    }

    // WALK TO THE NODE AT 'pos' (temp) AND THE ONE BEFORE IT (befpos)
    befpos = NULL;
    temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        befpos = temp;
        temp = temp->link;
    }

    if (temp == NULL) { //POSITION BEYOND LENGTH
        printf("Invalid position\n");
        break;
    }

    aftpos = temp->link; //NODE AFTER THE ONE WE DELETE
    befpos->link = aftpos; //MOVE FORWARD

    if (aftpos != NULL) { //MIDDLE DELETE
        aftpos->prv = befpos; //MOVE BACKWARD
    } else {  //DELETE LAST NODE
        lstnode = befpos; //UPDATE TAIL FOR REVERSE TRAVESAL
    }

    free(temp);
    break;

case 3: for(int i = 1; temp->link!= NULL; i++){ //WE WANT TO STOP A NODE BEFORE THE END SO THE MIDDLE CONDITION IS FULFILLED
        befpos = temp;
        temp = temp->link;
        }
        befpos->link = NULL;
        lstnode = befpos; //CHANGING LASTNODE POINTER
        free(temp);
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
