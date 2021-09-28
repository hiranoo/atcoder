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
  ll a, b, k;
  cin >> a >> b >> k;

  if(a-k >= 0) a -= k;
  else{
    b -= k - a;
    a = 0;
    b = max(0LL, b);
    //b = max(0LL, b);
  }
  cout << a << " " << b << endl;
}