#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"

using namespace std;
//1780backjun 분할정복 문제.
vector<vector<int>> Array;
int MaxN;
int mione=0, zero=0, one=0;
void repeat(int startX,int startY,int N) {
	int mem = Array[startY][startX];
	int flag = 1;
	for (int i = startY; i < startY+N; i++) {
		for (int j = startX; j < startX+N; j++) {
			if (mem != Array[i][j]) {
				int Su = N / 3;
				int X, Y;
				int XP = 1, YP = 1;
				for (int z = 0; z < MaxN; z += Su) {
					if (XP==1&&startX < z) {
						X = z - Su;
						XP = 0;
					}
					if (YP==1&&startY < z) {
						Y = z - Su;
						YP = 0;
					}
				}
				for (int z = 0; z < 3; z++) {
					repeat(X, Y, Su);
					repeat(X + Su, Y, Su);
					repeat(X + Su * 2, Y, Su);
					Y += Su;
				}
				flag = 0;
				break;
			}
				
		}
		if (flag == 0) break;
	}
	if (flag == 1) {
		if (mem == -1) mione++;
		else if(mem == 0) zero++;
		else one++;
	}
}
int main() {
	fast;
	cin >> MaxN;
	int Su;
	for (int i = 0; i < MaxN; i++) {
		vector<int> Ary;
		for (int j = 0; j < MaxN; j++) {
			cin >> Su;
			Ary.push_back(Su);
		}
		Array.push_back(Ary);
	}
	repeat(0, 0, MaxN);
	cout << mione << endl;
	cout << zero << endl;
	cout << one << endl;
}
