//https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0


#include <bits/stdc++.h>
using namespace std;

int foo() {
    string s;
    cin >> s;
    unordered_map <char, pair<int,int> > mp;
    int n = s.length(), i = 0;
    int ptr = 0, length = 0;
    int ans = INT_MIN;
    
    while(i < n) {
        mp[s[i]].second++;
        if(mp[s[i]].second > 1) {
            while(ptr <= mp[s[i]].first) {
                mp[s[ptr]].second--;
                ptr++;
            }
        }
        mp[s[i]].first = i;
        length = i - ptr + 1;
        ans = max(ans, length);
        i++;
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
