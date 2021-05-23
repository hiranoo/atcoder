#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto e : v) os << e << ' '; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { for (auto e : v) os << e << ' ';  return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &v) { for (auto e : v) os << e << ' ';  return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp) { for (auto e : mp) os << e << ' '; return os; }

template <typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } else return false; }
template <typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } else return false; }
inline bool in(int x, int y, int h, int w) { return 0 <= x && x < h && 0 <= y && y < w; }
inline void print() { cout << '\n'; }
template <typename T1, typename... T2> void print(const T1 a, const T2 &... b) { cout << a << ' '; print(b...); }

//#define DEBUG
#ifdef DEBUG
inline void debug_print() { cerr << endl; }
template <typename T1, typename... T2> void debug_print(const T1 a, const T2 &... b) { cerr << a << ' '; debug_print(b...); }
#define debug(...) cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = " , debug_print(__VA_ARGS__);
#else
#define debug(...) true
#endif

const int INF = (1<<30)-1;
const long long LINF = 1LL<<60;
const double EPS = 1e-9;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int dx[8] = {-1,0,1,0,1,-1,1,-1};
const int dy[8] = {0,1,0,-1,1,-1,-1,1};

//-------------------------- Libraries --------------------------//

//--------------------------- Solver ----------------------------//

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return 0;
}

void solve() {
    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) {
        int w, h;
        cin >> w >> h;
        v[i] = {w, -h};
    }

    sort(v.rbegin(), v.rend());

    int MAX = 100002;
    atcoder::segtree<int, op, e> seg(MAX);

    for (int i = 0; i < N; i++) {
        auto [w, h] = v[i];
        h = -h;
        int tmp = seg.prod(h+1, MAX) + 1;
        if (tmp > seg.get(h)) seg.set(h, tmp);
    }

    cout << seg.all_prod() << '\n';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}
