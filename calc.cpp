#include <iostream>
#include <string>
#include <getopt.h>
#include <sstream>
#include <vector>

bool verbose = false;
std::vector<long> num;

void calculate(char op, std::vector<long>& num);
void argselect(int argc, char** argv);
void printhelp();
//bool isOper(string& user);

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
        readline >> sstream; // read line into stream then get oper
        char op = sstream[0];
        if(op == 'q'){return 0;}

        std::vector<std::string> tokens;
        do {
            std::string token;
            std::getline(readline, token, ' ');
            tokens.push_back(token);
            }while(!readline.eof());

        for(auto token : offset(tokens, 1))//only use numbers after the first element in the line
        {
             num.push_back(stol(token));
        }
        //std::cout << "\n";
        if(verbose == true){
            for(auto token : tokens)
            std::cout << token << std::endl;
            calculate(op, num);
        }else
            calculate(op, num);
            num.clear();
    }
    return 0;
}

void calculate(char op, std::vector<long>& num)
{
    long total = 1;

    if(op == '+'){
       for (const auto& i: num)
            total += i;
            std::cout << total - 1<< "\n";
    }else if(op == '*'){
            for(const auto& i: num)
                total *= i;
                std::cout << total << "\n";
    }else if(op == '^') {
        for(const auto& i: num)
            total ^= i;
            std::cout << total << "\n";
    }
}

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

*/
