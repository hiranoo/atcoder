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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n; cin >> n;
  vector<pii> r(n);
  rep(i, 0, n-1) cin >> r[i].first >> r[i].second;

  if(n==1) {
    cout << r[0].first - r[0].second + 1 << endl;
    return 0;
  }

  auto comp = [&] (pii a, pii b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  };

  if(n%2==1) {
    sort(all(r), comp);
    int ans = r[n/2].second;
    sort(all(r));
    ans -= r[n/2].first;
    ans++;

    cout << ans << endl;
  }else{
    sort(all(r), comp);
    int ans = r[n/2].second + r[n/2-1].second;
    sort(all(r));
    ans -= r[n/2].first + r[n/2-1].first;
    ans++;
    cout << ans << endl;
  }
}
