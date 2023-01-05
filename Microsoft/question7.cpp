/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	bool canFinish(int n, vector<vector<int>> &pre)
	{
		vector<int> adj[n];
		for (int i = 0; i < pre.size(); i++)
		{
			adj[pre[i][1]].push_back(pre[i][0]);
		}

		vector<int> topo;
		vector<int> indegree(n, 0);
		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			for (auto j : adj[i])
				indegree[j]++;
		}
		for (int node = 0; node < n; node++)
		{
			if (!indegree[node])
				q.push(node);
		}
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			topo.push_back(node);
			for (auto i : adj[node])
			{
				indegree[i]--;
				if (!indegree[i])
					q.push(i);
			}
		}
		return topo.size() == n;
	}
};