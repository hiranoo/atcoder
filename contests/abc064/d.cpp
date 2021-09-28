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
const ll INF = 1e18;

int main() {
  int n; cin >> n;
  string s; cin >> s;

  int cnt = 0, pre = 0;
  for(auto c : s) {
    if(c == '(') {
      cnt++;
    }
    else {
      cnt--;
      if(cnt < 0) pre = max(pre, -cnt);
    }
  }

  rep(i, 0, pre-1) s = "(" + s;

  cnt = 0;
  for(auto c : s) {
    if(c == '(') cnt++;
    else cnt--;
  }
  rep(i, 0, cnt-1) s += ")";
  cout << s << endl;
}

// int main() {
//   int n; cin >> n;
//   string s; cin >> s;
//   vector<int> vec;
//   int tail = 0;
//   bool fp = false;
//   int p = 0, m = 0;
//   rep(i, 0, n-1) {
//     // cout << fp << " " << p << " " << m << endl;
//     if(!fp && s[i] == '(') fp=true, p++;
//     else if(fp && s[i] == '(') p++;
//     else if(fp && s[i] == ')') {
//       if(p) p--;
//       else fp=false, m++;
//     }
//     else if(!fp && s[i] == ')') {
//       m++;
//     }
//   }

//   string ans = "";
//   rep(i, 0, m-1) ans += '(';
//   ans += s;
//   rep(i, 0, p-1) ans += ')';
//   cout << ans << endl;
// }