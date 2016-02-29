#include "String.h"
#include <stdio.h>

int main(){
  String str;
  String str2("Salut");
  String str4("Beaucoup");
  String str3(str2);

  printf("Length : %zu \n",str2.length());
  printf("Max_Size : %zu \n",str2.max_size());
<<<<<<< HEAD
  //~ str2.resize((size_t)7);
  printf("Size: %zu \n",str2.size());
  str2.clear();
  printf("Size: %zu \n",str2.size());
  char* essai=str3.c_str();
  printf(essai);

  printf(essai);
=======
  str2.resize((size_t)3,'c');
  String str3(str);
  str2='c';
  
>>>>>>> 9e978ce7958bdd49f78247e2a058f157758b97f9
  return 0 ;
}
