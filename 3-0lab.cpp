#include <iostream>
#include <string>

int main(int argc,char *argv[])
{
  std::string  Text;
  std::cout<<"vvedi stroku\t";
  std::cin>> Text;
  //std::string Text;
  std::string old="pen";
  std::string repl="pensil";

  std::cout<< "orig:\t"<<Text<<std::endl;
  Text.replace(Text.find(old),old.length(),repl);
  std::cout<<"new:\t"<<Text<<std::endl;
  return 0;
}
