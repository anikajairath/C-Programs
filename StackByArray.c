#include <stdio.h>
#include <stdlib.h>
#define N 5

int stack [N]; //defining stack as array
int top = -1; // setting stack as empty

void push(){

    int x = 0;
    printf("ENTER NO: ");
    scanf("%d", &x);

    if(top == (N-1)){
        printf("\nSTACK OVERFLOW!");
    }
    else{
        top++; //Incrementing top to nxt position in array
        stack[top] = x;
    }

}

void pop(){

int n = 0;

if(top == -1){

    printf("\nSTACK UNDERFLOW!");
}

else{

    n = stack[top]; //storing the value of top before deleting it
    top--;
    printf("\n%d HAS BEEN DELETED", n);
}
}

void peek(){

int n = 0;

if(top == -1){
    printf("\nSTACK IS EMPTY");
}

else{

printf("\nTHE LAST MOST ELEMENT = %d\n", stack[top]);
}
}

void display(){

if(top == -1){

    printf("\nSTACK IS EMPTY");
}

else{
printf("\nPRINTING THE STACK:\n");

for(int n = top;n>= 0;n--){

    printf("\n%d", stack[n]);
}
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

printf("\nPRESS 0 TO CONTINUE AND 1 TO EXIT:\n");
scanf("%d", &choice);
    }while(choice == 0);

    exit(0);

}
