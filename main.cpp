#include "String.h"
#include <stdio.h>

int main(){
  String str;
  String str2("Salut");
  String str4("Beaucoup");
  String str3(str2);

  printf("Length : %zu \n",str2.length());
  printf("Max_Size : %zu \n",str2.max_size());

  printf("Size: %zu \n",str2.size());
  str2.clear();
  printf("Size: %zu \n",str2.size());
  const char* essai=str3.c_str();
  String str5="trop" +str4;
  return 0 ;
}
