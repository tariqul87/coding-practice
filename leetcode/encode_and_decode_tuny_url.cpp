#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Encodes a URL to a shortened URL.
    hash<string> urlHash;
    map<string, string> stringMap;
    string encode(string longUrl)
    {
        string shortUrl = to_string(urlHash(longUrl));
        stringMap[shortUrl] = longUrl;

        return "http://tinyurl.com/" + shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        string tinyUrl = "http://tinyurl.com/";

        return stringMap[shortUrl.substr(tinyUrl.size())];
    }
};

int main(void)
{
    string str = "https://leetcode.com/problems/design-tinyurl";
    Solution solution;
    cout << str << endl;
    str = solution.encode(str);
    cout << solution.decode(str) << endl;
    return 0;
}