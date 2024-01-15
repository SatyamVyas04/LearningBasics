# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main(){
	fn_n();
}

void fn_n(){
	// Function Table Header Rows
	printf("\n> Function (n)\n");
	printf("\n| N\t\t| Output\n");

	// Output Initialised
	int out;

	// Input values from 0 to 100 Loop
	for (int input = 1; input <= 100; input++){
		out = input;
		printter_int(input, out);
	}
	printf("\n\n");
}

void printter_int(int input, int out){
	printf("| %-5d\t\t| %-5d\n", input, out);
}

void printter_float(int input, float out){
	printf("\n> Float Printer\n");	
}
