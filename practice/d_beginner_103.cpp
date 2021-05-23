#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;
#define MAX_V 100
#define MAX_E 100
#define INF 100000
#define MAX_N 100005

typedef struct Bridge{
  long first, second;
  bool operator < (const Bridge& r){
    return (second < r.second);
  }
} P;

long n, m;
vector<P> bridges(0);

long search(){
  long k = 0;
  long ans = 1;
  vector<bool> ok(m);
  rep(i, 0, m-1) ok[i] = false;
  ok[0] = true;

  while(k < m){
    //cout << k << endl;
    long now = bridges[k].second;
    bool updated = false;
    rep(i, k+1, m-1){
      if(bridges[i].first < now){
        //cout << k << " " << i << " left(i):" << bridges[i].first << " right(k):" << now << endl;
        ok[i] = true;
        //cout << " " << i << endl;
      }
    }
    
    // next k
    rep(i, k+1, m-1){
      if(!ok[i]){ 
        k = i;
        updated = true;
        break;
      }
    }
    
    if(!updated) break;
    ans++;
  }

  return ans;
}

int main(){
  cin >> n >> m;
  rep(i, 0, m-1){
    int x, l;
    cin >> x >> l;
    bridges.push_back(P{x-1, l-1});
  }

  // 終点でソート
  sort(bridges.begin(), bridges.end());
  
  //cout << "bridges" << endl;
  //rep(i, 0, m-1) cout << bridges[i].first << " " << bridges[i].second << endl;

  long ans = search();
  cout << ans << endl;
}