//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue <pair<int,int>> Q;
        
        int m = grid.size();
        int n = grid[0].size();
        int minute = -1, fresh = 0;
        
        //find positions of all rotten oranges
        //and add them to queue
        for (int i = 0; i < m; i++) { 

            for (int j = 0; j < n; j++){
                
                if(grid[i][j]==2){
                    Q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
                
            } 
        }
        
        if(fresh == 0) return 0;
        
        //this acts as a marker
        Q.push({-1,-1});
        
        while(!Q.empty()){
            
            int i = Q.front().first;
            int j = Q.front().second;
            
            Q.pop();
            
            //end of one iteration
            if(i ==-1 && j ==-1){
                minute++;
                if(!Q.empty()){
                    Q.push({-1,-1});
                }
            }
            //add adjacent fresh oranges to queue
            else{
                if(j-1>=0 && grid[i][j-1]==1){
                    Q.push({i,j-1});
                    grid[i][j-1] = 2;
                    fresh--;
                }
                if(j+1<n && grid[i][j+1]==1){
                    Q.push({i,j+1});
                    grid[i][j+1] = 2;
                    fresh--;
                }
                if(i-1>=0 && grid[i-1][j]==1){
                    Q.push({i-1,j});
                    grid[i-1][j] = 2;
                    fresh--;
                }
                if(i+1<m && grid[i+1][j]==1){
                    Q.push({i+1,j});
                    grid[i+1][j] = 2;
                    fresh--;
                }
                
            }
        }
        
        return fresh ? -1 : minute;

    }
};
