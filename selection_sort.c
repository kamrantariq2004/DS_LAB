#include<stdio.h>
void printArray(int * A,int n){
    for (int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

}
void selection_sort(int *A,int n){
    int indexOfMin;
    for(int i =0;i<n-1;i++){
        indexOfMin = i;
        for(int j =i+1;j<n;j++){
            if(A[j]<A[indexOfMin]){
                indexOfMin = j; //indexOfMin will store index of the smallest element 
            }
        }
        //swap A[i] && A[indexOfMin]
        int temp=A[i];
        A[i]=A[indexOfMin];
        A[indexOfMin]=temp;
    }


}
int main(){
    int A[] = {12,34,1,3,2,23};
    int n =6;
    printArray(A,n);
    selection_sort(A,n);
    printArray(A,n);

}