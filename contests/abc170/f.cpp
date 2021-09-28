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
// const ll INF = 1e18;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

// struct P {
//   int x, y, dir;
// };

void solve1() {
  int h, w, k; cin >> h >> w >> k;
  int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy; sx--, sy--, gx--, gy--;
  vector<string> s(h);
  rep(i, 0, h-1) cin >> s[i];

  const int INF = 1001001001;
  vector dist(h, vector<int>(w, INF));
  dist[sx][sy] = 0;
  queue<pii> q;
  q.push(pii(sx, sy));
  int cnt = 0;
  while(q.size()) {
    cnt++;
    auto [i, j] = q.front(); q.pop();
    for(int ni = i-1; ni >= i-k; ni--) {
      if(ni < 0 || s[ni][j]=='@' || dist[ni][j] <= dist[i][j]) break;
      if(chmin(dist[ni][j], dist[i][j]+1)) q.push(pii(ni, j));
    }
    for(int ni = i+1; ni <= i+k; ni++) {
      if(ni >= h || s[ni][j]=='@' || dist[ni][j] <= dist[i][j]) break;
      if(chmin(dist[ni][j], dist[i][j]+1)) q.push(pii(ni, j));
    }
    for(int nj = j-1; nj >= j-k; nj--) {
      if(nj < 0 || s[i][nj]=='@' || dist[i][nj] <= dist[i][j]) break;
      if(chmin(dist[i][nj], dist[i][j]+1)) q.push(pii(i, nj));
    }
    for(int nj = j+1; nj <= j+k; nj++) {
      if(nj >= w || s[i][nj]=='@' || dist[i][nj] <= dist[i][j]) break;
      if(chmin(dist[i][nj], dist[i][j]+1)) q.push(pii(i, nj));
    }
  }

  int ans = INF;
  chmin(ans, dist[gx][gy]);
  if(ans < INF) cout << ans << endl;
  else cout << -1 << endl;
}

// @をsetに残しているので、@が多いとTLE
// @の縦横の位置を別のsetにもっておけば、未探索マスのsetからは@を消せる！
void solve2() {
  int h, w, k; cin >> h >> w >> k;
  int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy; sx--, sy--, gx--, gy--;
  vector<string> s(h);
  rep(i, 0, h-1) cin >> s[i];

  vector<set<int>> hv(h), wv(w);
  rep(i, 0, h-1) rep(j, 0, w-1) if(s[i][j]=='.') hv[i].insert(j);
  rep(j, 0, w-1) rep(i, 0, h-1) if(s[i][j]=='.') wv[j].insert(i);

  vector<set<int>> hblocks(h), wblocks(w);
  rep(i, 0, h-1) rep(j, 0, w-1) if(s[i][j]=='@') hblocks[i].insert(j);
  rep(j, 0, w-1) rep(i, 0, h-1) if(s[i][j]=='@') wblocks[j].insert(i);

  const int INF = 1001001001;
  vector dist(h, vector<int>(w, INF));
  dist[sx][sy] = 0;
  queue<pii> q;
  q.push(pii(sx, sy));

  while(q.size()) {
    auto [i, j] = q.front(); q.pop();
    if(i==gx && j == gy) break;
    if(wv[j].size()>1) {
      for(auto itr=wv[j].find(i); itr != (--wv[j].begin()); --itr) {
        if(*itr==i) continue;
        if(i-*itr > k) break;
        if(wblocks[j].lower_bound(i) != wblocks[j].lower_bound(*itr)) break;
        if(chmin(dist[*itr][j], dist[i][j]+1)) q.push(pii(*itr, j));
      }
      for(auto itr=wv[j].find(i); itr != wv[j].end(); ++itr) {
        if(*itr==i) continue;
        if(*itr-i > k) break;
        if(wblocks[j].lower_bound(i) != wblocks[j].lower_bound(*itr)) break;
        if(chmin(dist[*itr][j], dist[i][j]+1)) q.push(pii(*itr, j));
      }
    }

    if(hv[i].size()>1) {
      for(auto itr=hv[i].find(j); itr != hv[i].end(); ++itr) {
        if(*itr==j) continue;
        if(*itr-j > k) break;
        if(hblocks[i].lower_bound(j) != hblocks[i].lower_bound(*itr)) break;
        if(chmin(dist[i][*itr], dist[i][j]+1)) q.push(pii(i, *itr));
      }
      for(auto itr=hv[i].find(j); itr != (--hv[i].begin()); --itr) {
        if(*itr==j) continue;
        if(j-*itr > k) break;
        if(hblocks[i].lower_bound(j) != hblocks[i].lower_bound(*itr)) break;
        if(chmin(dist[i][*itr], dist[i][j]+1)) q.push(pii(i, *itr));
      }
    }

    hv[i].erase(j);
    wv[j].erase(i);
  }

  // rep(i, 0, h-1) rep(j, 0, w-1) cout << i << " " << j << " " << hv[i].size() << " " << wv[j].size() << endl;

  int ans = dist[gx][gy];
  if(ans < INF) cout << ans << endl;
  else cout << -1 << endl;
}

void solve3() {
  ll h, w, k; cin >> h >> w >> k;
  ll sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy; sx--, sy--, gx--, gy--;
  vector<string> s(h);
  rep(i, 0, h-1) cin >> s[i];

  auto toId = [&](ll i, ll j, ll v) {
    return (i*w+j)*4+v;
  };
  auto modCeilK = [&](ll x) {
    return (x+k-1)/k*k;
  };

  const ll INF = 1e18;
  vector<ll> dist(h*w*4, INF);
  priority_queue<pll, vector<pll>, greater<pll>> q;
  auto push = [&](ll i, ll j, ll v, ll x) {
    ll id = toId(i,j,v);
    if (dist[id] <= x) return;
    dist[id] = x;
    q.emplace(x,id);
  };

  rep(d, 0, 3) push(sx, sy, d, 0);

  while(q.size()) {
    ll cost = q.top().first;
    ll id = q.top().second;
    q.pop();
    ll i = id/4/w;
    ll j = id/4%w;
    ll v = id%4;

    if(dist[id] < cost) continue;

    rep(nv, 0, 3) {
      push(i, j, nv, modCeilK(cost));

      ll ni = i+di[v], nj = j+dj[v];
      if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
      if(s[ni][nj]=='@') continue;
      push(ni, nj, v, cost+1);
    }
  }

  ll ans = INF;
  rep(i, 0, 3) chmin(ans, dist[toId(gx, gy, i)]);
  if(ans < INF) cout << (modCeilK(ans)/k) << endl;
  else cout << -1 << endl;
}

void solve4() {
  int h, w, k;
  cin >> h >> w >> k;
  int si, sj, ti, tj;
  cin >> si >> sj >> ti >> tj;
  --si; --sj; --ti; --tj;
  vector<string> g(h);
  rep(i, 0, h-1) cin >> g[i];

  auto toId = [&](int i, int j, int v) {
    return (i*w+j)*4+v;
  };
  auto modCeilK = [&](ll x) {
    return (x+k-1)/k*k;
  };
  
  const ll INF = 1e18;
  vector<ll> dist(h*w*4, INF);
  priority_queue<pll, vector<pll>, greater<pll>> q;

  auto push = [&](int i, int j, int v, ll x) {
    int id = toId(i,j,v);
    if (dist[id] <= x) return;
    dist[id] = x;
    q.emplace(x,id);
  };

  rep(v, 0, 3) push(si, sj, v, 0);
  while(q.size()) {
    ll d = q.top().first;
    ll id = q.top().second;
    q.pop();
    if(dist[id] != d) continue;
    int i = id/w/4;
    int j = id/4%w;
    int v = id%4;
    rep(nv, 0, 3) {
      push(i, j, nv, modCeilK(d));

      int ni = i + di[v], nj = j + dj[v];
      if (0 <= ni && ni < h && 0 <= nj && nj < w) {
        if (g[ni][nj] == '.') {
          push(ni,nj,v,d+1);
        }
      }
    }
  }

  rep(v, 0, 3) {
    rep(i, 0, h-1) {
      rep(j, 0, w-1) cout << (dist[toId(i, j, v)]<INF? dist[toId(i, j, v)] : -1) << " "; cout << endl;
    }
    cout << endl;
  }

  ll ans = INF;
  rep(v, 0, 3) ans = min(ans, dist[toId(ti,tj,v)]);
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    ans = modCeilK(ans)/k;
    cout << ans << endl;
  }
}

int main() {
  // solve1();
  // solve2();
  solve3();
  // solve4();
}
