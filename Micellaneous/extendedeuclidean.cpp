// We will denote the GCD of a and b with g in this section.

// The changes to the original algorithm are very simple. If we recall the algorithm, we can see that the algorithm ends with b=0 and a=g. For these parameters we can easily find coefficients, namely g⋅1+0⋅0=g.

// Starting from these coefficients (x,y)=(1,0), we can go backwards up the recursive calls. All we need to do is to figure out how the coefficients x and y change during the transition from (a,b) to (b,amodb).

// Let us assume we found the coefficients (x1,y1) for (b,amodb):

// b⋅x1+(amodb)⋅y1=g
// and we want to find the pair (x,y) for (a,b):

// a⋅x+b⋅y=g
// We can represent amodb as:

// amodb=a−⌊ab⌋⋅b
// Substituting this expression in the coefficient equation of (x1,y1) gives:

// g=b⋅x1+(amodb)⋅y1=b⋅x1+(a−⌊ab⌋⋅b)⋅y1
// and after rearranging the terms:

// g=a⋅y1+b⋅(x1−y1⋅⌊ab⌋)
// We found the values of x and y:

#include<bits/stdc++.h>
using namespace std;

int32_t gcdExtended(int a, int b, int *x, int *y){
    if(a==0){
        *x = 0;
        *y = 1;
        return b;
    }
    
    int x1,y1;
    int gcd = gcdExtended(b%a,a,&x1,&y1);
    
    *x = y1 - (b/a)*x1;
    *y = x1;
    
    return gcd;
}

int32_t main(){
    
    int a,b,x,y;
    cin >> a >> b;
    cout << gcdExtended(a,b,&x,&y) << endl;
    cout << x << " " << y << endl;
    
    return 0;
}
