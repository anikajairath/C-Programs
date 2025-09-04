#include <stdio.h>
#include <stdlib.h>

struct node{

int data;
struct node * link;

};

void main(){

struct node *head = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF STARTING NODE
struct node *sec = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF SECOND NODE
struct node *thi = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF THIRD NODE
struct node *fou = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF FOURTH NODE
struct node *fif = (struct node*) malloc(sizeof(struct node)); //TO POINT TO ADDRESS OF FIFTH NODE

struct node *newnode;

struct node* temp;
int choice;
int pos;

head->data = 100;
head->link = sec;

sec->data = 200;
sec->link = thi;

thi->data = 300;
thi->link = fou;

fou->data = 400;
fou->link = fif;

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

temp = head; //INITIALIZING TEMP AGAIN

switch(choice){

case 1: newnode->link = head;
        head = newnode;
        break;

case 2: printf("\nENTER THE POSITION AT WHICH NEW NODE IS TO BE INSERTED:\n");
        scanf("%d", &pos);
        struct node* befpos;

        for(int i = 1; i< pos; i++){ //LOOP WILL STOP A POSITION BEFORE pos. AS WE ALREADY HAVE temp. temp WILL START FROM 1
        befpos = temp;
        temp = temp->link;
        }
        befpos->link = newnode;
        newnode->link = temp; //TEMP IN THE END WILL HAVE pos
        break;

case 3: newnode->link = NULL;
        while(temp != NULL){ //temp AT LAST WILL HAVE NULL. SO NEED befpos
        befpos = temp;
        temp = temp->link;}
        befpos->link = newnode;
        break;

}

temp = head; //INITIALIZING TEMP AGAIN

printf("\n\nNOW PRINTING THE MODIFIED LINKED LIST:\n");

while(temp != NULL){

    printf("\n%d", temp->data);
    temp = temp->link;
}

printf("\n\n");



}

