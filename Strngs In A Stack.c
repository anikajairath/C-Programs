#include <stdio.h>
#include <stdlib.h>
#define N 5

char stack[N][10]; //defining stack as array
int top = -1; // setting stack as empty

void push(){

printf("\nENTER THE STRING:-\n");

if(top == (N-1)){

    printf("\nSTACK OVERFLOW!");
}

else{

    top++;
    scanf("%9s", stack[top]);
}
}

void pop(){

if(top == -1){
    printf("\nSTACK UNDERFLOW!");
}

else{
    printf("\n%s HAS BEEN DELETED", stack[top]);
    top--;
}
}

void display(){

if (top == -1) {  //IF STACK IS EMPTY
        printf("\nSTACK IS EMPTY");
        return;
    }

    printf("\nDISPLAYING THE STACK:-\n");

    for (int i = top; i >= 0; i--) {
        printf("\n%s", stack[i]);
    }
}

void peek(){


if(top == -1){
    printf("\nSTACK IS EMPTY");
}

else{

printf("\nTHE LAST MOST ELEMENT = %s\n", stack[top]);
}

}


int main(){

int choice = 0;

printf("\t\t\t\t\tOPERATIONS ON STACK IMPLEMENTED BY ARRAY");
printf("\n\t\t\t\t\t----------------------------------------");

do{
    int opt = 0;


    printf("\nTYPE:\n");
    printf("1 FOR INSERTION\n");
    printf("2 FOR DELETION OF THE LASTMOST ELEMENT\n");
    printf("3 FOR DISPLAYING LAST MOST ELEMENT\n"); //Display but not delete top
    printf("4 FOR DISPLAYING COMPLETE STACK\n");
    scanf("%d", &opt);

    switch(opt){

    case 1: push();
    break;

    case 2: pop();
    break;

    case 3: peek();
    break;

    case 4: display();
    break;

    default: printf("\nCHOOSE A VALID OPTION\n");
    break;
    }

printf("\n\nPRESS 0 TO CONTINUE AND 1 TO EXIT:\n");
scanf("%d", &choice);
    }while(choice == 0);

    exit(0);

}
