//https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map < map <char, int>, vector <string> > mp;
        vector < vector <string> > result;
        
        if(strs.size() == 0) 
            return result;
        
        for(int i = 0; i < strs.size(); i++){
            map < char, int> tmp;
            for(int j = 0; j < strs[i].size(); j++){
                tmp[strs[i][j]]++;
            }
            mp[tmp].push_back(strs[i]);
        }
        
        
        for(auto m : mp){
            result.push_back(m.second);
        }
        
        return result;
    }
};
