#include<stdio.h>

void swap(int x,int y){
    int temp=x;
    x=y;
    y=temp;
}

void heapify(int a[],int n,int i){
    int largestindex=i;
    int leftindex=2*i+1;
    int rightindex=2*i+2;
    if(leftindex<n && a[leftindex]>a[largestindex]){
        largestindex=leftindex;
    }
    if(rightindex<n && a[rightindex]>a[largestindex]){
        largestindex=rightindex;
    }
    if(largestindex!=i){
        swap(a[i],a[largestindex]);
        heapify(a,n,largestindex);
    }
}

void maxheap(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    printf("Max HeapTree\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

void heapsort(int a[],int n){
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void main(){
    int a[]={1,12,9,5,6,10};
    int n=sizeof(a)/sizeof(int);
    maxheap(a,n);
    heapsort(a,n);
    printf("Sorted List\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}