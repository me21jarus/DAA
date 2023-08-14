#include<stdio.h>

void warshalls(int a[10][10],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=a[i][j] || (a[i][k]&& a[k][j]);
            }
        }
    }
}

void main(){
    int a[10][10],n;
    printf("Enter the number of node\n");
    scanf("%d",&n);
    printf("Enter Adjacent Matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    warshalls(a,n);
    printf("Transisitve Closure\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}