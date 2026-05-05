/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/
void mergeSortHelper(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void mergeSort(int arr[], int size) {
    // TODO: implement merge sort
    //(void)arr;
    //(void)size;
    if (size<2) return;
    mergeSortHelper(arr, 0, size-1);

}

void mergeSortHelper(int arr[], int left, int right){
    if (left>=right) return;
    if (left<right){
        int mid = left + (right - left)/2; //?
        mergeSortHelper(arr,left, mid);
        mergeSortHelper(arr, mid+1, right);
        merge(arr, left, mid, right);
    }

}

void merge(int arr[], int left, int mid, int right){
     int i,j,k;
     int L1 = mid - left+1;
     int R1 = right - mid;

     int L[L1], R[R1];
     for (i=0;i<L1;i++){
        L[i] = arr[left+i];
     }
     
     for (j=0;j<R1;j++){
        R[j] = arr[mid+1+j];
     }

     i=0; j=0; k=left;
     while (i<L1 && j<R1){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
     }
     while (i<L1){
        arr[k] = L[i];
        i++; k++;
     }
     
     while (j<R1){
        arr[k] = R[j];
        j++; k++;
     }
}

