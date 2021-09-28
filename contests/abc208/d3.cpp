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

struct P {
  int x, y;
  P (int x=0, int y=0) : x(x), y(y) {}
  P operator+ (const P &v){
    return P(x+v.x, y+v.y);
  }
  P operator- (const P &v){
    return P(x-v.x, y-v.y);
  }
  bool operator== (const P &v){
    return x==v.x && y==v.y;
  }
  int norm(){
    return x*x + y*y;
  }
  int dot(const P &v){
    return x*v.x + y*v.y;
  }
  int cross(const P &v){
    return x*v.y - y*v.x;
  }
};

struct RT {
  double ang; int norm; int id;
  RT(double ang=0, int norm=0, int id=-1) : ang(ang), norm(norm), id(id) {}
  bool operator< (const RT &v){
    if(ang == v.ang) return norm < v.norm;
    return ang < v.ang;
  }
};

void z_algorithm(vector<int> &s,vector<int> &arr){
  int i,j,k,l;
	l=s.size();
  arr[0]=l;
  i=1;j=0;
  while(i<l){
    while((i+j)<l){
      if(s[j]!=s[i+j]){break;}
      j++;
    }
    arr[i]=j;
    if(j==0){i++;continue;}
    k=1;
    while((i+k)<l){
      if(k+arr[k]>=arr[i]){break;}
      arr[i+k]=arr[k];
      k++;
    }
    j=arr[i]-k;
    i+=k;
  }
}

int main() {
  int n; cin >> n;
  vector<P> a(n), b(n);
  rep(i, 0, n-1) cin >> a[i].x >> a[i].y;
  rep(i, 0, n-1) cin >> b[i].x >> b[i].y;

  if(n == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  
  // a, bについて、座標をn倍、重心を計算
  P g_a = P(0,0), g_b = P(0,0);
  for(auto &v : a) {g_a = g_a + v; v = P(n*v.x, n*v.y);}
  for(auto &v : b) {g_b = g_b + v; v = P(n*v.x, n*v.y);}
  for(auto &v : a) v = v - g_a;
  for(auto &v : b) v = v - g_b;

  // 重心に一致する点は除外する
  bool a_erase=false, b_erase=false;
  if(find(all(a), P(0, 0)) != a.end()) {a.erase(find(all(a), P(0, 0))); a_erase=true;}
  if(find(all(b), P(0, 0)) != b.end()) {b.erase(find(all(b), P(0, 0))); b_erase=true;}
  if((a_erase && !b_erase) || (!a_erase && b_erase)){
    cout << "No" << endl; return 0;
  }
  if(a_erase) n--;

  // 偏角ソート
  vector<RT> rt_a(n), rt_b(n);
  rep(i, 0, n-1) rt_a[i] = RT(atan2(a[i].y, a[i].x), a[i].norm(), i); 
  rep(i, 0, n-1) rt_b[i] = RT(atan2(b[i].y, b[i].x), b[i].norm(), i);
  sort(all(rt_a));
  sort(all(rt_b));

  // norm, 内積, 外積 をパラメータとして配列化
  vector<int> na(3*n), nb(3*n);
  rep(i, 0, n-1){
    int j = rt_a[i].id;
    int nj = rt_a[(i+1)%n].id;
    na[3*i] = a[j].norm();
    na[3*i+1] = a[j].dot(a[nj]);
    na[3*i+2] = a[j].cross(a[nj]);
  }
  rep(i, 0, n-1){
    int j = rt_b[i].id;
    int nj = rt_b[(i+1)%n].id;
    nb[3*i] = b[j].norm();
    nb[3*i+1] = b[j].dot(b[nj]);
    nb[3*i+2] = b[j].cross(b[nj]);
  }

  // 数列na, nbが3要素ずつのローテーションで一致するかどうかを判定
  // z-algorithmを使うとO(n) らしい
  /*
  rep(i, 0, n-1){
    bool same = true;
    rep(j, 0, n-1){
      int nj = (j + i) % n;
      if(!(na[3*j]==nb[3*nj] && na[3*j+1]==nb[3*nj+1] && na[3*j+2]==nb[3*nj+2])){
        same = false;
        break;
      }
    }
    if(same) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  */
  
  // z_algorithm
  vector<int> zs;
  int sn = na.size();
  for(auto v : na) zs.push_back(v);
  for(auto v : nb) zs.push_back(v);
  for(auto v : nb) zs.push_back(v);
  vector<int> zr(sn*3);
  z_algorithm(zs, zr);  
  for(int i = sn; i < 2*sn; i+=3) if(zr[i] >= sn){cout << "Yes" << endl; return 0;}
  cout << "No" << endl;
}
