//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    unordered_map <char , int> lookup;
        queue <char> store;
	    cin >> n;
	    while(n--){
	        char ch;
	        cin >> ch;
	        lookup[ch]++;
	        store.push(ch);
	        while(!store.empty() && lookup[store.front()]!=1){
	            store.pop();
	        }
	        if(store.empty()) cout << -1 << " ";
	        else cout << store.front() << " ";
	    }
	    cout << endl;
	}
	return 0;
}
