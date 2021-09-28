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

int decode(string &a) {
  int ans = 0;
  for(auto s : a) if(s != ':') {
    ans *= 10;
    ans += (int)(s - '0');
  }
  return ans;
}

int _main() {
  int n; cin >> n;
  if(n == 0) return -1;
  vector<pii> train(n);
  rep(i, 0, n-1) {
    string a, b; cin >> a >> b;
    train[i] = pii(decode(a), decode(b));
  }
  map<int, int> mp;
  for(auto t : train) mp[t.first] = mp[t.second] = 1;
  int cnt = 0;
  for(auto itr = mp.begin(); itr != mp.end(); itr++) itr->second = cnt++;

  vector<ll> sum(20000, 0);
  for(auto t : train) {
    sum[mp[t.first]]++;
    sum[mp[t.second]]--;
  }

  ll ans = 0;
  ll res = 0;
  for(auto s : sum) {
    res += s;
    ans = max(ans, res);
  }
  cout << ans << endl;

  return 0;
}

int main() {
  while(1) {
    if(_main() == -1) break;
  }
}