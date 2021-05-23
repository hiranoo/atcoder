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

typedef pair<int, int> edge; // to, cost

int V, E;
vector<vector<edge>> cost(MAX_V, vector<edge>(0));
vector<int> dp(MAX_V);
vector<int> prev_node(MAX_V);
vector<bool> used(MAX_V);

void search(int s){
    rep(v, 0, V-1){
        dp[v] = INF;
        prev_node[v] = -1;
        used[v] = false;
    }
    dp[s] = 0;
    
    while(1){
        int v = -1;
        rep(u, 0, V-1){
            if(!used[u] && (v==-1 || dp[v] > dp[u]) ) v = u;
        }

        if(v == -1) break;

        rep(nv, 0, cost[v].size()-1){
            edge e = cost[v][nv];
            if(dp[e.first] > dp[v] + e.second){
                dp[e.first] = dp[v] + e.second;
                prev_node[e.first] = v;
            }
        }
        used[v] = true;
    }
}

void describe(int s){
    cout << endl << "Min costs" << endl;
    rep(to, 0, V-1){
        cout << s << "->" << to << ": " << dp[to] << endl;
    }

    int v = 6;
    while(v!=0){
        cout << v << " <- ";
        v = prev_node[v] ;
    }cout << 0 << endl;
}

int main(){
    cin >> V >> E;

    rep(v, 0, E-1){
        int from, to, cos;
        cin >> from >> to >> cos;
        cost[from].push_back(edge(to, cos));
        cost[to].push_back(edge(from, cos));
    }

    int s = 0;

    search(s);
    describe(s);
}