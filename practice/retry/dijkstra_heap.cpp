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
    int to, cost;
} edge;

typedef pair<int, int> P; // cost, target node


int V, E;
vector<vector<edge>> cost(MAX_V, vector<edge>(0));
vector<int> dp(MAX_V);
vector<int> prev_node(MAX_V);
vector<bool> used(MAX_V);

void search(int s){
    rep(v, 0, V-1){
        dp[v] = INF;
        prev_node[v] = -1;
    }
    dp[s] = 0;

    priority_queue<P> que;
    que.push(P(0, 0));
    
    while(que.size()){
        P p = que.top(); que.pop();
        int v = p.second;

        rep(k, 0, cost[v].size()-1){
            edge e = cost[v][k];
            int to = e.to;
            int cos = e.cost;
            if(dp[to] > dp[v] + cos){
                dp[to] = dp[v] + cos;
                que.push(P{dp[to], to});
            }
        }

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
        cost[from].push_back(edge{to, cos});
        cost[to].push_back(edge{from, cos});
    }

    int s = 0;

    search(s);
    describe(s);
}