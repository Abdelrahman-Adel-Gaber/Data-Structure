#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using  namespace std;

typedef unsigned long long ull;
typedef vector<ull> HashTable;
struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<ull>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}


size_t multiplier =1;
const size_t prime = 1000000007;

ull hash_func(const string& s) {
        ull hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash ;
    }

HashTable PreCompueHashes(const string& t,ull p) {
    ull T=t.size();
    HashTable H(T-p+1);
    string s(t.begin()+T-p,t.end());
    H[T-p]= hash_func(t.substr(t.size()-p,t.size()));
    ull y=1;
    for(ull i=0;i<p; i++)
     y=(y*multiplier)%prime;

   for(long long i=T-p-1; i>=0; --i) {
        H[i]=(multiplier*H[i+1]+t[i]-y*t[i+p])%prime;
     }
    return H;
    }


std::vector<ull> get_occurrences(const Data& input) {
    string s = input.pattern, t = input.text;
    // multiplier=rand()%(s.size()-1)+1;
    std::vector<ull> ans;
    HashTable H=PreCompueHashes(t,s.size());
    ull h_pattern=hash_func(s);
     for (size_t i = 0; i<H.size() ; ++i){
        if (H[i] == h_pattern) {
            for(int j=i; (j-i)<s.size(); j++) {
                if(t[j]!=s[j-i])
                  break;
                else if(j-i == s.size()-1)
                    ans.push_back(i);
            }
          }
        }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
