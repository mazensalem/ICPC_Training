/*
* AC in 4
* really easy problem really dump platform
* The logic is correct the input reading is a mess WHY doesn't it just give me the hieght and width
* Should I do dark majick to know them
* any way just read the input the new lines are blanks in getline anyway.
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

vector<string> adj;
vector<vector<bool>> visted;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int ans = 0;
int temp = 0;
void dfs(int i, int j) {
	if (visted[i][j]) return;
	visted[i][j] = true;
	ans = max(ans, temp);

	for (int k = 0; k < 8; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		if (ni >= 0 && ni < adj.size() && nj >= 0 && nj < adj[ni].size()) {
			if (adj[ni][nj] == '1' && !visted[ni][nj]) {
				temp++;
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
	

	string st;
	while (getline(cin, st) && st.empty());
	adj.push_back(st);

	while (t--) {
		while (getline(cin, st) && !st.empty()) { adj.push_back(st); }

		if (!adj.size()) { t++; continue; }

		visted = vector<vector<bool>>(adj.size(), vector<bool>(adj[0].size(), 0));
		for (int i = 0; i < adj.size(); i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				if (adj[i][j] == '1' && !visted[i][j]) {
					temp = 1;
					dfs(i, j);
				}
			}
		}
		cout << ans << "\n";
		ans = 0;
		adj.clear();
		visted.clear();

		if (t > 0) {
			cout << "\n";
		}
	}

   return 0;
}
