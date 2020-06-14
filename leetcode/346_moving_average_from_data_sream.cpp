#include "array.cpp"

class MovingAverage {
public:
    /** Initialize your data structure here. */
    double sum;
    int size;
    queue<int> q;
    MovingAverage(int size) {
        sum = 0;
        this->size = size;
    }
    
    double next(int val) {
    	if (size == 0) {
    		return 0.0;
    	}
    	
        if (q.size() == size) {
        	sum -= q.front();
        	q.pop();
        }

        sum += val;
        q.push(val);
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

 int main(void){
 	MovingAverage s(3);
 	cout<<s.next(1)<<endl;
 	cout<<s.next(10)<<endl;
 	cout<<s.next(3)<<endl;
 	cout<<s.next(5)<<endl;
 }