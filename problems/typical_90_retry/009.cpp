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

double th(double a1, double a2) {
  return min(fabs(a1 - a2), 2*M_PI - fabs(a1 - a2));
}

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n);
  rep(i, 0, n-1) cin >> x[i] >> y[i];

  double ans = 0;
  rep(c, 0, n-1) {
    vector<double> ang;
    rep(i, 0, n-1) if(i != c) ang.push_back(atan2(y[i] - y[c], x[i] - x[c]));
    sort(all(ang));

    int m = n - 1;
    rep(i, 0, m-1) {
      if(ang[i] < 0) {
        auto it = lower_bound(all(ang), ang[i]+M_PI);
        if(it == ang.begin()) {
          ans = max(ans, th(ang[m-1], ang[i]));
          ans = max(ans, th(ang[0], ang[i]));
        }
        else if(it == ang.end()) {
          ans = max(ans, th(ang[i], ang[0]));
          ans = max(ans, th(ang[m-1], ang[i]));
        }
        else {
          ans = max(ans, th(*it, ang[i]));
          --it; ans = max(ans, th(*it, ang[i]));
        }
      }else{
        auto it = lower_bound(all(ang), ang[i] - M_PI);
        if(it == ang.begin()) {
          ans = max(ans, th(ang[m-1], ang[i]));
          ans = max(ans, th(ang[0], ang[i]));
        }
        else if(it == ang.end()) {
          ans = max(ans, th(ang[i], ang[0]));
          ans = max(ans, th(ang[m-1], ang[i]));
        }
        else {
          ans = max(ans, th(*it, ang[i]));
          --it; ans = max(ans, th(*it, ang[i]));
        }
      }
    }
      

    // cout << c << endl;
    // for(auto v : ang) cout << v * 180 / M_PI << " "; cout << endl;
    // int r = 1;
    // int m = n - 1;
    // rep(l, 0, m-2) {
    //   if(l == r) r++;
    //   while(r < m-1) {
    //     double cdiff = fabs(ang[r] - ang[l]);
    //     double ndiff = fabs(ang[r+1] - ang[l]);
    //     if( min(fabs(2*M_PI - ndiff), ndiff) > min(fabs(2*M_PI - cdiff), cdiff) ) r++;
    //     else break;
    //   }

    //   if(ans < min(fabs(ang[r] - ang[l]), 2*M_PI - fabs(ang[r] - ang[l])) ) {
    //     ans = min(ang[r] - ang[l], 2*M_PI - ang[r] + ang[l]);
    //   }
    // }
  }

  cout << fixed << setprecision(10) << ans * 180.0 / M_PI << endl;
}