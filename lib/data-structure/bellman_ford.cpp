#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

int INF = 100000;
typedef struct EDGE {
    int from;
    int to;
    int cost;
} edg;

int MAX_V = 100;
int V, E;

int s = 0;

vector<edg> G(0);
vector<int> dp(MAX_V);

void search(){
    rep(i, 0, V-1){
        dp[i] = INF;
    }
    dp[s] = 0;
    while(1){
        bool update = false;
        rep(m, 0, 2*E-1){
            edg e = G[m];
            cout << "(from, to, cost):" << e.from << " " << e.to << " " << e.cost;
            cout << " dp(from):" << dp[e.from] << " dp(to):" << dp[e.to];
            if(dp[e.from]!=INF && dp[e.to] > dp[e.from] + e.cost){
                dp[e.to] = dp[e.from] + e.cost;
                update = true;
                cout << " -> " << dp[e.to];
            }cout << endl;
        }
        if(!update) break;
    }
}

int main(){
    int from, to, cost;
    cin >> V >> E;
    rep(i, 0, E-1){
        cin >> from >> to >> cost;
        G.push_back(edg{from, to, cost});
        G.push_back(edg{to, from, cost});
    }

    rep(i, 0, G.size()-1){
        cout << "from, to, cost=" << G[i].from << " " << G[i].to << " " << G[i].cost << endl;
    }
    search();
    rep(f, 0, V-1){
        cout << s << " to " << f << " = " << dp[f] << endl;
    }
}