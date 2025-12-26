#include<stdio.h>
void printArray(int * A,int n){
    for (int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

}
int Partition(int A[],int low,int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;

    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            int temp = A[j];
            A[j]=A[i];
            A[i]=temp;
        }
    }while(i<j);
    //swap A[low]  & A[j]
    int temp = A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;

}
void Quick_sort(int A[],int low,int high){
    int PartitionIndex; // index of pivot after partition 

    if(low<high){
        PartitionIndex = Partition(A,low,high);

        printArray(A,6); // to see the partitions

        Quick_sort(A,low,PartitionIndex-1); //sorts left subarray

        Quick_sort(A,PartitionIndex+1,high); //sorts right subarray
    }
}
int main(){
    int A[] = {12,34,1,3,2,23};
    int n =6;
    printArray(A,n);
    Quick_sort(A,0,n-1);
    printf("\nfinal sorted array\n");
    printArray(A,n);

}