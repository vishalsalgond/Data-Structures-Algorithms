//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

#include <bits/stdc++.h>
using namespace std;

// 1) Sort the activities according to their finishing time.
// 2) Select the first activity from the sorted array and print it.
// Do following for remaining activities in the sorted array.
// If the start time of this activity is greater than or 
// equal to the finish time of previously selected activity t
// hen select this activity and print it

bool comp(pair <int, int> &a, pair <int, int> &b){
    return a.second < b.second;
}

void foo(){
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    vector< pair <int,int> > mp(n);
    map<pair<int,int>, int > lookup;
    for(int i = 0; i < n; i++) {
        mp[i] = {a[i], b[i]};
        lookup[mp[i]] = i+1;
    }
    int prev = 0;
    sort(mp.begin(), mp.end(), comp);
    for(int i = 0; i < n; i++) {
        if(mp[i].first >= prev){
            cout << lookup[mp[i]] << " ";
            prev = mp[i].second;
        }
    }
    cout << endl;
    
}

int main() {
	int t;
	cin >>  t;
	while(t--) {
	    foo();
	}
}
