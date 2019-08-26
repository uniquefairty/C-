#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#pragma warning (disable:4996)



int main6()//�������ļ�
{
	double a[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double b = 0.0;

	size_t ret_code = 0;
	FILE *fp = fopen("test.bin", "wb");
	fwrite(a, sizeof(*a), 5, fp);
	fclose(fp);

	fp = fopen("test.bin", "rb");

	while ((ret_code = fread(&b, sizeof(double), 1, fp)) >= 1)
	{
		printf("%lf\n", b);
	}
	if (feof(fp))
	{
		printf("Error reading test.bin:unexpected end of file\n");
	}
	else if (ferror(fp))
	{
		perror("Error reading test.bin");
	}
	fclose(fp);
	fp = NULL;

	system("pause");

}

int main(void)//�ı��ļ��ж�
{
	int c;
	FILE *fp = fopen("text.txt", "r");

	if (!fp)
	{
		perror("File opening failed");
		return EXIT_FAILURE;
	}

	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}

	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");

	fclose(fp);
	system("pause");
	
}
int main4()
{
	int n;
	FILE *pFile;
	char buffer[27];

	pFile = fopen("myfile.txt", "w+");
	for (n = 'A'; n <= 'Z'; n++)
	{
		fputc(n, pFile);
	}

	rewind(pFile);//���ļ�ָ���λ�÷��ص��ļ�����ʼλ��
	fread(buffer, 1, 26, pFile);

	fclose(pFile);

	buffer[26] = '\0';
	puts(buffer);
	system("pause");
	return 0;
}
int main3()
{
	FILE *pFile;
	long size;

	pFile = fopen("myfile.txt", "rb");
	if (pFile == NULL)
	{
		perror("Error opening file");
	}
	else{
		fseek(pFile, 0, SEEK_END);//�����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ��
		size = ftell(pFile);//�����ļ�ָ���������ʼλ�õ�ƫ����
		fclose(pFile);
		printf("Size of myfile.txt:%d bytes.\n", size);
	}
	system("pause");
	return 0;
}
int main2()
{
	FILE *pFile;
	pFile = fopen("example.txt", "wb");
	fputs("This is an apple.", pFile);
	fseek(pFile, 9, SEEK_SET);
	fputs("sam", pFile);
	fclose(pFile);
	return 0;
}

int main1()
{
	/*FILE *pFile;
	pFile = fopen("myfile.txt", "w");
	if (pFile != NULL)
	{
		fputs("fopen example", pFile);
		fclose(pFile);
	}*/


	int a = 1000;
	FILE *pf = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf);
	fclose(pf);
	pf = NULL;
	system("pause");
	return 0;
}