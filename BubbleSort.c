#include<stdio.h>

void printArray(int * A,int n){
    for (int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

}

void bubbleSort(int *A,int n){
    int temp;
    for(int i =0;i<n-1;i++){ //for number of passes
        for(int j=0;j<n-i-1;j++){//for comparisons per pass,per pass comparisons decrease obviously
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}
void bubbleSort_efficient(int *B,int n){ // decreases time complexity for sorted arrays and the same as above for unsorted ones
    int temp;
    int isSorted =0;
    for(int i =0;i<n-1;i++){ //for number of passes
        printf("working on pass %d \n",i+1);
        isSorted =1;



        for(int j=0;j<n-i-1;j++){//for comparisons per pass,per pass comparisons decrease obviously
            if(B[j]>B[j+1]){
                int temp = B[j];
                B[j]=B[j+1];
                B[j+1]=temp;
                isSorted=0; //bcz if the array enters this condition then it is not sorted already
            }

        }
        if(isSorted){
            return;
        }
    }
}




int main(){
    int A[] = {12,34,1,3,2,23};
    int B[]= {1,2,3,12,23,34};//sorted array already
    int n = 6; // length of array
    printArray(A,n);
    bubbleSort(A,n);
    printArray(A,n);
    bubbleSort_efficient(B,n);
    printArray(B,n);

    return 0;
}