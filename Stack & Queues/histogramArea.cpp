//https://leetcode.com/problems/largest-rectangle-in-histogram/


class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        stack <int> s;
        
        //if current element is smaller than top of stack
        //then keep popping elements till tcurrent is greater than top
        
        //while popping elements find the total area considering
        //that particular bar as the smallest and  decide 2 boundaries
        
        for(int i = 0; i < n; i++) {
            if(s.empty()) {
                ans = max(ans, a[i] * (i + 1));
                s.push(i);
            } 
            else {
                if(a[s.top()] >= a[i]) {
                    while(!s.empty() && a[s.top()] >= a[i]) {
                        int top = s.top();
                        s.pop();
                        
                        if(s.empty()) {
                            ans = max(ans, a[top] * (i));
                        } else {
                            if(a[top] == a[i]) 
                                ans = max(ans, a[top] * (i - s.top()));
                            else
                                ans = max(ans, a[top] * (i - s.top() - 1));
                        }
                    }
                }
                s.push(i);
            }
        }
        
        //stack will always have elements in increasing order
        
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            
            if(s.empty()) ans = max(ans, a[top] * n);
            else ans = max(ans, a[top] * (n - s.top() - 1));

        }
        
        return ans;
    }
};
