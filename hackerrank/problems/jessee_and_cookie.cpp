#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;


vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */

class PriorityQueue
{
    vector<int> A;
    int length;

  public:
    PriorityQueue(vector<int> arr)
    {
        int heap_size = arr.size();

        for (int i = 0; i < heap_size; i++)
        {
            A.push_back(arr[i]);
        }

        build_max_heap();
    }
    void build_max_heap()
    {
        int heap_size = A.size();
        for (int i = heap_size / 2 - 1; i >= 0; i--)
        {
            max_heapify(i);
        }
    }
    int size()
    {
        return A.size();
    }
    void max_heapify(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        int heap_size = A.size();
        if (l < heap_size && A[l] < A[smallest])
        {
            smallest = l;
        }

        if (r < heap_size && A[r] < A[smallest])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            int temp = A[i];
            A[i] = A[smallest];
            A[smallest] = temp;

            max_heapify(smallest);
        }
    }
    void print()
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    int pop()
    {
        if (A.size() <= 0)
        {
            return -1;
        }
        int heap_size = A.size();
        int number = A[0];
        A[0] = A[heap_size - 1];
        A.pop_back();
        max_heapify(0);

        return number;
    }
    void insert(int i) {
        A.push_back(i);
        int childPosition = A.size() - 1;
        int parentPosition = (childPosition - 1) / 2;

        while(childPosition > 0 && A[childPosition] < A[parentPosition])
        {
            int temp = A[childPosition];
            A[childPosition] = A[parentPosition];
            A[parentPosition] = temp;

            childPosition = parentPosition;
            parentPosition = (childPosition - 1) /2 ;
        }
    }
};


int cookies(int k, vector<int> A) {
    /*
     * Write your code here.
     */
    PriorityQueue *p = new PriorityQueue(A);

    int sweetNess = 0, count = 0, n1 = p->pop();

    while(n1 < k && n1 != -1) {
        int n2 = p->pop();
        count++;

        p->insert(n1 + 2*n2);
        n1 = p->pop();
    }

    if (n1 == -1) {
        return -1;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
