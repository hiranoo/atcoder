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

void chmax(ll &a, ll b) {a = max(a, b);}
void chmin(ll &a, ll b) {a = min(a, b);}

int main() {
  ll n; cin >> n;

  if(n == 1) {
    cout << 'A' << endl;
    return 0;
  }

  string s;
  while(n > 0) {
    if(n%2 == 0) {
      n /= 2;
      s += "B";
    }else{
      n--;
      s += "A";
    }
  }

  reverse(all(s));
  cout << s << endl;
}