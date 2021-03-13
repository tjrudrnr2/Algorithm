#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

long long N, M;
long long arr[51][3];
bool visited[51];
vector<int> shark[51];
int food[51];
int ans;

void comp(int v1, int v2)
{
	if (arr[v1][0] >= arr[v2][0] && arr[v1][1] >= arr[v2][1]
		&& arr[v1][2] >= arr[v2][2])
	{
		shark[v1].push_back(v2);
	}
	else if (arr[v1][0] <= arr[v2][0] && arr[v1][1] <= arr[v2][1]
		&& arr[v1][2] <= arr[v2][2])
	{
		shark[v2].push_back(v1);
	}
}
bool dfs(int idx)
{
	if (visited[idx])
	{
		return false;
	}
	visited[idx] = true;
	for (int i = 0; i < shark[idx].size(); i++)
	{
		int nxt = shark[idx][i];
		if ((food[nxt] == 0 || dfs(food[nxt])))
		{
			food[nxt] = idx;
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
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			comp(i, j);
		}
	}
	abc();
	abc();
	cout << N - ans;
}