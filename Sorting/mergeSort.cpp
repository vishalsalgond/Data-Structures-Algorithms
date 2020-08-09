#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {

  int leftStart = left, leftEnd = mid;
  int rightStart = mid + 1, rightEnd = right;

  int l = leftStart, r = rightStart;
  int temp[rightEnd - leftStart + 1], index = 0;

  while(leftStart <= leftEnd && rightStart <= rightEnd) {
    if(arr[leftStart] <= arr[rightStart]) 
      temp[index++] = arr[leftStart++];
    else 
      temp[index++] = arr[rightStart++];
  }

  
  while(leftStart <= leftEnd) 
    temp[index++] = arr[leftStart++];
  
  while(rightStart <= rightEnd) 
    temp[index++] = arr[rightStart++];

  index = 0;
  for(int i = left; i <= right; i++) 
    arr[i] = temp[index++];
  
}

void mergeSort(int arr[], int left, int right) {
  if(left < right) {
    
    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
  
}

void foo() {
  int n; cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if(n > 1)
    mergeSort(arr, 0, n - 1);
  
  for(int i = 0; i < n; i++) 
    cout << arr[i] << " ";
  
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
  int t;
  cin >> t;
  while(t--) foo();

  return 0;
}
