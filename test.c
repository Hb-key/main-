#include"CommentConvert.h"

void test()
{
	FILE* pRead = fopen("input.c", "r");
	if (pRead == NULL)
	{
		perror("error for pRead");
		exit(EXIT_FAILURE);
	}
	FILE* pWrite = fopen("output.c", "w");
	if (pWrite == NULL)
	{
		perror("error for pWrite");
		exit(EXIT_FAILURE);
	}
	CommentConvert(pRead, pWrite);
	fclose(pRead);
	pRead = NULL;
	fclose(pWrite);
	pWrite = NULL;
}
int main()
{
	test();
	return  0;
}