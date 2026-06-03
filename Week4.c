#include<stdio.h>
#include<time.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void QuickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr, low, high);

        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
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

    clock_t start, end;

    start=clock();

    QuickSort(arr, 0, n-1);

    end=clock();

    printf("Sorted List : ");
    for(int i=0;  i<n; i++){
        printf("%d ", arr[i]);
    }

    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Time Taken : %f", time_taken);
}