#include <bits/stdc++.h>
// #include <atcoder/segtree>
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
const ll INF = 1e18;


int main() {
  string s; cin >> s;
  if(s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) {
    cout << "Weak" << endl;
    return 0;
  }
  string num = "01234567890";
  
  bool f = true;
  rep(i, 0, 2) if(s[i+1] != num[(int)(s[i] -'0') + 1]) f = false;
  if(f) cout << "Weak" << endl;
  else cout << "Strong" << endl;
  
}