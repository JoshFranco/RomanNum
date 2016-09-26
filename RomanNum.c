#include "RomanNum.h"
#include<regex.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* NewStr(const char* OldStr){
	int t = 0;		
	int I_count = 0;
	int X_count = 0;
	int C_count = 0;
	int M_count = 0;
	const char* tmp = OldStr;
	char* OutputStr = malloc(100 * sizeof(char));	

	while((tmp = strstr(tmp,"I"))){
		I_count++;
		tmp++;	
	}
	tmp = OldStr;
	while((tmp = strstr(tmp,"X"))){
		X_count++;
		tmp++;	
	}
	tmp = OldStr;
	while((tmp = strstr(tmp,"C"))){
		C_count++;
		tmp++;	
	}
	tmp = OldStr;
	while((tmp = strstr(tmp,"M"))){
		M_count++;
		tmp++;	
	}
	
	strcpy(OutputStr,"");
	for(t = 0; t < M_count;t++){
		strcat(OutputStr,"M");
	}
	for(t = 0; t < C_count;t++){
		strcat(OutputStr,"C");
	}
	for(t = 0; t < X_count;t++){
		strcat(OutputStr,"X");
	}
	for(t = 0; t < I_count;t++){
		strcat(OutputStr,"I");
	}	
	return OutputStr;
}

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
    	while (*str){ 		//Compares the substring with the newstring
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

char* Compress(const char* package){
	char* CompressStr = NULL;	
	CompressStr = SearchAndSwap(package,"IIIII","V");
	CompressStr = SearchAndSwap(CompressStr,"VV","X");
	CompressStr = SearchAndSwap(CompressStr,"XXXXX","L");
	CompressStr = SearchAndSwap(CompressStr,"LL","C");
	CompressStr = SearchAndSwap(CompressStr,"CCCCC","D");
	CompressStr = SearchAndSwap(CompressStr,"DD","M");
	CompressStr = SearchAndSwap(CompressStr,"VIIII","IX");
	CompressStr = SearchAndSwap(CompressStr,"LXXXX","XC");
	CompressStr = SearchAndSwap(CompressStr,"DCCCC","CM");
	CompressStr = SearchAndSwap(CompressStr,"IIII","IV");
	CompressStr = SearchAndSwap(CompressStr,"XXXX","XL");
	CompressStr = SearchAndSwap(CompressStr,"CCCC","CD");
	return CompressStr;
		
}

char* Unpack(const char* package){
	char* UnpackedStr = NULL;	
	UnpackedStr = SearchAndSwap(package,"IV","IIII");	//Use the SearchAndSwap function to make the "package" in terms of I X C and M
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
	regcomp(&reg, "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", REG_EXTENDED);	//Regular Expression for a Roman Numeral, for formating

	CorrectFormat = regexec(&reg, var1, 0, NULL, 0);	//Check if the input variables are in the correct format
	if(CorrectFormat != 0){					//Its a NON-MATCH?!?!		
		printf("The Roman Numeral did not follow the correct input method, plz use all uppercase and follow the described rules in the README file\n");		
		exit(EXIT_FAILURE);
	}
	CorrectFormat = regexec(&reg, var2, 0, NULL, 0);
	if(CorrectFormat != 0){					//Its a NON-MATCH?!?!		
		printf("The Roman Numeral did not follow the correct input method, plz use all uppercase and follow the described rules in the README file\n");		
		exit(EXIT_FAILURE);
	}
	puts(var1);
	puts(var2);
	strcpy (Answ,var1);
	strcat (Answ,var2);				//Concatenate the two variables into one
	puts(Answ);	

	Answ = Unpack(Answ);		//Unpack the variables to make it simple to sort
	puts(Answ);	
	Answ = NewStr(Answ);		//Sort the variables to the correct format
	puts(Answ);	
	Answ = Compress(Answ);		//Compress the sorted string, var1 and var2 are now added
	
	puts(Answ);	
	return Answ;
	

	
} 
