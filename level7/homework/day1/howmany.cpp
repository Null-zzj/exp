/*********************************************
* @FileName: howmany.cpp
* @Author: Null-zzj
* @Mail: zj.zhu.cn@gmail.com
* @Created Time: Tue Jul 18 16:44:06 2023
*********************************************/

#include<iostream>
using namespace std;

void howmany(const char* str, int &U, int &L, int &S)
{
	char *p = (char *)str;
	while(*p++ != '\0')
	{
		if(*p > 'a' && *p < 'z')
		{	
			L++;
		}else if(*p > 'A' && *p < 'Z' )
		{
			U++;
		}
		else if(*p == ' ')
		{
		   	S++;
		}
	}	

}


int main(int argc, char *argv[])
{	
	const char *str = "abcAHSD nsdvnJJKSN";

	int U = 0, L = 0, S = 0;
	
	howmany(str, U, L, S);
	
	printf("%d %d %d\n", U, L, S);
	return 0;
}






