//https://practice.geeksforgeeks.org/problems/activity-selection/0


#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second < b.second;
}

int foo() {
    int n; cin >> n;
    vector <pair <int, int>> activity(n);
    
    for(int i = 0; i < n; i++) 
        cin >> activity[i].first;
    
    
    for(int i = 0; i < n; i++) 
        cin >> activity[i].second;
    
    sort(activity.begin(), activity.end(), comp);
    
    int ans = 1, prev = activity[0].second;
    
    for(int i = 1; i < n; i++) {
        if(activity[i].first >= prev) {
            ans ++;
            prev = activity[i].second;
        }
    }
    
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    cout << foo() << endl;
	}
	return 0;
}
