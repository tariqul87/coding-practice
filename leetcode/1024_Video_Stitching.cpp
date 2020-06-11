#include "array.cpp"

class Solution
{
public:
    vector<int> getNextClip(vector<vector<int>> &clips, vector<int> currentClip)
    {
        int maxDuration = currentClip[1], i = 0;
        vector<int> nextClip = {};
        while (i < clips.size())
        {
            if (clips[i][0] <= currentClip[1])
            {
                if (clips[i][1] > maxDuration)
                {
                    nextClip = {clips[i][0], clips[i][1]};
                    maxDuration = nextClip[1];
                }

                clips.erase(clips.begin() + i);
            }
            else
            {
                i++;
            }
        }

        return nextClip;
    }
    int videoStitching(vector<vector<int>> &clips, int T)
    {
        int len = 0;
        vector<int> currentClip = {0, 0};
        int maxDuration = 0;

        while (maxDuration < T && clips.size())
        {
            currentClip = getNextClip(clips, currentClip);
            // cout << "Current: ";
            // printIntArray(currentClip, " ");
            // cout << endl;
            // printDoubleIntArray(clips, " ");
            if (currentClip.size() == 0)
            {
                return -1;
            }
            maxDuration = currentClip[1];
            len++;
        }

        return maxDuration >= T ? len : -1;
    }
};

int main(void)
{
    vector<vector<int>> clips = {{3,6}, {5, 9}};
    int T = 4;
    Solution solution;
    cout << solution.videoStitching(clips, T) << endl;
}