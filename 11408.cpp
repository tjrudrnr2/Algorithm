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
vector<p> worker[802];
int flow[802][802]; // 현재 흐른 유량
queue<int> q;
int dist[802];
int prevnode[802];
bool inQ[802];
int cycle[802];
int cnt, ans;

void init()
{
	while (!q.empty())
	{
		q.pop();
	}
	memset(prevnode, 0, sizeof(prevnode));
	memset(inQ, 0, sizeof(inQ));
	memset(cycle, 0, sizeof(cycle));
	for (int i = 1; i <= 801; i++)
	{
		dist[i] = inf;
	}
	q.push(0);
	inQ[0] = true;
	cycle[0]++;
}
void spfa()
{
	init();
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		inQ[now] = false;
		for (int i = 0; i < worker[now].size(); i++)
		{
			int nxt = worker[now][i].first;
			int w = worker[now][i].second;
			if (flow[now][nxt] == 0 && dist[nxt] > dist[now] + w)
			{
				dist[nxt] = dist[now] + w;
				prevnode[nxt] = now;
				if (inQ[nxt] == false)
				{
					inQ[nxt] = true;
					cycle[nxt]++;
					q.push(nxt);
					if (cycle[nxt] >= N)
					{
						return;
					}
				}
			}
		}
	}
	return;
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
			worker[i].push_back(p(400 + v, w));
			worker[400 + v].push_back(p(i, -w));
			flow[400 + v][i] = 1;
		}
	}
	// Source와 연결
	for (int i = 1; i <= N; i++)
	{
		worker[S].push_back(p(i, 0));
		worker[i].push_back(p(S, 0));
		flow[i][S] = 1;
	}
	// Sink와 연결
	for (int i = 1; i <= M; i++)
	{
		worker[400 + i].push_back(p(T, 0));
		worker[T].push_back(p(400 + i, 0));
		flow[T][400 + i] = 1;
	}
	mcnf();
}