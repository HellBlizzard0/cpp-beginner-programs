#include <stdio.h>

#include <math.h>

#define M_IN 39.3701 /*Meter to Inch*/
#define M_MILE 0.000621371 /*Meter to Mile*/
#define M_FT 3.28084 /*Meter to feet*/

int main() {

   char unitfrom, unitto; /* unitfrom means "from unit" , unitto means "to unit"*/
   double varfrom, varto; /* varfrom means "from variable" , varto means "to variable"*/
   char convertFromMessage[] = "Convert from:\na) Kilometers\nb) Meters\nc) Centimeters\nd) Miles\ne) Feet\nf) Inches\nEnter Your Choice (a to f)";
   char convertToMessage[] = "Convert to:\na) Kilometers\nb) Meters\nc) Centimeters\nd) Miles\ne) Feet\nf) Inches\nEnter Your Choice (a to f)";
   
   printf("Converter program written by Ahmad Alsaqqa - 201541790\n\n");

   /*
   a) Kilometers
   b) Meters
   c) Centimeters
   d) Miles
   e) Feet
   f) Inches 
   */

   printf("%c", convertFromMessage);
   scanf(" %c", & unitfrom);

   switch (unitfrom) {

   case ('a'): {

      printf("Enter the Value in Kilometers:\n");
      scanf("%lf", & varfrom);

      printf("%c", convertToMessage);
      scanf("%c", & unitto);

      switch (unitto) {
         /*From kilomater to....*/

      case ('a'): {

         varto = varfrom;

         printf("%.6f Kilometers = %.6f Kilometers", varfrom, varto);

         return 0;
      }
      case ('b'): {

         varto = varfrom * 1000;
         printf("%.6f Kilometers = %.6f Meters", varfrom, varto);

         return 0;
      }
      case ('c'): {

         varto = varfrom * pow(10, 6);
         printf("%.6f Kilometers = %.6f Centimeters", varfrom, varto);

         return 0;
      }
      case ('d'): {

         varto = (varfrom * pow(10, 3)) * M_MILE;
         printf("%.6f Kilometers = %.6f Miles", varfrom, varto);

         return 0;
      }
      case ('e'): {

         varto = (varfrom * pow(10, 3)) * M_FT;
         printf("%.6f Kilometers = %.6f Feet", varfrom, varto);

         return 0;
      }
      case ('f'): {

         varto = (varfrom * pow(10, 3)) * M_IN;
         printf("%.6f Kilometers = %.6f Inches", varfrom, varto);

         return 0;
      }

      }

      case ('b'): {
         /*Convert Meters to....*/

         printf("Enter the Value in Meter:\n");
         scanf("%lf", & varfrom);

         printf("%c", convertToMessage);
         scanf(" %c", & unitto);

         switch (unitto) {

         case ('a'): {

            varto = varfrom / 1000;

            printf("%.6f Meter = %.6f Kilometers", varfrom, varto);

            return 0;
         }
         case ('b'): {

            varto = varfrom;
            printf("%.6f Meter = %.6f Meters", varfrom, varto);

            return 0;
         }
         case ('c'): {

            varto = varfrom * pow(10, 3);
            printf("%.6f Meter = %.6f Centimeters", varfrom, varto);

            return 0;
         }
         case ('d'): {

            varto = varfrom * M_MILE;
            printf("%.6f Meter = %.6f Miles", varfrom, varto);

            return 0;
         }
         case ('e'): {

            varto = varfrom * M_FT;
            printf("%.6f Meter = %.6f Feet", varfrom, varto);

            return 0;
         }
         case ('f'): {

            varto = varfrom * M_IN;
            printf("%.6f Meter = %.6f Inches", varfrom, varto);

            return 0;
         }
         }

      }
      case ('c'): {
         /*Convert Centimeters to....*/

         printf("Enter the Value in Centimeters:\n");
         scanf("%lf", & varfrom);

         printf("%c", convertToMessage);
         scanf(" %c", & unitto);

         switch (unitto) {

         case ('a'): {

            varto = varfrom / 1000000;

            printf("%.6f Centimeters = %.6f Kilometers", varfrom, varto);

            return 0;
         }
         case ('b'): {

            varto = varfrom / 1000;
            printf("%.6f Centimeters = %.6f Meters", varfrom, varto);

            return 0;
         }
         case ('c'): {

            varto = varfrom;
            printf("%.6f Centimeters = %.6f Centimeters", varfrom, varto);

            return 0;
         }
         case ('d'): {

            varto = varfrom / 1000 * M_MILE;
            printf("%.6f Centimeters = %.6f Miles", varfrom, varto);

            return 0;
         }
         case ('e'): {

            varto = varfrom / 1000 * M_FT;
            printf("%.6f Centimeters = %.6f Feet", varfrom, varto);

            return 0;
         }
         case ('f'): {

            varto = varfrom / 1000 * M_IN;
            printf("%.6f Meter = %.6f Inches", varfrom, varto);

            return 0;
         }
         }

      }

      case ('d'): {
         /*Convert Miles to....*/

         printf("Enter the Value in Miles:\n");
         scanf("%lf", & varfrom);

         printf("%c", convertToMessage);
         scanf(" %c", & unitto);

         switch (unitto) {

         case ('a'): {

            varto = varfrom * pow(10, -3) / M_MILE;

            printf("%.6f Miles = %.6f Kilometers", varfrom, varto);

            return 0;
         }
         case ('b'): {

            varto = varfrom / M_MILE;
            printf("%.6f Miles = %.6f Meters", varfrom, varto);

            return 0;
         }
         case ('c'): {

            varto = varfrom * pow(10, 3) / M_MILE;
            printf("%.6f Miles = %.6f Centimeters", varfrom, varto);

            return 0;
         }
         case ('d'): {

            varto = varfrom;
            printf("%.6f Miles = %.6f Miles", varfrom, varto);

            return 0;
         }
         case ('e'): {

            varto = varfrom * M_FT / M_MILE;
            printf("%.6f Miles = %.6f Feet", varfrom, varto);

            return 0;
         }
         case ('f'): {

            varto = varfrom * M_IN / M_MILE;
            printf("%.6f Miles = %.6f Inches", varfrom, varto);

            return 0;
         }

         break;
         }
      }

   }
   case ('e'): {
      /*Convert Feet to....*/

      printf("Enter the Value in Feet:\n");
      scanf("%lf", & varfrom);

      printf("%c", convertToMessage);
      scanf(" %c", & unitto);

      switch (unitto) {

      case ('a'): {

         varto = varfrom * pow(10, -3) / M_FT;

         printf("%.6f Feet = %.6f Kilometers", varfrom, varto);

         return 0;
      }
      case ('b'): {

         varto = varfrom / M_FT;
         printf("%.6f Feet = %.6f Meters", varfrom, varto);

         return 0;
      }
      case ('c'): {

         varto = varfrom * pow(10, 3) / M_FT;
         printf("%.6f Feet = %.6f Centimeters", varfrom, varto);

         return 0;
      }
      case ('d'): {

         varto = varfrom * M_MILE / M_FT;
         printf("%.6f Feet = %.6f Miles", varfrom, varto);

         return 0;
      }
      case ('e'): {

         varto = varfrom;
         printf("%.6f Feet = %.6f Feet", varfrom, varto);

         return 0;
      }
      case ('f'): {

         varto = varfrom * M_IN / M_FT;
         printf("%.6f Feet = %.6f Inches", varfrom, varto);

         return 0;
      }

      break;
      }
      case ('f'): {
         /*Convert Inches to....*/

         printf("Enter the Value in Inches:\n");
         scanf("%lf", & varfrom);

         printf("%c", convertToMessage);
         scanf(" %c", & unitto);

         switch (unitto) {

         case ('a'): {

            varto = varfrom * pow(10, -3) / M_IN;

            printf("%.6f Inches = %.6f Kilometers", varfrom, varto);

            return 0;
         }
         case ('b'): {

            varto = varfrom / M_IN;
            printf("%.6f Inches = %.6f Meters", varfrom, varto);

            return 0;
         }
         case ('c'): {

            varto = varfrom * pow(10, 3) / M_IN;
            printf("%.6f Inches = %.6f Centimeters", varfrom, varto);

            return 0;
         }
         case ('d'): {

            varto = varfrom * M_MILE / M_IN;
            printf("%.6f Inches = %.6f Miles", varfrom, varto);

            return 0;
         }
         case ('e'): {

            varto = varfrom * M_FT / M_IN;
            printf("%.6f Inches = %.6f Feet", varfrom, varto);

            return 0;
         }
         case ('f'): {

            varto = varfrom;
            printf("%.6f Inches = %.6f Inches", varfrom, varto);

            return 0;
         }
         default: {

            printf("Error: choice %c is not valid! program terminated", unitto);

         }

         return 0;
         }

         default: {

            printf("Error: choice %c is not valid! program terminated", unitfrom);

         }

         break;
      }

      return 0;
   }
   }
}
