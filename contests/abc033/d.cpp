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
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;

// v[i]-v[j], v[i]-v[k]のなす角度が鋭角、直角、鈍角のどれか
int angle(vector<pii> &v, int i, int j, int k){
  int cos = (v[i].first - v[j].first) * (v[i].first - v[k].first) + (v[i].second - v[j].second) * (v[i].second - v[k].second);
  if(cos > 0) return 1;
  if(cos == 0) return 0;
  else return -1;
}


int main(){
  int n; cin >> n;
  vector<pii> v(n);
  rep(i, 0, n-1) cin >> v[i].first >> v[i].second;

  int ans[3] = {0, 0, 0};
  float EPS = 0.000001;

  rep(i, 0, n-1){
    vector<float> angles(0);
    int x0 = v[i].first;
    int y0 = v[i].second;
    rep(j, 0, n-1){
      if(j == i) continue;
      float theta = atan2(v[j].second - y0, v[j].first - x0);
      angles.push_back(theta + M_PI);
    }
    sort(all(angles));

    int l = 0, r = 0;
    rep(j, 0, n-2){
      while(r <= n-2 && fabs(angles[r] - M_PI/2) >= EPS && angles[r] < M_PI/2) {
        r++;
      } 
      
      int large = n-1 - (r-l);
      int choku = 0;
      while(r <= n-2 && fabs(angles[r] - M_PI/2) < EPS){
        r++;
        large--;
        choku++;
      }

      ans[1] += choku;
      ans[2] += large;

      if(l == r) r++;
      
      l++;
    }
  }

  ans[0] = n*(n-1)*(n-2)/6 - ans[1] - ans[2];

  /*
  rep(i, 0, n-1){
    rep(j, i+1, n-1){
      rep(k, j+1, n-1){
        int a1 = angle(v, i, j, k);
        int a2 = angle(v, j, i, k);
        int a3 = angle(v, k, i, j);
        int mul = a1 * a2 * a3;
        if(mul > 0) ans[0]++;
        else if(mul == 0) ans[1]++;
        else ans[2]++;
      }
    }
  }
  */

  cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}