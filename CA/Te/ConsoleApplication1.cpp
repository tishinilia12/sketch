// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
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
#include <cstring>
#include <ctype.h>


using namespace std;
int main() {
	int n = 99, k = 100,p;
	cin >> p;
	k = 1;
	if (p == 2) {
		cout << "4 5" << endl;
		cout << "2 1 2" << endl << "1 2" << endl << "3 5 1 3" << endl << "2 2 3" << endl;
		return 0;
	}
	vector<pair<int,int> >v;
	vector<int>l;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			v.push_back(make_pair(i, i + 1));
			l.push_back(2);
		}
	}
	cout << v.size() << " " << k << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << l[i] << " " << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}
