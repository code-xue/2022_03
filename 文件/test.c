#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//文件分为程序文件和数据文件
//程序文件包括源程序文件（.c）、目标文件（.obj）、可执行文件（.exe）
//数据文件：文件的内容不一定是程序，而是程序运行时读写的数据

//1.文件的打开和关闭
//fopen函数：FILE * fopen ( const char * filename, const char * mode );
//常见打开方式有：r：只读，当文件不存在时，会报错
//                w：只写，当文件不存在时，会新建一个文件
//                a：追加，当文件不存在时，会新建一个文件

//fclose函数：关闭文件   int fclose ( FILE * stream );

int main()
{
	//打开文件
	FILE* pf = fopen("test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

//*************************************************************************
//2.文件的顺序写入
//fgetc:字符输入函数
//fputc:字符输出函数
//fgets:文本行输入函数
//fputs:文本行输出函数
//fscnaf:格式化输入函数
//fprintf:格式化输出函数
//fread:二进制输入函数
//fwrite:二进制输出函数

int main()
{
	//打开文件
	FILE* pf = fopen("test.dat", "w");//读取时是r，输入时是w
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//文件写入
	//fputc('x', pf);
	//fputc('u', pf);
	//fputc('e', pf);
	//fputs("abc\n", pf);
	//fputs("def\n", pf);

	//文件读取
	//int ret = fgetc(pf);
	//printf("%c\n", ret);
	//char arr[10] = {0};
	//fgets(arr, 4, pf);   //实际读取3个字符，因为最后要加上一个\0

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

//格式化输入输出函数

struct S
{
	char arr[20];
	int a;
};

int main()
{
	struct S s = { 0};
	FILE* pf = fopen("test.dat", "r");//读取时是r，输入时是w
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//输入数据
	//fprintf(pf, "%s %d", s.arr, s.a);

	//读取数据
	fscanf(pf, "%s %d", s.arr, &s.a);
	printf("%s %d", s.arr, s.a);


	fclose(pf);
	pf = NULL;
	return 0;
}

//二进制输入输出数据

struct S
{
	char arr[20];
	int a;
};

int main()
{
	struct S s = { "abc", 10 };
	FILE* pf = fopen("test.dat", "w");//读取时是r，写入时是w
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//写入数据
	fwrite(&s, sizeof(struct S), 1, pf);

	//读取数据
	fread(&s, sizeof(struct S), 1, pf);

	fclose(pf);
	pf = NULL;
	return 0;
}

//scanf:针对标准输入的格式化的输入语句，stdin,键盘输入
//fscanf:针对所有输入流的格式化的输入语句，stdio和文件
//sscanf:从一个字符串中读取一个格式化的数据

//printf:针对标准输出的格式化的输出语句，stdout,打印在屏幕上
//fprintf:针对全部输出流的格式化的输出语句，stdout,打印在屏幕上
//sprintf:把一个格式化的数据，转化成字符串


//***********************************************************************************
//文件随机读写
//fseek函数：根据文件指针的位置和偏移量来定位文件指针
//int fseek ( FILE * stream, long int offset, int origin );
//origin的位置有三种：
//1.SEEK_CUR:文件指针的当前位置
//2.SEEK_END:文件的末尾（\0的地址）
//3.SEEK_SET:文件的起始位置


int main()
{
	//假设文件中字符为abcde
	FILE* pf = fopen("test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	int ch = fgetc(pf);
	printf("%c\n", ch); //a

	fseek(pf, -1, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch); //a

	fseek(pf, 2, SEEK_SET);
	ch = fgetc(pf);
	printf("%c\n", ch);//c

	fseek(pf, -3, SEEK_END);
	ch = fgetc(pf);
	printf("%c\n", ch);//c

	fclose(pf);
	pf = NULL;
	return 0;
}


//*********************************************************************
//文件读取结束的判定
//ferror函数：文件读取失败时返回非0值
//feof函数：文件读取正常结束时返回非0值

int main()
{
	FILE* pfread = fopen("test.dat", "r");
	if (pfread == NULL)
	{
		perror("pfread");
		return 1;
	}
	FILE* pfwrite = fopen("test2.dat", "w");
	if (pfwrite == NULL)
	{
		//关闭test.dat文件
		fclose(pfread);
		pfread = NULL;
		perror("pfwrite");
		return 1;
	}

	int ch = 0;
	//fgetc读取到文本最后时返回EOF
	while (ch = fgetc(pfread) != EOF)
	{
		fputc(ch, pfwrite);
	}

	//判断读取文件因为什么原因结束
	if (ferror(pfread))
	{
		printf("文件读取出错\n");
	}
	if (feof(pfread))
	{
		printf("文件正常读取结束\n");
	}

	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;
	return 0;
}


//****************************************************************************
//文件缓冲区：ANSIC标准采用“缓冲文件系统”处理数据文件，从内存向磁盘输出数据会先送到内存中的缓冲区，
//装满缓冲区后才一起送到磁盘上，如果从磁盘向计算机读入数据，
//则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），
//然后再从缓冲区逐个地将数据送到程序数据区（程序变量等）
