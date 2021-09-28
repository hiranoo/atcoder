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
  int n; ll C; cin >> n >> C;
  map<ll, ll> event;
  rep(i, 0, n-1) {
    ll a, b, c; cin >> a >> b >> c;
    b++;
    event[a] += c;
    event[b] += -c;
  }

  int pre = 0;
  int cur = 0;
  ll ans = 0;
  ll money = 0;
  for(auto itr=event.begin(); itr != event.end(); itr++) {
    cur = itr->first;
    if(cur != pre) {
      ans += (cur-pre) * min(money, C);
      pre = cur;
    }
    money += itr->second; 
  }

  cout << ans << endl;

  // map<pll, ll> plan;
  // map<ll, ll> date;
  // rep(i, 0, n-1) {
  //   int a, b, c; cin >> a >> b >> c;
  //   a--;
  //   plan[pll(a, b)] = c; // [a, b)
  //   date[a]++;
  //   date[b]++;
  // }

  // ll i = 0;
  // for(auto itr = date.begin(); itr != date.end(); itr++) {
  //   itr->second = i++;
  // }

  // vector<ll> true_date(date.size()+10, 0);
  // for(auto itr = date.begin(); itr != date.end(); itr++) {
  //   true_date[itr->second] = itr->first;
  // }

  // vector<ll> money(date.size()+5, 0);
  // for(auto itr = plan.begin(); itr != plan.end(); itr++) {
  //   pll p = itr->first;
  //   ll c = itr->second;
  //   money[date[p.first]] += c;
  //   money[date[p.second]] -= c;
  // }

  // ll now = 0;
  // ll ans = 0;
  // for(ll i=0; i < money.size()-1; i++) {
  //   now += money[i];
  //   ans += min(now, C) * (true_date[i+1] - true_date[i]);
  // }
  // cout << ans << endl;
}
