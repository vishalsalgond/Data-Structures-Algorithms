//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0


#include <bits/stdc++.h>
using namespace std;


void permute(string s, int l, int r, set <string> &st) {
    for(int i = l; i < r; i++) {
        swap(s[l], s[i]);   //while moving to next level
        st.insert(s);
        permute(s, l + 1, r, st);
        swap(s[i], s[l]);  //while backtracking
    }
}

void foo() {
    string s;
    cin >> s;
    int n = s.length();
    if(n == 1){
        cout << s << endl;
    }
    else {
        set <string> st;
        permute(s, 0, n, st);
        for(string ss : st) 
            cout << ss << " ";
        cout << endl;
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    foo();
	}
	return 0;
}
