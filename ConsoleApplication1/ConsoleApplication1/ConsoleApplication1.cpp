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
 
void f(unordered_map<string, int>&m, int &n, string &sSum, vector<vector<int>>&v, vector<int> &zzz){
    int count = 0;
    istringstream iss(sSum, istringstream::in);
    string s1, s;
    iss >> s1;
    if (m.find(s1) == m.end()){
        m[s1] = n;
        v.push_back(zzz);
        n++;
    }
    while (iss >> s){
        if (m.find(s) == m.end()){
            m[s] = n;
            v.push_back(zzz);
            n++;
        }
        v[m[s1]].push_back(m[s]);
        s1 = s;
        s.clear();
    }
}
int main(int argc, char* argv[])
{
    unordered_map<string, int>m;
    vector<vector<int>>v;
    vector<int> zzz;
    ifstream cin("F:\\stackoverflow\\tmp5.txt");
    ofstream cout("F:\\stackoverflow\\flesh5.txt");
    string sLine, sSum;
    int n = 0, leng;
    while (cin >> leng){
        getline(cin, sLine);
        for (int i = 0; i < leng; i++){
            getline(cin, sLine);
            if (sLine != ""){
                sSum += sLine + ' ';
            }
        }
        f(m, n, sSum, v, zzz);
        getline(cin, sLine);
        sSum.clear();
    }
    cout << m.size() << " ";
    int coutn = 0;
    for (unordered_map<string, int>::iterator it = m.begin(); it != m.end(); it++){
        coutn++;
        cout << (*it).second << " " << (*it).first << " ";
    }
    for (int i = 0; i < v.size(); i++){
        cout << v[i].size() << " ";
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
    }
    return 0;
}