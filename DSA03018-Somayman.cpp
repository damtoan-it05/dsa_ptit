#include<iostream>
#include<algorithm>
using namespace std;
int n;
void Init() {
	cin >> n;
}
void result(int x1, int x2) {
	for(int i=0; i<x1; i++) {
		cout <<"4";
	}
	for(int i=0; i<x2; i++) {
		cout <<"7";
	}
}
void Greedy() {
	int x1=n/4, x2=n/7,x=-1,y=-1;
	int s=x1+x2;
	for(int i=x2; i>=0; i--) {
		x1=(n-i*7)/4;
		if((x1*4 + i*7)==n) {
			if(s>x1+x2){
				s=x1+x2;
				x=x1;
				y=i;
			}
			else if(s==x1+x2 && x1 > x){
				x=x1;
				y=i;
			}
		}
	}
	if(x==-1){
		cout << "-1";
		return;
	}
	result(x,y);
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		Init();
		Greedy();
		cout << endl;
	}
	return 0;
}