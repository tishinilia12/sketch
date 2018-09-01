// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//
/*struct node {
	int key[26];
	int link;
	int shlink;
	int lg;
	int wh;
};
vector<int> answer;
int fre = 2;
vector<node>trie(2);
void add_word(const string &s,int zzz) {
	int a = 1;
	for (int i = 0; i < s.size(); i++) {
		if (trie[a].key[s[i] - 'a'] == -1) {
			node tmp;
			trie[a].key[s[i] - 'a'] = fre;
			a = fre;
			fre++;
			for (int i = 0; i < 26; i++)
				tmp.key[i] = -1;
			tmp.link = 0;
			tmp.shlink = 0;
			tmp.lg = -1;
			tmp.wh = 1;
			trie.push_back(tmp);
		}
		else {
			a = trie[a].key[s[i] - 'a'];
			trie[a].wh++;
		}
	}
	trie[a].lg = zzz;
}
void bild() {
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
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
