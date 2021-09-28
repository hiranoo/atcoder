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
  string s; cin >> s;

  vector<int> cnt(10, 0);
  for(auto c : s) cnt[(int)(c-'0')]++;

  if(s.size() == 1) {
    if(s[0] == '8') cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  } else if (s.size() == 2) {
    if(stoi(s) % 8 == 0) cout << "Yes" << endl;
    else{
      int a = s[1] - '0', b = s[0] - '0';
      if((10*a+b) % 8 == 0) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    return 0;
  }
  
  rep(i, 1, 9) rep(j, 1, 9) rep(k, 1, 9) {
    int ret = 100*i + 10*j + k;
    if(ret % 8 != 0) continue;
    map<int, int> mp;
    mp[i]++, mp[j]++, mp[k]++;
    if(cnt[i] >= mp[i] && cnt[j] >= mp[j] && cnt[k] >= mp[k]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}