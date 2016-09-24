#include "RomanNum.h"
#include<regex.h>
#include<stdio.h>
#include<stdlib.h>

const char* RomanNum(char x[]){
	int CorrectFormat;
	regex_t reg;
	regcomp(&reg, "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", REG_EXTENDED);	
	CorrectFormat = regexec(&reg, x, 0, NULL, 0);
	if(CorrectFormat == 0) 			//It's a MATCH!!!!
		return x;	
	else{					//Its a NON-MATCH?!?!		
		printf("The Roman Numeral did not follow the correct input method, plz use all uppercase and follow the described rules in the README file");		
		exit(EXIT_FAILURE);
	}

	
} 
