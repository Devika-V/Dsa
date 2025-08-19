#include<stdio.h>
void inter(int a[],int b[],int m,int n){
    printf("Intersection is:");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
	    if(a[i]==b[j]){
		
	        printf("%d ",b[j]);
		    }
		}
	    
	
    }

  printf("\n"); 
    
}

int main(){
    int a[10];
    int b[10];
    int m,n;
    printf("Enter m: ");
    scanf("%d",&m);
    printf("Enter the values:\n");
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter the value:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    
    inter(a,b,m,n);

}
