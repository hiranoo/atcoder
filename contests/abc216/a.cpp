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
  string s; cin >> s;
  int x, y;
  if(s.size() == 3) {
    x = s[0] - '0';
    y = s[2] - '0';
  }else{
    x = s[0] - '0';
    x *= 10;
    x += (int)(s[1] - '0');
    y = s[3] - '0';
  }
  if(0 <= y && y <= 2) cout << x << '-' << endl;
  else if(y <= 6) cout << x << endl;
  else cout << x << '+' << endl;  

}