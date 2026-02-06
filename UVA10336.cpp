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

vector<string> adj;
vector<vector<bool>> visted;

unordered_map<char, int> res;


int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int h, w;

void dfs(int i, int j) {
	if (visted[i][j]) return;
	visted[i][j] = true;
	for (int k = 0; k < 4; k++) {
		if (i + dx[k] >= 0 && i + dx[k] < h && j + dy[k] >= 0 && j + dy[k] < w) {
			if (adj[i + dx[k]][j + dy[k]] == adj[i][j]) {
				dfs(i + dx[k], j + dy[k]);
			}
		}
	}
}


bool comp(pair<char, int> a, pair<char, int > b) {
	// (a < b);
	if (a.second > b.second) {
		return true;
	}
	else if (b.second > a.second) {
		return false;
	}
	else {
		return a.first < b.first;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int wol = 1; wol <= n; wol++) {
		adj.clear();
		res.clear();
		visted.clear();


		cin >> h >> w;
		visted = vector<vector<bool>>(h, vector<bool>(w));
		
		for (int i = 0; i < h; i++) {
			string s;
			cin >> s;
			adj.push_back(s);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visted[i][j]) {
					dfs(i, j);
					res[adj[i][j]]++;
				}
			}
		}
		
		
		vector<pair<char, int>> vec;
		for (auto c : res) {
			vec.push_back(c);
		}
		sort(vec.begin(), vec.end(), comp);

		cout << "World #" << wol << "\n";
		for (auto c : vec) {
			cout << c.first << ": " << c.second << "\n";
		}
	}

    return 0;
}
