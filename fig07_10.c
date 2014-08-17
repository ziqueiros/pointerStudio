// Fig. 7.10: fig07_10.c
// Converting a string to uppercase using a 
// non-constant pointer to non-constant data.
#include <stdio.h>
#include <ctype.h>

void convertToUppercase( char *sPtr ); // prototype

int main10( void )
{
   char string[] = "cHaRaCters and $32.98"; // initialize char array

   printf( "The string before conversion is: %s", string );

   //Por que no usamos aqui &, si deberiamos pasar la direcccion!!!!
   convertToUppercase( string );
   printf( "\nThe string after conversion is: %s\n", string );

   //Error you cannot assign
   //char a = 'a';
   //string = (char *)&a;

   //Why you cannot assing a new value here!!!!?????
   //char string2[] = "cHaRaCters and $32.98";
   //string = string2;
   //string = "test";
   //printf( "\nThe string after SECOND conversion is: %s\n", string );

   return 0;
} // end main

// convert string to uppercase letters
// aqui estamos pasando un valor una direccion que no podemos modificar
// para hacerlo apuntar a otra seccion de memoria
void convertToUppercase( char *sPtr )
{
   while ( *sPtr != '\0' ) { // current character is not '\0' 
      *sPtr = toupper( *sPtr ); // convert to uppercase
      ++sPtr; // make sPtr point to the next character
   } // end while

   /**
    * Pero aqui la nocion que trta de ejemplificar de un puntero
    * non-constant?????
    *
    * Tomado del libro de deteil
    * The highest level of data access is granted by a non-constant pointer to non-constant data.
    * In this case, the data can be modified through the dereferenced pointer, and the pointer can
    * be MODIFIED to point to other data items.!!!!!
    *
    */
   char innerString[] = "test";
   sPtr = innerString;

   printf( "\ninside: %s\n", sPtr );

} // end function convertToUppercase



/**************************************************************************
 * (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
