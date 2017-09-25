#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>
//#include <stack>
#include <sstream>
//#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
int verbose = false;
//std::string file = "test.txt";


void argselect(int argc, char** argv);
void printhelp();
//void printinter();
//void printverbose();
//bool isOper(string& user);
//int calculate();
//..............used to offset vector........................
template <class T>
struct iter_pair {
    T a, b;

    T begin() const { return a; }
    T end() const { return b; }
};

template <class T>
using iterator_t = decltype(std::begin(std::declval<T&>()));


template <class T>
iter_pair<iterator_t<T&>> offset(T& container, size_t skip) {
    return {std::next(container.begin(), skip), container.end()};
}
//.......................................stackoverflow:Barry..
int main(int argc, char** argv)
{
    argselect(argc, argv);

    std::string user;

    while(std::getline(std::cin, user))
    {
        std::string sstream;
        std::stringstream readline(user);
        readline >> sstream;
        char op = sstream[0];
        std::cout << "first char: "<< op << std::endl;
        std::vector<std::string> tokens;
        do {
            std::string token;
            std::getline(readline, token, ' ');
            tokens.push_back(token);
            }while(!readline.eof());
        int size = tokens.size();
        std::cout << size << std::endl;

        for (auto token : offset(tokens, 1)) {
        std::cout << token << ' ';
    }
        // numbers.push_back(user);
        // int num;
        //for(auto number: numbers)

     // std::cout << number << "Yes" << std::endl;

        /*
        if(istringstream(user) >> num)
        {
            cStack.push(num);

        }else if(isOperator(user)) {
            performOp(input, cStack);

        }else if(user == "quit") {
            return 0;
        }
        */

    }


    return 0;
}



//void performOP(const string& input, stack<int>&


void printhelp()
{

    std::cout << "funcion help menu" << std::endl;
    exit(1);
}



void argselect(int argc, char** argv)
{
    const char* const opt = "hv";

    while(true)
    {

        const auto select = getopt(argc,argv,opt);
        if (-1 == select)
            break;
        switch(select)
        {
        case 'v':
            verbose = true;

            std::cout << "verbose mode On" << std::endl;
            break;
        case 'h':
            std::cout << "This is the help menu" <<std::endl;

            break;
        case '?':
            default:
            std::cout <<  "Unknown command" << std::endl;
            break;
        }

    }
}

/*
bool isOper(const string& user)
{
    string oper[] = {"+", "*", "^"}
    for(auto op: oper)
    {
        if(user == oper[op])
        {
            return true;
        }
    }
    return false;
}

void calculate(const string& user, stack<int>& cStack )
{
    long calcValue, intValue, answer;
    calcValue = cstack.top();
    calcValue.pop();


    return 0;

}

void printinter()
{


}

void printverbose()
{


}

*/


