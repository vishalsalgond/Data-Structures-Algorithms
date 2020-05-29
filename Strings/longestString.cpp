https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        if(n==1 || n==0){
            return n;
        }
        
        map <char, int > lookup;
        int ptr1 = 0, ptr2 = 0, max_len=0;
        
        while(ptr2 < n){
            if(lookup[s[ptr2]]== 0){
                lookup[s[ptr2]]++;
                max_len = max(max_len, ptr2 - ptr1 + 1);
                ptr2++;
            }
            else{
                lookup[s[ptr1]]--;
                ptr1++;
                max_len = max(max_len, ptr2 - ptr1 + 1);
            }
        }
        
        return max_len;
        
    }
};
