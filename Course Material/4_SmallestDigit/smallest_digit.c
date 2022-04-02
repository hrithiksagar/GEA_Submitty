#include "smallest_digit.h"
#include "stdio.h"

int FindSmallest(int InputNumber){
     int r, sml = 9;


  while (InputNumber > 0) {
       r = InputNumber % 10;
       if (sml > r) {
           sml = r;
       }
       InputNumber =InputNumber / 10;
   }
    return sml;
}