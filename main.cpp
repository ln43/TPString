#include "String.h"
#include <stdio.h>

int main(){
  String str;
  String str2("Salut");
  printf("Length : %zu \n",str2.length());
  printf("Max_Size : %zu \n",str2.max_size());
  str2.resize((size_t)3,'c');
  String str3(str);
  str2='c';
  
  return 0 ;
}
