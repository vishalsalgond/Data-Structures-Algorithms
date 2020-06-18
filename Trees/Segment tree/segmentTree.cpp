#include <bits/stdc++.h>
#define ll long long
using namespace std;

int getMid(int start, int end){
    return start + (end-start)/2; 
}

int getSumUtil(int *st, int start, int end, int qs, int qe, int current){
    
    //total overlap
    if(qs <= start && qe >= end) return st[current];
    
    //no overlap
    if(end < qs || start > qe) return 0;
    
    //partial overlap
    int mid = getMid(start, end);
    
    return getSumUtil(st, start, mid, qs, qe, 2*current+1) +
        getSumUtil(st, mid+1, end, qs, qe, 2*current+2);
    
}

// Return sum of elements in range from index qs (quey start)  
// to qe (query end). It mainly uses getSumUtil() 
int getSum(int* st, int n, int qs, int qe){
    
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return -1;  
    }
    
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int start, int end, int *st, int current){
    
    if(start == end){
        st[current] = arr[start];
        return arr[start];
    }
    
    int mid = getMid(start,end);
    
    // If there are more than one elements, then recur for left and  
    // right subtrees and store the sum of values in this node
    st[current] = constructSTUtil(arr, start, mid, st, current*2+1) +
                constructSTUtil(arr, mid+1, end, st, current*2+2);
}

int *constructST(int arr[], int n){
    
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,x)-1;
    
    int *st = new int[max_size];
    
    //Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
    
    //Return the constructed segment tree
    return st;
    
}

int main(){
    
    int size;
    cout << "Enter size of array : " ;
    cin >> size;
    
    int arr[size];
    cout << "Enter the array elements :" << endl;
    
    for(int i=0; i<size; i++) cin >> arr[i];
    
    //Build segment tree from given array
    int *st = constructST(arr,size);
    
    int start, end;
    cout << "Enter start of the range : ";
    cin >> start;
    cout << "Enter end of the range : ";
    cin >> end;
    
    cout<<"\nSum of values in given range = "<< getSum(st, size, start-1, end-1) << endl;
    
    return 0;
}

//Time Complexity 
//O(n) for construction
//O(log(n)) for query

