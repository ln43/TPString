#include "String.h"
#include <stdio.h>

int main(){
  String str;
  String str2("Salut");
  String str4("Beaucoup");
  String str3(str2);

  printf("Length : %zu \n",str2.length());
  printf("Max_Size : %zu \n",str2.max_size());

  str2.resize((size_t)7);
  printf("Size: %zu \n",str2.size());
  str2.clear();
  printf("Size: %zu \n",str2.size());
  char* essai=str3.c_str();
  printf(essai);

  printf(essai);

  str2.resize((size_t)3,'c');
  String str6(str);
  str2='c';
  String operatoregal;
  operatoregal=str4;
  printf("Size: %zu \n",operatoregal.size());
//==============
  printf("%zu \n",str2.capacity()) ;
  printf("%d \n",str2.empty()) ;
  printf("%d \n",str.empty()) ;
  String str5("Hello !") ;
  printf("Size : %zu\n",str5.length()) ;
  printf("Capacity : %zu\n",str5.capacity()) ;
  str5.reserve((size_t)10) ;
  printf("Size : %zu\n",str5.length()) ;
  printf("Capacity : %zu\n",str5.capacity()) ;
  str5.reserve((size_t)9) ;
  printf("Size : %zu\n",str5.length()) ;
  printf("Capacity : %zu\n",str5.capacity()) ;
  str5.reserve((size_t)5) ;
  printf("Size : %zu\n",str5.length()) ;
  printf("Capacity : %zu\n",str5.capacity()) ;
  str5.reserve((size_t)200) ;
  printf("Size : %zu\n",str5.length()) ;
  printf("Capacity : %zu\n",str5.capacity()) ;
  return 0 ;
}
