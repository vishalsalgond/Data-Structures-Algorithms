//https://practice.geeksforgeeks.org/problems/check-if-two-line-segments-intersect/0

#include <iostream>
using namespace std;
#define ll long long

ll overlap(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    if(x3 <= max(x1, x2) && x3 >= min(x1, x2) && 
        y3 <= max(y1, y2) && y3 >= min(y1, y2)) 
        return 1;
    return 0;
}

ll orientation(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll temp = ((x1 - x3)*(y2 - y3)) - ((y1 - y3)*(x2 - x3));
    if(temp == 0) 
        return 0;
    else if(temp > 0) 
        return 1;
    return -1;
}

ll foo() {
    ll x1,y1,x2,y2;
    ll x3,y3,x4,y4;
    ll or1, or2, or3, or4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    //check if lines intersect
    // 1 --> clockwise orientation
    // -1 --> anti-clockwise orientation
    or1 = orientation(x1, y1, x2, y2, x3, y3);
    or2 = orientation(x1, y1, x2, y2, x4, y4);
    or3 = orientation(x3, y3, x4, y4, x1, y1);
    or4 = orientation(x3, y3, x4, y4, x2, y2);
    
    
    if(or1 != or2 && or3 != or4) 
        return 1;
        
    if(or1 == 0 && overlap(x1, y1, x2, y2, x3, y3)) return 1;
    
    if(or2 == 0 && overlap(x1, y1, x2, y2, x4, y4)) return 1;
    
    if(or3 == 0 && overlap(x3, y3, x4, y4, x1, y1)) return 1;
    
    if(or4 == 0 && overlap(x3, y3, x4, y4, x2, y2)) return 1;
    
    return 0;
}


int main() {
	int t;
	cin >> t;
	while(t--) {
	    cout << foo() << endl;
	}
	return 0;
}
