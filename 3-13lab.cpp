#include <cstring>
#include <iostream>

int main()
{
  char string[100], tmp[100];

  std::cout<<"input: ";
  std::cin.getline(string, 100);

  strcpy(tmp, string);

  char *del=strtok(tmp," ");
  while(del !=NULL)
  {
    if(del[0]==del[strlen(del)-1])
    {
      if(del==tmp) break;
      int n=del-tmp;
      strncpy(tmp,string,n);
      tmp[n]='\0';
      std::cout<<tmp;
      break;
    }
    del=strtok(NULL," ");
  }
  return 0;
}
