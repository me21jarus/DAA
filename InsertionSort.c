#include<stdio.h>
#include<stdlib.h>

void InsertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0 & a[j]>temp){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}

int main(){
    int n,a[100000];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Generating random number...\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        printf("%d\t",a[i]);
    }
    printf("\n");
    InsertionSort(a,n);
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}