class Solution {
public:
    string longestPalindrome(string s) {
        
        int max_len = 0;
        string ans = "";
        int n = s.length();
        
        
        //for odd length of palindrome string   
        // mid elements are actual characters
        //for cases like babad
        
        for(int mid=0; mid<n ; ++mid){
            for(int x=0; mid-x>=0 && mid+x<n ;++x){
                if(s[mid-x]!=s[mid+x]){
                    break;
                }
                else{
                    int len = 2*x + 1;
                    if(len>max_len){
                        max_len = len;
                        ans = s.substr(mid-x,len);
                    }
                    
                }
            }
        }
        
        
        //for even length of palindrome string
        // mid element are the gaps
        // for cases like abba
        
        for (int mid=0; mid<n-1; ++mid){
            for(int x=1; mid-x+1>=0 && mid+x<n; ++x){
                if(s[mid-x+1]!=s[mid+x]){
                    break;
                }
                else{
                    int len = 2*x;
                    if(len>max_len){
                        max_len = len;
                        ans = s.substr(mid-x+1,len);
                    }
                    
                }
            }
        }
        
        return ans;
        
    }
};
