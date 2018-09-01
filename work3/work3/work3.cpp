// work3.cpp: определяет точку входа для консольного приложения.
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
pair<long long, long long> tM;
pair<long long, long long> tA;
int main() {
	tM.first = 1000000007;
	tM.second = 1000000009;
	tA.first = 10007;
	tA.second = 10009;
	int ans = 0;
	string s[2];
	cin >> s[0];
	s[1] = s[0];
	reverse(s[1].begin(), s[1].end());
	pair<long long, long long> pt;
	vector<pair<long long, long long>>a(s[0].size());
	int zzz = 1;
	vector<vector<pair<long long, long long>>> v(2, vector<pair<long long, long long>>(s[0].size() - zzz + 1));
	for (int y = 1; y >= 0; y--) {
		for (long long i = 0; i < zzz; i++) {
			v[y][0].first = (v[0][y].first *tA.first + s[y][i]) % tM.first;
			v[y][0].second = (v[0][y].second *tA.second + s[y][i]) % tM.second;
		}
		for (long long i = zzz; i < s[y].size(); i++) {
			v[y][i - zzz + 1].first = (v[y][i - zzz].first *tA.first + s[y][i]) % tM.first;
			v[y][i - zzz + 1].second = (v[y][i - zzz].second*tA.second + s[y][i]) % tM.second;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			cout << v[i][j].first << " " << v[i][j].second << " ";
		}
		cout << endl;
	}
	a[0].first = 1;
	a[0].second = 1;
	for (int i = 1; i < s[0].size(); i++) {
		a[i].first = (a[i-1].first*tA.first) % tM.first;
		a[i].second = (a[i-1].second*tA.second) % tM.second;
	}

	for (int i = 0; i < s[0].size(); i++) {
		
	}
}