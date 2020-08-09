#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end) {
    int pIndex = start;
    int pivot = arr[end];

    for(int index = start; index <= end - 1; index++) {
      if(arr[index] < pivot) {
        swap(arr[pIndex], arr[index]);
        pIndex++;
      }
    }
    
    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void quickSort(int arr[], int low, int high) {

    if(low < high) {

      int pIndex = partition(arr, low, high);

      quickSort(arr, low, pIndex - 1);
      quickSort(arr, pIndex + 1, high);
    }
}

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver Code 
int main()  
{  
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
     
    printArray(arr, n);  
    return 0;  
}  
