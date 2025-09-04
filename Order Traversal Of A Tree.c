#include <stdio.h>
#include <stdlib.h>

struct node{

    int data; //DATA PART
    struct node *lft; //LEFT CHILD
    struct node *rgt; //RIGHT CHILD
};

struct node *create(){ //CREATION OF NEW NODE
 int x;

 struct node *newnode;
 newnode = (struct node*) malloc(sizeof(struct node)); //CREATING NEW NODE

 printf("\n\nENTER DATA: (ENTER -1 FOR NO NODE)\n");
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

void preorder(struct node *root){ //nLR

    if(root == NULL){
        return;
    }

    printf("\t%d", root->data);
    preorder(root->lft); //MAKE ROOT THE LEFT CHILD
    preorder(root->rgt); //MAKE ROOT THE RIGHT CHILD

}

void inorder(struct node* root){ //LnR

    if(root == NULL){
        return;
    }

    inorder(root->lft);
    printf("\t%d", root->data);
    inorder(root->rgt);
}

void postorder(struct node* root){ //LRn

    if(root == NULL){
        return;
    }

    postorder(root->lft);
    postorder(root->rgt);
    printf("\t%d", root->data);
}


void main(){

struct node *root;

printf("\t\t\t\t\t\tORDER TRAVERSAL OF A TREE");

root = create(); //CREATIONG A TREE FROM ROOT

int choice;
int uchoice = 0;

do{
printf("\nENTER 1 FOR PREORDER TRAVERSAL");
printf("\nENTER 2 FOR INORDER TRAVERSAL");
printf("\nENTER 3 FOR POSTORDER TRAVERSAL\n");
scanf("%d", &choice);

switch(choice){

case 1: printf("\n\nPRINTING PREORDER TRAVERSAL OF TREE...\n\n");
        preorder(root);
        break;

case 2: printf("\n\nPRINTING INORDER TRAVERSAL OF TREE...\n\n");
        inorder(root);
        break;

case 3: printf("\n\nPRINTING POSTORDER TRAVERSAL OF TREE...\n\n");
        postorder(root);
        break;

default: printf("\nENTER A VALID OPTION");
         break;
}

printf("\n\n\nENTER 0 TO CONTINUE AND 1 TO EXIT\n");
scanf("%d", &uchoice);
}while(uchoice == 0);
}
