#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void max_sliding_window_naive(vector<int> const & A, int w) {
   deque <int>Q;
    for(int i=0; i<w; i++ )
     {
         while(!Q.empty() && A[i]>=A[Q.back()]){
             Q.pop_back();
         }
         Q.push_back(i);
     }

     for(int i=w; i<A.size(); i++) {
         cout<<A[Q.front()]<<" ";
          while(!Q.empty() && A[i]>=A[Q.back()]){
             Q.pop_back();
           }
          Q.push_back(i);

         while(!Q.empty() && (i-w)>=Q.front()){
             Q.pop_front();
           }
     }
   cout<<A[Q.front()]<<" ";
    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
