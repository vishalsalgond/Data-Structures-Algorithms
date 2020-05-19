//https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        
        if(s.length()&1){
	        return false;
	    }
	    stack <char> stack;
	    for(char x : s){
	        if(x=='(' || x=='[' || x=='{') stack.push(x);
	        else{
	            if(x==')'){
	                if(!stack.empty()){
	                    if(stack.top()=='(') stack.pop();
    	                else return false;
	                }
	                else return false;
	            }
	            
	            if(x==']'){
	                if(!stack.empty()){
	                    if(stack.top()=='[') stack.pop();
    	                else return false;
	                }
	                else return false;
	            }
	            
	            if(x=='}'){
	                if(!stack.empty()){
	                    if(stack.top()=='{') stack.pop();
    	                else return false;
	                }
	                else return false;
	            }
	        }
	    }
	    if(stack.empty()) return true;
	    else return false;
    }
};
