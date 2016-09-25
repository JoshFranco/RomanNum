#include "RomanNum.h"
#include<regex.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* SearchAndSwap(const char* str, const char* old, const char* new1){
	char* ret;
	int i;
	int count = 0;
	int newlen = strlen(new1);
    	int oldlen = strlen(old); 

    	for (i = 0; str[i] != '\0'; i++){
        	if (strstr(&str[i], old) == &str[i]){
            		count++;
            		i += oldlen - 1;
        	}
    	}
    	ret = (char *)malloc(i + count * (newlen - oldlen));

    	if (ret == NULL)
        	exit(EXIT_FAILURE);
    	i = 0;
    	while (*str){
        	if (strstr(str, old) == str){
            		strcpy(&ret[i], new1);
            		i += newlen; 
            		str += oldlen;
        	}
        	else
        		ret[i++] = *str++;
    	}
    	ret[i] = '\0';
    	return ret;
}

char* Unpack(const char* package){
	char* UnpackedStr = NULL;	
	UnpackedStr = SearchAndSwap(package,"IV","IIII");
	UnpackedStr = SearchAndSwap(UnpackedStr,"IX","VIIII");
	UnpackedStr = SearchAndSwap(UnpackedStr,"XL","XXXX");
	UnpackedStr = SearchAndSwap(UnpackedStr,"XC","LXXXX");
	UnpackedStr = SearchAndSwap(UnpackedStr,"CD","CCCC");
	UnpackedStr = SearchAndSwap(UnpackedStr,"CM","DCCCC");
	UnpackedStr = SearchAndSwap(UnpackedStr,"V","IIIII");
	UnpackedStr = SearchAndSwap(UnpackedStr,"L","XXXXX");
	UnpackedStr = SearchAndSwap(UnpackedStr,"D","CCCCC");
	return UnpackedStr;
}

const char* RomanNum(const char* var1, const char* var2){
	char* Answ = malloc(24 * sizeof(char));	
	int CorrectFormat;	

	regex_t reg;
	regcomp(&reg, "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", REG_EXTENDED);	

	CorrectFormat = regexec(&reg, var1, 0, NULL, 0);
	if(CorrectFormat != 0){					//Its a NON-MATCH?!?!		
		printf("The Roman Numeral did not follow the correct input method, plz use all uppercase and follow the described rules in the README file\n");		
		exit(EXIT_FAILURE);
	}
	CorrectFormat = regexec(&reg, var2, 0, NULL, 0);
	if(CorrectFormat != 0){					//Its a NON-MATCH?!?!		
		printf("The Roman Numeral did not follow the correct input method, plz use all uppercase and follow the described rules in the README file\n");		
		exit(EXIT_FAILURE);
	}

	strcpy (Answ,var1);
	strcat (Answ,var2);
	Answ = Unpack(Answ);
	return Answ;
	

	
} 
