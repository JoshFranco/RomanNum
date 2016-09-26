#include "RomanNum.h"
#include<regex.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* Subtract(const char* var1, const char* var2){
	int I_count1 = 0;
	int X_count1 = 0;
	int C_count1 = 0;
	int M_count1 = 0; 
	int I_count2 = 0;
	int X_count2 = 0;
	int C_count2 = 0;
	int M_count2 = 0; 
	int t = 0;
	char* OutputStr = malloc(100 * sizeof(char));
	
	const char* tmp = var1;	
	while((tmp = strstr(tmp,"I"))){
		I_count1++;
		tmp++;	
	}
	tmp = var1;	
	while((tmp = strstr(tmp,"X"))){
		X_count1++;
		tmp++;	
	}
	tmp = var1;	
	while((tmp = strstr(tmp,"C"))){
		C_count1++;
		tmp++;	
	}
	tmp = var1;	
	while((tmp = strstr(tmp,"M"))){
		M_count1++;
		tmp++;	
	}

	tmp = var2;	
	while((tmp = strstr(tmp,"I"))){
		I_count2++;
		tmp++;	
	}
	tmp = var2;	
	while((tmp = strstr(tmp,"X"))){
		X_count2++;
		tmp++;	
	}
	tmp = var2;	
	while((tmp = strstr(tmp,"C"))){
		C_count2++;
		tmp++;	
	}
	tmp = var2;	
	while((tmp = strstr(tmp,"M"))){
		M_count2++;
		tmp++;	
	}

	if(I_count1 > I_count2){
		X_count2 = X_count2 - 1;
		I_count2 = I_count2 + 10;	
	}
	if(X_count1 > X_count2){
		C_count2 = C_count2 - 1;
		X_count2 = X_count2 + 10;	
	}
	if(C_count1 > C_count2){
		M_count2 = M_count2 - 1;
		C_count2 = C_count2 + 10;	
	}


	
	strcpy(OutputStr,"");
	for(t = 0; t < M_count2 - M_count1;t++){
		strcat(OutputStr,"M");
	}
	for(t = 0; t < C_count2 - C_count1;t++){
		strcat(OutputStr,"C");
	}
	for(t = 0; t < X_count2 - X_count1;t++){
		strcat(OutputStr,"X");
	}
	for(t = 0; t < I_count2 - I_count1;t++){
		strcat(OutputStr,"I");
	}	
	return OutputStr;
	
}


int AddOrSub(const char* var1, const char* var2){
	int I_count1 = 0;
	int X_count1 = 0;
	int C_count1 = 0;
	int M_count1 = 0; 
	int I_count2 = 0;
	int X_count2 = 0;
	int C_count2 = 0;
	int M_count2 = 0; 
	
	const char* tmp = var1;	
	while((tmp = strstr(tmp,"I"))){
		I_count1++;
		tmp++;	
	}
	tmp = var1;	
	while((tmp = strstr(tmp,"X"))){
		X_count1 = X_count1+10;
		tmp++;	
	}
	tmp = var1;	
	while((tmp = strstr(tmp,"C"))){
		C_count1 = C_count1+100;
		tmp++;	
	}
	tmp = var1;	
	while((tmp = strstr(tmp,"M"))){
		M_count1 = M_count1+1000;
		tmp++;	
	}

	tmp = var2;	
	while((tmp = strstr(tmp,"I"))){
		I_count2++;
		tmp++;	
	}
	tmp = var2;	
	while((tmp = strstr(tmp,"X"))){
		X_count2 = X_count2+10;
		tmp++;	
	}
	tmp = var2;	
	while((tmp = strstr(tmp,"C"))){
		C_count2 = C_count2+100;
		tmp++;	
	}
	tmp = var2;	
	while((tmp = strstr(tmp,"M"))){
		M_count2 = M_count2+1000;
		tmp++;	
	}
	if(I_count2+X_count2+C_count2+M_count2 > I_count1+X_count1+C_count1+M_count1)
		return 0;	//sub
	else
		return 1;	//add
}

char* SortStr(const char* OldStr){
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
	char* Temp1;
	char* Temp2;	
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

	Temp1 = Unpack(var1);
	Temp2 = Unpack(var2);
	//puts(var1);
	//puts(var2);
	if(AddOrSub(var1,var2) == 1){
		strcpy (Answ,Temp1);
		strcat (Answ,Temp2);	//Concatenate the two variables into one
		Answ = SortStr(Answ);	//Sort the variables to the correct format
		Answ = Compress(Answ);	//Compress the sorted string, var1 and var2 are now added
		return Answ;
	}
	else{
		Answ = Subtract(Temp1,Temp2);
		Answ = Compress(Answ);
		return Answ;
	}
		


	
	

	
} 
