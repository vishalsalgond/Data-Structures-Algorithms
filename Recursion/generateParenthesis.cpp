//https://leetcode.com/problems/generate-parentheses/


class Solution {
public:
    int length;
    void backtrack(int open, int close, vector <string> &ans, string curr) {
        if(curr.length() == length) {
            ans.push_back(curr);
            return;
        }
        
        if(open > 0)
            backtrack(open - 1, close, ans, curr + "(");
        
        if(close - open > 0)
            backtrack(open, close - 1, ans, curr + ")");
    }
    
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        vector <string> ans = {};
        length = 2 * n;
        backtrack(open, close, ans, "");
        return ans;
    }
};
