/*
����ϵͳ����������⡣����ϵͳ�����Ϊϵͳ������û��������֡�
���У�ϵͳ��������ȼ� < 50���û���������ȼ� >= 50�� <= 255�����ȼ�����255��Ϊ�Ƿ�����Ӧ�����޳���
����һ�������task[]������Ϊn��task�е�Ԫ��ֵ��ʾ��������ȼ�����ֵԽС�����ȼ�Խ�ߡ�
����schedulerʵ�����¹��ܣ���task[] �е�������ϵͳ�����û��������δ�ŵ� system_task[] ����� user_task[] �����У�������Ԫ�ص�ֵ��������task[] �����е��±꣩��
�������ȼ��ߵ���������ǰ�棬����Ԫ��Ϊ-1��ʾ������ 

���磺task[] = {0, 30, 155, 1, 80, 300, 170, 40, 99}    system_task[] = {0, 3, 1, 7, -1}    user_task[] = {4, 8, 2, 6, -1}
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


map <int,int> W; // ���map���ǵ�ͼ����˼���������������ݱ�ļ�ֵ���������һ��W������keyΪint��valueҲ��int
int main(){
	int n,i,j=0,k=0;
	cout<<"���������������";
	cin>>n;
	int *task= new int(n); // ����һ���µĴ�������Ŀռ䣬������ʼֵ�趨Ϊ�����n������һ��ָ��˴��ĵ�ַ
	int *system_task=new int(n); // ����
	int *user_task=new int(n); // ����
	for(i=0;i<n;i++) { // ѭ����������Ĵ���
		cin>>task[i]; // �����Ӧ������
		if(task[i]<50){
			system_task[j++]=task[i]; // �������ֵ����ϵͳ������
			W.insert(make_pair(task[i],i));
		}
		if(task[i]>=50&&task[i]<=255){
			user_task[k++]=task[i];
			W.insert(make_pair(task[i],i));
		}
	}
	//�������������ڽ�ϵͳ������û������������ֵ������������sort()������algorithm�����һ����������
	sort(system_task,system_task+j);
	sort(user_task,user_task+k);
	for(i=0;i<j;i++) {
		map <int,int>::iterator it = W.find(system_task[i]);
		system_task[i]=it->second;
		cout<<system_task[i]<<" ";
	}
	cout<<"-1"<<endl;
	for(i=0;i<k;i++) {
		map <int,int>::iterator it = W.find(user_task[i]);
		user_task[i]=it->second;
		cout<<user_task[i]<<" ";
	}
	cout<<"-1"<<endl;
	// delete []task;
	// delete []system_task;
	// delete []user_task;
	system("pause"); //����ֱ�Ӵ�������
	return 0;
}
/*
	��ע֪ʶ�㣺
	int *p=1��//*p�����Ĳ���ֵ��p��������ʮ�������ڴ��ַ
*/