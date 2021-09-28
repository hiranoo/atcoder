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
const int INF = 1001001001;

vector<vector<int>> b(2, vector<int>(3));
vector<vector<int>> c(3, vector<int>(2));

// int dfs(int);

vector<int> score(19684, INF);
vector<vector<int>> panel(3, vector<int>(3, 2));

int f(int turn) {
  int s = 0;
  rep(i, 0, 2) rep(j, 0, 2) s *= 3, s += panel[i][j];
  if(score[s] != INF) return score[s];

  bool all = true;
  int ma = 0, mi = INF;
  rep(i, 0, 2) rep(j, 0, 2) if(panel[i][j] == 2) {
    all = false;
    panel[i][j] = turn;
    int t = f(turn^1);
    ma = max(ma, t);
    mi = min(mi, t);
    panel[i][j] = 2;
  }

  if(all) {
    int t = 0;
    rep(i, 0, 1) rep(j, 0, 2) if(panel[i][j] == panel[i+1][j]) t += b[i][j];
    rep(i, 0, 2) rep(j, 0, 1) if(panel[i][j] == panel[i][j+1]) t += c[i][j];
    return t;
  } 

  return score[s] = turn==0? ma : mi;
}

int main() {
  int t = 0;
  rep(i, 0, 1) rep(j, 0, 2) cin >> b[i][j], t += b[i][j];
  rep(i, 0, 2) rep(j, 0, 1) cin >> c[i][j], t += c[i][j];

  int c = f(0);
  cout << c << endl;
  cout << t - c << endl;
}

// int main(){
//   cin.sync_with_stdio(false);
//   int sum = 0;
//   rep(i, 2)rep(j, 3) cin >> b[i][j], sum += b[i][j];
//   rep(i, 3)rep(j, 2) cin >> c[i][j], sum += c[i][j];

//   int chokudai = dfs(0);

//   print(chokudai);
//   print(sum - chokudai);

//   return 0;
// }

// int dfs(int turn) {
//   int p = 0;
//   rep(i, 3)rep(j, 3) p *= 3, p += panel[i][j];
//   if(score[p] != INF) return score[p];

//   int ma = 0, mi = INF;
//   bool fullfill = true;
//   rep(i, 3)rep(j, 3)if(panel[i][j] == 2) {
//     fullfill = false;
//     panel[i][j] = turn;
//     int t = dfs((turn + 1) % 2);
//     maxch(ma, t);
//     minch(mi, t);
//     panel[i][j] = 2;
//   }

//   if(fullfill) {
//     int t = 0;
//     rep(i, 2)rep(j, 3)if(panel[i][j] == panel[i + 1][j]) t += b[i][j];
//     rep(i, 3)rep(j, 2)if(panel[i][j] == panel[i][j + 1]) t += c[i][j];
//     return t;
//   }

//   return score[p] = (turn == 0) ? ma : mi;
// }

