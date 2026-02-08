/*
* AC in 3
* 1 -> I thought the last case handling was wronge [it wasn't]
* 2 -> the truth the output formatting was wrong for the first column
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

vector<vector<char>> adj;
vector<vector<int>> res;

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

void dfs(int x, int y, int num) {
	if (res[x][y] != -1) return;
	res[x][y] = num;

	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < adj.size() && ny >= 0 && ny < adj[nx].size()) {
			if (adj[x][y] == adj[nx][ny]) {
				dfs(nx, ny, num);
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	string input;
	while (getline(cin, input)) {
		if (input == "%") {
			res = vector<vector<int>>(adj.size(), vector<int>(adj[0].size(), -1));
			vector<int> col_sizes;
			int count = 1;

			for (int i = 0; i < adj.size(); i++) {
				for (int j = 0; j < adj[i].size(); j++) {
					if (res[i][j] == -1) {
						dfs(i, j, count++);
					}
				}
			}

			for (int col = 0; col < res[0].size(); col++) {
				int maxsize = 0;
				for (int row = 0; row < res.size(); row++) {
					if (to_string(res[row][col]).size() > maxsize) {
						maxsize = to_string(res[row][col]).size();
					}
				}
				col_sizes.push_back(maxsize);
			}

			for (int i = 0; i < res.size(); i++) {
				for (int j = 0; j < res[i].size(); j++) {
					int spaces = col_sizes[j] - to_string(res[i][j]).size() + 1;
					if (j == 0) spaces--;
					for (int ci = 0; ci < spaces; ci++) cout << " ";
					cout << res[i][j];
				}
				cout << "\n";
			}
			cout << "%\n";
			adj.clear();
			continue;
		}
		
		if (input.empty()) {continue;}

		vector<char> row;
		for (int i = 0; i < input.size(); i += 2) {
			row.push_back(input[i]);
		}

		adj.push_back(row);
	}




	res = vector<vector<int>>(adj.size(), vector<int>(adj[0].size(), -1));
	vector<int> col_sizes;
	int count = 1;

	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (res[i][j] == -1) {
				dfs(i, j, count++);
			}
		}
	}

	for (int col = 0; col < res[0].size(); col++) {
		int maxsize = 0;
		for (int row = 0; row < res.size(); row++) {
			if (to_string(res[row][col]).size() > maxsize) {
				maxsize = to_string(res[row][col]).size();
			}
		}
		col_sizes.push_back(maxsize);
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0];
		for (int j = 1; j < res[i].size(); j++) {
			int spaces = col_sizes[j] - to_string(res[i][j]).size() + 1;
			for (int ci = 0; ci < spaces; ci++) cout << " ";
			cout << res[i][j];
		}
		cout << "\n";
	}
	cout << "%\n";
	adj.clear();


    return 0;
}
