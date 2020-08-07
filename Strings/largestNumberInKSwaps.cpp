//https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps/0


#include <bits/stdc++.h>
using namespace std;

string maxn;

void recur(string s, int k, int start, int end){
    if(k == 0)
        return;
    
    char curr_max = s[start];
    
    for(int i = start; i < end; i++) {
        if(s[i] > curr_max) {
            curr_max = s[i];
        }
    }
    
    if(curr_max != s[start]) k--;
    
    
    for(int i = start; i < end; i++) {
        
        if(s[i] == curr_max) {
            swap(s[start], s[i]);
            
            if(s > maxn) 
                maxn = s; 
                
            recur(s, k, start + 1, end);
            
            //backtracking
            swap(s[start], s[i]);
        }
    }
    
}

string foo() {
    int k; cin >> k;
    string s; cin >> s;
    int n = s.length();
    
    if(n == 1) 
        return s;
        
    maxn = "0";
    
    recur(s,k,0,n);
    
    return maxn;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    cout << foo() << endl;
	}
	return 0;
}
