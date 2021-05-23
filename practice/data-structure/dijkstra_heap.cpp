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
#define INF 100000

typedef struct EDGE {
    int to, cost;
} edge;

typedef pair<int, int> P; // min-distance, node-id

int V, E;

vector<vector<edge>> G(MAX_V, vector<edge>(0));
int dp[MAX_V];
int prev_node[MAX_V];

void search(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dp, dp+V, INF);
    fill(prev_node, prev_node+V, -1);
    dp[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(dp[v] < p.first) continue;

        rep(i, 0, G[v].size()-1){
            edge e = G[v][i];
            if(dp[e.to] > dp[v] + e.cost){
                dp[e.to] = dp[v] + e.cost;
                prev_node[e.to] = v;
                que.push(P(dp[e.to], e.to));
            }
        }
    }
}

void min_route(int v, int s){
    vector<int> bp(0);
    int original_v = v;
    while(v != s){
        int buf_cost=INF;
        int min_k=v;
        rep(k, 0, V-1){
            int cos = INF;
            rep(j, 0, G[k].size()-1){
                if(G[k][j].to == v) cos = G[k][j].cost;
            }
            if(buf_cost > dp[k] + cos){
                buf_cost = dp[k] + cos;
                min_k = k;
            }
        }
        //cout << endl << "node before " << v << "= " << min_k << endl;
        bp.push_back(min_k);
        v = min_k;
    }

    for(int k = bp.size()-1; k >= 0; k--){
        cout << bp[k] << "->";
    }cout << original_v;
}

void prev_route(int v, int s){
    vector<int> bp(0);
    while(v != s){
        bp.push_back(v);
        v = prev_node[v];
    }bp.push_back(v);
    
    for(int i = bp.size()-1; i >= 0; i--){
        cout << bp[i] << "->";
    }
}

int main(){
    int from, to, cos;
    cin >> V >> E;
    rep(i, 0, E-1){
        cin >> from >> to >> cos;
        G[from].push_back(edge{to, cos});
        G[to].push_back(edge{from, cos});
    }


    search(0);
    rep(f, 0, V-1){
        cout << 0 << " to " << f << " = " << dp[f] << " route:";
        //min_route(f, 0);
        prev_route(f, 0);
        cout << endl;
    }
}