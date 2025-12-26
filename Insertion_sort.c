#include<stdio.h>

void printArray(int * A,int n){
    for (int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

}

void insertionSort(int *A,int n){
    int key,j;

    for(int i =1;i<n;i++){ //passes
        key = A[i];
        j = i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j]; //shifting the elements
            j--;
        }
        A[j+1]=key; // putting the key or selected element at suitable place
    }
}
int main(){
    int A[] = {12,34,1,3,2,23};
    int n =6;
    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);
}