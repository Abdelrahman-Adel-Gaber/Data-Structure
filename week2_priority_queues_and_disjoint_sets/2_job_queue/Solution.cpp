#include <iostream>
#include <vector>
#include <algorithm>


using std::vector;
using std::cin;
using std::cout;
using std::swap;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;
  vector < vector<long long> > Min_Heap;
  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

 void sift_up(int child) {
     int parent =(child-1)/2;
     bool condition = (Min_Heap[parent][0] > Min_Heap[child][0]) ||((Min_Heap[parent][0] == Min_Heap[child][0]) &&(Min_Heap[parent][1] > Min_Heap[child][1]));

     while( (child>=1) && condition )
     {
         swap(Min_Heap[parent][0],Min_Heap[child][0]);
         swap(Min_Heap[parent][1],Min_Heap[child][1]);
         child= parent;
         parent =(child-1)/2;
         condition = (Min_Heap[parent][0] > Min_Heap[child][0]) ||((Min_Heap[parent][0] == Min_Heap[child][0]) &&(Min_Heap[parent][1] > Min_Heap[child][1]));
      }

 }

 void sift_down(int parent) {
     int Min_index =parent;
     int l= 2*parent+1;
     int r= 2*parent+2;
     bool condition =false;

     if(l<Min_Heap.size())
      condition = (Min_Heap[Min_index][0]>Min_Heap[l][0]) ||( (Min_Heap[Min_index][0]==Min_Heap[l][0]) &&(Min_Heap[Min_index][1]>Min_Heap[l][1])) ;

     if( (l<Min_Heap.size()) && condition ) {
         Min_index =l;
     }

    if(r<Min_Heap.size())
     condition = (Min_Heap[Min_index][0]>Min_Heap[r][0]) ||( (Min_Heap[Min_index][0]==Min_Heap[r][0]) &&(Min_Heap[Min_index][1]>Min_Heap[r][1])) ;

     if( (r<Min_Heap.size()) && condition ) {
         Min_index =r;
     }

     if(Min_index != parent) {
         swap(Min_Heap[parent][0],Min_Heap[Min_index][0]);
         swap(Min_Heap[parent][1],Min_Heap[Min_index][1]);

          sift_down(Min_index);
         }

 }

  void Extract_Min(int i)
  {
     assigned_workers_[i]=Min_Heap[0][1];
     start_times_[i]=Min_Heap[0][0];
     Min_Heap[0][0]+=jobs_[i];
     sift_down(0);
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());


    for(int i=0; (i<num_workers_) && (i<jobs_.size()) ; i++)
    {
        Min_Heap.push_back({jobs_[i],i});
        sift_up(i);
        assigned_workers_[i]=i;
        start_times_[i]=0;
    }

    for(int i =num_workers_ ; i<jobs_.size() ;i++ )
     Extract_Min(i);
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
