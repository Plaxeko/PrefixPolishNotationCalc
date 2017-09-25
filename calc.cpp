/* Amir Torabi 5293010 */

#include <iostream>
#include <string>
#include <getopt.h>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <stdexcept>
#include <math.h>
bool verbose = false;
std::vector<long> num;

void printoutput(bool& verbose,std::vector<long>& num,char& op, std::vector<std::string>& tokens);
void calculate(char& op, std::vector<long>& num);
void argselect(int argc, char** argv);
void printhelp();
bool isoper(char& op);

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

        if(tolower(op) == 'q'){return 0;}

        std::vector<std::string> tokens;
        do {
            std::string token;
            std::getline(readline, token, ' ');
            tokens.push_back(token);
            }while(!readline.eof());
         for(auto token : offset(tokens, 1))//only use numbers after the first element in the line,check for integer
        {
            try{
                    if(!isdigit(stol(token))){
                    num.push_back(stol(token));
                    }else
                        std::cout << "please enter a valid integer. ";
                }
            catch(const std::invalid_argument& a)
                {
                std::cerr << "";
                }
        }
            printoutput(verbose,num,op, tokens);
   }
    return 0;
}

void printoutput(bool& verbose,std::vector<long>& num,char& op, std::vector<std::string>& tokens)
{
    if(verbose == true){
        std::cout << op;
        for(auto token : tokens)
            std::cout << " "  << token;
            std::cout << " = ";
            calculate(op, num);
            num.clear();
        }else
            calculate(op, num);
            num.clear();

}

void calculate(char& op, std::vector<long>& num)
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
            total = i * i;
            std::cout << total << "\n";
    }else if(!isoper(op)){
            std::cout << "\n" <<"please enter a valid operator as a prefix." << std::endl;}
}

void printhelp()
{
    std::cout << "*********************************************************************************************\n"
                 "* Give the system an operator first. Then give a number of integers to perform.             *\n"
                 "* -v will set the system to verbose mode and display your input before the result.          *\n"
                 "* .............................................................................             *\n"
                 "* You can Add (+), multiply (*), and give exponent (^).                                     *\n"
                 "* ..........................................................................................*\n"
                 "* type 'quit' to exit the program                                                           *\n"
                 "* ..........................................................................................*\n"
                 "* You can process a file with a set of operators which the program will process by line.    *\n"
                 "*********************************************************************************************\n"
                 "Created by Amir Torabi. \n"
<< std::endl;
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
            printhelp();

            break;
        case '?':
            default:
            std::cout <<  "Unknown command" << std::endl;
            break;
        }
    }
}

bool isoper(char& op)
{
    if(op == '+' || op == '*' || op == '^')
     {
            return true;
        }
    return false;
}


