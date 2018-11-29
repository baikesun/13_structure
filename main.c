#include <stdio.h>
#include <stdlib.h>

int fget_word(FILE* fp, char* word);
int is_whitespace(char c);

int main(void)
{
	FILE* fp;
	
	char file_name[100];
	char word[100];
	
	printf("input the file name : ");
	scanf("%s", file_name);
	
	fp = fopen(file_name, "r");
	
	//error handling(방어코드) 
	if(fp == NULL)
	{
		printf("\nERROR! check the file name : %s\n", file_name);
		
		return -1;   //return 0도 상관 없지만 정상적으로 끝나는 경우와 구분하기 위해 다른 값으로 return 하는 것. 
	}
	
	//word reading
	while(fget_word(fp, word) != 0)
	{
		//word processing
		printf("%s\n", word);   //test code
	}
	
	fclose(fp);
	
	return 0;
}

int fget_word(FILE* fp, char* word)
{
	char c;
	int cnt;
	
	while((c = fgetc(fp)) != EOF)   //문자 받음  
	{
		if(is_whitespace(c) == 0)   //유의미한 글자면 나감  
		{
			break;
		}
	}
	
	if(c == EOF)   //최초 읽은 문자가 마지막 일때  
	{
		return 0;
	}
	
	//본격적으로 단어를 한글자씩 읽음 
	cnt = 0;
	word[cnt++] = c;   //아까 읽은 첫번째 글자 읽음  
	word[cnt] = '\0';    //혹시 뒤에서 못읽을 수 있으므로 한글자짜리 단어)
	
	while((word[cnt] = fgetc(fp)) != EOF)
	{
		if(is_whitespace(word[cnt]) == 1)
		{
			word[cnt] = '\0';
			break;
		}
		
		cnt++;
	} 
	
	return cnt;
}

int is_whitespace(char c)
{
	if((c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || 
	   (c == '(') || (c == ')'))
	{
		return 1;   //공백글자다.
	}
	
	return 0;   //유의마한 글자다. 
}
