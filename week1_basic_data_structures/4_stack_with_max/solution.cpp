#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

 int max =0;
 int numOfRepetition=0;
class StackWithMax {
    vector<int> stack;

  public:

    void Push(int value) {
        stack.push_back(value);
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
    }

    int Front() {
        assert(stack.size());
       return stack.back();
    }
    int Max() const {

        return *max_element(stack.begin(), stack.end()) ;
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
            if(std::stoi(value) >max)
            {max =std::stoi(value); }
        }
        else if (query == "pop") {

           int x=stack.Front();
           stack.Pop();
           if(x==max)
           {
               max=stack.Max();
           }

        }
        else if (query == "max") {
            cout << max << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
