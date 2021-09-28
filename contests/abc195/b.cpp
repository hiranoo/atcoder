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
  int a, b, w;
  cin >> a >> b >> w; w *= 1000;

  int mi = 1000005, ma = -1;
  for(int k = 1; k <= 1000005; k++) {
    if(a*k <= w && w <= b*k) mi = min(mi, k), ma = max(ma, k);
  }
  if(ma != -1) cout << mi << " " << ma << endl;
  else cout << "UNSATISFIABLE" << endl;
}