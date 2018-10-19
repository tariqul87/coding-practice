#include <iostream>
#include <stdlib.h>
using namespace std;

bool insideHouse(int s, int t, int distance) {
    if (distance >= s && distance <= t) {
        return true;
    }

    return false;
}

int main(void) {
    int s, t, a, b, m, n;

    cin>>s>>t>>a>>b>>m>>n;
    
    int totalApples = 0, totalOrganges = 0;

    for (int i=0;i<m; i++) {
        int d;
        cin>>d;

        if (insideHouse(s, t, a + d)) {
            totalApples++;
        }
    }

    for (int i=0;i<n; i++) {
        int d;
        cin>>d;

        if (insideHouse(s, t, b + d)) {
            totalOrganges++;
        }
    }

    cout<<totalApples<<endl<<totalOrganges<<endl;

    return 0;
}
