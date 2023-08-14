#include<stdio.h>

int max(int x,int y){
    if(x>y) return x;
    else return y;
}

void knapsack(int w[],int p[],int n,int m){
    int v[10][10];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){v[i][j]==0;}
            else if(j<w[i]){v[i][j]=v[i-1][j];}
            else {v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);}
        }
    }
    printf("The max profit = %d\n",v[n][m]);
    printf("Items selected\n");
    int max=v[n][m];
    for(int i=n;i>0&&max>0;i--){
        if(v[i][m]!=v[i-1][m]){
            printf("items %d->profit %d\n",w[i],p[i]);
            m=m-w[i];
            max=max-p[i];
        }
    }
}

void main(){
    int w[10],p[10],n,m;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    printf("Enter the capacity\n");
    scanf("%d",&m);
    printf("Enter the weight matrix\n");
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    printf("Enter the profit matrix\n");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    knapsack(w,p,n,m);
}