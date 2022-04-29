#include <stdio.h>
#include <ctype.h>

int main()
{
 FILE* spFileIn;
 FILE* spFileOut;

 char ch;
 int intcount, wordcount, charcount;

 intcount = 0;
 wordcount = 0;
 charcount = 0;

 spFileIn = fopen("input.txt", "r");

   if ( spFileIn )
   {	
	   while ((ch=getc(spFileIn)) != EOF) {

		   if (isalpha(ch) || isspace(ch) || isdigit(ch) || ch == ' ' || ch != '\n') { ++charcount; }

		   if (ch == ' ' ) { ++wordcount; }

       if (isdigit(ch)) { ++intcount; }
	   }
     //if ((charcount > 0) && (isdigit(ch))) {
	   if (charcount > 0) {
		++intcount;
		++wordcount;
	   }
    }
   else
      {
         printf("Failed to open the file\n");
        }

        fclose(spFileIn);

    printf("Character Count: %d \n", charcount);
    printf("Word Count: %d \n", wordcount);
    printf("Integer Count: %d \n", intcount);

return(0);
}