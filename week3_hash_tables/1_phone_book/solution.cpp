#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;

//direct accessing method
vector <string> PhoneBook(10000000);



vector<string> read_queries() {
    int n;
    cin >> n;

    string query;
    vector <string> result;
    for (int i = 0; i < n; ++i) {

        cin >> query;
        if (query == "add") {
            int num;
            cin >> num >> PhoneBook[num];
        }else if (query == "find")
        {
            int num;
            cin >> num;
            if(PhoneBook[num]=="\0")
            {
                result.push_back("not found");
            } else
            {
              result.push_back(PhoneBook[num]);
             }

        }else
        {
            //delection
            int num ;
            cin >>num;
            PhoneBook[num]="\0";

        }


    }
    return result;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}



int main() {
    write_responses(read_queries());
    return 0;
}
