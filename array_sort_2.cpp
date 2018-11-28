/*
操作系统任务调度问题。操作系统任务分为系统任务和用户任务两种。
其中，系统任务的优先级?<?50，用户任务的优先级?>=?50且?<=?255。优先级大于255的为非法任务，应予以剔除。
现有一任务队列task[]，长度为n，task中的元素值表示任务的优先级，数值越小，优先级越高。
函数scheduler实现如下功能，将task[]?中的任务按照系统任务、用户任务依次存放到?system_task[]?数组和?user_task[]?数组中（数组中元素的值是任务在task[]?数组中的下标），
并且优先级高的任务排在前面，数组元素为-1表示结束。?

例如：task[]?=?{0,?30,?155,?1,?80,?300,?170,?40,?99}????system_task[]?=?{0,?3,?1,?7,?-1}????user_task[]?=?{4,?8,?2,?6,?-1}
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


map <int,int> W;
int main(){
	int n,i,j=0,k=0;
	cin>>n;
	int *task= new int(n);
	int *system_task=new int(n);
	int *user_task=new int(n);
	for(i=0;i<n;i++) {
		cin>>task[i];
		if(task[i]<50)
		{
			system_task[j++]=task[i];
			W.insert(make_pair(task[i],i));
		}
		if(task[i]>=50&&task[i]<=255)
		{
			user_task[k++]=task[i];
			W.insert(make_pair(task[i],i));
		}
	}
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
	delete []task;
	delete []system_task;
	delete []user_task;
	return 0;
}