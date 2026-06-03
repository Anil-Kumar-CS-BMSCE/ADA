#include<stdio.h>

void Merg(int arr[], int x, int m, int r){
    int n1=m-x+1, n2=r-m;

    int L[n1], R[n2];

    for(int i=0; i<n1; i++){
        L[i]=arr[x+i];
    }

    for(int j=0; j<n2; j++){
        R[j]=arr[m+1+j];
    }

    int i=0, j=0, k=x;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }else{
            arr[k++]=R[j++];
        }
    }

    while(i<n1){
        arr[k++]=L[i++];
    }

    while(j<n2){
        arr[k++]=R[j++];
    }
}

void MergSort(int arr[], int x, int r){
    if(x < r){
        int m=(x+r)/2;
        MergSort(arr, x, m);
        MergSort(arr, m+1, r);
        Merg(arr, x, m, r);
    }
}

int main(){
    int n;

    printf("Enter the Number of Elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the Array of Elements : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    MergSort(arr, 0, n-1);

    printf("Sorted List : ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}