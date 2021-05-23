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

typedef pair<int, int> edge;
typedef struct PLOG{
  int node;
  long log;
} P;

int V, E;
vector<vector<int>> G(MAX_V, vector<int>(0));
int res = 0;
//vector<int> vmap(MAX_V);
//int vmap = 0;

void display(int v, int log){
  rep(i, 0, V-1){
    if((1<<i) & log) cout << " " << i;
  }
  cout << ": " << v << endl;
}

int search(int s){
  int res = 0;

  stack<P> stk;
  stk.push(P{s, 0});

  while(stk.size()){
    P p = stk.top(); stk.pop();
    int v = p.node;
    long log = p.log;

    
    if((1 << v) & log) continue; // visit a vertex only a time

    log += (1 << v); // visit vertex v

    //if visited all vertexes, increment res and search other paths
    if(log == (1 << E) -1){
      res++;
      //display(v, log);
      continue;
    }

    rep(j, 0, G[v].size()-1){
      stk.push(P{G[v][j], log});
    }
  }

  return res;
}

void search2(int s, int visited){
  
  if(visited & (1 << s)){
    return;
  }

  //display(s, visited);
  if(visited + (1 << s) == (1 << E) - 1){
    res++;
    return;
  }


  rep(k, 0, G[s].size()-1){
    int nv = G[s][k];
    search2(nv, visited + (1 << s));
  }
  return;
}

int search3(int v, bool visits[MAX_V]){
  rep(i, 0, V-1){
    if(visits[i]) cout << i << ",";
  }cout << "::" << v << endl;

  bool completed = true;
  rep(i, 0, V-1){
    if(!visits[i]){
      completed = false;
      break;
    }
  }
  cout << completed << endl;
  if(completed){
    return 1;  
  }

  int ret = 0;

  rep(i, 0, G[v].size()-1){
    int nv = G[v][i];
    if(visits[nv]) continue;
    visits[nv] = true;
    ret += search3(nv, visits);  
    visits[nv] = false;
  }

  cout << "ret: " << ret << endl;

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

    rep(i, 0, V-1){
      rep(j, 0, G[i].size()-1){
        //cout << i << " - " << G[i][j] << endl;
      }
    }

    bool visits[MAX_V] = {false}; visits[0] = true;
    int s = 0;
    //search2(s, 0);
    int ans = search3(0, visits);
    cout << res << endl;
}