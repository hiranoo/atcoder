#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

int INF = 100000;

int heap[100] = {-INF};
int size = 0;

void push(int x){
	int i = size++;
	while(i>0){
		int p = (i-1)/2;
		if(heap[p] <= x) break;
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}

int pop(){
	int tail = heap[size-1]; size -= 1;
	int res = heap[0];

	int i = 0;
	while(i *2 + 1 < size){
		int ch1 = 2*i + 1;
		int ch2 = 2*i + 2;
		if(ch2 < size && heap[ch2] < heap[ch1]) ch1 = ch2;
		if(heap[ch1] > tail) break;
		heap[i] = heap[ch1];
		i = ch1;
	}

	heap[i] = tail;

	return res;
}

void display(int n, char command){
	if(n==0){
		cout << "#### before " << command << " ##############" << endl;
	}else{
		cout << "#### after " << command << " ##############" << endl;
	}

	for(int i = 0; i < size; i++){
		cout << heap[i] << ' ';
	}cout << endl << endl;

}

int main(){
	char command;
	int x;
	while(1){
		cout << "command-- push: input a, pop: input b" << endl;
		cin >> command;
		if(command == 'a') {
			cin >> x; 
			display(0, command);
			push(x);
			display(1, command);
		}else{
			display(0, command);
			pop();
			display(1, command);
		}
	}

	return 0;
}
