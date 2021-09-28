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
  string s1, s2, s3; cin >> s1 >> s2 >> s3;

  set<char> ss;
  for(char c : s1) ss.insert(c);
  for(char c : s2) ss.insert(c);
  for(char c : s3) ss.insert(c);
  if(ss.size() > 10) {
    cout << "UNSOLVABLE" << endl;
    return 0;
  }

  vector<int> I(10);
  rep(i, 0, 9) I[i] = i;
  string t = "";
  for(auto c : ss) t += c;

  do {
    map<char, int> mp;
    rep(i, 0, t.size()-1) mp[t[i]] = I[i];

    ll N1 = 0, N2 = 0, N3 = 0;
    if(mp[s1[0]]==0 || mp[s2[0]]==0 || mp[s3[0]]==0) continue;
    for(int i = 0; i < s1.size(); i++) N1 *= 10LL, N1 += (ll)mp[s1[i]];
    for(int i = 0; i < s2.size(); i++) N2 *= 10LL, N2 += (ll)mp[s2[i]];
    for(int i = 0; i < s3.size(); i++) N3 *= 10LL, N3 += (ll)mp[s3[i]];
    // if(N1==9567 && N2==1085) cout << N1 << " " << N2 << " " << N3 << endl;
    if(N1+N2 == N3) {
      printf("%lld\n%lld\n%lld\n", N1, N2, N3);
      return 0;
    }
  } while(next_permutation(all(I)));

  cout << "UNSOLVABLE" << endl;
}