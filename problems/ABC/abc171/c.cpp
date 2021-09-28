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

int main () {
  ll n; cin >> n;
  // n--;

  // ll a = 26;
  // int keta = 1;
  // while(n >= a) {
  //   a = 26*(a+1);
  //   keta++;
  // }
  // // cout << "keta:" << keta << endl;

  // a = a/26 - 1;
  // // cout << a << endl;
  // while(keta > 0) {
  //   int c = 0;
  //   while(a + pow(26, keta-1) <= n) {
  //     a += pow(26, keta-1);
  //     c++;
  //   }
  //   cout << (char)('a' + c);
  //   keta--;
  // }
  // cout << endl;

  string s = "";
  while(n > 0) {
    n--;
    s += (char)('a' + n%26);
    n /= 26;
  }
  reverse(all(s));
  cout << s << endl;
}