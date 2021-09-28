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
  int a, b, c, d; cin >> a >> b >> c >> d;

  for(int i = 0; i < 1000; i++) {
    // cout << i << endl;
    if(i%2 == 0) {
      c -= b;
      if(c <= 0) {
        cout << "Yes" << endl;
        return 0;
      }
    }else{
      a -= d;
      if(a <= 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
}