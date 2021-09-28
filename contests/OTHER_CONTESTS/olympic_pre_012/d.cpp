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
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
#define INF 100000;

vector<int> t(202);
vector<int> a(202);
vector<int> b(202);
vector<int> c(202);
vector<vector<int>> cloth(202, vector<int>(0));
vector<vector<int>> dp(202, vector<int>(202));

void display(int i, int n){
    rep(j, 0, i){
        cout << "day " << j << endl;
        rep(k, 0, n-1) cout << " cloth:" << k << " dp:" << dp[j][k] << endl;
    }
}

int main(){
    int d, n; cin >> d >> n;
    rep(i, 0, d-1) cin >> t[i];
    rep(i, 0, n-1) cin >> a[i] >> b[i] >> c[i];
    
    // t[i]について適した服を整理
    rep(i, 0, d-1){
        rep(j, 0, n-1){
            if(a[j] <= t[i] && t[i] <= b[j]) cloth[i].push_back(j);
        }
    }

    // init dp
    rep(i, 0, d-1) rep(k, 0, n-1) dp[i][k] = -INF;
    rep(k, 0, n-1){
        rep(cl, 0, cloth[0].size()-1){
            if(cloth[0][cl] == k) dp[0][k] = 0;
        }
    }
    //rep(k, 0, n-1) cout << dp[0][k] << ", "; cout << endl;
    
    /*
    // prod dp
    // 何日目か
    rep(i, 1, d-1){
        // 各種着ていい服について、dpの最大値を求める
        vector<int> max_vs(n);
        rep(k, 0, cloth[i].size()-1){
            int cl = cloth[i][k];
            int max_v = -INF;
            // 今日はcloth[i][k]を着る。昨日着れたすべての服との組み合わせを考える
            rep(kk, 0, n-1){
                // 昨日は服kkを着た
                int tmp = dp[i-1][kk] + abs(c[cl] - c[kk]);
                if(tmp > max_v){
                    max_v = tmp;
                }
            }
            dp[i][cl] = max_v;
        }
    }
    */

    rep(i, 1, d-1){
      // argmax c[j_max], argmin c[j_min]
      int j_max=0; int j_min=0; 
      int c_max=0; int c_min=INF;
      rep(j, 0, cloth[i].size()-1){
        int cl = cloth[i][j]; int c_now=c[cl];
        if(c_max < c_now){ c_max = c_now; j_max=cl; }
        if(c_min > c_now){ c_min = c_now; j_min=cl; }
      }
      rep(j, 0, n-1){
        dp[i][j_max] = max(dp[i][j_max], dp[i-1][j] + abs(c[j] - c[j_max]));
        dp[i][j_min] = max(dp[i][j_min], dp[i-1][j] + abs(c[j] - c[j_min]));
      }
    }

    int ans = 0;
    rep(k, 0, n-1) ans = max(ans, dp[d-1][k]);
    cout << ans << endl;

    //display(d-1, n);

    return 0;
}   
/*
    // prod dp
    // 何日目か
    rep(i, 1, d-1){
        // 各種着ていい服について、dpの最大値を求める
        vector<int> max_vs(n);
        rep(k, 0, cloth[i].size()-1){
            int max_v = 0;
            // 今日はcloth[i][k]を着る。昨日着れたすべての服との組み合わせを考える
            rep(kk, 0, n-1){
                // 昨日は服kkを着た
                int tmp = dp[kk] + abs(c[cloth[i][k]] - c[kk]);
                if(tmp > max_v){
                    max_v = tmp;
                }
            }
            max_vs[k] = max_v;
        }
        rep(k, 0, cloth[i].size()-1){
            dp[cloth[i][k]] = max_vs[k];
        }
    }
   
    int ans = 0;
    rep(k, 0, n-1) ans += max(ans, dp[k]);
    cout << ans << endl;
    return 0;
}   
*/
