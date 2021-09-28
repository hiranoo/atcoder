#include <bits/stdc++.h>
// #include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;
const ll INF = 1e18;


int main() {
  int a, b; cin >> a >> b;
  if(0 < a && b==0) cout << "Gold" << endl;
  else if(0 == a && 0 < b) cout << "Silver" << endl;
  else cout << "Alloy" << endl;
  
}