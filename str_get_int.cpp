/*
���������� 
ʶ�������ַ��������е�������ͳ����������������Щ�ַ�����ʽ������ת��Ϊ������ʽ������
Ҫ��ʵ�ֺ����� 
void take_num(const char *strIn, int *n, unsigned int *outArray)
�����롿 strIn��   ������ַ���
������� n��       ͳ��ʶ���������������
       outArray��ʶ�����������ֵ������outArray[0]�������ַ����д����ҵ�һ��������
 outArray[1]�ǵڶ����������Դ����ơ������ַ�Ѿ����䣬����ֱ��ʹ��
�����ء� ��
ע��
I��     �������ַ����г��ֵ�������(+, -)��������ת�����Ϊ�Ǹ�����������0����������
II��    ������ת��������������Χ����������������п��ܳ��ֵ�����������ᳬ��unsigned int�ɴ���ķ�Χ
III��   ��Ҫ���� '0' ��ʼ�������ַ������������ "00035" ��Ӧת��Ϊ����35��
        "000" Ӧת��Ϊ����0��"00.0035" Ӧת��Ϊ����0��35������С���㣺mmm.nnn����������mmm��nnn��ʶ��
IV��   �����ַ������ᳬ��100 Bytes���벻�ÿ��ǳ����ַ����������
ʾ�� 
���룺strIn = "ab00cd+123fght456-25  3.005fgh"
�����n = 6
outArray = {0, 123, 456, 25, 3, 5}
*/
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int k=0,n=0;
void take_num(const string strIn,int *outArray){
	int sum=0;
	for(int i=0;i<strIn.length();i++) {
		if(isdigit(strIn[i])) {
			sum=sum*10+strIn[i]-'0';
			if(!isdigit(strIn[i+1]))
			{
				outArray[k++]=sum; 
				n++;
				sum=0;
			}
		}
	}
}

int main(){
	string str;
	//cin>>str;
	getline(cin,str); //��Ҫ������ո�Ĵ�����getline(cin,str);�滻cin>>str;
    int *outArray = new int[str.length()];
	take_num(str,outArray);
	cout<<n<<endl;
	for(int i=0;i<k;i++){
		cout<<outArray[i]<<" ";
  }
	cout<<endl;
	return 0;
}
