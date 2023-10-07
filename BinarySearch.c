#include<stdio.h>
#include<stdlib.h>

void BinarySearch(int a[],int low,int high,int key){
    
    int mid=(low+high)/2;

    if(a[mid]==key)
        printf("The element %d is present in %d",a[mid],mid);

    else if(key<a[mid])
        BinarySearch(a,low,mid-1,key);
    
    else
        BinarySearch(a,mid+1,high,key);


}

int main(){
    
    int a[1000],n,key;
    int low=0;
    int high=n-1;
    
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    
    printf("Enter the elements of array in sorted element\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Array elements:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");

    printf("Enter element you want to search\n");
    scanf("%d",&key);

    BinarySearch(a,0,n-1,key);

}