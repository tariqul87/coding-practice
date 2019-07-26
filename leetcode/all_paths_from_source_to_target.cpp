#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph, int source = 0)
    {
        vector<vector<int>> result;
        int destination = graph.size() - 1;
        for (int i = 0; i < graph[source].size(); i++)
        {
            vector<vector<int>> paths;
            if (graph[source][i] == destination)
            {
                result.push_back({source, destination});
            }
            else
            {
                paths = allPathsSourceTarget(graph, graph[source][i]);
            }

            if (paths.size())
            {
                for (int j = 0; j < paths.size(); j++)
                {
                    paths[j].insert(paths[j].begin(), source);
                    result.push_back(paths[j]);
                }
            }
        }

        return result;
    }
};

int main(void)
{
    vector<vector<int>> graph = {{1, 2}, {3}, {4}, {}, {}};
    Solution solution;
    graph = solution.allPathsSourceTarget(graph);
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}