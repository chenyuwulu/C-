/*
字符串替换：编写一个字符串替换函数，如strSrc为原字符串，strFind是待替换的字符串，strReplace为替换字符串。
如：“ABCDEFGHIJKLMNOPQRSTUVWXYZ”这个字符串，把其中的“RST”替换为“ggg”这个字符串，结果就变成了：
ABCDEFGHIJKLMNOPQgggUVWXYZ
*/
#include <iostream>
#include <string>
using namespace std;
 
string strSrc,strFind,strReplace; //定义这些字符串变量
 
int main()
{
	cout<<"请输入原字符串:";
	cin>>strSrc;
	cout<<"请输入要替换的字符串";
	cin>>strFind;
	cout<<"请输入替换成什么字符串";
	cin>>strReplace;
	int i=strSrc.find(strFind); // 在原字符串中寻找到对应字符串的下标
	int length=strFind.length(); // 获取要被替换的字符串的长度
	strSrc.replace(i,length,strReplace); //使用函数，将从i（下标）位置开始替换，替换长度为length,替换的内容为strReplace
	cout<<strSrc<<endl; // 输出最后替换过的字符串
	system("pause"); //避免直接窗口闪退
	return 0;
}