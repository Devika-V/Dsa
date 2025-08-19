#include<stdio.h>
void mean(int a[],int n){
   
    float s=0;
    for(int i=0;i<n;i++){
        s=s+a[i];
    }
    printf("The mean is: %f\n",s/n);

}

void median(int a[], int n){
    float median;
    if(n%2!=0){
        median=a[(n-1)/2];
    }
    else{
        median=(a[n/2]+a[(n-1)/2])/2;
    }
    printf("The median is: %f \n",median);
}

void mode(int a[],int n){
    int mode=a[0];
    int mc=0;
    for(int i=0;i<n;i++){
        int c=0;
	for(int j=0;j<n;j++){
	    if(a[j]==a[i]){
	        c++;
	    }
	}
	if(c>mc){
	    mc=c;
	    mode=a[i];
	}
    }
    printf("The mode is: %d\n",mode);
}



int main(){
int n;
printf("Enter the no of elements: " );
scanf("%d",&n);
int a[n];
printf("Enter the elements:\n");

for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}

printf("choose\n");
printf("1 for mean\n 2 for median\n 3 for mode:\n");
int choice;
scanf("%d",&choice);
switch(choice){

case 1: mean(a,n);
	break;
case 2: median(a,n);
	break;
case 3: mode(a,n);
	break;
default: printf("invalid choice\n");
       	break;
}

}
