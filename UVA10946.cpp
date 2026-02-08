/*
* AC in 1
* just remember to check if your nighbour are of the same type in connected components
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

using namespace std;

int x, y;
vector<string> adj;
vector<vector<bool>> visted;
vector<pair<char, int>> res;

int dx[] = {1, -1, 0, 0};
int dy[] = { 0, 0, 1, -1 };


bool comp(pair<char, int> a, pair<char, int> b) {
	if (a.second > b.second) {
		return true;
	}
	else if (a.second < b.second) {
		return false;
	}
	else {
		return a.first < b.first;
	}
}


void dfs(int i, int j) {
	if (visted[i][j]) return;
	visted[i][j] = true;
	res.back().second++;

	for (int k = 0; k < 4; k++) {
		if (i + dx[k] >= 0 && i + dx[k] < x && j + dy[k] >= 0 && j + dy[k] < y) {
			if (adj[i + dx[k]][j + dy[k]] == adj[i][j]) {
				dfs(i + dx[k], j + dy[k]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int p_count = 0;
	
	while (cin >> x >> y) {
		p_count++;
		adj.clear();
		visted = vector<vector<bool>>(x, vector<bool>(y, 0));
		res.clear();

		if (x == 0 && y == 0)
			break;


		for (int i = 0; i < x; i++) {
			string s;
			cin >> s;
			adj.push_back(s);
		}
		
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (!visted[i][j] && adj[i][j] != '.') {
					res.push_back({ adj[i][j], 0 });
					dfs(i, j);
				}
			}
		}

		sort(res.begin(), res.end(), comp);

		cout << "Problem " << p_count << ":\n";
		for (auto pot : res) {
			cout << pot.first << " " << pot.second << "\n";
		}

	}

    return 0;
}
