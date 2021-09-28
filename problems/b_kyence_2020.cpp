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
#define MAX_N 100005

typedef struct Robot{
  long first, second;
  bool operator < (const Robot& r){
    return (first + second < r.first + r.second);
  }
} R;

long n; 
vector<R> robots(0);

long left(long i){
  return robots[i].first - robots[i].second;
}
long right(long i){
  return robots[i].first + robots[i].second;
}

/*
struct less_than_key
{
    inline bool operator() (const R& struct1, const R& struct2)
    {
        return (struct1.first + struct1.second < struct2.first + struct2.second);
    }
};
*/

long search(){
  long k = 0;
  long ans = 1;
  while(k < n){
    bool updated = false;
    rep(i, k+1, n-1){
      //cout << k << " " << i << " r:" << right(k) << " l:" << left(i) << endl;
      if(right(k) <= left(i)){
        k = i;
        updated = true;
        break;
      }
    }
    if(!updated) break;
    
    ans++;
  }
  return ans;
}

int main(){
  cin >> n;
  rep(i, 0, n-1){
    int x, l;
    cin >> x >> l;
    robots.push_back(R{x, l});
  }

  // 終点でソート
  //sort(robots.begin(), robots.end(), less_than_key());
  sort(robots.begin(), robots.end());
  
  //cout << "robots" << endl;
  //rep(i, 0, n-1) cout << robots[i].first << " " << robots[i].second << endl;

  long ans = search();
  cout << ans << endl;
}