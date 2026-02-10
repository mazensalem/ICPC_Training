/*
* AC in 2
* the idea is correct but the implementation had 2 problems
* 1 you should use cin.ignore() before using getline with cin >>
* 2 the reset logic between testcases were not correct
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <set>
#include <cstring>
#include <map>
#include <stack>
#include <cmath>

using namespace std;

int st_row, st_col;
vector<string> adj;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int i, int j) {
	if (adj[i][j] != ' ') return;
	adj[i][j] = '#';

	for (int k = 0; k < 4; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];

		if (ni >= 0 && ni < adj.size() && nj >= 0 && nj < adj[ni].size()) {
			if (adj[ni][nj] == ' ') {
				dfs(ni, nj);
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	cin.ignore();

	string st;
	int row = 0;
	while (getline(cin, st)) {
		if (st[0] == '_') {
			adj[st_row][st_col] = ' ';
			dfs(st_row, st_col);
			for (int i = 0; i < adj.size(); i++) {
				cout << adj[i] << "\n";
			}
			cout << st << "\n";
			adj.clear();
			row = 0;
		}
		else {
			adj.push_back(st);
			for (int col = 0; col < st.size(); col++) {
				if (st[col] == '*') {
					st_row = row;
					st_col = col;
				}
			}
			row++;
		}
	}

   return 0;
}
