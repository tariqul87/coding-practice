#include "array.cpp"

class Solution {
public:
	int getMaxIndex(vector<int>& A, int index){
		int maxNumber = A[0], maxIndex = 0;

		for(int i=0; i<=index; i++) {
			if (maxNumber < A[i]) {
				maxNumber = A[i];
				maxIndex = i;
			}
		}

		return maxIndex;
	}
	void flip(vector<int>& A, int k) {
		int size = k/2;
		for(int i=0; i<size; i++) {
			swap(A[i], A[k-i-1]);
		}
	}
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        for(int i=A.size() - 1; i > 0; i--) {
        	int maxIndex = getMaxIndex(A, i);

        	if (maxIndex != i) {
        		flip(A, maxIndex+1);
        		flip(A, i+1);
                
                result.push_back(maxIndex+1);
                result.push_back(i+1);
        	}
        }

        return result;
    }
};

int main(void) {
	vector<int> arr = {1,5,3,4,2};
	Solution s;

	printIntArray(s.pancakeSort(arr), " ");

	return 0;
}