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
  vector<ll> a(n+1);
  rep(i, 1, n) cin >> a[i];
  sort(a.begin()+1, a.end());

  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i, 1, n) sum[i] = sum[i-1] + a[i];

  double ans = INF;
  rep(k, 1, n-1) {
    double x = a[k]/2.0;
    if(2*k-n<0) x = a[k+1]/2.0;
    chmin(ans, (2*k - n)*x + sum[n] - sum[k]);
  }

  chmin(ans, (sum[n] - a[1]/2.0*n));
  chmin(ans, n*a[n]/2.0);


  cout << fixed << setprecision(10) << (double)ans/(double)n << endl;
}