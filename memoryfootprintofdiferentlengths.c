/*
 * memoryfootprintofdiferentlengths.c
 *
 *  Created on: Aug 2, 2014
 *      Author: ixidor
 */

//long double lArray[5]
//int iArray[5]
//This conversion causes a buffer overflow,
//memcpy(&iArray,&lArray,sizeof(lArray));
//One option is to cast the long double elements to
//int before doing de memcpy call
#include <stdio.h>
#include <windows.h>

int memoryfootprintofdiferentlengths() {

	wchar_t wideCharArray[] = L"123456789";
	char string[9];

	int result = WideCharToMultiByte(CP_UTF8, 0, wideCharArray,
			sizeof(wideCharArray), string, size(string), NULL, NULL);
	//Solution do not confuse memory footprints of different data types
	//int result = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR), wideCharArray,
	//		sizeof(wideCharArray) / sizeof(wchar_t), string, sizeof(string), NULL, NULL);
	//In this way we are calculating the size in characters

	printf("%s\n", string);

	return 0;
}

