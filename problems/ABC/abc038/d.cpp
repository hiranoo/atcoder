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

typedef struct Box{
  int h, w;
  bool operator < (const Box& b){
    if(h == b.h) return (w > b.w);
    return (h < b.h);
  }
} P;

long n;
vector<P> box(0);

int op(int i, int j){
  return max(i, j);
}

int e(){
  return 0;
}

// dp.get(i)は、幅wの箱を外側として最も入れ子が多くなるときの入れ子数
atcoder::segtree<int, op, e> dp(MAX_N); // e()で初期化される？

int search(){
  int res = 0;
  for(int i = 0; i < n; i++){
    // dp[i] = max(dp[j] | box[j].w < box[i].w) + 1
    int w = box[i].w;
    int tmp = dp.prod(0, w) + 1; // log(n)
    //cout << " i:" << i << " h:" << box[i].h << " w:" << w << " dp(3):" << dp.get(3) << " dp(5):" << dp.get(5) << " dp(6):" << dp.get(6) << endl;
    if(tmp > dp.get(w)){
      dp.set(w, tmp); // log(n)
      res = max(res, tmp);
    }
  }
  //cout << "fin::" << " dp(3):" << dp.get(3) << " dp(5):" << dp.get(5) << " dp(6):" << dp.get(6) << endl;
  return res;
}

int main(){
  cin >> n;
  rep(i, 0, n-1){
    int a, b;
    cin >> a >> b;
    box.push_back(P{a, b});
  }

  // 箱のhが小さい順にソート hが同じときはwが大きい順にソート
  sort(box.begin(), box.end());

  int ans = search();
  cout << ans << endl;

}