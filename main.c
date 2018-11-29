#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	
	char file_name[100];
	
	printf("input the file name : ");
	scanf("%s", file_name);
	
	fp = fopen(file_name, "r");
	
	//error handling(방어코드) 
	if(fp == NULL)
	{
		printf("\nERROR! check the file name : %s\n", file_name);
		
		return -1;   //return 0도 상관 없지만 정상적으로 끝나는 경우와 구분하기 위해 다른 값으로 return 하는 것. 
	}
	
	printf("%c\n", fgetc(fp));
	
	fclose(fp);
	
	return 0;
}
