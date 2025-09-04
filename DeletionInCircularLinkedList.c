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

printf("PRINTING THE HARDCODED LINKED LIST:\n");

temp = head; //ASSIGNING THE HEAD TO TEMP;

while(temp->link != head){

    printf("\t%d", temp->data);
    temp = temp->link;
}
printf("\t%d", temp->data);

printf("\n\nTYPE");
printf("\n1 FOR DELETION AT BEGINNING");
printf("\n2 FOR DELETION AT SPECIFIED POSITION");
printf("\n3 FOR DELETION AT END\n");

scanf("%d", &choice);

temp = head; //ASSIGNING THE HEAD TO TEMP;

switch(choice){

case 1: temp = head;
        head = sec;
        fif->link = sec;
        free(temp);
        break;

case 2: printf("\nENTER THE POSITION AT WHICH NEW NODE IS TO BE DELETED:\n");
        scanf("%d", &pos);

        for(int i = 1; i<pos; i++){
        befpos = temp; //POINTING TO THE NODE JUST BEFORE POSITION
        temp = temp->link; //THIS IS RIGHT NOW POINTING TO THE EXACT POSITION WE WANT TO DELETE
        }
        befpos->link = temp->link; //AS TEMP HAS BEEN UPDATED NOW, IT WILL POINT TO befpos->link->link
        free(temp);
        break;

case 3: for(int i = 1; temp->link!= head; i++){ //WE WANT TO STOP A NODE BEFORE THE END SO THE MIDDLE CONDITION IS FULFILLED
        befpos = temp;
        temp = temp->link;
        }
        befpos->link = head;
        free(temp);
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
