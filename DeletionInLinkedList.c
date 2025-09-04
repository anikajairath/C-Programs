#include <stdio.h>
#include <stdlib.h>

struct node{

int data;
struct node * link;

};

void main(){

struct node *fir = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF STARTING NODE
struct node *sec = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF SECOND NODE
struct node *thi = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF THIRD NODE
struct node *fou = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF FOURTH NODE
struct node *fif = (struct node*) malloc(sizeof(struct node));; //TO POINT TO ADDRESS OF FIFTH NODE


struct node* temp;
struct node* head;
struct node* befpos;
int choice;
int pos;


fir->data = 100;
fir->link = sec;

sec->data = 200;
sec->link = thi;

thi->data = 300;
thi->link = fou;

fou->data = 400;
fou->link = fif;

fif->data = 500;
fif->link = NULL;

printf("PRINTING THE HARDCODED LINKED LIST:\n");

head = fir;
temp = head; //ASSIGNING THE HEAD TO TEMP;

while(temp != NULL){

    printf("\t%d", temp->data);
    temp = temp->link;
}

printf("\n\nTYPE 1 TO DELETE A NODE AT THE BEGINNING");
printf("\n\nTYPE 2 TO DELETE A NODE AT THE SPECIFIED POSITION");
printf("\n\nTYPE 3 TO DELETE A NODE AT THE END\n");
printf("\nENTER: ");
scanf("%d", &choice);

temp = head; //INITIALIZING TEMP AGAIN

switch(choice){

case 1: struct node* del = head;
        head = head->link;
        free(del);

case 2: printf("\nENTER THE POSITION AT WHICH NEW NODE IS TO BE DELETED:\n");
        scanf("%d", &pos);

        if (pos <= 1) {
        struct node* del = head;
        head = head->link;
        free(del);
        break;
        }

        for(int i = 1; i<pos; i++){
        befpos = temp; //POINTING TO THE NODE JUST BEFORE POSITION
        temp = temp->link; //THIS IS RIGHT NOW POINTING TO THE EXACT POSITION WE WANT TO DELETE
        }
        if (temp == NULL) {           // POSITION BEYOND LIST LENGTH
        printf("Invalid position\n");
        break;
        }
        befpos->link = temp->link; //AS TEMP HAS BEEN UPDATED NOW, IT WILL POINT TO befpos->link->link
        free(temp);
        break;

case 3: if (head == NULL) { break; }                  // <-- ADD: empty list
        if (head->link == NULL) {                     // <-- ADD: single node
            free(head);
            head = NULL;
            break;
        }
        for(int i = 1; temp->link!= NULL; i++){ //WE WANT TO STOP A NODE BEFORE THE END SO THE MIDDLE CONDITION IS FULFILLED
        befpos = temp;
        temp = temp->link;
        }
        befpos->link = NULL;
        free(temp);
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
