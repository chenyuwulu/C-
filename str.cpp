/*
�ַ����滻����дһ���ַ����滻��������strSrcΪԭ�ַ�����strFind�Ǵ��滻���ַ�����strReplaceΪ�滻�ַ�����
�磺��ABCDEFGHIJKLMNOPQRSTUVWXYZ������ַ����������еġ�RST���滻Ϊ��ggg������ַ���������ͱ���ˣ�
ABCDEFGHIJKLMNOPQgggUVWXYZ
*/
#include <iostream>
#include <string>
using namespace std;
 
string strSrc,strFind,strReplace; //������Щ�ַ�������
 
int main()
{
	cout<<"������ԭ�ַ���:";
	cin>>strSrc;
	cout<<"������Ҫ�滻���ַ���";
	cin>>strFind;
	cout<<"�������滻��ʲô�ַ���";
	cin>>strReplace;
	int i=strSrc.find(strFind); // ��ԭ�ַ�����Ѱ�ҵ���Ӧ�ַ������±�
	int length=strFind.length(); // ��ȡҪ���滻���ַ����ĳ���
	strSrc.replace(i,length,strReplace); //ʹ�ú���������i���±꣩λ�ÿ�ʼ�滻���滻����Ϊlength,�滻������ΪstrReplace
	cout<<strSrc<<endl; // �������滻�����ַ���
	system("pause"); //����ֱ�Ӵ�������
	return 0;
}