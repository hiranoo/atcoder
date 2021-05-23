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
#include <random>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;
#define MAX_V 8
#define MAX_E 100
#define INF 100000

int main(){

  int a, b;
  cin >> a; b = 0;
  int cnt = 0;
  while(cnt < a){
    int c = cnt;
    b |= (1 << c);
    cnt++;
  }
  cout << "res:" << b << " (1<<a)-1:" << (1 << a) -1 << endl; 
  cout << "bitset " << bitset<MAX_V>(b) << " (1<<a)-1:" << bitset<MAX_V>((1 << a) -1) << endl;
}