/*Our implementation of basic string library functions
strlen(): implemented as mystrlen() 
  The function takes a single argument, i.e, the string variable whose length is to be found, 
  and returns the length of the string passed. (excluding '\0')

strcat(): implemented as mystrcat()
  concatenates (joins) two strings. It takes two arguments, i.e, two strings or character arrays, 
  and stores the resultant concatenated string in the first string specified in the argument.
  
strcpy(): implemented as mystrcpy()
  The strcpy() function copies the string pointed by source (including the null character) to 
  the character array destination.
  
strcmp(): implemented as mystrcmp()
 The strcmp() compares two strings character by character. If the first character of two strings 
 are equal, next character of two strings are compared. This continues until the corresponding 
 characters of two strings are different or a null character '\0' is reached.
  

*/

#include "string.h"
#include "stdio.h"

/*function prototypes*/
int mystrlen(char*);
void mystrcat(char*, char*);
void mystrcpy(char*, char*);
int mystrcmp(char*, char*);
main()
{
	char s1[20];
	char s2[20];
	char s3[50];
	int len,compare;
	clrscr();
	printf("\nEnter first string (19 characters max): ");
	gets(s1);
	printf("\nEnter second string(19 char max.): ");
	gets(s2);
	len = mystrlen(s1);
	printf("\nLength of first string : Our function = %d, By Library: %d",len, strlen(s1));
	len = mystrlen(s2);
	printf("\nLength of first string : Our function = %d, By Library: %d",len, strlen(s2));
	getch();
	/*clear s3[] first*/
	s3[0]='\0';
	mystrcpy(s3,s1);
	mystrcat(s3,"-"); /*- is a seperator, could be blank also*/
	mystrcat(s3,s2);
	printf("\nStrings [%s] and [%s] are concatenated(joined) as\n [%s] ",s1,s2,s3);
	getch();
	compare = mystrcmp(s1,s2);
	printf("\nComparing strings [%s] and [%s]: ",s1,s2);
	if(compare == 0)
		printf("\nStrings are same");
	else if(compare <0)
			printf("\Strings are different and [%s] comes before [%s] ",s1,s2);
		else
			printf("\Strings are different and [%s] comes before [%s] ",s2,s1);
	getch();

}
int mystrlen(char *s)
{
	int i=0;
	while(*(s+i) != '\0')
	{
		i++;
	}
	return i;
}

void mystrcat(char* dest, char* src)
{
	int i,j, length;
	length = mystrlen(src);
	j =  mystrlen(dest);

	for(i=0;i<length;i++)
	{
		*(dest+j+i) = *(src+i);
	}
	/*dont forget to add '\0' at end to make dest a string again*/
	*(dest+j+i)='\0';
}

void mystrcpy(char* dest, char* src)
{
	while(*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}
int mystrcmp(char* a, char* b)
{
	int i=0;
	/*Either strings are same -> they will end at '\0' at same index
	  so observe each character and wait for '\0' */
	while(*a == *b)
	{
		if(*a == '\0')
			return 0; /*both strings are same and have ended */
		else
		{
			/*move forward to next character */
			a = a+1;
			b = b+1;
		}
	}
	/* control comes here means that strings were different
	   simply return the difference (ASCII value) */
	return *a - *b;
}