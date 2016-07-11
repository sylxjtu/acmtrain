#include <cstdio>
#include <cstring>
using namespace std;

char nums[][15] = {
  "zero"   , "one"     , "two"      , "three"   , "four"    ,
  "five"   , "six"     , "seven"    , "eight"   , "nine"    ,
  "ten"    , "eleven"  , "twelve"   , "thirteen", "fourteen",
  "fifteen", "sixteen" , "seventeen", "eighteen", "nineteen",
  "twenty" , "thirty"  , "forty"    , "fifty"   , "sixty"   ,
  "seventy", "eighty"  , "ninety"   ,
};

char suffixs[][15] = {
  "hundred", "thousand", "million",
};

int numsToint[] = {
   0,  1,  2,  3,  4,
   5,  6,  7,  8,  9,
  10, 11, 12, 13, 14,
  15, 16, 17, 18, 19,
  20, 30, 40, 50, 60,
  70, 80, 90,
};

int suffixsToint[] = {
  100, 1000, 1000000,
};

char temp[1000];
char temp2[1000];

int main(){
  while(fgets(temp, 1000, stdin)){
    int product = 1;
    int value = 0;
    int tmpp = 0;
    while(sscanf(temp+tmpp, "%s", temp2) == 1){
      if(strcmp(temp2, "negative") == 0) product = -1;
      else{
        for(int i = 0; i < 28; i++){
          if(strcmp(temp2, nums[i]) == 0){
            value += numsToint[i];
            break;
          }
        }
        for(int i = 0; i < 3; i++){
          if(strcmp(temp2, suffixs[i]) == 0){
            value = value / suffixsToint[i] * suffixsToint[i] + value % suffixsToint[i] * suffixsToint[i];
            break;
          }
        }
      }
      tmpp += strlen(temp2);
    }
    if(tmpp) printf("%d\n", value*product);
  }
}
