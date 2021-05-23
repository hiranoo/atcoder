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
#define MAX_V 100
#define INF 100000


int V, E;

int s = 0;

vector<vector<int>> cost(MAX_V, vector<int>(MAX_V));
vector<int> dp(MAX_V);
bool used[MAX_V];

void search(){
    rep(i, 0, V-1){
        dp[i] = INF;
    }
    dp[s] = 0;
    while(1){
        int v = -1;
        rep(u, 0, V-1){
            if(!used[u] && (v==-1 || dp[v] > dp[u])) v = u;
        }

        if(v == -1) break;

        used[v] = true;
        
        rep(u, 0, V-1){
            
            dp[u] = min(dp[u], dp[v] + cost[v][u]);
        }
        
    }
}

int main(){
    int from, to, cos;
    cin >> V >> E;
    rep(i, 0, V-1){
        rep(j, 0, V-1){
            cost.at(i).at(j) = INF;
        }cost[i][i] = 0;
    }
    rep(i, 0, E-1){
        cin >> from >> to >> cos;
        cost[from][to] = cos;
        cost[to][from] = cos;   
    }


    search();
    
    rep(f, 0, V-1){
        cout << s << " to " << f << " = " << dp[f] << endl;
    }
}