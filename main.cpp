#include "String.h"
#include <stdio.h>

int main(){
  String str;
  String str2("Salut");
<<<<<<< HEAD
  String str3(str2);
=======
  printf("Length : %zu \n",str2.length());
  printf("Max_Size : %zu \n",str2.max_size());
  str2.resize((size_t)7);
  String str3(str);
>>>>>>> fe8b8d2eb2667c6d6d5aa02cc35e13b8325d4620
  return 0 ;
}
