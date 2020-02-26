/* ftell example : getting size of a file */
#include <stdio.h>
#include<string.h>
#include <assert.h>

int main()
{
	FILE * pFile;
	char buffer[] = { 'x' , 'y' , 'z' };
	pFile = fopen ( "myfile.bin" , "wb" );
	fwrite (buffer , 1 , sizeof(buffer) , pFile );
	fclose (pFile);
	return 0;
}


#if 0
int main()
{
	FILE *fp = fopen("1.txt", "r");

	if (fp == NULL)
	{
		assert(fp);
		return 0;
	}

	return 0;
}

#endif
#if 0
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

#endif

