#include "String.h"
#include <stdio.h>

int main(){
  
  String str;
  String str2("Salut");
  printf("Length : %zu \n",str2.length());
  printf("Max_Size : %zu \n",str2.max_size());
  str2.resize((size_t)7);
  //String str3(str); //Erreur lors de l'execution avec valgrind
  return 0 ;
}
