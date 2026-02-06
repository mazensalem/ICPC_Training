/*
* AC after 3 attempts 
* 1-> wrong approach storing the tree in an array would cause a memory overflow
* 2-> not setting and clearring between testcases correctly
* 3-> presentation error for the trailling space
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


struct Node {
	int value;
	Node* L;
	Node* R;
	Node(int v, Node* l, Node* r) { value = v; L = l; R = r; }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	

	string st;
	Node* root = new Node(-1, NULL, NULL);
	bool notcomp = false;
	while (cin >> st) {
		if (st == "()") {
			string res = "";
			queue<Node*> BFS;
			BFS.push(root);
			while(BFS.size()){
				Node* t = BFS.front();
				BFS.pop();
				if (!t) continue;

				if (t->value == -1) {
					notcomp = true;
					break;
				}
				else {
					res += to_string(t->value) + ' ';
				}
				BFS.push(t->L);
				BFS.push(t->R);
			}

			if (notcomp) {
				cout << "not complete\n";
			}
			else {
				res[res.size() - 1] = '\n';
				cout << res;
			}

			root = new Node(-1, NULL, NULL);
			notcomp = false;
		}
		else {
			int value = stoi(st.substr(1, st.find(',')));
			string pos = st.substr(st.find(','));
			Node* cur = root;
			for (char c : pos) {
				if (c == 'R') {
					if (!cur->R) {
						cur->R = new Node(-1, NULL, NULL);
					}
					cur = cur->R;
				}
				else if (c == 'L') {
					if (!cur->L) {
						cur->L = new Node(-1, NULL, NULL);
					}
					cur = cur->L;
				}
			}
			if (cur->value != -1) notcomp = true;
			cur->value = value;
		}
	}

    return 0;
}
