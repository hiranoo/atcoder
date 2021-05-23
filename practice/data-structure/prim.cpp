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

typedef struct EDGE{
    int from, to, cost;
} edge;

int V, E;
vector<vector<int>> cost(MAX_V, vector<int>(MAX_V));
vector<bool> inside_x(MAX_V); // 集合Xに含まれるか
vector<int> mincost(); // 集合Xと頂点ｖを繋ぐ最小コスト

int prim(){
    rep(v, 0, V-1){
        inside_x[v] = false;
        mincost[v] = INF;
    }

    mincost[0] = 0;
    int res = 0;
    while(1){
        int v = -1;
        rep(u, 0, V-1){
            // 集合X に含まれない頂点のうち、どの頂点vをXに加えると、Xのコストが最小になるか
            if(!inside_x[u] && (v==-1 || mincost[v] > mincost[u]+cost[u][v])){
                v = u;
            }
        }

        if(v == -1) break;

        inside_x[v] = true;
        res += mincost[v];
        
        rep(u, 0, V-1){
            // 集合Xとの最小距離を更新　mincost[u]:X\{v}との最小距離, cost[u][v]: vとの最小距離
            mincost[u] = min(mincost[u], cost[u][v]); // 集合Xの要素u についてはmincost[u] = 0だが、もう使わないので考慮していない
        }
    }
    

}

int main(){
    cin >> V >> E;

    rep(v, 0, V-1){
        rep(k, 0, V-1){
            cost[v][k] = INF;
        }cost[v][v] = 0;
    }
    rep(i, 0, E-1){
        int from, to, cos;
        cin >> from >> to >> cos;
        cost[from][to] = cos;
        cost[to][from] = cos;
    }

    int min_cost = prim();
    cout << min_cost << endl;
}