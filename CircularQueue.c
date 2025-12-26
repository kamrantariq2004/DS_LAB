#include<stdio.h>
#include<stdlib.h>
struct Circularqueue{
    int size;
    int front;
    int rear;
    int *arr;
};
int isEmpty(struct Circularqueue *q){
    if(q->front == q->rear){
        return 1;
    }
    else return 0;
}
int isFull(struct Circularqueue *q){
    if((q->rear+1)%q->size == q->front){
        return 1;
    }else{
        return 0;
    }
}
void Enqueue(struct Circularqueue *q,int val){
    if(isFull(q)){
        printf("Queue overflow");
    }else{
        q->rear = (q->rear+1)%q->size; //circular queue increment so for last increment in array it will go back to 0th index
        q->arr[q->rear]=val;
        printf("Enqueued element : %d\n",val);
    }
}
int Dequeue(struct Circularqueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue underflow");
    }else{
        q->front = (q->front+1)%q->size;
        a = q->arr[q->front];
    }
    return a;
}

int main(){
    struct Circularqueue q;
    q.size = 4;
    q.front=q.rear=0; //incase of circular queue otherwise will get problem in isFull()
    q.arr = (int*)malloc(q.size*sizeof(int));

    //enqueue some elements
    Enqueue(&q,90);
    Enqueue(&q,78);
    Enqueue(&q,56); //can only enqueue 3 elements bcz we initialize front & rear from 0

    printf("\ndequeuing element %d: ",Dequeue(&q));
    printf("\ndequeuing element %d: ",Dequeue(&q));
    printf("\ndequeuing element %d: \n",Dequeue(&q));
    Enqueue(&q,34); //possible only bcz of circular queue
    Enqueue(&q,0);
    printf("\ndequeuing element %d: ",Dequeue(&q));
    printf("\ndequeuing element %d: ",Dequeue(&q));


    if(isFull(&q)){
        printf("\nQueue is full");
    }
    if(isEmpty(&q)){
        printf("\nQueue is empty");
    }

}