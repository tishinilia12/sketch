// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
//
#include <iostream> 
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <stack>
#include <fstream>
#include <bitset>
#include <sstream> 
#include <unordered_map>

using namespace std;
#define x first
#define y second
int h, w, need, n;
vector<pair<int, int>>point;
vector < pair<int, vector<int> > > bot;
bool f(int mid) {
	int mx = -1;
	for (int i = 0; i < n; i++) {
		pair<int, vector<int> > tmp;
		if (point[i].x-mid-1 < 0) {
			tmp.x = 0;
		}
		else {
			tmp.x = point[i].x - mid - 1;
		}


	}
}
int main() {
	
	cin >> w >> h >> need >> n;
	point.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> point[i].x >> point[i].y;
	}
	sort(point.begin(), point.end());
	int r = max(h, w) + 1;
	int l = -1;
	int mid;
	while (l!=r+1) {
		mid = (l + r) / 2;
		if (f(mid)) {
			r = mid + 1;
		}
		else {
			l = mid;
		}
	}
	cout << l;
	return 0;
}
/**/