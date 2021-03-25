//https://practice.geeksforgeeks.org/problems/smallest-number-subset1220/1

class Solution{   
public:
    long long findSmallest(long long arr[], int n) {
        
        long long track = 1;
        
        //find the starting point of the first gap
        //using elements 0 to i - 1 we can reach result - 1
        //then we can reach arr[i] + result - 1 using elements 0 to i
        for(int i = 0; i < n && arr[i] <= track; i++) {
            track = track + arr[i];
        }
        
        
        return track;
        
    }
};
