#include <iostream>
#include <vector>

using namespace std;

double findGrantsCap( vector<int> grantsArray, int newBudget ) 
{
  // your code goes here
  sort(grantsArray.begin(), grantsArray.end());
  double previousSum = 0.0, result = 0;
    
  for(int i=0; i<grantsArray.size() && grantsArray[i] < newBudget; i++) {
    double currentCap = (newBudget - previousSum) / (grantsArray.size() - i);
    
    if (i == 0 || (currentCap > grantsArray[i-1] && currentCap <= grantsArray[i])) {
      result = currentCap;
    }
    
    previousSum += grantsArray[i];
    
  }
  
  return result;
}

int main() {
  vector<int> grants = {2, 100, 50, 120, 100};
  int newBudget = 190;
  
  cout<<findGrantsCap(grants, newBudget)<<endl;
  return 0;
}