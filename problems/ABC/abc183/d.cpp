#include <bits/stdc++.h>
#include <atcoder/segtree>
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
  ll n, w; cin >> n >> w;
  vector<ll> num(200005, 0);
  rep(i, 0, n-1) {
    int s, t; ll p; cin >> s >> t >> p;
    num[s] += p;
    num[t] -= p;
  }

  ll sum = 0;
  for(auto v : num) {
    sum += v;
    if(sum > w) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}