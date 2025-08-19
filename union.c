#include<stdio.h>
#define M 100
int z;
int s[M];
void Union(int a[],int n,int b[], int m){
    int c=0;
    for(int i=0;i<n;i++){
        s[c++]=a[i];
    }
    
    for(int j=0;j<m;j++){
	int f=0;
        for(int i=0;i<n;i++){
	    if(b[j]==a[i]){
		f+=1;
	        break;
	    }
	}
	if(!f){
	    s[c++]=b[j];
	}
    }
z=c;
}
int main(){
int n,m;
printf("Enter the value for n:\n");
scanf("%d",&n);
printf("Enter the value for m:\n");
scanf("%d",&m);
int a[n],b[m];
printf("Enter the elements for a\n");
for(int i=0;i<n;i++){
    scanf("%d ",&a[i]);
}

printf("Enter the elements for b\n");
for(int i=0;i<m;i++){
    scanf("%d ",&b[i]);
}
Union(a,n,b,m);
printf("The union is\n");
for(int i=0;i<z;i++){
    printf("%d ",s[i]);
}
printf("\n");
return 0;
}

