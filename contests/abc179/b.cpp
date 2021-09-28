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
const ll INF = 1e16;

bool chmax(ll &a, ll b) {if(a < b) {a = b; return true;} return false;}
bool chmin(ll &a, ll b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n; cin >> n;
  int a = 0;
  rep(i, 0, n-1) {
    int d1, d2; cin >> d1 >> d2;
    if(d1 == d2) {
      a++;
      if(a == 3) {
        cout << "Yes" << endl;
        return 0;
      }
    }
    else a = 0;
  }
  cout << "No" << endl;
}