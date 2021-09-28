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

typedef pair<int, int> P;

int MAX_V = 5;

vector<vector<int>> G(MAX_V, vector<int>());
vector<int> color(MAX_V);

bool judge(){
    rep(i, 0, MAX_V-1){
        if(color[i]==0) return false;
    }
    return true;
}

void display(int n, int c){
    cout << "node:" << n << " color:" << c << " already colored?:" << color[n] << endl;
}
bool search(){
    stack<P> stk;
    stk.push(P(0, 1));
    rep(i, 0, MAX_V-1) color[i] = 0;
    while(stk.size()){
        P p = stk.top(); stk.pop();
        int n = p.first;
        int c = p.second;

        display(n, c);
        if(color[n] != 0 && color[n] != c) return false;
        if(color[n] != 0) continue;
        color[n] = c;

        rep(i, 0, G[n].size()-1){
            cout << " n:" << n << " i:" << i << " G[n][i]:" << G[n][i] << endl;
            stk.push(P(G[n][i], -c));
        }
    }
    return true;
}

int main(){
    int from, to;
    while(1){
        cout << "input from to" << endl;
        cin >> from >> to;
        if(from==-1) break;
        G[from].push_back(to);
        G[to].push_back(from);
    }

    rep(i, 0, MAX_V-1){
        rep(j, 0, G[i].size()-1){
            cout << " from:" << i << " to:" <<  G[i][j] << endl;
        }
    }
    bool res = search();
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
}