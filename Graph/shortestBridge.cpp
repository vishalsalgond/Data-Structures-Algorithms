//https://leetcode.com/problems/shortest-bridge/submissions/


class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int m, n;

    void paint(int i, int j, vector<vector<int>>& mat) {

        mat[i][j] = 2;

        for(int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];

            if(x < n && x >= 0 && y < m && y >= 0) {
                if(mat[x][y] == 1) paint(x, y, mat);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& mat) {
        n = mat.size();
        if(n == 0) return 0;
        m = mat[0].size();

        //paint all with color 2
        for(int i = 0; i < n; i++) {
            int flag = 0;
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    paint(i, j, mat);
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        
        //keep on painting node at depth 1 from current
        //if you found node with color 1, return
        for(int color = 2; ; color++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    
                    if(mat[i][j] == color) {
                        for(int dir = 0; dir < 4; dir++) {
                            int x = i + dx[dir], y = j + dy[dir];
                            if(x < n && x >= 0 && y < m && y >= 0) {
                                if(mat[x][y] == 0) 
                                    mat[x][y] = color + 1;
                                if(mat[x][y] == 1) 
                                    return color - 2;
                            }
                        }
                    }
                    
                }
            }
        }
        return -1;
    }
};
