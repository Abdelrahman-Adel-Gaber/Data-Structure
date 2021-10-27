#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


vector <int> Tree_as_array;

struct Node {
  int key;
  Node *left;
  Node *right;

};

void in_order(Node *tree) {
    // Finish the implementation
    // You may need to add a new recursive method to do that

    if(tree->left != NULL)
     in_order(tree->left);


   Tree_as_array.push_back(tree->key);


    if(tree->right!=NULL)
     in_order(tree->right);

  }

bool IsBinarySearchTree() {
  // Implement correct algorithm here
   int n= Tree_as_array.size();

   int current ;
   current =1;

   while(current < n ) {
       if(Tree_as_array[current] < Tree_as_array[current-1])
            return false;

       if( (current+1) < n)
        if(Tree_as_array[current] > Tree_as_array[current+1])
            return false;

    current += 2 ;
   }

  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree (nodes);
  int left, right;

  for (int i = 0; i < nodes; ++i) {
    cin >> tree[i].key >> left >> right;

   if(left == -1)
    tree[i].left=NULL;
    else
    {
      tree[i].left= &(tree[left]);
    }

   if(right == -1)
    tree[i].right=NULL;
    else
    {
      tree[i].right= &(tree[right]);
    }


   }
   if(nodes>0)
    in_order(&tree[0]);

   Tree_as_array.resize(nodes);

  if (IsBinarySearchTree()) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
