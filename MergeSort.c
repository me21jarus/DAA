#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void divide(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        divide(a,low,mid);
        divide(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    int temp[100000];
    while(i<=mid && j<=high){
        if(a[i]<a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while(i<=mid) temp[k++]=a[i++];
    while(j<=high) temp[k++]=a[j++];
    for(int k=low;k<=high;k++){
        a[k]=temp[k];
    }
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
    printf("The time take to sort using merge sort is %f",tt);
}