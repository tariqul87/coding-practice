#include "array.cpp"

class Solution
{
public:
    int RED = 0;
    int BLUE = 1;
    vector<vector<long int>> eR;
    vector<vector<long int>> eB;
    vector<vector<long int>> reds;
    vector<vector<long int>> blues;
    vector<int> result;
    vector<int> getBlueEdgeNodes(int x, int n)
    {
        vector<int> neighbours;
        for (int i = 0; i < n; i++)
        {
            if (blues[x][i] == 1)
            {
                neighbours.push_back(i);
            }
        }

        return neighbours;
    }
    vector<int> getRedEdgeNodes(int x, int n)
    {
        vector<int> neighbours;
        for (int i = 0; i < n; i++)
        {
            if (reds[x][i] == 1)
            {
                neighbours.push_back(i);
            }
        }

        return neighbours;
    }
    void bfs(int n)
    {
        vector<vector<int>> nodes;
        nodes.push_back({0, RED});
        nodes.push_back({0, BLUE});
        eR[0][0] = 0;
        eB[0][0] = 0;
        int index = 0, distance = 0;

        while (index < nodes.size())
        {
            int size = nodes.size();
            while (index < size)
            {
                int node = nodes[index][0], color = nodes[index][1];

                if (color == RED)
                {
                    vector<int> blueEdgeNodes = getBlueEdgeNodes(node, n);
                    for (int neighbour : blueEdgeNodes)
                    {
                        // cout << "Blue edge NeighBour of " << node << ": " << neighbour << endl;
                        if (eB[0][neighbour] > eR[0][node] + 1)
                        {
                            eB[0][neighbour] = eR[0][node] + 1;
                            nodes.push_back({neighbour, BLUE});
                        }
                    }
                }
                else
                {
                    vector<int> redEdgeNodes = getRedEdgeNodes(node, n);
                    for (int neighbour : redEdgeNodes)
                    {
                        // cout << "Red edge NeighBour of " << node << ": " << neighbour << endl;
                        if (eR[0][neighbour] > eB[0][node] + 1)
                        {
                            eR[0][neighbour] = eB[0][node] + 1;
                            nodes.push_back({neighbour, RED});
                        }
                    }
                }
                index++;
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
    {
        for (int i = 0; i < n; i++)
        {
            vector<long int> row(n, INT_MAX);
            vector<long int> edges(n, INT_MAX);
            eR.push_back(row);
            eB.push_back(row);
            reds.push_back(edges);
            blues.push_back(edges);
            reds[i][i] = 0;
            blues[i][i] = 0;
        }

        for (int i = 0; i < red_edges.size(); i++)
        {
            int src = red_edges[i][0], dest = red_edges[i][1];
            // eR[src][dest] = 1;
            reds[src][dest] = 1;
        }

        for (int i = 0; i < blue_edges.size(); i++)
        {
            int src = blue_edges[i][0], dest = blue_edges[i][1];
            // eB[src][dest] = 1;
            blues[src][dest] = 1;
        }

        bfs(n);

        for (int i = 0; i < n; i++)
        {
            long int distance = min(eR[0][i], eB[0][i]);
            result.push_back(distance == INT_MAX ? -1 : distance);
        }

        return result;
    }
};

int main(void)
{
    Solution s;
    int n = 9;
    vector<vector<int>> red_edges = {{3, 1}, {2, 3}, {7, 6}, {5, 1}, {1, 3}, {8, 1}, {5, 4}, {8, 4}, {6, 3}, {4, 7}, {0, 1}, {7, 8}, {3, 8}};
    vector<vector<int>> blue_edges = {{4, 1}, {5, 8}, {3, 7}, {7, 1}, {1, 8}, {8, 7}, {5, 4}};

    printIntArray(s.shortestAlternatingPaths(n, red_edges, blue_edges), " ");

    return 0;
}