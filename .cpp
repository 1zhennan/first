#include<stdio.h>
int main()
{
	char s[100], a[10][100] = { '\0' }, m[10][100] = { '\0' }, act[10] = { '\0' };
	//s为输入的字符串，a为整理后的各个单词，m为输入的各个待匹配单词，act为待匹配单词对应的操作
	char* pm = NULL, * pa = NULL; //定义指针
	int i = 0, j = 0, k = 0, n = 0, b = 0, c = 0, d = 0; 
	//i, j为二维数组a的行列，k为二维数组m的行，n为待匹配单词个数，b为原有单词总个数，c、d为复制单词用到的长度和位数
	printf("please enter a string consisting of english words:\n");
	gets_s(s); //输入字符串
	char* ps = s;
	for (;*ps != '\0';ps++) //将各个单词记入a
	{
		if (*ps != 32)
		{
			a[i][j] = *ps;
			j++;
		}
		if (*ps == 32)
		{
			a[i][j] = '\0'; //加截止符
			i++;
			b = i;
			j = 0;
		}
	}
	a[i][j] = '\0'; //加截止符
	printf("please enter the number of words to be matched(1~9):\n");
	scanf_s("%d", &n);
	printf("please enter words(no more than 100 characters) and corresponding action(0 or 1):\n");
	for (k = 0;k < n;k++)
	{
		scanf_s("%s", m[k], 100);//将待匹配单词记入m
		getchar(); //空格
		act[k] = getchar(); //将操作记入act
	}
	printf("the result is:\n");
	for (i = 0;i <= b;i++) //对a中每一个单词
	{
		for (k = 0;k < n;k++) //对m中每一个单词
		{
			pm = m[k]; 
			pa = a[i]; //m[k]，a[i]不可更改，pm、pa可更改
			for (;(*pm != '\0') && (*pa != '\0') && (*pm == *pa);pm++, pa++); //遇到截止符停止
			if (*pm - *pa == 0 && act[k] == '1') //*pm - *pa为0说明两者相等，操作为1，复制一次
			{
				for (c = 0;a[i][c] != '\0';c++); //计算a[i]长度
				a[i][c] = 32; //加上空格
				for (d = 0;d < c;d++)
					a[i][c + d + 1] = a[i][d]; //复制一次
			}
			else if (*pm - *pa == 0 && act[k] == '0') //操作为0，删除
				a[i][0] = '\0';
			else; //两者不相等，不做操作
		}
		printf("%s ", a[i]); //输出修改后的单词
	}
}
