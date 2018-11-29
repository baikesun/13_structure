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
	
	//error handling(����ڵ�) 
	if(fp == NULL)
	{
		printf("\nERROR! check the file name : %s\n", file_name);
		
		return -1;   //return 0�� ��� ������ ���������� ������ ���� �����ϱ� ���� �ٸ� ������ return �ϴ� ��. 
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
	
	while((c = fgetc(fp)) != EOF)   //���� ����  
	{
		if(is_whitespace(c) == 0)   //���ǹ��� ���ڸ� ����  
		{
			break;
		}
	}
	
	if(c == EOF)   //���� ���� ���ڰ� ������ �϶�  
	{
		return 0;
	}
	
	//���������� �ܾ �ѱ��ھ� ���� 
	cnt = 0;
	word[cnt++] = c;   //�Ʊ� ���� ù��° ���� ����  
	word[cnt] = '\0';    //Ȥ�� �ڿ��� ������ �� �����Ƿ� �ѱ���¥�� �ܾ�)
	
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
		return 1;   //������ڴ�.
	}
	
	return 0;   //���Ǹ��� ���ڴ�. 
}
