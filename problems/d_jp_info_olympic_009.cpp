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
#define MAX_V 8
#define MAX_E 100
#define MAX_N 10
#define INF 100000

typedef struct pp{
  int id;
  int choice;
  long number;
}P;

int n, k;
int card[MAX_N];
vector<long> created(0);
vector<bool> used(MAX_N);

// ソート関数
template<class T>
inline void container_sort(std::vector<T>& v) {
  std::sort(v.begin(), v.end());
}

//////////////////////////////
// 重複削除関数
template<class T>
void vec_unique(T& v) {

  container_sort(v);
  v.erase(
    std::unique(
      v.begin(),
      v.end()),
    v.end()
  );

}

void display(){
  rep(i, 0, created.size()-1) cout << created[i] << " ";
  cout << endl;
}

int keta(int num){
  int cnt = 0;
  while(num > 0){
    num /= 10;
    cnt++;
  }
  return cnt;
}
int search(){
  stack<P> stk;
  rep(i, 0, n-1){
    stk.push(P{i, 0, 0});
  }

  while(stk.size()){
    P p = stk.top(); stk.pop();
    int id = p.id; // 何枚目のカードを選ぶのか
    int ch = p.choice; //今までに選んだカードのbit列
    long num = p.number; //いままでに合成した数

    int depth = bitset<MAX_N>(ch).count();

    if(depth > k) continue;

    // choose card? then set bit
    ch |= (1 << id);

    ///cout << "card:" << card[id] << " num:" << num << " bit:" << bitset<MAX_N>(ch) << endl;

    // register the number
    if(depth == k){
      created.push_back(num);
      continue;
    }

    

    // choose next card
    rep(i, 0, n-1){
      if(!(ch & (1<<i))){
        ///cout << "next:" << " card:" << card[i] << " now-num:" << num << " bit:" << bitset<MAX_N>(ch) << endl;
        int new_num = pow(10, keta(num))*card[id] + num;
        stk.push(P{i, ch, new_num}); //次に選ぶカード、今までに選んだカード群、今までに合成した数
      }
    }
  }

  vec_unique(created);

  ///display();

  return created.size();
}

int main(){

  cin >> n;
  cin >> k;

  
  rep(i, 0, n-1){
    cin >> card[i];
  }

  int ans = search();
  cout << ans << endl;
}