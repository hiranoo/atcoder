#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

typedef pair<int, int> P;

vector<string> a(10);
vector<string> reached(10);

void display(vector<string> m){
	//cout << "\n-------------------" << endl;
	rep(y, 0, 9){
		//cout << m[y] << endl;
	}	
}
bool inside(int x, int y){
	if( 0<=x && x<10 && 0<=y && y<10 && reached[y][x] == 'o') return true;
	return false;
}

bool sea(int x, int y){
	if( 0<=x && x<10 && 0<=y && y<10 && reached[y][x] == 'x') return true;
	return false;
}

bool judge(){
	rep(y, 0, 9){
		rep(x, 0, 9){
			if(inside(x,y)){
				return false;
			}
		}
	}
	return true;
}

bool search(int x, int y){
	// initialize reached map
	copy(a.begin(), a.end(), reached.begin());
	//reached[1][1] = 'r';
	////cout << "first copied map" << endl;
	//display(reached);
	
	// 埋め立て不可能（陸）ならば、falseを返す
	if(inside(x, y)) return false;
	
	// initialize stk
	stack<P> stk;
	stk.push(P(x, y));

	int dx[4] = {0,1,0,-1};
	int dy[4] = {-1,0,1,0};

	while(stk.size()){
		//display(reached);
		P p = stk.top(); stk.pop();
		int x = p.first; int y = p.second;
		
		// 範囲外はスキップ
		if( !(inside(x, y) || sea(x, y)) ) continue;

		//cout << " x: " << x << " y: " << y << " reached[x]: " << reached[y][x] << endl;
		
		reached[y][x] = 'x';
		
		rep(i, 0, 3){
			int nx = x + dx[i]; int ny = y + dy[i];
			// debug
			//cout << "  nx: " << nx << " ny: " << ny;
			//if(inside(nx, ny) || sea(nx, ny)) //cout << " reached: " << reached[ny][nx];
			//cout << endl;

			if(inside(nx, ny)) stk.push(P(nx, ny));
		}
	}

	display(reached);
	
	return judge();
}

int main(){
	rep(i, 0, 9){
		cin >> a[i];
	}

	bool flag = false;
	rep(y, 0, 9){
		rep(x, 0, 9){
			//cout << "\n///////// start /////////" << endl;
			//cout << "sx: " << x << " sy: " << y << " map: " << a[y][x] << endl;
			if(search(x,y)){
				flag = true;
				//cout << "X,Y= " << x << ", " << y << endl;
				break;
			}
		}
		if(flag) break;
	}

	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
