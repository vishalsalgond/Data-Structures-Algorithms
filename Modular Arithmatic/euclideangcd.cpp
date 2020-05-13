#include<bits/stdc++.h>
using namespace std;

int32_t gcd(int a, int b){
    if(a==0) return b;
    else return gcd(b%a,a);
}

int32_t main(){
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
}

//O(log(min(a,b)))
