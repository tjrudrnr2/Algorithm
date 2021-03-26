#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int, int> p;
int T, N, M;
vector<int> node[201];
int cap[201][201]; // 지나갈 수 있는 개미 마릿수
int flow[201][201]; // 현재 지나간 개미 마릿수
int prevnode[201]; // 지나온 경로 확인
int ans;
queue<int> q;

void init()
{
	while (!q.empty())
	{
		q.pop();
	}
	for (int i = 1; i <= N; i++)
	{
		prevnode[i] = 0;
	}
	q.push(1);
}
bool bfs()
{
	init();
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == N)
		{
			return true;
		}
		for (int i = 0; i < node[now].size(); i++)
		{
			int nxt = node[now][i];
			// 방문한적 없고 갈 수 있는 길
			if (prevnode[nxt] == 0 && cap[now][nxt] - flow[now][nxt] > 0)
			{
				q.push(nxt);
				prevnode[nxt] = now;
			}
		}
	}
	return false;
}
void abc()
{
	while (1)
	{
		if (!bfs())
		{
			break;
		}
		for (int i = N; i != 1; i = prevnode[i])
		{
			int prev = prevnode[i];
			flow[prev][i] += 1;
			flow[i][prev] -= 1;
		}
		ans++;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		for (int j = 0; j < M; j++)
		{
			int x, y;
			cin >> x >> y;
			node[x].push_back(y);
			node[y].push_back(x); // 음의 간선
			if (x == 1 || y == N) // 1마리만 통과
			{
				cap[x][y] = 1; 
				cap[y][x] = 1; 
				flow[y][x] = 1;
			}
			else 
			{
				cap[x][y] = 1000;
				cap[y][x] = 1000;
				flow[y][x] = 1000;
			}
		}
		abc();
		cout << ans << '\n';

		// initialize
		ans = 0;
		for (int k = 0; k <= N; k++)
		{
			node[k].clear();
			for (int j = 1; j <= N; j++)
			{
				cap[k][j] = 0;
				flow[k][j] = 0;
			}
		}
	}
}