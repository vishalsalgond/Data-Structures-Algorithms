#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
//========================================

void siftDown(int currIdx, int endIdx, vector <int> &arr) {

  int firstChild = 2 * currIdx + 1;
  int secondChild = 2 * currIdx + 2;
  int changeIdx;

  if(currIdx > endIdx || firstChild > endIdx) 
    return;

  //if second child exists
  if(secondChild <= endIdx) {
    if(arr[firstChild] > arr[secondChild]) 
      changeIdx = firstChild;
    else changeIdx = secondChild;
  }
  else {
    changeIdx = firstChild;
  }

  if(arr[changeIdx] > arr[currIdx]) {
    swap(arr[changeIdx], arr[currIdx]);
    siftDown(changeIdx, endIdx, arr);
  } 
  else return;
}


void buildMaxHeap(vector <int> &arr) {
  int lastParent = arr.size() / 2;

  for(int currIdx = lastParent; currIdx >= 0; currIdx--) 
    siftDown(currIdx, arr.size() - 1, arr);

}

void heapsort(vector <int> &arr) {
  buildMaxHeap(arr);
  
  for(int endIdx = arr.size() - 1; endIdx > 0; endIdx--) {
    swap(arr[0], arr[endIdx]);
    siftDown(0, endIdx - 1, arr);
  }
}



int main() {
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
    int i;
    vector <int> arr = {1, 5, 3, 167, 23, 56, 63, 7};
    heapsort(arr);
    fo(i, (int)arr.size()) cout << arr[i] << " ";
    cout << endl;
}
