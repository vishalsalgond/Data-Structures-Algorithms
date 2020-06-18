#https://leetcode.com/problems/break-a-palindrome/

class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        
        n = len(palindrome)
        ans = ""
        if(n==1):
            return ans
        
        else:
            
            if(n%2==1):
                for j in range(n//2+1):
                    if(palindrome[j]!='a'):
                        ans += 'a'
                        ans += palindrome[j+1:]
                        break
                    ans += palindrome[j]
            else:
                for j in range(n//2):
                    if(palindrome[j]!='a'):
                        ans += 'a'
                        ans += palindrome[j+1:]
                        break
                    ans += palindrome[j]
                    
    
            if(len(ans)<n or ans[::-1] == ans):
                ans = ''
                ans += palindrome[:-1]
                ans += 'b'
                return ans

                            
            return ans
                
                        
            
