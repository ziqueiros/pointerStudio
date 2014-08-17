/*
 * stackOverflow.c
 *
 *  Created on: Jul 31, 2014
 *      Author: ixidor
 */

#include <stdio.h>
#include <string.h>

void fun1(char * r);

int stackOverFlow(){
	char *myString;
	myString = "QWERTYUIOPASDFGHJKLÑqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq";
	fun1(myString);
	return 0;
}


void fun1(char *r){
	char toSay[20];
	strcpy(toSay,r);
	printf(toSay);
}


