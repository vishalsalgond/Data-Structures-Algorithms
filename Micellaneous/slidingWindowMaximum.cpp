//https://leetcode.com/problems/sliding-window-maximum/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        vector <int> ans;
        deque <int> Q(k);

        for(int i = 0; i < k; i++) {
            while(!Q.empty() && a[i] >= a[Q.back()]) 
                Q.pop_back();

            Q.push_back(i);
        }
        ans.push_back(a[Q.front()]);
        
        for(int i = k; i < n; i++) {

            //Remove elements from previous window
            while(!Q.empty() && Q.front() <= i - k)
                Q.pop_front();
            
            //Remove all elements smaller than curr
            while(!Q.empty() && a[i] >= a[Q.back()])
                Q.pop_back();
            
            //push the index
            Q.push_back(i);
            
            //store the ans
            ans.push_back(a[Q.front()]);
        }
        
        return ans;
    }
};
