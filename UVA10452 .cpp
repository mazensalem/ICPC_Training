/*
* Right Idea just a presentation error for the trailling space
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


int dx[] = { 0, 0, -1 };
int dy[] = { 1, -1, 0 };
string dir[] = {"right", "left", "forth"};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		int startx, starty;
		cin >> m >> n;
		vector<string> adj(m);
		for (int i = 0; i < m; i++) {
			string l;
			cin >> l;
			adj[i] = l;
			for (int j = 0; j < n; j++)
			{
				if (l[j] == '@')
				{
					startx = i;
					starty = j;
				}
			}

		}

		string avpath = "IEHOVA#";
		int pathind = 0;
		vector<string> res;

		while (adj[startx][starty] != '#') {
			for (int i = 0; i < 3; i++) {
				if (startx + dx[i] >= 0 && startx + dx[i] < m) {
					if (starty + dy[i] >= 0 && starty + dy[i] < n) {
						if (adj[startx + dx[i]][starty + dy[i]] == avpath[pathind]) {
							startx = startx + dx[i];
							starty = starty + dy[i];
							res.push_back(dir[i]);
							pathind++;
						}
					}
				}
			}
		}

		int i;
		for (i = 0; i < res.size() - 1;i++) {
			cout << res[i] << " ";
		}
		cout << res[i];
		cout << "\n";

	}


    return 0;
}
