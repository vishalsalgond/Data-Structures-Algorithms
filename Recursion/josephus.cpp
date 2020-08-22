//https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0


#include <bits/stdc++.h>
using namespace std;

int josephus(int n , int k) {
    if(n == 1) 
        return 1;
    //take k - 1 steps from current position
    //kill the person at curr + k - 1 pos
    //move to next person
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    cout << josephus(n, k) << endl;
	}
	    
	return 0;
}
