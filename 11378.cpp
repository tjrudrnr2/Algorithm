#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

int N, M, K;
vector<int> node[1001];
int ans;
bool visited[1001];
int work[1001];

bool dfs(int idx)
{
	if (visited[idx])
	{
		return false;
	}
	visited[idx] = true;
	for (int i = 0; i < node[idx].size(); i++)
	{
		int nxt = node[idx][i];
		if (work[nxt] == 0 || dfs(work[nxt]))
		{
			work[nxt] = idx;
			return true;
		}
	}
	return false;
}
void abc()
{
	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		if (dfs(i))
		{
			ans++;
		}
	}
}
void abc2()
{
	while (1)
	{
		if (K == 0)
		{
			return;
		}
		int tmp = 0;
		for (int i = 1; i <= N; i++)
		{
			memset(visited, false, sizeof(visited));
			if (dfs(i))
			{
				ans++;
				K--;
			}
			else
			{
				tmp++;
			}
		}
		if (tmp == N)
		{
			return;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int n;
			cin >> n;
			node[i].push_back(n);
		}
	}
	abc();
	abc2();
	cout << ans;
}