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

int main() {
	int a[2];
	a[0] = 0;
	a[1] = 0;
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].second;
		v[i].second %= 2;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int z = 1;
	for (int i = 0; i < n; i++) {
		z += v[i].second;
		a[z % 2] += v[i].first;
	}
	cout << a[0] << endl;
	return 0;
}