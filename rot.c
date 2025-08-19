#include<stdio.h>
void rotate(int a[],int n,char d,int c){
    int temp[n];
    if(d=='l' || d=='L'){
        for(int i=0;i<n;i++){
	    int j=i+c;
	    if(j>=n){
	        j=j-n;
	    }
	    temp[i]=a[j];
	}
	
    }
    else if(d=='r' || d=='R'){
        for(int i=0;i<n;i++){
	    int j=i-c;
	    if(j<0){
	        j=j+5;
	    }
	    temp[i]=a[j];
	}
    }

for(int i=0;i<n;i++){
    printf("%d ",temp[i]);
}
printf("\n");
}

int main(){
int a[5]={1,2,3,4,5};
char d='r';
int n=5;
int c=2;

rotate(a,n,d,c);



}
