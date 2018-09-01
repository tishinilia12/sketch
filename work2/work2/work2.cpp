// work2.cpp: определяет точку входа для консольного приложения.
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



struct node {
	int key[27];
	int l;
	int r;
	int p;
	int link;
	int ans;
};
int tmp=1;
int sp=0;
string s;
vector<node>v(2);

void  adduk(int i) {
	while (1) {
		if (v[tmp].r < sp) {
			if (v[tmp].key[s[i] - 'a'] == -1) {
				node z;
				for (int i = 0; i < 27; i++) {
					z.key[i] = -1;
				}
				z.l = i;
				z.r = s.size() - 1;
				z.p = tmp;
				v[tmp].key[s[i] - 'a'] =v.size();
				tmp = v[tmp].link;
				v.push_back(z);
				sp = v[tmp].r + 1;
				continue;
			}

			tmp = v[tmp].key[s[i] - 'a'];
			sp = v[tmp].l;
		}
		if (sp == -1 || s[i] == s[sp]) {
			sp++;
			return ;
		}
		else
		{
			node z;
			z.p = v[tmp].p;
			for (int i = 0; i < 27; i++) {
				z.key[i] = -1;
			}
			z.l = v[tmp].l;
			z.r = sp - 1;
			z.key[s[sp]-'a'] = tmp;
			node z1;
			z1.p = v.size();
			for (int i = 0; i < 27; i++) {
				z1.key[i] = -1;
			}
			z1.l = i;
			z1.r = s.size() - 1;
			z.key[s[i]-'a'] = v.size()+1;
			v.push_back(z);
			v.push_back(z1);
			v[tmp].l = sp;
			int n = v.size() - 2;
			v[tmp].p = n;
			v[v[n].p].key[s[v[n].l]-'a'] = n;
			tmp = v[v[n].p].link;
			sp = v[n].l;
			while (sp <= v[n].r) {
				tmp = v[tmp].key[s[sp]-'a'];
				sp += v[tmp].r - v[tmp].l + 1;
			}
			if (sp != v[n].r + 1) {
				v[n].link = v.size();
			}
			else {
				v[n].link = tmp;
			}
			sp = v[tmp].r - sp + v[n].r + 2;
		}
	}
}
int zzz = 1;
void dfs1(int root) {
	if (v[root].key[26] != -1) {

		int n = v[root].key[26];
		v[n].ans= zzz;
		zzz++;
		dfs1(n);
	}
	for (int i = 0; i < 26; i++) {
		if (v[root].key[i] != -1) {
			int n = v[root].key[i];
			v[n].ans = zzz;
			zzz++;
			dfs1(n);
		}
	}
}
void dfs(int root) {
	if (v[root].key[26] != -1) {
		int n = v[root].key[26];
		cout << v[v[n].p].ans << " " << v[n].l << " " << v[n].r + 1 << endl;
		dfs(n);
	}
	for (int i = 0; i < 26; i++) {
		if (v[root].key[i] != -1) {
			int n= v[root].key[i];
			cout << v[v[n].p].ans << " " << v[n].l << " " << v[n].r + 1 << endl;
			dfs(n);
		}
	}
}
int main() {
	for (int i = 0; i < 27; i++) {
		v[0].key[i] = 1;
		v[1].key[i] = -1;
	}
	v[0].r = -1;
	v[0].l = -1;
	v[1].p = 0;
	v[1].link = 0;
	v[1].l = -1;
	v[1].r = -1;
	string ss;
	int zzz;
	cin >> zzz;
	cin >> ss;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '$') {
			s[i] = 'z' + 1;
		}
	}
	for (int i = 0; i < min(50, zzz); i++) {
		s += ss;
	}

	for (int i = 0; i < s.size(); i++) {
		adduk(i);
	}
	cout << v.size() - 1 << endl;
	return 0;
}

