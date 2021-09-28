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
  map<string, int> mp;
  mp["ABC"] = mp["AGC"] = mp["ARC"] = mp["AHC"] = 0;
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  mp[s1]++, mp[s2]++, mp[s3]++;
  for(auto it : mp) {
    if(it.second == 0) cout << it.first << endl;
  }
}