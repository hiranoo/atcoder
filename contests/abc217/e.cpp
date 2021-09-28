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
// const ll INF = 1e16;
const int INF = 1001001001;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  deque<int> deq;
  priority_queue<int, vector<int>, greater<int>> pq;

  int Q; cin >> Q;
  for(int i = 0; i < Q; i++) {
    int t; cin >> t;
    if(t == 1) {
      int x; cin >> x;
      deq.push_back(x);
    }else if(t == 2) {
      if(pq.size() == 0) {
        cout << deq.front() << endl;
        deq.pop_front();
      }else{
        cout << pq.top() << endl;
        pq.pop();
      }
    }else{
      while(deq.size()) pq.push(deq.front()), deq.pop_front();
    }
  }
}

// pii op(pii a, pii b) {
//   return min(a, b);
// }

// pii e() {
//   return pii(INF, INF);
// }

// int main() {
//   int n; cin >> n;
//   // atcoder::segtree<pii, op, e> seg(n);
//   atcoder::segtree<pii, op, e> seg(200009);

//   int cnt = 0;
//   bool sorted = false;
//   int head_id = 0;
//   int tail_id = 0;
//   rep(i, 0, n-1) {
//     int typ; cin >> typ;
//     if(typ == 1) {
//       int x; cin >> x;
//       seg.set(cnt, pii(x, cnt));
//       cnt++;
//       if(!sorted) tail_id++;
//     }
//     if(typ == 2) {
//       if(!sorted) {
//         pii p = seg.get(head_id);
//         cout << p.first << endl;
//         seg.set(head_id, pii(INF, head_id));
//         head_id++;
//       }else{
//         pii p = seg.prod(head_id, tail_id);
//         if(p.first < INF) {
//           cout << p.first << endl;
//           seg.set(p.second, pii(INF, p.second));
//         }else{
//           head_id = tail_id++;
//           pii pp = seg.get(head_id);
//           cout << pp.first << endl;
//           seg.set(head_id, pii(INF, head_id));
//           head_id++; tail_id++;
//         }
//       }
//     }
//     if(typ == 3) {
//       sorted = true;
//       tail_id = cnt;
//     }
//   }
// }