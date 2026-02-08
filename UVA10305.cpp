/*
* AC in 1
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

vector<vector<int>> adj;
bool visted[110];
string res = "";


void dfs(int i) {
	if (visted[i]) return;
	visted[i] = 1;

	for (int j : adj[i]) {
		dfs(j);
	}
	res += to_string(i + 1) + " ";
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m) {
		if (m == 0 && n == 0) break;
		memset(visted, 0, sizeof visted);
		res = "";
		adj = vector<vector<int>>(n);
		while (m--) {
			int a, b;
			cin >> a >> b;
			adj[b - 1].push_back(a - 1);
		}

		for (int i = 0; i < n; i++) {
			dfs(i);
		}

		res[res.size() - 1] = '\n';
		cout << res;
	}

    return 0;
}
