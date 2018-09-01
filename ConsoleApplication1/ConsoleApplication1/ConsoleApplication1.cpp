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


using namespace std;

#define Mfor(i,b,e) for(int i=b;i<e;i++)
#define Mrof(i,b,e) for(int i=e,i>=b;i--)
#define all(x) (x).begin(), (x).end()
template <class T> void Vcin(vector<T>& V)
{
	Mfor(i, 0, V.size()) { cin >> V[i]; }
}

int  main() {
	unsigned int x, n,x1,x2;
	cin >> n;
	unsigned int v[125003];
	for (int i=0; i < n / 2 + 1; ++i) cin >> v[i];
	make_heap(v, v + n / 2 + 1);
	for (int i= n / 2 + 1; i < n; ++i) {
		cin >> v[n / 2 + 1];
		push_heap(v, v + n / 2 + 2);
		pop_heap(v, v + n / 2 + 2);
	}
	if (n % 2) {
		cout << v[0] << endl;
	}
	else {
		x1 = v[0];
		pop_heap(v, v + n / 2 + 1); 
		x2 = v[0];
		if ((x1 + x2) % 2 == 0)
			cout << (x1 + x2) / 2 << endl;
		else
			cout << (x1 + x2) / 2 << "." << 5 << endl;
	}
}