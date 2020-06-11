#include <bits/stdc++.h>
using namespace std;

vector<string> problemStr = {
    "#75 Sort Colors",
    "#80 Remove Duplicates from Sorted Array II",
    "#88 Merge Sorted Array",
    "#457 Circular Array Loop",
    "#713 Subarray Product Less Than K",
    "#845 Longest Mountain in Array",
    "#904 Fruit into baskets",
    "#925 Long Pressed name",
    "#986 Interval list intersections",
    "#33 Search in rotated sorted array",
    "#69 Sqrt(x)",
    "#153 Find min in rotated sorted array",
    "#349 Intersection of two arrays",
    "#441 Arranging coins",
    "#475 Heaters",
    "#658 Find K closest elements",
    "#911 Online Election",
    "#463 Island Perimeter",
    "#535 Encode and decode TinyURL",
    "#575 Distribute Candies",
    "#739 Daily Temperatures",
    "#748 Shortest Completing Word",
    "#811 Subdomain visit count",
    "#884 Uncommon words from Twos sentences",
    "#953 Verifying an Alien Dictionary",
    "#961 N-Repeated Element in Size 2N Array",
    "#1160 Find words that can be formed by characters",
    "#1078 Occurences after bigram",
    "#468 Validate IP Address",
    "#522 Longest Uncommon Subsequence II",
    "#539 Minimum Time Difference",
    "#553 Optimal Division",
    "#791 Custom Sort String",
    "#833 Find and replace in String",
    "#835 Image Overlap",
    "#893 Groups of Special-Equivalent Strings",
    "#1156 Swap For Longest Repeated Character Substring",
    "#424 Longest Repeating Character Replacement",
    "#1040 Moving Stones Until Consecutive II",
    "#101 Symmetric Tree",
    "#108 Convert Sorted Array to Binary Search Tree",
    "#226 Invert Binary Tree",
    "#538 Convert BST to Greater Tree",
    "#543 Diameter of a Binary Tree",
    "#637 Average of Levels in Binary Tree",
    "#654 Maximum Binary Tree",
    "#669 Trim a Binary Search Tree",
    "#589 N-ary Tree Preorder Traversal",
    "#894 All Possible Full Binary Trees",
    "#979 Distribute Coins in Binary Tree",
    "#993 Cousins in a Binary Tree",
    "#1022 Sum of Root To Leaf Binary Numbers",
    "#1104 Path In Zigzag Labelled Binary Tree",
    "#1110 Delete Nodes And Return Forest",
};

vector<int> easyProblems = {437, 572, 617, 538, 543, 101, 104, 226, 234, 206, 166, 35, 392, 350, 204, 463, 532, 28, 125, 88, 283, 344, 350, 169, 155, 346, 303, 70, 198};
vector<int> mediumProblems = {314, 156, 652, 222, 114, 199, 285, 337, 109, 817, 86, 147, 82, 737, 787, 323, 394, 529, 721, 752, 127, 490, 694, 254, 294, 81, 658, 792,
                              277, 525, 729, 16, 845, 253, 385, 355, 456, 373, 402, 211, 304, 648};

int main(void)
{
    vector<int> problems = {};
    for (string str : problemStr)
    {
        while (str.back() < '0' || str.back() > '9')
        {
            str.pop_back();
        }

        problems.push_back(stoi(str.substr(1, str.size() - 1)));
    }
    sort(problems.begin(), problems.end());

    for (int i = 0; i < mediumProblems.size(); i++)
    {
        cout << "Solve: " << mediumProblems[i] << endl;
    }
    return 0;
}