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

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n, k; ll p; cin >> n >> k >> p;
  vector<ll> a(n);
  rep(i, 0, n-1) cin >> a[i];

  vector<vector<ll>> sum1(k+1), sum2(k+1);

  int m = n/2;
  rep(s, 0, (1<<m) - 1) {
    ll res = 0;
    int cnt = 0;
    rep(i, 0, m-1) if(s>>i & 1) cnt++, res += a[i];
    if(cnt <= k) sum1[cnt].push_back(res);
  }

  rep(s, 0, (1<<n-m) - 1) {
    ll res = 0;
    int cnt = 0;
    rep(i, 0, n-m-1) if(s>>i & 1) cnt++, res += a[i+m];
    if(cnt <= k) sum2[cnt].push_back(res);
  }

  rep(i, 0, k) sort(all(sum1[i])), sort(all(sum2[i]));

  ll ans = 0;
  rep(i, 0, k) for(auto v : sum1[i]) ans += max(0, (int)(upper_bound(all(sum2[k-i]), p-v) - sum2[k-i].begin()));
  cout << ans << endl;
}

// int main() {
//   int n, k; ll p; cin >> n >> k >> p;
//   vector<ll> a(n);
//   rep(i, 0, n-1) cin >> a[i];

//   vector<map<ll, int>> m1(n+1), m2(n+1); // i個選んだときの合計額の場合の数

//   rep(s, 0, (1<<(n/2)) - 1) {
//     ll res = 0;
//     int cnt = 0;
//     rep(i, 0, n/2 - 1) if(s>>i & 1) cnt++, res += a[i];
//     m1[cnt][res]++;
//   }

//   rep(s, 0, (1<<(n - n/2)) - 1) {
//     ll res = 0;
//     int cnt = 0;
//     rep(i, 0, n-n/2 - 1) if(s>>i & 1) cnt++, res += a[(int)(n/2 + i)];
//     m2[cnt][res]++;
//   }

//   vector<map<ll, int>> order1(n+1), order2(n+1);
//   rep(cnt, 0, n) {
//     int i = 0;
//     for(auto v : m1[cnt]) order1[cnt][v.first] = i++;
//   }

//   rep(cnt, 0, n) {
//     int i = 0;
//     for(auto v : m2[cnt]) order2[cnt][v.first] = i++;
//   }

//   vector<vector<ll>> sum1(n+1), sum2(n+1);
//   rep(i, 0, n) sum1[i].push_back(0), sum2[i].push_back(0);
//   rep(i, 0, n) {
//     int j = 0;
//     for(auto v : m1[i]) sum1[i].push_back(sum1[i][j] + v.second), j++;
//   }
//   rep(i, 0, n) {
//     int j = 0;
//     for(auto v : m2[i]) sum2[i].push_back(sum2[i][j] + v.second), j++;
//   }

//   // cout << "0個の合計額（場合の数）：" << " ";
//   // for(auto v : m2[0]) cout << v.first << " (" << v.second << "), "; cout << endl;
//   // cout << "1個の合計額（場合の数）：" << " ";
//   // for(auto v : m2[1]) cout << v.first << " (" << v.second << "), "; cout << endl;

//   // rep(j, 0, sum2[1].size()-1) cout << sum2[1][j] << " "; cout << endl;

//   ll ans = 0;
//   rep(i, 0, k) for(auto v : m1[i]) {
//     if(p < v.first) continue;
//     // cout << i << "個の合計額：" << v.first << " ( " << v.second << " 通り)" << endl;
//     auto itr = m2[k-i].upper_bound(p-v.first);
//     int j = itr != m2[k-i].end()? order2[k-i][ itr->first ]: m2[k-i].size();
//     // cout << " j:" << j << endl;
//     // cout << " ちょうど" << k-i << "個の合計額が" << p-v.first <<"円以下となる後半の選び方：" << (j>0? sum2[k-i][j]: 0) << endl;
//     if(j) ans += v.second * sum2[k-i][j];
//   }
//   cout << ans << endl;
// }