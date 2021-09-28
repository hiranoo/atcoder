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
const ll INF = 1e16;

void chmax(ll &a, ll b) {a = max(a, b);}
void chmin(ll &a, ll b) {a = min(a, b);}

int main() {
  int n; cin >> n;
  map<pair<string, string>, int> mp;
  rep(i, 0, n-1) {
    string s, t; cin >> s >> t;
    mp[make_pair(s, t)]++;
  }
  bool same = false;
  for(auto itr : mp) if(itr.second >= 2) same=true;
  if(same) cout << "Yes" << endl;
  else cout << "No" << endl;
}