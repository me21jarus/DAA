#include<stdio.h>

int a[10][10],n;
int visited[10];

void BFS(int start_node){
    int u,v;
    int q[10],r=-1,f=0;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    visited[start_node]=1;
    q[++r]=start_node;
    while(r>=f){
        u=q[f++];
        printf("%d\t",u);
        for(v=0;v<n;v++){
            if(visited[v]==0 && a[u][v]==1){
                q[++r]=v;
                visited[v]=1;
            }
        }
    }
}

void main(){
    int start_node=0;
    printf("Enter no of nodes\n");
    scanf("%d",&n);
    printf("Enter the matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("BFS Traversal\n");
    BFS(start_node);
}