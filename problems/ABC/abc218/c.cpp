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
  int n; cin >> n;
  vector<string> s(n), t(n);
  rep(i, 0, n-1) cin >> s[i];
  rep(i, 0, n-1) cin >> t[i];

  int cnt = 0;
  rep(i, 0, n-1) rep(j, 0, n-1) {
    if(s[i][j] == '#') cnt++;
    if(t[i][j] == '#') cnt--;
  }
  if(cnt != 0) {
    cout << "No" << endl;
    return 0;
  }

  auto offset = [] (vector<string> a) {
    int n = a.size();
    int x = 0, y = 0;
    rep(i, 0, n-1) {
      bool ret = true;
      rep(j, 0, n-1) if(a[i][j] == '#') ret = false;
      if(!ret) {
        y = i;
        break;
      }
    }
    rep(j, 0, n-1) {
      bool ret = true;
      rep(i, 0, n-1) if(a[i][j] == '#') ret = false;
      if(!ret) {
        x = j;
        break;
      }
    }
    return pii(y, x);
  };
  
  auto same = [&] (vector<string> a, vector<string> b) {
    int n = a.size();
    bool ok = true;
    pii off_a = offset(a), off_b = offset(b);
    rep(i, 0, n-1) rep(j, 0, n-1) {
      if(i+off_a.first > n-1 || j+off_a.second > n-1 || i+off_b.first > n-1 || j+off_b.second > n-1) break;
      if(a[i+off_a.first][j+off_a.second] != b[i+off_b.first][j+off_b.second]) {
        ok = false;
        break;
      }
    }
    return ok;
  };

  // auto display = [](vector<string> &a) {
  //   cout << endl;
  //   rep(i, 0, a.size()-1) {
  //     cout << a[i] << endl;
  //   }
  // };

  vector<string> ss = s;
  rep(rot, 0, 3) {
    rep(y, 0, n-1) rep(x, 0, n-1) {
      ss[n-1-x][y] = s[y][x];
    }
    // display(ss);
    // display(t);
    if(same(ss, t)) {
      cout << "Yes" << endl;
      return 0;
    }
    s = ss;
  }
  cout << "No" << endl;
}

// int main() {
//   int n; cin >> n;
//   vector<string> s(n), t(n);

//   rep(i, 0, n-1) cin >> s[i];
//   rep(j, 0, n-1) cin >> t[j];

//   pii sy, sx, ty, tx;
//   auto fy = [&] (vector<string> &ss) {
//     pii y;
//     rep(i, 0, n-1) {
//       int tmp = 0;
//       rep(j, 0, n-1) if(ss[i][j]=='#') tmp++;
//       if(tmp) {
//         y.first = i;
//         break;
//       }
//     }

//     for(int i = n-1; i >= 0; i--) {
//       int tmp = 0;
//       rep(j, 0, n-1) if(ss[i][j] == '#') tmp++;
//       if(tmp) {
//         y.second = i;
//         break;
//       }
//     }
//     return y;
//   };

//   auto fx = [&] (vector<string> &ss) {
//     pii x;
//     rep(j, 0, n-1) {
//       int tmp = 0;
//       rep(i, 0, n-1) if(ss[i][j]=='#') tmp++;
//       if(tmp) {
//         x.first = j;
//         break;
//       }
//     }

//     for(int j = n-1; j >= 0; j--) {
//       int tmp = 0;
//       rep(i, 0, n-1) if(ss[i][j] == '#') tmp++;
//       if(tmp) {
//         x.second = j;
//         break;
//       }
//     }
//     return x;
//   };

//   sy = fy(s);
//   sx = fx(s);
//   ty = fy(t);
//   tx = fx(t);

//   vector<vector<int>> ns(sy.second-sy.first+1, vector<int>(sx.second-sx.first+1));
//   vector<vector<int>> nt(ty.second-ty.first+1, vector<int>(tx.second-tx.first+1));

//   int cnt = 0;
//   rep(i, sy.first, sy.second) rep(j, sx.first, sx.second) {
//     if(s[i][j] == '.') ns[i-sy.first][j-sx.first] = 0;
//     else ns[i-sy.first][j-sx.first] = 1, cnt++;
//   }
//   rep(i, ty.first, ty.second) rep(j, tx.first, tx.second) {
//     if(t[i][j] == '.') nt[i-ty.first][j-tx.first] = 0;
//     else nt[i-ty.first][j-tx.first] = 1, cnt--;
//   }

//   if(cnt != 0) {
//     cout << "No" << endl;
//     return 0;
//   }
  
//   // auto display = [](vector<vector<int>> &a) {
//   //   cout << endl;
//   //   rep(i, 0, a.size()-1) {
//   //     rep(j, 0, a[0].size()-1) {
//   //       if(a[i][j]) cout << '#';
//   //       else cout << '.';
//   //     }cout << endl;
//   //   }
//   //   cout << endl;
//   // };

//   // display(ns);
//   // display(nt);

//   int dy = sy.second - sy.first;
//   int dx = sx.second - sx.first;

//   bool ok = true;
//   rep(y, 0, dy) rep(x, 0, dx) {
//     if(nt.size()-1 < dx-x || nt[0].size()-1 < y) {
//       ok = false;
//       break;
//     }
//     if(nt[dx-x][y] != ns[y][x]) {
//       ok = false;
//       break;
//     }
//   }

//   if(ok) {
//     cout << "Yes" << endl;
//     return 0;
//   }

//   ok = true;
//   rep(y, 0, dy) rep(x, 0, dx) {
//     if(nt.size()-1 < dy-y || nt[0].size()-1 < dx-x) {
//       ok = false;
//       break;
//     }
//     if(nt[dy-y][dx-x] != ns[y][x]) {
//       ok = false;
//       break;
//     }
//   }

//   if(ok) {
//     cout << "Yes" << endl;
//     return 0;
//   }

//   ok = true;
//   rep(y, 0, dy) rep(x, 0, dx) {
//     if(nt.size()-1 < x || nt[0].size()-1 < dy-y) {
//       ok = false;
//       break;
//     }
//     if(nt[x][dy-y] != ns[y][x]) {
//       ok = false;
//       break;
//     }
//   }

//   if(ok) {
//     cout << "Yes" << endl;
//     return 0;
//   }

//   ok = true;
//   rep(y, 0, dy) rep(x, 0, dx) {
//     if(nt.size()-1 < y || nt[0].size()-1 < x) {
//       ok = false;
//       break;
//     }
//     if(nt[y][x] != ns[y][x]) {
//       ok = false;
//       break;
//     }
//   }

//   if(ok) {
//     cout << "Yes" << endl;
//     return 0;
//   }


//   cout << "No" << endl;
// }