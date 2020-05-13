#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;++i) cin >> nums[i];
        int max_ending_here = nums[0], max_so_far = nums[0];
        for(int i=1;i<n;++i)
            max_ending_here = max(max_ending_here+nums[i], nums[i]);
            max_so_far = max(max_ending_here, max_so_far);
        cout << max_so_far << endl;
    }
    return 0;
}

//O(n)
