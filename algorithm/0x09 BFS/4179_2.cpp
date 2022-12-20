#include <bits/stdc++.h>
using namespace std;

int r,c;
char board[1000][1000];
int fire[1000][1000], jihoon[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;

	queue<pair<int,int>> Q1;
	queue<pair<int,int>> Q2;

	for(int i=0; i<r; i++) {
		fill(fire[i], fire[i] + c, -1);
		fill(jihoon[i], jihoon[i] + c, -1);
		string str;
		cin >> str;
		for(int j=0; j<c; j++) {
			board[i][j] = str[j];
			if(str[j]=='F') {
				fire[i][j] = 0;
				Q1.push({i,j});
			} else if(str[j]=='J') {
				jihoon[i][j] = 0;
				Q2.push({i,j});
			}
		}
	}

	while(!Q1.empty()) {
		pair<int,int> cur = Q1.front(); Q1.pop();
		for(int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
			if(fire[nx][ny]>=0 || board[nx][ny]=='#') continue;
			fire[nx][ny] = fire[cur.first][cur.second] + 1;
			Q1.push({nx,ny}); 
		}
	}

	while(!Q2.empty()) {
		pair<int,int> cur = Q2.front(); Q2.pop();
		for(int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if(nx<0 || nx>=r || ny<0 || ny>=c) {
				cout << jihoon[cur.first][cur.second] + 1;
				return 0;
			}
			if(jihoon[nx][ny]>=0 || board[nx][ny]=='#') continue;
			if(fire[nx][ny]!= -1 && fire[nx][ny] <= jihoon[cur.first][cur.second]+1) continue;
			jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
			Q2.push({nx,ny}); 
		}
	}
	cout << "IMPOSSIBLE";
	
}

