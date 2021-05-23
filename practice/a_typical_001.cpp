#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <stack>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

typedef pair<int, int> P;

int h, w;
vector<string> c(520);
vector<vector<bool>> mapped(520, vector<bool>(520));
int sx,sy,gx,gy;

stack<P> stk;

void display(){
	cout << "\n***********************" << endl;
	rep(y, 0, h-1){
		cout << c[y] << endl;
	}
}
void search(int x, int y){
	if( x < 0 || w <= x || y < 0 || h <= y || c[y][x]=='#') return;
	if(mapped[y][x]) return;

	mapped[y][x] = true;

	search(x+1,y);
	search(x-1,y);
	search(x,y+1);
	search(x,y-1);
}

bool stack_search(int sx, int sy){
	stk.push(P(sx, sy));
	int cnt =0;
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	while(stk.size()){
		//cout << "\ncnt: " << cnt << endl;
		
		P p = stk.top();stk.pop();
		int x = p.first;
		int y = p.second;
		//cout << " x:" << x << " y:" << y << endl;
		if( x==gx && y==gy){
			return true;
		}
		if( x < 0 || w <= x || y < 0 || h <= y || c[y][x]=='#') continue;
		if(mapped[y][x]) continue;
		mapped[y][x] = true;
		//cout << "pushing neighbours..." << endl;
		stk.push(P(x+1, y));
		stk.push(P(x-1, y));
		stk.push(P(x, y+1));
		stk.push(P(x, y-1));
	}
	return false;
}

bool inside(int x, int y){
	if( x < 0 || w <= x || y < 0 || h <= y || c[y][x]=='#') return false;
	return true;
}
void set_outside(int x, int y){
	if( !(x < 0 || w <= x || y < 0 || h <= y) ) c[y][x] = '#';
}
void set_passed(int x, int y){
	if( !(x < 0 || w <= x || y < 0 || h <= y) ) c[y][x] = 'p';
}
bool goal(int x, int y){
	if( !(x < 0 || w <= x || y < 0 || h <= y) && c[y][x] != 'g') return true;
	return false;
}
bool scan(int lx, int rx, int y){
	//cout << "scanning lx, rx, y:" << lx << " " << rx << " " << y << endl;
	bool added = false;
	for(int x = lx; x <= rx; x++){
		//cout << "x:" << x << endl;
		if(!inside(x, y)) added=false;
		else if(!added){
			stk.push(P(x, y));
			added = true;
			//cout << "pushed: " << x << " " << y << endl;
		}
		if(inside(x, y)) set_passed(x,y);
		if(x==gx && y==gy) return true;
	}
	return false;
}

bool scan_search(int sx, int sy){
	//display();

	// inside (x,y)
	if(!inside(sx,sy)) return false;
	//stack<P> stk;
	stk.push(P(sx,sy));
	while(stk.size()){
		//display();
		P p = stk.top(); stk.pop();
		int x = p.first; int y = p.second;
		int lx = x;
		//cout << "x:" << lx << " y:" << y << endl;
		// left scan
		while(inside(lx-1,y)){
			//cout << "l loop" << endl;
			set_outside(lx-1, y);
			lx = lx -1;
		}
		// right scan
		while(inside(x,y)){
			//cout << "r loop/ x:" << x << endl;
			set_outside(x, y);
			x = x+1;
		}
		
		scan(lx, x-1, y+1);
		scan(lx, x-1, y-1);

		if(goal(gx, gy)) return true;
	}
	return false;
}

int main(){
	cin >> h >> w;
	rep(i, 0, h-1){
		cin >> c[i];
	}
	rep(y, 0, h-1){
		rep(x, 0, w-1){
			mapped[y][x] = false;
			if(c[y][x] == 's'){
				sx = x; sy = y;
			}
			if(c[y][x] == 'g'){
				gx = x; gy = y;
			}
		}
	}

	/*
	search(sx,sy);
	if(mapped[gy][gx]) cout << "Yes" << endl;
	else cout << "No" << endl;
	*/
	
	/*
	if(stack_search(sx, sy)) cout << "Yes" << endl;
	else cout << "No" << endl;
	*/

	if(scan_search(sx, sy) || !inside(gx, gy)) cout << "Yes" << endl;
	else cout << "No" << endl;


	return 0;
}
