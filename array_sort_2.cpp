/*
操作系统任务调度问题。操作系统任务分为系统任务和用户任务两种。
其中，系统任务的优先级 < 50，用户任务的优先级 >= 50且 <= 255。优先级大于255的为非法任务，应予以剔除。
现有一任务队列task[]，长度为n，task中的元素值表示任务的优先级，数值越小，优先级越高。
函数scheduler实现如下功能，将task[] 中的任务按照系统任务、用户任务依次存放到 system_task[] 数组和 user_task[] 数组中（数组中元素的值是任务在task[] 数组中的下标），
并且优先级高的任务排在前面，数组元素为-1表示结束。 

例如：task[] = {0, 30, 155, 1, 80, 300, 170, 40, 99}    system_task[] = {0, 3, 1, 7, -1}    user_task[] = {4, 8, 2, 6, -1}
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


map <int,int> W; // 这个map不是地图的意思，而是类似于数据表的键值概念，创建了一个W容器，key为int，value也是int
int main(){
	int n,i,j=0,k=0;
	cout<<"请输入数组个数：";
	cin>>n;
	int *task= new int(n); // 创建一个新的存放整数的空间，并将初始值设定为输入的n，返回一个指向此处的地址
	int *system_task=new int(n); // 如上
	int *user_task=new int(n); // 如上
	for(i=0;i<n;i++) { // 循环数组个数的次数
		cin>>task[i]; // 输入对应的数组
		if(task[i]<50){
			system_task[j++]=task[i]; // 将这个数值放入系统数组里
			W.insert(make_pair(task[i],i));
		}
		if(task[i]>=50&&task[i]<=255){
			user_task[k++]=task[i];
			W.insert(make_pair(task[i],i));
		}
	}
	//以下两句是用于讲系统数组和用户数组里面的数值进行升序排序，sort()函数是algorithm里面的一个排序函数。
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
	system("pause"); //避免直接窗口闪退
	return 0;
}
/*
	备注知识点：
	int *p=1；//*p里面存的才是值，p里面存的是十六进制内存地址
*/