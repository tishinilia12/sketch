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

using namespace std;

long long f(long long a) {
	long long c = 0,z=1;
	while (a) {
		if (a % 10) {
			c += a % 10 * z;
			z *= 10;
		}
		a /= 10;
	}
	return c;
}
int main() {
	long long n,m;
	cin >> n >> m;
	if (f(n) + f(m) == f(n + m)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}