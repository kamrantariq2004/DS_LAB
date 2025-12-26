#include<stdio.h>
#define max 10
int main(){
    int graph[max][max] = {0};
    int edges,vertices;
    int u,v;

    printf("Enter the number of vertices\n");
    scanf("%d",&vertices);

    printf("Enter the number of edges\n");
    scanf("%d",&edges);

    for(int i =0;i<edges;i++){
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;
    }

    printf("adjacency matrix:\n");
    for(int i = 0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}