#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

struct triple {
	int x, y; char type;
	triple(char a, int b, int c){
		x = b; y = c;
		type = a;
	}
};

int n,m;
vector<vector<char>> maze, state;
vector<vector<int>> tp;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char dir[4] = {'R','D','L','U'};

bool isBorder(int i, int j){
	return (i == 1 || i == n || j == 1 || j == m);
}

int main(){

	cin >> n >> m;
	maze = vector<vector<char>> (n+2, vector<char> (m+2, '#'));
	state = vector<vector<char>> (n+2, vector<char> (m+2, '1')); //inalterado,  inalcançável = 0,1
	tp = vector<vector<int>> (n+2, vector<int> (m+2, -1));
	queue<triple> q, waiting;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> maze[i][j];
			if(maze[i][j] == 'M'){
				q.push(triple('M',i,j));
			} else if(maze[i][j] == 'A'){
				waiting.push(triple('H',i,j));
			} else {
				state[i][j] = '0';
			}
		}
	}

	while(!waiting.empty()){
		q.push(waiting.front());
		waiting.pop();
	}

	int x = -1,y = -1;
	while(!q.empty()){
		triple nx = q.front(); q.pop();
		if(isBorder(nx.x,nx.y) && nx.type == 'H'){
			cout << "YES\n";
			x = nx.x; y = nx.y;
			break;
		}
		for(int t = 0; t < 4; t++){
			int a = nx.x + dx[t], b = nx.y + dy[t];
			if(state[a][b] == '0' && maze[a][b] == '.'){
				state[a][b] = '1'; tp[a][b] = t;
				q.push(triple(nx.type,a,b));
			}
		}
	}

	if(x == -1 && y == -1){
		cout << "NO\n";
		return 0;
	}

	stack<char> st;
	while(tp[x][y] != -1){
		int k = tp[x][y];
		st.push(dir[k]);
		x -= dx[k]; y -= dy[k];
	}

	cout << st.size() << "\n";
	while(!st.empty()){
		cout << st.top(); st.pop();
	}
	cout << "\n";

	return 0;
}