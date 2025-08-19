#include<stdio.h>
int top=-1;
void push(int a[],int e,int n){
    if(top==n-1){
	printf("Stack overflow\n");
    }
    else{
        top++;
	a[top]=e;
	printf("Element pushed successfully\n");

    }
    
}

int pop(int a[],int n){
    if(top==-1){
        printf("Stack underflow\n");
	return -1;
    }
    else{
	int e=a[top];
	top--;
	printf("Element popped successfully\n");
	return e;
        
    }

}

void peek(int a[]){
    if(top==-1){
        printf("Stack underflow\n");
    }
    else{
        printf("Top element:%d\n",a[top]);
    }
}


int main(){
int n=5;
int a[5]={0};
int e;
push(a,1,n);
push(a,2,n);
push(a,3,n);
peek(a);
pop(a,n);
peek(a);
return 0;
}


