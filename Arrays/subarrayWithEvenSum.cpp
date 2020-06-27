//https://practice.geeksforgeeks.org/problems/find-the-number-of-sub-arrays-having-even-sum/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector <int> a(n);
	    
	    for(int i=0;i<n;i++) cin >> a[i];
	    
	    unordered_map <int, pair<int,int> > lookup;
	    int sum=0,odd=0,ans=0;
	    
	    for(int i=0;i<n;i++){
	        sum += a[i];
	        if(sum&1) odd++;
	        else lookup[i].first++;
	        lookup[i].second = odd;
	    }
	    
	    for(int i=0;i<n;i++){
	        if(lookup[i].first==1){
	            ans += (i+1)-lookup[i].second;
	        }
	        else{
	            ans += lookup[i].second-1;
	        }
	        
	    }
	    cout << ans << endl;
	    
	}
	return 0;
}
