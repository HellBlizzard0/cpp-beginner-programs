#include <stdio.h>
#include <math.h>

int read_store_data (double prodid[], double prodqua[], double prodprice[]);	//This function collects the data from the products file and returns a counter for those products.
void read_order (double orderid[], double orderqua[], int *ordercount);	//This function collects the data from the orders file.
void process_order (double prodid[], double prodqua[], double prodprice[], double orderid[], double orderqua[],  int prodcount, int ordercount);	//This function collects the data from the previous two functions and generates the bill into a seperate file.
int main () {
	
	char choice;	// choice is the user choice on the main interface
	double prodid[100], prodqua[100], prodprice[100], orderid[100], orderqua[100];	// prod prefix means product || order prefix means order || id is for the product ID || price is the product price || qua means the product quantity.
	int trig=1, prodcount=0, ordercount;	// trig is a trigger for the main interface's loop || prod prefix means product || order prefix means order || count is to count the number of product in each file.
	
	printf ("Online Purchase Program written by Ahmad Alsaqqa - 201541790 - Sec. 11\n\n");
	
	do {	// The main interface.
		
		printf ("a) Read a store data file\nb) Read an order and generate a bill\nc) Exit program\n\nEnter Choice:");
		scanf (" %c", &choice);
		
		switch (choice) {
		
			case 'a' :{	// Read a store data file.
				
				prodcount = read_store_data ( prodid, prodqua, prodprice );
				break;
			}
			case 'b' :{	// Read an order and generate a bill.
				
				if ( prodcount != 0){	// if statement to check if the user input a store data file first or not.
					read_order (orderid , orderqua, &ordercount);
					process_order (prodid, prodqua, prodprice, orderid, orderqua, prodcount, ordercount);
				}
				else {
					printf ("Error: Store data file unspecified or empty!\n");
					trig = 0;
				}
				break;
			}
			case 'c' :{	//Close the program.
				printf ("Good bye!");
				trig = 0;
				break;
			}
			default :{
				printf("Error: Wrong input, please try again.\n");
				
				break;
			}
		}
	} while (trig == 1);
	
	return 0;
}

int read_store_data (double prodid[], double prodqua[], double prodprice[]) {
	
	int i=0, prodcount=1, trig=1;	// i is for looping porpuses
	char filename[100]; 	// filename is the name of the file :)
	FILE *filepointer;		// filepointer is the pointer of the file :)
	
	do {	// Loop to give the user more chances to enter the file name.
	
		printf ("Enter the name of the store data file:");		// Filename frompt.	
		scanf (" %s", &filename);
	
		filepointer = fopen( filename, "r" );
		
		if ( fscanf (filepointer, "%lf %lf %lf", &prodid[i], &prodqua[i], &prodprice[i]) == -1 )	// if statement to check if the file exists.
			printf ("Failed to open %s\n", filename);
		else {
			trig=0;
			i++;
			while ( fscanf ( filepointer , "%lf %lf %lf", &prodid[i], &prodqua[i], &prodprice[i]) != EOF ) {	// This loop collects the data from the file.
			prodcount++;
			i++;
			}
		}
	}	while ( trig != 0);
	printf ("File %s was opened successfull:%d products are found.\n", filename, i);
	fclose (filepointer);
	
	return prodcount;	
}

void read_order (double orderid[], double orderqua[], int *ordercount) {
	int i=0, trig=1;			// i is for looping porpuses
	char filename[100]; // filename is the name of the file :)
	FILE *filepointer;  // filepointer is the pointer of the file :)
	
	
	do {	// Loop to give the user more chances to enter the file name.
	
		printf ("Enter the name of the order file data file:");	// Filename frompt.
		scanf (" %s", &filename);
	
		filepointer = fopen( filename, "r" );
																												
		if ( fscanf (filepointer, "%lf %lf", &orderid[i], &orderqua[i]) == -1 )	// if statement to check if the file exists.
			printf ("Failed to open %s\n", filename);
		else {
			trig=0;
			i++;
			while ( fscanf (filepointer, "%lf %lf", &orderid[i], &orderqua[i]) != EOF ) {	// This loop collects the data from the file.
			i++;
			}
		}
	} while ( trig != 0 );
	*ordercount = i;
	
	fclose (filepointer);
	
	return;
}
void process_order (double prodid[], double prodqua[], double prodprice[], double orderid[], double orderqua[],  int prodcount, int ordercount){
	int i=0,j, exist=0, index;	// i and j are for looping porpuses || exist is for checking if the order exist in the store file || index is to record the index of the product price if an order existed.
	double orderprice[100];
	char filename[100]; // filename is the name of the file :)
	FILE *filepointer;	// filepointer is the pointer of the file :)
	
	
	printf ("Enter the name of the bill file data file:");	// Filename frompt.
	scanf (" %s", &filename);
	
	filepointer = fopen( filename, "w" );
																													
																																																				
	fprintf (filepointer, "Product		Quantity	Unit Price	Price\n-------		--------	----------	------\n");
		
		do {		// Nested loop to check if orders from the order file exist in the store file. Then, an If statement, accordingly, decides what to print in the bill file.
			j = 0;
	
			while ( j < prodcount) {
				
				
				
				
				if (prodid[j] == orderid[i]){	// if statement to check if the oreder exist in the store file
					index = j;	// index reocrder
					j = 99;		// inner loop terminator
					exist = 1;	// order exist
				}
				else
					exist = 0;	// order does not exist
				j++;
			}

			if ( exist == 1 )	{
				
				fprintf (filepointer, "%5.0f		%5.0f		%8.2f		%8.2f\n", orderid[i], orderqua[i], prodprice[index], prodprice[index] * orderqua[i]);
			}
			else	{
				
				fprintf (filepointer, "%5.0f	Sorry, the order does not exist.\n", orderid[i]);
			}
			i++;
		}	while (i < ordercount);
	
	fclose (filepointer);	
	return;
}
