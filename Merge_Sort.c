#include<stdio.h>

void printArray(int * A,int n){
    for (int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

}
void merge(int A[],int mid,int low,int high){
    int i,j,k,B[100];
    i =low;
    j=mid+1;
    k=low;
    while(i<=mid &&j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
            k++;
        }else{
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        i++;
        k++;
    }
    while(j<=high){
        B[k]=A[j];
        j++;
        k++;

    }
    for(int i =low;i<=high;i++){
        A[i]=B[i];
    }
}
void Merge_sort(int A[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        Merge_sort(A,low,mid);
        Merge_sort(A,mid+1,high);
        merge(A,mid,low,high);

    }

}
int main(){
    int A[] = {12,34,1,3,2,23};
    int n =6;
    printArray(A,n);
    Merge_sort(A,0,5);
    printf("\nfinal sorted array\n");
    printArray(A,n);

}