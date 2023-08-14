#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void divide(int a[],int low,int high){
    if(low<high){
        int mid=partition(a,low,high);
        divide(a,low,mid-1);
        divide(a,mid+1,high);
    }
}

int partition(int a[],int low,int high){
    int pivot=low,i=low+1,j=high;
    while(i<j){
        while(a[i]<=a[pivot]) i++;
        while(a[j]>a[pivot]) j--;
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;
    return j;
}

void main(){
    int n,a[100000];
    clock_t start,end;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Generating random numbers\n");
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
        printf("%d\t",a[i]);
    }
    start=clock();
    divide(a,0,n-1);
    end=clock();
    printf("The sorted List \n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    double tt=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The time take to sort using quick sort is %f",tt);
}