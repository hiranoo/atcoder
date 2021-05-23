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
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;
#define MAX_V 100
#define MAX_E 100
#define INF 100000
#define MAX_N 100005

int main(){
  int n; cin >> n;
  vector<int> w(n);
  rep(i, 0, n-1) cin >> w[i];

  //cout << 0 << endl;
  //vector<vector<int>> memo(10, vector<int>(0));

  vector<int> yama(0);
  for(int i = 0; i < n; i++){
    // 自分の乗っかれる山がないなら、自分が山になる
    bool ok = false;
    for(int j = 0; j < yama.size(); j++){
      if(yama[j] >= w[i]){
        ok = true;
        break;
      }
    }
    if(!ok){
      yama.push_back(w[i]);
      //cout << "yama_id: " << yama.size()-1 << " i:" << i << " w[i]:" << w[i] << endl;
      //memo.at(yama.size()-1).push_back(w[i]);
      continue;
    }

    // 自分が乗っかれる山のうちてっぺんが最も軽い山に乗る
    int min_yama_id = -1;
    for(int j = 0; j < yama.size(); j++){
      if(yama[j] >= w[i]){
        if(min_yama_id == -1){
          min_yama_id = j;
        }else if(yama[j] < yama[min_yama_id]){
          min_yama_id = j;
        }
      }
    }
    yama[min_yama_id] = w[i];
    //memo.at(min_yama_id).push_back(w[i]);
  }

  cout << yama.size() << endl;

  /*
  cout << endl;

  for(int i = 0; i < 10; i++){
    cout << "i:" << i << endl;
    for(int j = 0; j < memo.at(i).size(); j++){
      cout << " " << memo.at(i).at(j) << endl;
    }
  }
  */
}