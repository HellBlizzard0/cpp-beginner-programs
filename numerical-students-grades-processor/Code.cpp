#include <stdio.h>
#include <math.h>

#define SINTINAL -1

int main (void){
	
	int grdstd, maxstd, minstd, i;  							// grdstd = each student grade || maxstd = the maximum students grade || minstd = minimum grade || i = an on/off switch for the loop || sumgrd = the sum of the grades.
	int inv, grd100_90, grd89_80, grd79_70, grd69_60, grdsub60; // inv = number of invalid entries || grdxx_yy = the number of students whos scored from xx to yy || stdsub60 = the number of students who got below 60.
	double avgstd, numstd, sumgrd;								// avgstd means the average grade for the students || numstd = number of students || sumgrd = the sum of the grades.
	
	printf("Grade Statistics Program written by AHMAD AL-SAQQA - 201541790\n\n");
	
	printf("Enter a list of students grades (0 to 100) ended with -1.\nPress enter between each grade.\n");
	
	i = 1;								// Just some variables presetting before the loop begins.
	inv = 0;
	sumgrd = 0;
	maxstd = 0;
	minstd = 100;
	numstd = 0; 
	grd89_80 = 0;
	grd79_70 = 0;
	grd69_60 = 0;
	grdsub60 = 0;
	
	
	while ( i == 1){			
		
		scanf ( "%d", &grdstd );
		
		if ( grdstd == SINTINAL ) 	// This nested if tests the checks for the sintinal trigger, maximum/minium grades, and the invalid entries, respectively.
			i = 0;
			
		else {
			
			if ( grdstd > maxstd ) {
				if ( grdstd > 100 ) {
					inv++;	
				}
				else
				maxstd = grdstd;
				}
			else {
				if( grdstd < minstd ) {
					if ( grdstd >= 0 ) {
					
					minstd = grdstd;
					}
					else
					inv++;
				}
			}
		
		
		}
	
	
		// The following if statements are checkpoints to check in which grade range the input is.
	
		if ( grdstd <= 100 && grdstd >= 90 ) {
			grd100_90++;
			numstd++;
			sumgrd += grdstd;
		}
	
		if ( grdstd <= 89 && grdstd >= 80 ){
			grd89_80++;
			numstd++;	
			sumgrd += grdstd;	
		}
			
		if 	( grdstd <= 79 && grdstd >= 70 ){
			grd79_70++;
			numstd++;
			sumgrd += grdstd;
		}
		
		if ( grdstd <= 69 && grdstd >= 60 ) {
			grd69_60++;
			numstd++;	
			sumgrd += grdstd;	
			
		}
	
		if ( grdstd < 60 && grdstd >= 0) {
			grdsub60++;
			numstd++;
			sumgrd += grdstd;		
		}
	

	}
	
	avgstd = sumgrd /  numstd ;				// Average calculator.
	
	
printf("Number of students who scored 90 to 100: %d\n",grd100_90);		// The final printing after the sintenal is triggered.
printf("Number of students who scored 89 to 80: %d\n",grd89_80);
printf("Number of students who scored 79 to 70: %d\n",grd79_70);
printf("Number of students who scored 69 to 60: %d\n",grd69_60);
printf("Number of students who scored below 60: %d\n",grdsub60);
printf("Number of invalid grades in the list: %d\n",inv);
printf("Maximum student grade: %d\n", maxstd);
printf("Minimum student grade: %d\n", minstd);
printf("Average student grade: = %.2f\n", avgstd);

	
	
	
	
	return 0;
}
