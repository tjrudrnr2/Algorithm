#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <math.h>
#include <stack>
using namespace std;

#define inf 1e9
typedef pair<int, int> p;
int N, M;
int S = 0, T = 801;
vector<p> node[802];
int cap[802][802], flow[802][802];
int prevnode[802], inQ[802], dist[802], cycle[802];
queue<int> q;
int cnt, ans;

void init()
{
	while (!q.empty())
	{
		q.pop();
	}
	memset(cycle, 0, sizeof(cycle));
	memset(prevnode, 0, sizeof(prevnode));
	memset(inQ, 0, sizeof(inQ));
	q.push(0);
	inQ[0] = true;
	cycle[0]++;
	for (int i = 1; i <= 801; i++)
	{
		dist[i] = 0;
	}
	dist[0] = inf;
}
void spfa()
{
	init();
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		inQ[now] = false;
		for (int i = 0; i < node[now].size(); i++)
		{
			int nxt = node[now][i].first;
			int w = node[now][i].second;
			if (prevnode[nxt] == 0 && dist[nxt] < dist[now] + w
				&& cap[now][nxt] - flow[now][nxt] > 0)
			{
				if (dist[now] == inf)
				{
					dist[now] = 0;
				}
				dist[nxt] = dist[now] + w;
				prevnode[nxt] = now;
				if (inQ[nxt] == false)
				{
					inQ[nxt] = true;
					q.push(nxt);
					cycle[nxt]++;
					if (cycle[nxt] >= N)
					{
						return;
					}
				}
			}
		}
	}
}
void mcnf()
{
	while (1)
	{
		spfa();
		if (prevnode[T] == 0)
		{
			break;
		}
		for (int i = T; i != S; i = prevnode[i])
		{
			int prev = prevnode[i];
			flow[prev][i]++;
			flow[i][prev]--;
		}
		cnt++;
		ans += dist[T];
	}
	cout << cnt << '\n' << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int v, w;
			cin >> v >> w;
			node[i].push_back(p(400 + v, w));
			node[400 + v].push_back(p(i, -w));
			cap[i][400 + v] = 1;
			cap[400 + v][i] = 1;
			flow[400 + v][i] = 1;
		}
		node[S].push_back(p(i, 0));
		node[i].push_back(p(S, 0));
		cap[S][i] = 1;
		cap[i][S] = 1;
		flow[i][S] = 1;
	}
	for (int i = 1; i <= M; i++)
	{
		node[400 + i].push_back(p(T, 0));
		node[T].push_back(p(400 + i, 0));
		cap[400 + i][T] = 1;
		cap[T][400 + i] = 1;
		flow[T][400 + i] = 1;
	}
	mcnf();
}