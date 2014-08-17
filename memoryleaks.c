/*
 * memoryleaks.c
 *
 *  Created on: Aug 3, 2014
 *      Author: ixidor
 */


#include <stdafx.h>
#include <stdlib.h>
#include <string.h>

char* concatname(char firstname[], char lastname[])
{

	int n,i;
	char* buffer;

	i = strlen(firstname) + strlen(lastname);
	//No espefica un total de memoria y simplemente lo castea a char????
	buffer = (char *)malloc(i+1);

	for(n=0; n < strlen(firstname);n++){
		buffer[n] = firstname[n];
	}

	for(n=0 ; n < strlen(lastname); n++){
		buffer[n+strlen(firstname)] = lastname[n];
	}

	//El codigo original dice aqui i, pero el valor real
	//deberia ser i+1
	buffer[i+1] = '\0';
	return buffer;
}

int _tmain(int argc, _TCHAR* argv[]){

	int n,i;
	char firstname[100];
	char lastname [100];
	char* list[100];
	printf("How many (100 max)");
	scanf("%d",&n);
	if(n>100)
	{
		exit(EXIT_FAILURE);
	}

	for(i=0; i < n ; i++){
		printf("Enter first name\n");
		scanf("%s",firstname);
		printf("Enter second name\n");
		scanf("%s",lastname);

		list[i] = concatname(firstname,lastname);
	}

	printf("The full list of name is \n");
	for(i=0; i <n ; i++){
		printf ("%s\n",list[i]);
	}

	for(i=0;i<n;i++){
		free(list[i]);
	}

	system("pause");
	return 0;
}



