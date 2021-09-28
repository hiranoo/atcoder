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

struct P {
  char c; int id;
  P(){}
  P(char c, int id) : c(c), id(id) {}
  // bool operator<(const P &p) {
  //   if(c == p.c) return id < p.id;
  //   return c < p.c;
  // }
  // bool operator==(const P &p) {
  //   if(c == p.c && id == p.id) return true;
  //   return false;
  // }
};

// P op(P p, P q) {
//   if(p.c == q.c) {
//     if(p.id < q.id) return p;
//     return q;
//   }else if(p.c < q.c) return p;
//   return q;
// }

// P e() {
//   return P(0, 1001001);
// }

pii op(pii p, pii q) {return min(p, q);}
pii e() {return pii(1000, 1000000);}

int main() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  atcoder::segtree<pii, op, e> seg(n);
  rep(i, 0, n-1) seg.set(i, pii(s[i]-'a', i));

  // rep(i, 0, n-1) cout << seg.get(i).first; cout << endl;
  // cout << seg.prod(0, n).first << endl;
  string t = "";
  int cur = 0;
  while(k > 0 && cur < n) {
    pii nxt = seg.prod(cur, n-k+1);
    // cout << (char)(nxt.first+'a') << " : " << nxt.second << " k:" << k << endl;
    t += 'a' + nxt.first;
    cur = nxt.second+1;
    k--;
  }

  cout << t << endl;
}