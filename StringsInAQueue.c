#include <stdio.h>
#define MAX 10

char que[MAX][MAX]; //declaring array of max size


void main(){

    int front = -1;
    int rear = -1;
    char input[MAX];
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

            if(front == -1){
            front = 0;}

            rear++;

            printf("\n\nENTER ELEMENT TO BE ENQUEUED:\n");
            scanf("%s", &que[rear]);
        }
    }

    if(choice == 2){

            if((front == -1 && rear == -1) || (rear < front)){
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
                printf("\n%s", que[i]);}

                printf("\n");
            }
    }

printf("\nENTER 0 TO CONTINUE OR 1 TO EXIT\n");
scanf("%d", &uchoice);

}while (uchoice == 0);


}

