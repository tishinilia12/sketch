// work1.cpp: определяет точку входа для консольного приложения.
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

vector<vector<int> >g;
int main() {
	int n, m;
	string s;
	cin >> n >> m;
	g.resize(n + m);
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j]=='1') {
				g[i].push_back(j+n);
				g[j + n].push_back(i);
			}
		}
	}
	
	return 0;
}
