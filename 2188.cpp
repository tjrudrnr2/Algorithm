#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

int N, M;
int cow[201];
vector<int> vv[201];
bool visited[201];
int prevnode[201];

bool dfs(int idx)
{
	if (visited[idx] == true)
	{
		return false;
	}
	visited[idx] = true;
	for (int i = 0; i < vv[idx].size(); i++)
	{
		int nxt = vv[idx][i];
		if (prevnode[nxt] == 0 || dfs(prevnode[nxt]) == true)
		{
			prevnode[nxt] = idx;
			return true;
		}
	}
	return false;
}
int abc()
{
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		if (dfs(i))
		{
			result++;
		}
	}
	return result;
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
			int u;
			cin >> u;
			vv[i].push_back(u);
		}
	}
	cout << abc();
}