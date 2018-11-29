#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	
	char file_name[100];
	
	printf("input the file name : ");
	scanf("%s", file_name);
	
	fp = fopen(file_name, "r");
	
	//error handling(����ڵ�) 
	if(fp == NULL)
	{
		printf("\nERROR! check the file name : %s\n", file_name);
		
		return -1;   //return 0�� ��� ������ ���������� ������ ���� �����ϱ� ���� �ٸ� ������ return �ϴ� ��. 
	}
	
	printf("%c\n", fgetc(fp));
	
	fclose(fp);
	
	return 0;
}
