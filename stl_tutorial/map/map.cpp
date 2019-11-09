#include <bits/stdc++.h>
using namespace std;

int main(void) {
    map<string, int> customMap;
    customMap["test"] = 2;
    customMap["test2"] = 3;
    if (customMap.find("test1") != customMap.end()) {
        cout<<"Found key"<<endl;
    }  else {
        cout<<"No key is found"<<endl;
    }

    for(auto start = customMap.begin(); start != customMap.end(); start++) {
        cout<<start->first<<": "<<start->second<<endl;
    }
    cout<<customMap["test"]<<endl;
    return 0;
}