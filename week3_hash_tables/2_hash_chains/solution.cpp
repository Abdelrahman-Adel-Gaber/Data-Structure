#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <math.h>

using std::string;
using std::vector;
using std::cin;
using namespace std;

 vector < list <string> > hash_table ;
 vector<string> result;

class QueryProcessor {

public:
    int bucket_count;
    // store all strings in one vector


    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
         for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;

    }


    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count)
    {
        hash_table.resize(bucket_count);
    }

    void readQuery() const {
        string query;
        cin >> query;
        if (query == "add")
        {
            string s;
            cin >> s;
            size_t hash_value=hash_func(s);

            if(hash_table[hash_value].size()==0)
            {
                hash_table[hash_value].push_front(s);
            }
            else
            {
                list <string> ::iterator it;

                for( it =hash_table[hash_value].begin();it !=hash_table[hash_value].end() ;)
                {
                    if(s.compare(* it)==0)
                        break ;
                    it++;
                    if( it == hash_table[hash_value].end())
                        hash_table[hash_value].push_front(s);
                }
            }
        }

        else if(query == "del")
        {
             string s;
             cin >> s;
             size_t hash_value=hash_func(s);
              list <string> ::iterator it;


            for( it=hash_table[hash_value].begin() ; it!=hash_table[hash_value].end() ; it++)
            {

                if( s.compare(*it) == 0 )
                {
                    hash_table[hash_value].erase(it);
                    break;
                }
            }
        }

        else if(query == "find")
        {

             string s;
             cin >> s;
             size_t hash_value=hash_func(s);

            if(hash_table[hash_value].size()==0)
                {result.push_back("no");
                     return ;
                     }
               list <string> ::iterator it;
             for( it=hash_table[hash_value].begin();it!=hash_table[hash_value].end();)
             {
                if( s.compare(*it) == 0 )
                {
                    result.push_back("yes");
                    break;
                }
                 it++;
                if(it==hash_table[hash_value].end())
                {
                    result.push_back("no");
                }
            }
        }

        else
        {
           //check
           int index;
           cin >>index;
           if(hash_table[index].size()==0)
           {
               result.push_back("  ");
           }
           else
           {
               string result_of_check;
               list <string>::iterator it;
               it=hash_table[index].begin();
               result_of_check= *it;
               it++;
               for( ;it!=hash_table[index].end();it++)
               {
                   result_of_check = result_of_check + ' ' +*it;
                 }
               result.push_back(result_of_check);
            }

        }



    }


    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            readQuery();

      for(long long i=0 ;i<result.size();i++)
          cout<<result[i]<<std::endl;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();

    return 0;
}
