#include "String.h"
#include <stdio.h>

int main(){
  
  String str;
  String str2("Salut");

  printf("Length : %zu \n",str2.length());
  String str3(str);
  return 0 ;
}
