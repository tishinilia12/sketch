/*#include <iostream> 
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
#include <random>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	deque<int> st, tmp;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == -1) {
			cout << st.front() << "\n";
			st.pop_front();
		}
		else if (x) {
			st.push_front(x);
		}
		else {
			if (st.size() < n - i) {
				tmp = st;
				while (!tmp.empty() && st.size()<n-i) {
					st.push_back(tmp.front());
					tmp.pop_front();
				}
			}
		}
	}
}
//*/