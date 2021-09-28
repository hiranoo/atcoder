#include <bits/stdc++.h>
#include <atcoder/all>
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
const ll INF = 3*1e18;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n, K; cin >> n >> K;
  vector<ll> x(n), y(n);
  rep(i, 0, n-1) cin >> x[i] >> y[i];

  vector<vector<ll>> norm2(n, vector<ll>(n));
  rep(i, 0, n-1) rep(j, 0, n-1) norm2[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
  
  vector<ll> d(1<<n, 0);
  rep(s, 1, (1<<n)-1) {
    rep(i, 0, n-1) rep(j, 0, n-1) {
      if((s>>i & 1) && (s>>j & 1)) {
        d[s] = max(d[s], norm2[i][j]);
      }
    }
  }

  vector<vector<ll>> dp(1<<n, vector<ll>(K+1, INF));
  dp[0][0] = 0;
  rep(s, 1, (1<<n)-1) rep(i, 1, K) for(int cs = s; cs != 0; cs = (cs - 1) & s) if(s | cs == s) dp[s][i] = min(dp[s][i], max(dp[s-cs][i-1], d[cs]));

  cout << dp[(1<<n)-1][K] << endl;
}

// int main() {
//   int n, K; cin >> n >> K;
//   vector<pll> p(n);
//   rep(i, 0, n-1) cin >> p[i].first >> p[i].second;
//   sort(all(p));
  
//   auto norm = [&] (int i, int j) {
//     return (p[i].first - p[j].first)*(p[i].first - p[j].first) + (p[i].second - p[j].second)*(p[i].second - p[j].second);
//   };

//   vector<vector<ll>> d(n, vector<ll>(n));
//   rep(i, 0, n-1) rep(j, 0, n-1) d[i][j] = norm(i, j);

//   auto f = [&](ll m) {
//     vector<bool> used(n, false);
//     int cnt = 0;
//     rep(i, 0, n-1) if(!used[i]) {
//       used[i] = true;
//       cnt++;
//       vector<pll> ps; // norm2, id
//       rep(j, 0, n-1) if(!used[j] && d[i][j] <= m) ps.push_back(pll(d[i][j], j));
//       sort(all(ps));
//       vector<int> members; members.push_back(i);
//       for(auto p : ps) {
//         int jm = p.second;
//         bool ok = true;
//         for(auto im : members) {
//           if(d[im][jm] > m) {
//             ok = false;
//             break;
//           }
//         }
//         if(ok) {
//           members.push_back(jm);
//           used[jm] = true;
//         }
//       } 
//     }

//     // cout << "m: " << m << " cnt: " << cnt << " K: " << K << endl;
//     return cnt;
//   };


//   ll l = -1, r = INF;
//   ll ans = INF;
//   while(r - l > 1) {
//     ll m = (r + l) / 2LL;

//     if(f(m) <= K) {
//       r = m;
//     }else{
//       l = m;
//     }
//   }

//   if(f(l) == K) cout << l << endl;
//   else cout << r << endl;
// }