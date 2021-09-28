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
  vector<int> x(n), y(n);
  rep(i, 0, n-1) cin >> x[i] >> y[i];

  rep(i, 0, n-1) rep(j, i+1, n-1) rep(k, j+1, n-1) {
    if( (x[j]-x[i])*(y[k]-y[i]) == (x[k]-x[i])*(y[j]-y[i]) ) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}