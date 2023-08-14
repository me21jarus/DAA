#include<stdio.h>
#include<stdlib.h>

int b[10];
int count=0;

int place(int row,int col){
    for(int i=1;i<row;i++){
        if(b[i]==col || (abs(b[i]-col==abs(row-i)))){
            return 0;
        }
    }
    return 1;
}

void display(int n){
    printf("Solution no %d\n",++count);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i]==j) printf("Q\t");
            else printf("*\t");
        }
        printf("\n");
    }
}

void Nqueens(int row,int n){
    for(int col=1;col<=n;col++){
        if(place(row,col)){
            b[row]=col;
            if(row==n) display(n);
            else Nqueens(row+1,n);
        }
    }
}

void main(){
       int n;
    printf("Enter the number of queen to be placed \n");
    scanf("%d",&n);
    if(n==2 || n==3)  printf("Solution doesnt exist \n");
    else              Nqueens(1,n);
    printf("\n total number of Solution =%d", count);
}