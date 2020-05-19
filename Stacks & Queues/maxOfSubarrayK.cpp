//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >>k;
	    
	    // Create a Double Ended Queue, q that will store indexes of array elements 
    	    // The queue will store indexes of useful elements in every window and it will 
    	    // maintain decreasing order of values from front to rear in q, i.e., 
    	    // a[q.front[]] to a[q.rear()] are sorted in decreasing order 
    	
	    vector <int> a(n);
	    deque <int> q;
	    for(int i=0;i<n;i++) cin >> a[i];
	    int i;
	    //manually find max element for first k elements
	    for(i=0;i<k;i++){
	        //remove all elements smaller than curr
	        while(!q.empty() && a[i]>=a[q.back()]){
	            q.pop_back();
	        }
	        q.push_back(i);
	    }
	    for(;i<n;i++){
	        //q.front will contain the max index of previous window
	        cout << a[q.front()] << " ";
	        
	        //remove all elements of previous window
	        while(!q.empty() && q.front()<=i-k) {
	            q.pop_front();
	            
	        }
	        //remove all elements that are smaller than current
	        while(!q.empty() && a[i]>=a[q.back()]){
	            q.pop_back();
	            
	        }
	        //add index of current element;
	        q.push_back(i);
	    }
	    //print max element of last window
	    cout << a[q.front()] << endl;
	}
	
	return 0;
}
