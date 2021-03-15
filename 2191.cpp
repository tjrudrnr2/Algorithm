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

typedef pair<double, double> p;
double N, M, S, V;
p loc[101];
p tunnel[101];
bool visited[101];
int prevnode[101];

//void my_stoi(string s1, string s2, int idx)
//{
//	string tmp_x, tmp_y;
//	for (int i = 0; i < s1.length(); i++)
//	{
//		if (s1[i] == '.')
//		{
//			tmp_x = s1.substr(0, i);
//		}
//	}
//	for (int i = 0; i < s2.length(); i++)
//	{
//		if (s2[i] == '.')
//		{
//			tmp_y = s2.substr(0, i);
//		}
//	}
//	int x, y;
//	x = stoi(tmp_x);
//	y = stoi(tmp_y);
//	loc[idx] = p(x, y);
//}
//void my_stoi2(string s1, string s2, int idx)
//{
//	string tmp_x, tmp_y;
//	for (int i = 0; i < s1.length(); i++)
//	{
//		if (s1[i] == '.')
//		{
//			tmp_x = s1.substr(0, i);
//		}
//	}
//	for (int i = 0; i < s2.length(); i++)
//	{
//		if (s2[i] == '.')
//		{
//			tmp_y = s2.substr(0, i);
//		}
//	}
//	int x, y;
//	x = stoi(tmp_x);
//	y = stoi(tmp_y);
//	tunnel[idx] = p(x, y);
//}
bool check(int x, int y, int xx, int yy)
{
	double dist = sqrt(pow((x - xx), 2) + pow((y - yy), 2));
	double cost = dist / V;
	if (cost <= S)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool dfs(int now)
{
	if (visited[now])
	{
		return false;
	}
	visited[now] = true;
	int nowx = loc[now].first;
	int nowy = loc[now].second;
	for (int i = 1; i <= M; i++)
	{
		int nxtx = tunnel[i].first;
		int nxty = tunnel[i].second;
		if (!check(nowx, nowy, nxtx, nxty))
		{
			continue;
		}
		if (prevnode[i] == 0 || dfs(prevnode[i]))
		{
			prevnode[i] = now;
			return true;
		}
	}
	return false;
}
int abc()
{
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		if (dfs(i))
		{
			ans++;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> S >> V;
	for (int i = 1; i <= N; i++)
	{
		double x, y;
		cin >> x >> y;
		loc[i] = p(x, y);
		/*string x_str;
		string y_str;
		cin >> x_str >> y_str;
		my_stoi(x_str, y_str, i); */
	}
	for (int i = 1; i <= M; i++)
	{
		double x, y;
		cin >> x >> y;
		tunnel[i] = p(x, y);
		/*string x_str;
		string y_str;
		cin >> x_str >> y_str;
		my_stoi2(x_str, y_str, i);*/
	}
	cout << N - abc();
}