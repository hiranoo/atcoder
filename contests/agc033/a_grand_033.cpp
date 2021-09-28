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

typedef struct{
    int x;
    int y;
} P;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int h, w;
vector<vector<int>> area(52, vector<int>(52));
vector<P> seed;
int INF = 3000;
int black = 0;

void display(int sx, int sy){
    cout << "******************" << endl;
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            int p = area.at(y).at(x);
            if(x==sx && y==sy) cout << ' ' << 'p';
            else cout << ' ' << p;
        }cout << endl;
    }cout << endl;
}

bool inside(int x, int y){
    if(0<=x && x<w && 0<=y && y<h && area.at(y).at(x) == 0) return true;
    return false;
}

int search(){
    
}

int main (){
    cin >> h >> w;
    rep(y, 0, h-1){
        rep(x, 0, w-1){
            char buf; cin >> buf;
            if(buf == '.'){
                area.at(y).at(x) = 0;
            }else{
                area.at(y).at(x) = 1;
                P p = {x, y}; seed.push_back(p);
                black++;
            }
        }
    }

    int depth = search();
    //cout << "depth:" << depth << endl;

    cout << depth << endl;
}