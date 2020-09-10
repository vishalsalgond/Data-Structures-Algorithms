//https://leetcode.com/problems/palindrome-partitioning/


class Solution {
public:
    vector < vector <string> > ans;
    
    int check_palindrome(string s) {
        int n = s.length();
        for(int i = 0; i <= n / 2; i++) {
            if(s[i] != s[n - 1 - i]) return 0;
        }
        return 1;
    }
    
    void recur(string &s, int start, vector <string> curr) {
        
        int n = s.length();
        
        if(start >= n){
            ans.push_back(curr);
            return;
        }
        //check for every substring
        for(int i = 1; i <= n - start; i++) {
            if(check_palindrome(s.substr(start, i))) {
                curr.push_back(s.substr(start, i));
                //check for substring starting from start + i
                recur(s, start + i, curr);
                curr.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector <string> curr;
        if(s.length() == 0) {
            ans.push_back(curr);
            return ans;
        }
        recur(s, 0, curr);
        return ans;
    }
};
