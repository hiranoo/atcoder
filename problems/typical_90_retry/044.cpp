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
  int n, q; cin >> n >> q;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  
  int head = 0;
  rep(i, 0, q-1) {
    int t, x, y; cin >> t >> x >> y;
    if(t == 1) {
      swap(a[(head+x-1)%n], a[(head+y-1)%n]);
    }else if(t == 2) {
      head = (head + n-1) % n;
    }else{
      cout << a[(head+x-1)%n] << endl;
    }
  }
}