/*
* AC in 8
* The first idea was wrong to use dfs for cycle detection.
* The secnod idea was from AI and was partially correct the idea for coordinate compression + flood fill
* Some problems were present for detecting overlapping holes which got solved by checking over each edge point
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
vector<vector<bool>> adj;
vector<vector<bool>> visted;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(long long i, long long j, bool isfirst) {
	stack<pair<long long, long long>> DFS;
	if (visted[i][j]) return;
	visted[i][j] = true;

	DFS.push({ i, j });

	while (!DFS.empty()) {
		long long ci = DFS.top().first, cj = DFS.top().second;
		DFS.pop();

		for (long long k = 0; k < 4; k++) {
			long long ni = ci + dx[k];
			long long nj = cj + dy[k];
			if (ni >= 0 && ni < adj.size() && nj >= 0 && nj < adj[0].size()) {
				if (!adj[ni][nj] && !visted[ni][nj]) {
					visted[ni][nj] = true;
					DFS.push({ ni, nj });
				}

				// an edge that cuts in open area doesn't exists
				if (!isfirst) {
					if (adj[ni][nj]) {
						for (int l = 0; l < 4; l++) {
							int nni = ni + dx[l], nnj = nj + dy[l];
							if (nni >= 0 && nni < adj.size() && nnj >= 0 && nnj < adj[0].size() && !adj[nni][nnj] && !visted[nni][nnj]) {
								visted[nni][nnj] = true;
								DFS.push({ nni, nnj });
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; 
	
	while (cin >> n) {
		if (n == 0) break;

		vector<pair<pair<long long, long long>, pair<long long, long long>>> cuts(n);
		vector<long long> xnums, ynums;

		for (long long i = 0; i < n; i++) {
			long long X1, Y1, X2, Y2;
			cin >> X1 >> Y1 >> X2 >> Y2;
			cuts[i] = {
				{X1, Y1},
				{X2, Y2}
			};

			xnums.push_back(X1);
			ynums.push_back(Y1);
			xnums.push_back(X2);
			ynums.push_back(Y2);
		}

		sort(xnums.begin(), xnums.end());
		xnums.erase(unique(xnums.begin(), xnums.end()), xnums.end());

		sort(ynums.begin(), ynums.end());
		ynums.erase(unique(ynums.begin(), ynums.end()), ynums.end());

		long long size = max((xnums.size() * 2) + 10, (ynums.size() * 2) + 10);
		adj = vector<vector<bool>>(size, vector<bool>(size, 0));
		visted = vector<vector<bool>>(size, vector<bool>(size, 0));
		for (long long i = 0; i < cuts.size(); i++) {
			long long startX = lower_bound(xnums.begin(), xnums.end(), cuts[i].first.first) - xnums.begin() + 1;
			long long startY = lower_bound(ynums.begin(), ynums.end(), cuts[i].first.second) - ynums.begin() + 1;
			long long endX = lower_bound(xnums.begin(), xnums.end(), cuts[i].second.first) - xnums.begin() + 1;
			long long endY = lower_bound(ynums.begin(), ynums.end(), cuts[i].second.second) - ynums.begin() + 1;

			startX *= 2;
			startY *= 2;
			endX *= 2;
			endY *= 2;


			if (startX == endX) {
				long long temp = startY;
				startY = min(startY, endY);
				endY = max(temp, endY);

				for (long long j = startY; j <= endY; j++) {
					adj[startX][j] = 1;
				}
			}
			else {
				long long temp = startX;
				startX = min(startX, endX);
				endX = max(temp, endX);
				
				for (long long j = startX; j <= endX; j++) {
					adj[j][startY] = 1;
				}
			}
		}

		long long ans = 0;
		dfs(0, 0, true);
		for (long long i = 1; i < adj.size(); i++) {
			for (long long j = 1; j < adj[i].size(); j++) {
				if (!adj[i][j] && !visted[i][j]) {
					ans++;
					dfs(i, j, false);
				}
			}
		}

		cout << ans << "\n";
	}



    return 0;
}
