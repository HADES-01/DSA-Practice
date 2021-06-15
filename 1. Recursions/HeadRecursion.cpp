#include<iostream>
using namespace std;

void fun(int n)
{
	if(n > 0){
		fun(n - 1);
		cout<<n<<" ";
	}
}

int main(){
	int a = 5;
	fun(5);
	return 0;
}

