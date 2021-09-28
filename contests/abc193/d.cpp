#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <time.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i, s, t) for(ll i = (s); i <= (t); i++)
#define repd(i, s, t) for(ll i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
const ll MOD = 1e9+7;
const ll INF = 1e18;


int main() {
  ll k; cin >> k;
  string s, t;
  cin >> s;
  cin >> t;

  vector<ll> left(10, k); left[0] = 0;
  vector<ll> t_has(10, 0), s_has(10, 0);
  rep(i, 0, 3) {
    left[(ll)(s[i]-'0')] --;
    left[(ll)(t[i]-'0')] --;
    s_has[(ll)(s[i]-'0')] ++;
    t_has[(ll)(t[i]-'0')] ++;
  }

  // rep(i, 1, 9) cout << left[i] << " "; cout << endl;
  // rep(i, 1, 9) cout << s_has[i] << " "; cout << endl;
  // rep(i, 1, 9) cout << t_has[i] << " "; cout << endl;

  ll total = (9*k-8)*(9*k-9);
  ll win = 0;
  rep(i, 1, 9) rep(j, 1, 9) {
    if(left[i]*left[j] == 0) continue;
    if(i==j && left[i] <= 1) continue;
    // cout << i << " " << j << endl;
    ll s_poll = 0, t_poll = 0;
    rep(x, 1, 9) {
      if(x == i) s_poll += x * pow(10, s_has[x]+1);
      else s_poll += x * pow(10, s_has[x]);
    }
    rep(x, 1, 9) {
      if(x == j) t_poll += x * pow(10, t_has[x]+1);
      else t_poll += x * pow(10, t_has[x]);
    }
    if(s_poll > t_poll) {
      if(i != j) win += left[i]*left[j];
      else win += left[i]*(left[i]-1);
      // cout << i << " " << j << " " << win << endl;
    }
  }
  // cout << win << " / " << total << endl;
  cout << fixed << setprecision(10) << double(win) / double(total) << endl;
}
