#include<stdio.h>

int p[10];

int parent(int x){
    while(x!=p[x]){
        x=p[x];
    }
    return x;
}
void kruskals(int a[10][10],int n){
    int u,v;
    for(int i=0;i<n;i++) p[i]=i;
    int sum=0;
    int ne=0;
    while(ne<n-1){
        int min=999;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]<min){
                    min=a[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        if(parent(u)!=parent(v)){
            printf("connect %d->%d=%d",u,v,a[u][v]);
            sum=sum+a[u][v];
            p[v]=u;
            ne++;
        }
        a[v][u]=999;
        a[u][v]=999;
    }
    printf("Total cost = %d\n",sum);
}

void main(){
    int a[10][10],n;
    printf("Enter the no of node\n");
    scanf("%d",&n);
    printf("Enter the weighted matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Minimum spanning tree\n");
    kruskals(a,n);
}