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

int h, w; ll C;

ll f(vector<vector<ll>> A) {
  rep(i, 0, h-1) rep(j, 0, w-1) A[i][j] += C*(i+j);
  vector<vector<ll>> B = A;
  for(int i = h-1; i >= 0; i--) for(int j = w-1; j >= 0; j--) {
    if(i < h-1) chmin(B[i][j], B[i+1][j]);
    if(j < w-1) chmin(B[i][j], B[i][j+1]);
  }

  ll fans = INF;
  rep(i, 0, h-1) rep(j, 0, w-1) {
    if(i == h-1 && j == w-1) continue;
    ll b = INF;
    if(i < h-1) chmin(b, B[i+1][j]);
    if(j < w-1) chmin(b, B[i][j+1]);
    chmin(fans, A[i][j] + b - 2*C*(i+j));
  }
  return fans;
}

int main() {
  cin >> h >> w >> C;
  vector<vector<ll>> A(h, vector<ll>(w));
  rep(i, 0, h-1) rep(j, 0, w-1) cin >> A[i][j];

  ll ans = f(A);
  reverse(all(A));
  chmin(ans, f(A));
  cout << ans << endl;
}