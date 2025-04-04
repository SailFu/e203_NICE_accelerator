
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "hbird_sdk_soc.h"

#include "insn.h"

int main(void)
{
   printf("\n***********************************************\n");
   printf("***** begin to test the NICE accelerator ******\n");
   printf("***********************************************\n\n");

   unsigned int begin_instret, end_instret, instret_normal, instret_nice;
   unsigned int begin_cycle,   end_cycle,   cycle_normal,   cycle_nice;

   int matrix_A[4][4] = 
      {{ 1,    2,    3,    4  },
       { 5,    6,    7,    8  },
       { 9,    10,   11,   12 },
       { 13,   14,   15,   16 }};

   int matrix_B[4][3] = 
      {{ -11,  -12,  -13  },
       { -14,  -15,  -16  },
       { -17,  -18,  -19  },
       { -20,  -21,  -22  }};

   int matrix_C[4][3];

   printf("matrix_A:\n");
   for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 4; j++) {
           printf("%5d ", matrix_A[i][j]);
       }
       printf("\n");
   }
   printf("\nmatrix_B:\n");
   for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 3; j++) {
           printf("%5d ", matrix_B[i][j]);
       }
       printf("\n");
   }

   begin_instret  =  __get_rv_instret();
   begin_cycle    =  __get_rv_cycle();

   nice_mul(matrix_A, matrix_B, matrix_C);

   end_instret    = __get_rv_instret();
   end_cycle      = __get_rv_cycle();

   printf("matrix_C:\n");
   for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 3; j++) {
           printf("%5d ", matrix_C[i][j]);
       }
       printf("\n");
   }
   
   instret_nice = end_instret - begin_instret;
   cycle_nice   = end_cycle - begin_cycle;

   printf("\t NICE instret: %d, cycle: %d \n", instret_nice, cycle_nice); 

   printf("\n**************************************************\n");
   printf("******** end of test the NICE accelerator ********\n");
   printf("**************************************************\n\n");


/*
   int i=100;
   int arr[4]={1,2,3,4};
   unsigned int array[ROW_LEN][COL_LEN]=
                {{10,20,30},
                 {20,30,40},
                 {30,40,50} 
                                 };
   unsigned int begin_instret, end_instret, instret_normal, instret_nice;
   unsigned int begin_cycle,   end_cycle,   cycle_normal,   cycle_nice;
   
   printf("**********************************************\n"); 
   printf("** begin to sum the array using ordinary add sum\n"); 
   begin_instret =  __get_rv_instret();
   begin_cycle   =  __get_rv_cycle();

   normal_case(array);

   end_instret = __get_rv_instret();
   end_cycle   = __get_rv_cycle();
   
   instret_normal = end_instret - begin_instret;
   cycle_normal = end_cycle - begin_cycle;
   printf("\n\n");

   printf("**********************************************\n"); 
   printf("** begin to sum the array using nice add sum\n"); 
   begin_instret =  __get_rv_instret();
   begin_cycle   =  __get_rv_cycle();

   nice_case(array);

   end_instret = __get_rv_instret();
   end_cycle   = __get_rv_cycle();
   
   instret_nice = end_instret - begin_instret;
   cycle_nice   = end_cycle - begin_cycle;


   printf("**********************************************\n"); 
   printf("** performance list \n"); 

   printf("\t normal: \n"); 
   printf("\t      instret: %d, cycle: %d \n", instret_normal, cycle_normal); 
   printf("\t nice  : \n"); 
   printf("\t      instret: %d, cycle: %d \n", instret_nice  , cycle_nice  ); 


   printf("**********************************************\n\n"); 
*/
   return 0;
}
