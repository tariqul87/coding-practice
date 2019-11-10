#include "array.cpp"

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        vector<string> result;
        map<string, int> subDomains;

        for (int i = 0; i < cpdomains.size(); i++)
        {
            string str = cpdomains[i];
            string countString = str.substr(0, str.find(" "));
            int count = stoi(countString);

            for (int i = str.size() - 1; i >= str.find(" "); i--)
            {
                if (str[i] == ' ' || str[i] == '.')
                {
                    string subDomainStr = str.substr(i + 1, str.size());
                    if (subDomains.find(subDomainStr) == subDomains.end())
                    {
                        subDomains[subDomainStr] = count;
                    }
                    else
                    {
                        subDomains[subDomainStr] += count;
                    }
                }
            }
        }

        for (auto start = subDomains.begin(); start != subDomains.end(); start++)
        {
            result.push_back(to_string(start->second) + " " + start->first);
        }

        return result;
    }
};

int main(void)
{
    vector<string> input = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    Solution solution;
    vector<string> result = solution.subdomainVisits(input);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}