// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

/*long long sum(long long r)
{
	long long result = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		result += t[r];
	return result;
}
void inc(long long i, long long delta)
{
	for (; i < 430000; i = (i | (i + 1)))
		t[i] += delta;
}*/

/*int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (rand() % 2)
		swap(a, b);
	if (a != b)
		parent[b] = a;
}
for(set<char>::iterator it = c.begin();it!=c.end();it++){
cout << *it;
}
*/
// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
//s.insert(s1.begin(), s1.end());- ���������� s1 � s
//copy( mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));-������� set
//islower(s[i])
//getline(cin,s,
//pq.pop()  - ���������� ���� pq
//myPrQueue.top() - ������� myPrQueue
//priority-queue<int>pq; - ���� �������� ���
//fixed << setprecision(9) - ����������� ����� 
//binary-search(v.begin(),v.end(),x)-����� � �� v
//lower-bound(v.begin(),v.end(),x) - ����� 1 � �� v
//upper-bound(v.begin(),v.end(),x) - max x +1 Ha v
//sort(v.begin(),v.end()) - ���������� ��� ������� v
//v.push-back(x) - �������� ��������� ���� x
//v.pop-back() - ������ ��������� ���� 
// - �������� � ����� s x
//s.size() -  ����� ������  s
//v.resize(123) - �������� ������ ������� v �� 123
//sort(a, )cout << fixed << setprecision(15)