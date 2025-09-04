#include <stdio.h>
#define max 100

char str[max];
char stack[max];
int top = -1;

void push(){

    for(int i = 0; str[i] != '\0'; i++){
        stack[i] = str[i];
        top++;
    }
}

void pop(){

     while(top > -1){
        printf("%c", stack[top]);
        top--;
    }

}

int main()
{
    int len = 0;

    printf("ENTER STRING\n");
    scanf("%s", &str);

    push();

    printf("\nPRINTING REVERSE STRING:\n");

    pop();
    printf("\n\n");

   return 0;
}
