/* ftell example : getting size of a file */
#include <stdio.h>
#include<string.h>

int main()
{
	FILE * fp;
	long size;

	char *buf = "hahaha";
	fp = fopen("myfile.txt", "w+");
	if (fp == NULL)
	{
		perror("Error opening file");
	}
	fwrite(buf, 1, strlen(buf), fp);

	fseek(fp, 0, SEEK_END);   // non-portable
	size = ftell(fp);
	fclose(fp);
	printf("Size of myfile.txt: %ld bytes.\n", size);

	return 0;
}