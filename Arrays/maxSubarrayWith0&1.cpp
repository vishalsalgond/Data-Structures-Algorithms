//https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

int maxLen(int arr[], int n)
{
    map<int, int> mp;
    
    for(int i = 0; i <= n; i++) {
        if(arr[i] == 0) 
            arr[i] = -1;
    }
    
    int c_sum = 0 , ans = 0;
    mp[0] = 0;
    for(int i = 0; i < n; i++) {
        c_sum += arr[i];
        if(c_sum != 0 && mp[c_sum] == 0) {
            mp[c_sum] = i + 1;
        }
        ans = max(ans, i + 1 - mp[c_sum]);
    }
    
    return ans;
    
}
