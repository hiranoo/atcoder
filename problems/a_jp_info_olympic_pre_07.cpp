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
    int vit;
} P;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int h, w;
int sx, sy, gx, gy;
vector<vector<int>> area(502, vector<int>(502));
vector<vector<int>> passed(502, vector<int>(502));

int main(){
  int n; cin >> n;
  n = 1000 - n;

  int cnt = 0;
  vector<int> coin = {500, 100, 50, 10, 5, 1};
  rep(i, 0, coin.size()-1){
    int tmp = n / coin[i];
    //cout << "n:" << n << " coin:" << coin[i] << " tmp:" << tmp << endl;

    n -= coin[i] * tmp;

    cnt += tmp;
  }

  cout << cnt << endl;
}