#include "String.h"
#include <stdio.h>

int main(){
  
  String str;
  String str2("Salut");
  String str3(str);
  printf("%zu \n",str2.capacity()) ;
  return 0 ;
}
