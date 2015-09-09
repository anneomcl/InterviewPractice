#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

namespace MySTDLib{

	inline bool IsPalindrome(char* str){
		char* start = str;
		char * end = str;
		while (*end){
			end++;
		}
		end--;

		while (end > start){
			if (*start != *end){
				return false;
			}
			start++;
			end--;
		}

		return true;
	}

	inline int MyAtoI(char * in){

		char* ptr = in;

		if (*ptr != ' ' && *ptr != '1' && *ptr != '2' && *ptr != '3' && *ptr != '4' &&
			*ptr != '5' && *ptr != '6' && *ptr != '7' && *ptr != '8' && *ptr != '9'){
			return 0;
		}

		while (*ptr == ' '){
			ptr++;
		}

		char extractedNumber[32] = "";
		int length = 0;
		while (*ptr == '1' || *ptr == '2' || *ptr == '3' || *ptr == '4' ||
			*ptr == '5' || *ptr == '6' || *ptr == '7' || *ptr == '8' || *ptr == '9'){
			char currChar[2];
			currChar[0] = *ptr; currChar[1] = '\0';
			strcat_s(extractedNumber, currChar);
			ptr++;
			length++;
		}

		ptr = extractedNumber;
		int number = 0;

		for (int i = 0; i < length; i++){
			char currChar = extractedNumber[i];
			number = number * 10 + (currChar - '0');
		}

		return number;
	}
}


