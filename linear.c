#include<stdio.h>
void linearSearch(int a[], int n,int key){
        int f=0;
	for(int i=0;i<n;i++){
        if(a[i]==key){
	    f=1;
	    printf("%d found at index %d\n",key,i);
	    break;
	}
        }
        if(f==0){   
       
	printf("Element not found\n");
    }
}

int main(){
int n;
int a[20];
printf("Enter the total no of elements:");
scanf("%d",&n);
printf("Enter %d  elements:\n",n);
for(int i=0;i<n;i++){
	scanf("%d", &a[i]); 

}
int key;


printf("Enter the number to search:\n");
scanf("%d",&key);

linearSearch(a,n,key);
return 0;
}
