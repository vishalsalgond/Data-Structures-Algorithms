//https://hack.codingblocks.com/app/practice/5/1264/problem


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	vector <ll> primes = {2,3,5,7,11,13,17,19};
	ll size = primes.size();
	ll subsets = 1 << size;

	//inclusion exclusion principle
	while(t--) {
		ll n, ans = 0;
		cin >> n;

		//generate all subsets
		//if length of subset is odd then add else subtract
		for(int i = 1; i < subsets; i++) {
			ll denominator = 1ll;
			int setbits = __builtin_popcount(i);

			ll x = i, pos = 0;
			while(x > 0) {
				if(x&1) {
					denominator *= primes[pos];
				}
				pos++;
				x = x >> 1;
			}

			if(setbits&1) {
				ans += floor(n/denominator);
			} else {
				ans -= floor(n/denominator);
			}
		}

		cout << ans << endl;
	}
}
