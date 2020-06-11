#include "./array.cpp"

class Solution
{
public:
    vector<int> getNeighbors(int val, vector<int> &distances)
    {
        vector<int> neighbors;
        string s = to_string(val);

        while (s.size() < 4)
        {
            s = "0" + s;
        }

        for (int i = 0; i < 4; i++)
        {
            string prevCombination = s, nextCombination = s;
            prevCombination[i] = (((int)(prevCombination[i] - '0') + 10 - 1) % 10) + '0';
            nextCombination[i] = (((int)(nextCombination[i] - '0') + 10 + 1) % 10) + '0';

            // cout << i << ": " << prevCombination << " " << nextCombination << endl;

            int prev = stoi(prevCombination), next = stoi(nextCombination);

            if (distances[prev] == INT_MAX)
            {
                neighbors.push_back(prev);
            }

            if (distances[next] == INT_MAX)
            {
                neighbors.push_back(next);
            }
        }

        return neighbors;
    }
    int getMinimumDistance(int src, int dest, vector<string> &deadends)
    {
        vector<int> srcDistances(10000, INT_MAX), destDistances(10000, INT_MAX);
        for (string str : deadends)
        {
            int dead = stoi(str);
            srcDistances[dead] = -1;
            destDistances[dead] = -1;
        }

        if (srcDistances[src] == -1 || destDistances[dest] == -1)
        {
            return -1;
        }

        int index = 0;
        srcDistances[src] = 0;
        destDistances[dest] = 0;
        vector<pair<int, int>> srcQueue, destQueue;
        srcQueue.push_back(make_pair(src, 0));
        destQueue.push_back(make_pair(dest, 0));

        while (index < srcQueue.size() && index < destQueue.size())
        {
            int currentSrc = srcQueue[index].first, srcCost = srcQueue[index].second;
            int currentDest = destQueue[index].first, destCost = destQueue[index].second;

            if (destDistances[currentSrc] != -1 && destDistances[currentSrc] != INT_MAX)
            {
                // cout << "matched src: " << currentSrc << endl;
                return srcCost + destDistances[currentSrc];
            }

            if (srcDistances[currentDest] != -1 && srcDistances[currentDest] != INT_MAX)
            {
                // cout << "matched dest: " << currentDest << endl;
                return srcDistances[currentDest] + destCost;
            }

            vector<int> srcNeighbors = getNeighbors(currentSrc, srcDistances);
            for (int val : srcNeighbors)
            {
                srcDistances[val] = srcCost + 1;
                srcQueue.push_back(make_pair(val, srcDistances[val]));
            }

            vector<int> destNeightbors = getNeighbors(currentDest, destDistances);
            for (int val : destNeightbors)
            {
                destDistances[val] = destCost + 1;
                destQueue.push_back(make_pair(val, destDistances[val]));
            }

            for (int i = 0; i < 1000; i++)
            {
            }

            index++;
        }

        return -1;
    }
    int openLock(vector<string> &deadends, string target)
    {
        return getMinimumDistance(0, stoi(target), deadends);
    }
};

int main(void)
{
    Solution s;
    vector<string> deadends = {"0000"};
    cout << s.openLock(deadends, "8888") << endl;

    return 0;
}
