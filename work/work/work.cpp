// work.cpp: определяет точку входа для консольного приложения.
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
	int key[2];
	//int link;
	//int shlink;
	//unsigned long long lg;
	//unsigned long long wh;
};
vector<int> answer;
int fre = 2;
vector<node>trie(2);
void add_word(const unsigned long long &s,int zzz) {
	int a = 1;
	for (int i = 0; i < 64; i++) {
		if (trie[a].key[s>>(63-i)&1] == -1) {
			node tmp;
			//cout << (s >> (63 - i)) << " ";
			trie[a].key[s >> (63 - i) & 1] = fre;
			a = fre;
			fre++;
			for (int i = 0; i < 2; i++)
				tmp.key[i] = -1;
			/*tmp.link = 0;
			tmp.shlink = 0;
			tmp.lg = 0;
			tmp.wh = 0;*/
			trie.push_back(tmp);
		}
		else {
			a = trie[a].key[s >> (63 - i) & 1];
		}
	}
	//cout << endl;
}
/*void bild() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			if (trie[u].key[i] != -1) {
				int sun = trie[u].key[i];
				int melink = trie[u].link;
				while (trie[melink].key[i] == -1) {
					melink = trie[melink].link;
				}
				trie[sun].link = trie[melink].key[i];
				if (trie[trie[sun].link].lg == -1) {
					trie[sun].shlink = trie[trie[sun].link].shlink;
				}
				else {
					trie[sun].shlink = trie[sun].link;
				}
				q.push(sun);
			}
		}
	}
}*/
int root=1;
unsigned long long mx=-1;
unsigned long long s;
int main() {
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 2; i++)
		trie[0].key[i] = 1;
	/*trie[0].link =0;
	trie[0].shlink = 0;
	trie[0].lg = 0;
	trie[0].wh = 0;*/
	for (int i = 0; i < 2; i++)
		trie[1].key[i] = -1;
	/*trie[1].link = 0;
	trie[1].shlink = 0;
	trie[1].lg = 0;
	trie[1].wh = 0;*/
	vector<unsigned long long>tmp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		add_word(s,i+1);
		tmp.push_back(s);
	}
	//bild();
	unsigned long long ans = 0;
	for (int i = 0; i < n; i++) {
		s = tmp[i];
		unsigned long long yu = 0;
		root = 1;
		for (int j = 0; j < 64; j++) {
			yu = yu << 1;
			if (trie[root].key[(s>>(63 - j)&1) ^ 1] != -1) {
			root=trie[root].key[(s >> (63 - j) & 1) ^ 1];
			yu += 1;
			}
			else {
				root = trie[root].key[(s >> (63 - j) & 1)];
			}
		}
		ans = max(ans, yu);
	}
	cout << ans << endl;
		return 0;
}
/**/
