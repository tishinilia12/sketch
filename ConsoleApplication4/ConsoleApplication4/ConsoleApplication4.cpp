// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
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


using namespace std;
vector<long long>prior;
vector<vector<long long>>gr;
vector<long long>prior_max;
vector<long long>prior_max1;
vector<long long>prior_max2;
vector<long long>prior_;
vector<long long> obr;
void dfs(int n){
    if (gr[n].size() == 0){
        prior_max1[n] = prior[n];
        prior_max[n] = prior[n];
    }
    prior_[n] += prior[n];
    for (int i = 0; i < gr[n].size(); i++){
        dfs(gr[n][i]);
        prior_[n] += prior_[gr[n][i]];
        if (prior_max1[n] == -1000000000000000){
            prior_max[n] = prior_max[gr[n][i]];
            prior_max1[n] = prior_max1[gr[n][i]];
            prior_max2[n] = prior_max2[gr[n][i]];
        }
        else{
            if (prior_max[n] + prior_max[gr[n][i]] >= prior_max1[n] + prior_max2[n]){
                prior_max1[n] = max(prior_max[n], prior_max[gr[n][i]]);
                prior_max2[n] = min(prior_max[n], prior_max[gr[n][i]]);
                prior_max[n] = max(prior_max[gr[n][i]], prior_max[n]);
            }
        }
    }
    prior_max[n] = max(prior_[n], prior_max[n]);
}
int  main(){
    long long n, i, a, b;
    cin >> n;
    prior.resize(n);
    gr.resize(n);
    obr.resize(n);
    prior_max.assign(n, -1000000000000000);
    prior_max1.assign(n, -1000000000000000);
    prior_max2.assign(n, -1000000000000000);
    prior_.resize(n);
    for (i = 0; i < n; i++){
        cin >> prior[i];
    }
    for (i = 0; i < n - 1; i++){
        cin >> a >> b;
        gr[a - 1].push_back(b - 1);
        obr[b - 1] = a - 1;
    }
    dfs(0);
    cout << prior_max1[0] + prior_max2[0];
}