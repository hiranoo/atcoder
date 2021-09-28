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
  rep(s, 0, (1<<n)-1) {
    int cnt = 0;
    bool ok = true;
    for(int i = n-1; i >= 0; --i) {
      if(s>>i & 1) cnt++;
      if(n-i-cnt < cnt) {
        ok = false;
        break;
      }
    }
    if(!ok) continue;
    if(n-cnt != cnt) continue;

    for(int i = n-1; i >= 0; --i) {
      if(s>>i & 1) cout << ')';
      else cout << '(';
    }cout << endl;
    // cout << bitset<4>(s) << endl;
  }
}