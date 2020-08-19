//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

void solve(int m[MAX][MAX], vector <string> &ans, int &n, string curr, int row, int col) {
    if(m[row][col] == 0) return;
    
    //when we reach destination
    if(row == n - 1 && col == n - 1) {
        ans.push_back(curr);
        return;
    }
    
    //so that we do not come back to this cell
    m[row][col] = 0;
    
    //check for all directions
    if(row + 1 < n && m[row + 1][col] == 1) {
        solve(m, ans, n, curr + 'D', row + 1, col);
        m[row + 1][col] = 1;
    }
    
    if(row - 1 >= 0 && m[row - 1][col] == 1) {
        solve(m, ans, n, curr + 'U', row - 1, col);
        m[row - 1][col] = 1;
    }
    
    if(col + 1 < n && m[row][col + 1] == 1) {
        solve(m, ans, n, curr + 'R', row, col + 1);
        m[row][col + 1] = 1;
    }
    
    if(col - 1 >= 0 && m[row][col - 1] == 1) {
        solve(m, ans, n, curr + 'L', row, col - 1);
        m[row][col - 1] = 1;
    }
    
    
}

vector<string> printPath(int m[MAX][MAX], int n) {
    string curr = "";
    vector <string> ans;
    solve(m, ans, n, curr, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
