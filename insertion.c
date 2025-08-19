#include<stdio.h>
void insertion(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i];
	int j=i-1;
	while(j>=0 && a[j]>key){
	    a[j+1]=a[j];
	    j--;
	}
	a[j+1]=key;

    }

}

int main(){
int a[]={9,8,2,5,1,7};
int n=sizeof(a)/sizeof(a[0]);
insertion(a,n);
for(int i=0;i<n;i++){
    printf("%d",a[i]);
}
printf("\n");
}
