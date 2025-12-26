#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};
int isFull(struct queue *q){
    if(q->rear==q->size-1){
        return 1;
    }else{
        return 0;
    }

}
int isEmpty(struct queue *q){
    if(q->rear==q->front){
        return 1;
    }else{
        return 0;
    }

}
void Enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("Queue is full");
    }else{
        q->rear++; //q->rear = q->rear+1
        q->arr[q->rear]=val;
        printf("Enqueued element : %d\n",val);
    }
}
int Dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is Empty");
    }else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 400;
    q.front=q.rear=0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    //BFS implementation

    int node;
    int i =0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7]={ //adjacency matrix for graph
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d\n",i);
    visited[i]=1;
    Enqueue(&q,i);
    while(!isEmpty(&q)){
        int node = Dequeue(&q);
        for(int j =0;j<7;j++){
            if(a[node][j]== 1  && visited[j]==0){
                printf("%d\t",j);
                visited[j]=1;
                Enqueue(&q,j);
            }
        }
    }

    return 0;

}