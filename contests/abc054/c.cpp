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
#define MAX_V 8
#define MAX_E 100
#define INF 100000

typedef pair <int, int> P;

int V, E;
vector<vector<int>> G(MAX_V, vector<int>(0));

int search(int v, bool visited[MAX_V]){
  bool allvisited = true;
  rep(i, 0, V-1){
    if(!visited[i]) allvisited = false;
  }

  if(allvisited) return 1;

  int ret = 0;
  rep(i, 0, G[v].size()-1){
    int nv = G[v][i];
    if(visited[nv]) continue;
    visited[nv] = true;
    ret += search(nv, visited);
    visited[nv] = false;
  }
  return ret;
}

int search2(int v, int visited){
  bool allvisited = true;
  rep(i, 0, V-1){
    if(!(visited & (1 << i))) allvisited = false;
  }

  //if(allvisited) return 1;
  //if(visited == (1 << E) -1) return 1; //この比較はよくないらしい（理由は不明） 
  if(bitset<MAX_V>(visited).count() == V) return 1;

  int ret = 0;
  rep(i, 0, G[v].size()-1){
    int nv = G[v][i];
    if(visited & (1 << nv)) continue;
    //visited[nv] = true;
    ret += search2(nv, (visited | (1 << nv)));
    //visited[nv] = false;
  }
  return ret;
}


int search_stack(int s){
  stack<P> stk;
  stk.push(P(0, 1));
  int ret = 0;

  while(stk.size()){
    P p = stk.top(); stk.pop();
    int v = p.first;
    int visited = p.second;
    
    if( visited == (1 << E)-1 ){
      ret++;
      continue;
    }

    visited |= (1 << v);

    rep(i, 0, G[v].size()-1){
      int nv = G[v][i];
      if(visited & (1 << nv)) continue;
      stk.push(P(nv, (visited | (1 << nv)) ));
    }
  }

  return ret;
}

int main(){
  cin >> V >> E;

  rep(v, 0, E-1){
      int from, to;
      cin >> from >> to;
      G[from-1].push_back(to-1);
      G[to-1].push_back(from-1);
  }

  bool visited[MAX_V];
  visited[0] = true;
  rep(i, 1, V-1) visited[i] = false;

  int ans = search2(0, 1);
  //int ans = search_stack(0);
  cout << ans << endl;

}