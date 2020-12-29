#include <stdio.h>
#include <math.h>

void draw_rec ( int reight , int ridth );	// rectangle drawing function
void draw_tri ( int teight );				// triangle drawing function
int grt_div ( int grtnum1 , int grtnum2 );	// greatest common divisor function
int inv_dig (int dig);						// the digit invertint function

int main () {
	
	int reight, ridth, teight, grtnum1, grtnum2, grtres, dig ,inv; // reight and ridth are the rectangle's height and width, respectively || teight is the triangle height || grtnum1/2 are the input numbers to find the gratest integer divisor || grtres is the result of the greatest integer divisor || dig is an input digit to be inversed || inv is the inverted digit.
	char input;													   // input is the user input in the main 
	
	printf("Multi Function Program written by AHMAD AL-SAQQA - 201541790\n\n");
	
	
	/*a) Draw a rectangle
	b) Draw a triangle
	c) Greatest Common Divisor
	d) Reverse Digits
	e) Exit program
	Enter your choice:
	*/
	printf ("a) Draw a rectangle\nb) Draw a triangle\nc) Greatest Common Divisor\nd) Reverse Digits\ne) Exit program\nEnter your choice:");	
	scanf (" %c", &input);
	

	switch (input) {
	
		
		case 'a' :{
			
			printf ("Enter rectangle height and width [1 to 30]: ");
			scanf ("%d %d", &reight, &ridth);
			
			if ( reight < 1 || reight > 30 || ridth < 1  || ridth > 30  ) 
				input = 'z';
			else 
				draw_rec ( reight , ridth );	
			break;
		}
		case 'b' :{
			
			printf ("Enter rectangle height and width [1 to 30]: ");
			scanf ("%d", &teight);
			
			if ( teight < 1 || teight > 30 ) 
				input = 'z';
			else 
				draw_tri( teight );
			
			break;
		}
			
		case 'c' :{
			
			printf ("Enter two integer numbers: ");
			scanf ("%d %d", &grtnum1 , &grtnum2);
			
			grt_div( grtnum1 , grtnum2 );
			
			break;
		}
		case 'd' :{
			
			printf ("Enter an integer number: ");
			 scanf ("%d", &dig);
			printf ("The reverse of the integer number %d is ", dig);
			inv_dig ( dig );
			
			break;
		}
		case 'e' : {
			
			printf("Good bye!");
			
			return 0;
		}

	}
	
			if ( input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e') {
			
			printf ("\nError: Terminate and try again!");
		}
	
	
	
	return 0;
	
	}
	
void draw_rec ( int reight , int ridth ) {				// rectangle drawing function
	
	int repin=1, repout=1;
	
	while ( repout <= reight ){						// The outer loop is for running the inner loop, printing a new line, and recycling inner loops values, respectively.			
		
		while ( repin <= ridth ){					// This inner loop is for printing the required  of spaces before printing the stars.
			
			printf("*");
			repin++;	
		}
		
		printf("\n");
		repout++;
		repin = 1;
	}
 	
}

void draw_tri ( int teight ) {							// triangle drawing function

	int spcreff, spccount, starreff, starcount, newlinecount;			// spc prefix means space || star prefix means star :) || reff suffix is the refferanced/presit value for each loop || count suffix is the counter for each loop
	
	spccount = 0;				// Just variable pressiting before the loop begins
	newlinecount = 1;
	spccount = 1;
	spcreff = teight -1;
	starreff = 1;	
	
	while ( newlinecount <= teight ) {				// The outer loop is for running the inner loops, printing a new line, and recycling inner loops values, respectively.
	
		while (spccount <= spcreff) {				// This inner loop is for printing the required  of spaces before printing the stars.
		
			printf(" ");
			spccount++;
		}
		if ( starreff == 1 )						// This if statement is to print, only, the top star of the triangle.
		printf("*");	
		while (starcount <= starreff){				// This inner loop is printing the starts of each row, except for the first one i.e the top of the triangle.
			
			printf("*");
			starcount++;
		}
		
		printf("\n");
		
		newlinecount++;
		
		spccount = 1;	
		spcreff--;
		
		starcount = 1;
		starreff+=2;
	}
}


int grt_div ( int grtnum1 , int grtnum2 ) {				// greatest common divisor function
	int i, grtres;
	
	for( i = 1; i <= grtnum1 && i <= grtnum2; i++ ) {		// This loop checks each integer from 1 to no more that the given integers if it is disivible by both the integers. It stops when it reaches the highest the result was recorded
	
		if ( grtnum1 % i == 0 && grtnum2 % i == 0 ) {

		grtres = i;

  		}
  	}
	
	printf ("The greatest common divisor of %d and %d is %d", grtnum1, grtnum2, grtres);
	return grtres;
	
}
int inv_dig (int dig) {									// the digit invertint function
	int inv;

	
	
	while ( dig  > 0) {			// This loop processes the number, one digit per cycle, and prints the inverse of the given number.
		
	inv = dig % 10;
	
	printf ("%d", inv);
	
	dig /= 10;
	
	}
 
	
}
