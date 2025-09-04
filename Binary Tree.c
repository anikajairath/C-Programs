#include <stdio.h>
#include <stdlib.h>

struct node{

    int data; //DATA PART
    struct node *lft; //LEFT CHILD
    struct node *rgt; //RIGHT CHILD
};

struct node *create(){
 int x;

 struct node *newnode;
 newnode = (struct node*) malloc(sizeof(struct node)); //CREATING NEW NODE

 printf("ENTER DATA: (ENETER -1 FOR NO NODE)\n");
 scanf("%d", &x);

 if(x == -1){

    return NULL;
 }

 newnode->data = x; //STORE DATA IN DATA PART OF NODE

 printf("ENTER LEFT CHILD OF %d:\n", x);
 newnode->lft = create(); //STORE VALUE RETURNED FROM CREATE IN LFT CHILD

 printf("ENTER RIGHT CHILD OF %d:\n", x);
 newnode->rgt = create(); //STORE VALUE RETURNED FROM CREATE IN RGT CHILD

 return newnode;

}


void main(){

struct node *root;

root = create(); //CREATIONG A TREE FROM ROOT

printf("\nPRINTING THE TREE...\n\n");

struct node *curr = root;

printf("PARENT NODE = %d", curr->data);
printf("\nLEFT CHILD = %d", curr->lft->data);
printf("\nRIGHT CHILD = %d", curr->rgt->data);

curr = curr->lft;

printf("\n\nLEFT SUB-TREE:");

while(curr->lft != NULL && curr->rgt != NULL){

    printf("\nPARENT NODE = %d", curr->data);
    printf("\nLEFT CHILD = %d", curr->lft->data);
    printf("\nRIGHT CHILD = %d", curr->rgt->data);

    printf("\n\n");

    curr = curr->lft;

}

curr = root->rgt;

printf("\n\nRIGHT SUB-TREE:");
while(curr->lft != NULL && curr->rgt != NULL){

    printf("\nPARENT NODE = %d", curr->data);
    printf("\nLEFT CHILD = %d", curr->lft->data);
    printf("\nRIGHT CHILD = %d", curr->rgt->data);

    printf("\n\n");

    curr = curr->rgt;

}

}
