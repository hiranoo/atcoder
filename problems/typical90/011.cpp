#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
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

struct J {
  int sd, c, s;
  J(int sd=0, int c=0, int s=0) : sd(sd), c(c), s(s) {}
  bool operator< (const J &j){
    if(sd == j.sd){
      if(c < j.c) return true;
      if(c > j.c) return false;
      if(c == j.c) return s < j.s;
    }
    return sd < j.sd;
  }
};

int main(){
  int n; cin >> n;
  vector<J> jobs;
  rep(i, 0, n-1){
    int d, c, s; cin >> d >> c >> s;
    if(d+1 < c) continue;
    jobs.emplace_back(J(d+1-c, c, s/10000000));
  }
  sort(all(jobs));

  for(auto j : jobs) printf("sd: %d, c: %d, s:%d\n", j.sd, j.c, j.s);

  ll score = 0;
  for(ll i = 0; i < 1LL << n; i++){
    //cout << bitset<5>(i) << endl;
    ll sum = 0;
    bool can = true;
    int today = 1;
    for(int j = 0; j < n; j++){
      if(i & 1LL << j) {
        //printf("jobs[%d] sd:%d, c:%d, s:%d\n", j, jobs[j].sd, jobs[j].c, jobs[j].s);
        if(today <= jobs[j].sd){
          sum += jobs[j].s;
          today += jobs[j].c;
        }else{
          can = false;
          break;
        }
      }
    }
    if(can) score = max(score, sum);
  }

  cout << score << endl;
}