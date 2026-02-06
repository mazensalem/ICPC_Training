/*
* AC in 2
* 1 -> The start for dfs shouldn't be a single point it should be every point in the graph
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

using namespace std;

string res = "";

vector<vector<char>> adj(28, vector<char>());
bool visted[28];
bool app[28];

void dfs(int node) {
	if (!app[node]) return;
	if (visted[node]) return;
	visted[node] = true;
	for (int i = 0; i < adj[node].size(); i++) {
		dfs(adj[node][i] - 'A');
	}
	res += node + 'A';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	string last = "";
	while (cin >> s) {
		if (s == "#") break;
		int ind = 0;
		while (ind < last.size() && ind < s.size()) {
			if (last[ind] != s[ind]) {
				adj[last[ind] - 'A'].push_back(s[ind]);
				break;
			}
			ind++;
		}
		last = s;
		
		for (char c : s)
			app[c - 'A'] = 1;
	}

	for (int i = 0; i < 27; i++) {
		dfs(i);
	}

	reverse(res.begin(), res.end());
	cout << res << "\n";
    return 0;
}
