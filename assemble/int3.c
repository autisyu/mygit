#include <iostream>
int main(int argc,char*argv[])
{
     asm ("int $1"); //µ÷ϵã¶Ï   co
     std::cout << "Hello world!" <<std::endl;
     return 0;
}
