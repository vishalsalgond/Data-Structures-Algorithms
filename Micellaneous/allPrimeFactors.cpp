#include <bits/stdc++.h>
using namespace std;

const int size = 1e4 + 5;
vector <int> sieve(size, 1);
vector <int> primes;

void primeSieve() {
    sieve[0] = sieve[1] = 0;
    
    for(int i = 4; i < size; i += 2) {
        sieve[i] = 0;
    }

    for(int i = 3; i < size; i += 2) {
        for(int j = i * i; j < size; j += i) {
            sieve[j] = 1;
        }
    }

    for(int i = 0; i < size; i++) {
        if(sieve[i] == 1)
            primes.push_back(i);
    }
}

vector <int> computeFactors(int n) {
    vector <int> arr;;

    int i = 0;
    int p = primes[0];

    while(p * p <= n) {
        while(n % p == 0) {
            n /= p;
            arr.push_back(p);
        }
        i++;
        p = primes[i];
    }

    if(n != 1) arr.push_back(n);

    return arr;

}


int main() {
    int t;
    cin >> t;
    primeSieve();
    while(t--) {
        int n;
        cin >> n;
        vector <int> ans = computeFactors(n);
        for(int x : ans) 
            cout << x << " ";
        cout << endl;
    }
}
