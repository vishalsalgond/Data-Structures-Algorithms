//https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1

/User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& M)
{
    int n = M.size();
    int left = 0, right = n - 1;
    int top = 0, down = n - 1;
    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < right - left; j++) {
            
            //1st rotation
            int temp1 = M[down - j][left];
            M[down - j][left] = M[top][left + j];
            
            //2nd rotation
            int temp2 = M[down][right - j];
            M[down][right - j] = temp1;
            
            //3rd rotation
            int temp3 = M[top + j][right];
            M[top + j][right] = temp2;
            
            //4th rotation
            M[top][left + j] = temp3;
            
        }
        top++; down--;
        left++; right--;
    }
}
