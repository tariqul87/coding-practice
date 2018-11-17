#include <iostream>
#include <vector>
using namespace std;

// mean heap
class Heap
{
    vector<int> arr;

  public:
    Heap()
    {
        cout << "this is a heap" << endl;
    }
};

int main()
{
    Heap *heap = new Heap();

    return 0;
}