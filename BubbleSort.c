#include<stdio.h>
#include<stdio.h>
#include<time.h>

void BubbleSort(int a[],int n){
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void main(){
    int n,a[100000];
    clock_t start,end;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Generating random number...\n");
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
        printf("%d\t",a[i]);
    }
    start=clock();
    BubbleSort(a,n);
    end=clock();
    printf("The sorted List is..\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    double tt=(double)(end-start)/CLOCKS_PER_SEC;
    printf("the time taken to sort the elements using Bubblesort is %f",tt);
}