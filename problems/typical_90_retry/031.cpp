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

vector<vector<int>> gr(51, vector<int>(2000));
vector<vector<bool>> flag(51, vector<bool>(2000, false));

int grundy(int w, int b) {
  if(w == 0 && b == 1) return 0;
  if(flag[w][b]) return gr[w][b];

  set<int> s;
  if(w > 0) s.insert(grundy(w-1, b+w));
  rep(k, 1, b/2) s.insert(grundy(w, b-k));

  int g = 0;
  while(s.count(g) > 0) g++;
  flag[w][b] = true;
  return gr[w][b] = g;
}

int main() {
  int n; cin >> n;
  vector<int> W(n), B(n);
  rep(i, 0, n-1) cin >> W[i];
  rep(i, 0, n-1) cin >> B[i];

  int res = 0;
  rep(i, 0, n-1) res ^= grundy(W[i], B[i]);
  if(res > 0) cout << "First" << endl;
  else cout << "Second" << endl;
}