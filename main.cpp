#include "String.h"
#include <stdio.h>

int main(){
  
  String str;
  String str2("Salut");
  printf("Length : %zu \n",str2.length());
  printf("Max_Size : %zu \n",str2.max_size());
  String str3(str);
  printf("%zu \n",str2.capacity()) ;
  return 0 ;
}
