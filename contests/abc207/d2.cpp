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
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;
const double EPS = 0.0001;

struct C {
  int x, y;
  C (int x=0, int y=0) : x(x), y(y) {}
  C operator+ (const C &c){
    return C(x+c.x, y+c.y);
  }
  C operator- (const C &c){
    return C(x-c.x, y-c.y);
  }
  C operator* (const C &c){
    return C(x*c.x - y*c.y, x*c.y + y*c.x);
  }
  bool operator< (const C &c){
    if(x == c.x) return y < c.y;
    return x < c.x;
  }
  bool operator== (const C &c){
    return x==c.x && y==c.y;
  }
  int norm() {
    return x*x + y*y;
  }
};

void init(vector<C> &a, int n){
  rep(i, 0, n-1){
    int x, y; cin >> x >> y;
    a[i] = C(x, y);
  }
}

vector<C> move (vector<C> a, C t, C rot) {
  vector<C> vec(a.size()); vec = a;
  rep(i, 0, a.size()-1) vec[i] = vec[i] + t;
  rep(i, 0, a.size()-1) vec[i] = vec[i] * rot;
  return vec;
}

void display(vector<C> &a){
  cout << "##############" << endl;
  for(auto v : a) printf("(%d, %d), ", v.x, v.y);
  cout << endl << endl;
}

int main() {
  int n; cin >> n;
  vector<C> a(n), b(n);
  init(a, n); init(b, n);

  if(n == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      if((a[1]-a[0]).norm() != (b[j]-b[i]).norm()) continue;

      vector<C> aa = move(a, C(0,0)-a[0], b[j]-b[i]);
      vector<C> bb = move(b, C(0,0)-b[i], a[1]-a[0]);
      sort(all(aa));
      sort(all(bb));
      
      /*
      printf("a[0] -> b[%d], a[0]..a[1] -> b[%d]..b[%d]\n", i, i, j);
      display(aa);
      display(bb);
      */

      bool same = true;
      rep(i, 0, n-1) {
        if(!(aa[i] == bb[i])) {
          same = false;
          break;
        }
      }

      if(same) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}