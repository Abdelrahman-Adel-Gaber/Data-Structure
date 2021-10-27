#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    int first_posirion;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            if(opening_brackets_stack.empty())
            {
              first_posirion = position+1;
            }
            Bracket x(next,position);
            opening_brackets_stack.push(x);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty())
                {
                  std::cout<<position+1<<std::endl;

                  return 0;
                }
            Bracket y =opening_brackets_stack.top();
            if(y.Matchc(next)){
               // Success
               opening_brackets_stack.pop();
            }
            else{
                std::cout<< position+1 << std::endl;

                return 0;
            }
        }
    }

    // Printing answer, write your code here
    if(opening_brackets_stack.empty())
    {
      std::cout<<"Success"<<std::endl;
    }
    else
    {
      std::cout<< first_posirion << std::endl;
    }
    return 0;
}
