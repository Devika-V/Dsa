#include<stdio.h>
void selection(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
	for(int j=i+1;j<n;j++){
	    if(a[j]<a[min]){
	        min=j;
	        
	    }
	}

	if(min!=i){
	    int temp=a[i];
	    a[i]=a[min];
	    a[min]=temp;
	}
    }
}
int main(){
    int a[]={9,4,1,8,2,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    selection(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
