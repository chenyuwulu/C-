/*
����һ������input[]?��������鳤��nΪ������������������Ԫ�طŵ�?output[]?�������м��λ�ã�
������鳤��nΪż����������������Ԫ�طŵ�?output[]?�����м�����λ��ƫ�ҵ��Ǹ�λ���ϣ�
Ȼ���ٰ��Ӵ�С��˳�������ڵ�һ��λ�õ����ߣ�����һ��һ�ҵ�˳�����δ��ʣ�µ�����
*/
#include <iostream>
#include <algorithm> //��sort()��������Ҫ���ã�stdҲ��Ҫ
using namespace std;
 
int input[100],output[100];
bool fuck(int a,int b)
{
	return a>b;   //�������У������Ϊreturn a>b����Ϊ����
}
int main()
{
	int i,a,b,j=1,n;
  cout<<"����������Ҫ��������������";
	cin>>n;
	for(i=0;i<n;i++) {
      cout<<"���������"<<i+1<<"����";
		cin>>input[i];
	}
	sort(input,input+n,fuck); // c++����������������ڴ��ַ����󣬵�һ����������ʼλ�ã��ڶ����ǽ���λ�ã���������������򣬿�Ϊ����
	i=n/2; //��ʼλ�ô�0��ʼ�ģ�����ֱ��ȡ���ķ�ʽ���ÿ��Ի�ȡ���м䣬ż���Ļ�����0��ʼλ�ã�Ҳ���÷��϶�һλ
	output[i]=input[0];
	a=b=i; //��i�ֳ����ݣ�����ָ�����������ѭ��λ�ú�ѭ������
	while(j<n) {
		output[--a]=input[j++];
		output[++b]=input[j++];
	}
	for(i=0;i<n;i++)
		cout<<output[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}
