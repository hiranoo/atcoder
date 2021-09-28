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
  int k; cin >> k;
  sort(all(s));

  set<string> ss;
  
  vector<int> v;
  rep(i, 0, s.size()-1) v.push_back(i);

  do {
    string t = "";
    for(auto i : v) t += s[i];
    if(ss.count(t) == 0) ss.insert(t), k--;
    if(k == 0) {
      cout << t << endl;
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
}