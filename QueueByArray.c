#include <stdio.h>
#define MAX 10

int que[MAX]; //declaring array of max size


void main(){

    int front = -1;
    int rear = -1;
    int input;
    int choice;
    int uchoice = 0;

    printf("ARRAY IMPLEMENTATION OF STACK");
    printf("\nIn Queue, Elements are added from rear and deleted from the front");

    do{
    printf("\n\nTYPE:");
    printf("\n1 TO ENQUEUE");
    printf("\n2 TO DEQUEUE");
    printf("\n3 TO DISPLAY ELEMENTS OF QUEUE\n");
    scanf("%d", &choice);

    if(choice == 1){

            if(rear == MAX-1){
            printf("\n\nQUEUE OVERFLOW!");
                }

            else {

            printf("\n\nENTER ELEMENT TO BE ENQUEUED:\n");
            scanf("%d", &input);

            if(front == -1){
            front = 0;}

            rear++;
            que[rear] = input;}
    }

    if(choice == 2){

            if((rear == -1 && front == -1) || (rear < front)){
            printf("\n\nQUEUE UNDERFLOW!");
                }

            else {front++;
            printf("\n\nELEMENT DEQUEUED");}

    }


    if(choice == 3){

            if(front == -1 && rear == -1){
                printf("THE QUEUE IS EMPTY");
            }

            else{
            printf("\n\nPRINTING THE QUEUE...");

            for(int i = front; i<= rear; i++){
                printf("\n%d", que[i]);}
            }
    }

printf("\nENTER 0 TO CONTINUE OR 1 TO EXIT\n");
scanf("%d", &uchoice);

}while (uchoice == 0);


}

