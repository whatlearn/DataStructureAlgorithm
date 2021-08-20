#include<iostream>
#include<stack>

using namespace std;

char flag_back(char close);

int main(int argc, char *argv[])
{
    string codeline = "{sadf[sadf]}asfd(sdfasdd)";

    stack<char> flag_stack;
    for(auto flag: codeline){
        if (flag == '\0'){
            break;
        }
        if (flag == '{' || flag == '[' || flag == '('){
            flag_stack.push(flag);
            continue;
        }
        if (flag == '}' || flag == ']' || flag == ')'){
            if(flag_stack.empty()){
                printf("error 1 !\n");
                return -1;
            } 
            else{
                if(flag_back(flag) == flag_stack.top()){
                    flag_stack.pop();
                    continue;
                }
                else{
                    printf("%c\n", flag);
                    printf("error 2 !\n");
                    return -1;
                }
            }
        }
    }
    if(!flag_stack.empty()){
        printf("error 3 !\n");
        return -1;
    }
    printf("this line code is correct!\n");
    return 0;
}

char flag_back(char close)
{
    if(close == ')')
        return '(';
    if(close == '}')
        return '{';
    if(close == ']')
        return '[';
    return 0;
}