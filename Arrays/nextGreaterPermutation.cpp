//https://practice.geeksforgeeks.org/problems/next-permutation/0

#include <bits/stdc++.h>
using namespace std;

void foo() {
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    
    int last = a[n-1];
    int bk = -1;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i - 1] < a[i]) {
            bk = i - 1;
            break;
        }
    }
    
    if(bk != -1) {
        int next_gr, index;
        int temp = a[bk], diff = INT_MAX;
        for(int i = bk + 1; i < n; i++) {
            if(a[i] - temp > 0 && a[i] - temp < diff) {
                diff = a[i] - temp;
                index = i;
            }
        }
        temp = a[index];
        a[index] = a[bk];
        a[bk] = temp;
        
    }
    
    sort(a.begin() + bk + 1, a.end());
    
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    puts("");
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    foo();
	}
	return 0;
}
