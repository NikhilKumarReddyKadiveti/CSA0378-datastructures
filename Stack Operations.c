#include <stdio.h>
int top=-1;
int stack[100];
void push(int n){
    if(top<99){
        top++;
        stack[top]=n;
    } 
    else{
        printf("Stack overflow\n");
    }
}
void pop(){
    if(top>-1){
        top--;
    }else{
        printf("Stack underflow\n");
    }
}
int display(){
    if(top>-1){
        return stack[top];
    }else{
        printf("Stack is empty\n");
        
    }
}

int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    push(a);
    printf("Top element: %d\n", display());
    pop();
    printf("Top element after pop: %d\n", display());
    
    return 0;
}