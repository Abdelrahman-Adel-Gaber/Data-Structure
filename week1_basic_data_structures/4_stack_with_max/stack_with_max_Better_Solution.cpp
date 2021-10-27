#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

class StackWithMax {
    vector<int> stack;
    deque<int> auxiliary_stack;
    int prev;

  public:

    StackWithMax () {
    prev=-1;
  }
    void Push(int value) {
        stack.push_back(value);
        if(value<prev)
        auxiliary_stack.push_back(value);
        else
        {
          auxiliary_stack.push_front(value);
          prev=value;
        }
    }

    void Pop() {
        assert(stack.size());
        int temp=stack[stack.size()-1];
        stack.pop_back();
        if(temp==auxiliary_stack.front())
            auxiliary_stack.pop_front();
        else
            auxiliary_stack.pop_back();
    }

    int Max() const {
        return auxiliary_stack.front();
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
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
