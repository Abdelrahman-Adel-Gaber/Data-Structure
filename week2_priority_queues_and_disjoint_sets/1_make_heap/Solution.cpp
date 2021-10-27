#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

 //std::ifstream File1("04");
 //std::ofstream File2("004.txt");


class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void check_if_heap(){
   int parent =0;
   int l=2*parent+1;
   int r=2*parent+2;
   int size_=data_.size();

   while(l<size_)
    {
      if(r<size_)
        { if( data_[parent]<data_[l] && data_[parent]<data_[r])
             { parent ++;
             l=2*parent+1;
             r=2*parent+2;
                }
                else
                    {
                      cout<<"Failed Algorithm\n";
                      return;
                    }
              }else
                  {if( data_[parent]<data_[l] )
                     { parent ++;
                     l=2*parent+1;
                        }
             }
     }
  }
  void WriteResponse() const {
    //changing was here
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
    cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    //changing was here
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
    cin>> data_[i];

  }

  void siftDown(int i)
  {
   int size_ =data_.size()-1;
   int min_index =i;
   int l=2*i+1;
   int r=2*i+2;

   if( (l<=size_) && (data_[l]<data_[min_index]) )
    min_index=l;

   if( (r<=size_) && (data_[r]<data_[min_index]) )
    min_index=r;

   if( i != min_index )
    {
      swap(data_[i],data_[min_index]);
      swaps_.push_back(make_pair(i,min_index));
      siftDown(min_index);
    }
  }

  void siftUp(int i)
  {
      int parent =(i-1)/2;
      if ((i >0) && (data_[parent]>data_[i]) )
        {
           swap(data_[i],data_[parent]);
           swaps_.push_back(make_pair(parent, i));
           siftDown(i);
           i=parent;
           parent =(i-1)/2;
         }

  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
     int temp = data_.size()/2;
    for (int child = data_.size()-1; child >= 0 ; child--)
       {
         int parent =(child-1)/2;
         if(data_[child]<data_[parent])
         {
           swap(data_[child],data_[parent]);
           swaps_.push_back(make_pair(parent, child));
           siftDown(child);


            }

         }

   //  check_if_heap();

    }




 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
