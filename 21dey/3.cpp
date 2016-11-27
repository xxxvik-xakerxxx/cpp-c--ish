#include <iostream>

//Функция Demonstration Function
//выводит на экран информативное сообщение

void DemonstrationFunction()
{
  std::cout<<"In DemonstrationFunction\n";
}
//Функция main выводит сообщение, а затем
//вызывает функцию DemonstrationFunction и
//выводит на экран второе сщщбщение.

int main()
{
  std::cout<<"In main\n";
  DemonstrationFunction();
  std::cout<<"Back in main\n";
  return 0;
}
