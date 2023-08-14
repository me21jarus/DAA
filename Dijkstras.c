#include<stdio.h>

int dist[10];
int visited[10];

void dijkstras(int g[10][10],int n,int source){
    int u,v;
    for(int i=0;i<n;i++){
        visited[i]=0;
        dist[i]=g[source][i];
    }
    visited[source]=1;
    for(int ne=0;ne<n;ne++){
        int min=999;
        for(int i=0;i<n;i++){
            if(visited[i]==0 && dist[i]<min){
                min=dist[i];
                u=i;
            }
        }
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(visited[v]==0 && dist[v]>dist[u]+a[u][v]){
                dist[v]=dist[u]+a[u][v];
            }
        }
    }
}

void main(){
    int a[10][10],n,source=0;
    printf("Enter the no of node\n");
    scanf("%d",&n);
    printf("Enter the weighted matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Single Source Shorestest path\n");
    dijkstras(a,n,source);
    for(int i=0;i<n;i++){
    printf("%d->%d=%d\n",source,i,dist[i]);
    }
}