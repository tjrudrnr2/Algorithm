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
int dup[2001][2001];
vector<int> cs;
vector<int> sw;
vector<int> node[2001];
int result;
bool visited[2001];
int select[2001];

bool dfs(int now)
{
	if (visited[now])
	{
		return false;
	}
	visited[now] = true;
	for (int i = 0; i < node[now].size(); i++)
	{
		int nxt = node[now][i];
		/*if (dup[now][nxt] == 1)
		{
			continue;
		}*/
		if (select[nxt] == 0 || dfs(select[nxt]))
		{
			select[nxt] = now;
			return true;
		}
	}
	return false;
}
int abc()
{
	for (int i = 0; i < cs.size(); i++)
	{
		memset(visited, false, sizeof(visited));
		if (dfs(cs[i]))
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
		char c;
		cin >> n >> c;
		if (c == 'c')
		{
			cs.push_back(n);
		}
		else if (c == 's')
		{
			sw.push_back(n);
		}
	}
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	cout << N - abc();
}