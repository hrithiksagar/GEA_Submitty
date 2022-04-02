#include "smallest_digit.h"
#include "stdio.h"

int FindSmallest(int InputNumber){
     int r, lar = 0;


   while (InputNumber > 0) {
       r = InputNumber % 10;
       if (lar < r) {
           lar = r;
       }
       InputNumber = InputNumber / 10;
   }
    return lar;
}