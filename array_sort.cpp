/*
给定一个数组input[] ，如果数组长度n为奇数，则将数组中最大的元素放到 output[] 数组最中间的位置，
如果数组长度n为偶数，则将数组中最大的元素放到 output[] 数组中间两个位置偏右的那个位置上，
然后再按从大到小的顺序，依次在第一个位置的两边，按照一左一右的顺序，依次存放剩下的数。
例如：input[] = {3, 6, 1, 9, 7}   output[] = {3, 7, 9, 6, 1}; 
			input[] = {3, 6, 1, 9, 7, 8}    output[] = {1, 6, 8, 9, 7, 3}
*/

//假设输入的数组为1,4,5,2,3
#include <iostream>
#include <algorithm> //用sort()排序函数需要引用，std也需要
using namespace std;
 
int input[100],output[100];
bool fuck(int a,int b)
{
	return a>b;   //升序排列，如果改为return a>b，则为降序
}
int main()
{
	int i,a,b,j=1,n;
  cout<<"请先输入您要输入的数组个数：";
	cin>>n;
	for(i=0;i<n;i++) {
      cout<<"请先输入第"<<i+1<<"个：";
		cin>>input[i];
	}
	sort(input,input+n,fuck); // c++里的排序函数，有了内存地址概念后，第一个参数是起始位置，第二个是结束位置，第三个是排序规则，空为升序。
	// 此时，input内的数组已经变成了5,4,3,2,1
	i=n/2; //起始位置从0开始的，所以直接取整的方式正好可以获取到中间，偶数的话由于0起始位置，也正好符合多一位
	output[i]=input[0]; //在output数组的中间位置放入最大的5
	a=b=i; //将i分成三份，用于指向两个数组的循环位置和循环次数
	while(j<n) { // 循环了4次
		output[--a]=input[j++]; // 最大数左边放接下来最大的
		output[++b]=input[j++]; // 最大数右边放接下来最大的
	} // 此处的循环就是题目要求的相邻
	//以下是输出当前数组
	for(i=0;i<n;i++)
		cout<<output[i]<<" ";
		cout<<endl;
	system("pause"); //避免直接窗口闪退
	return 0;
}
