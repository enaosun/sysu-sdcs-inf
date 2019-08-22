#include<bits/stdc++.h>
using namespace std;
#define COUNT 1000



bool exit_in_circle(double x , double y){
	double length = x*x+y*y;
	
	return length < 1;
}

int main(){
	int sum = 0 ;
	srand(time(NULL));
	for (int i = 0 ; i < COUNT ;i++){
		double x = (double)rand()/RAND_MAX;
		double y = (double)rand()/RAND_MAX;
		if(exit_in_circle(x,y)){
			sum++;
		}
	}
	cout << sum << endl;
	double result = (double)sum/COUNT*4;
	cout << result << endl;
	return 0;
}

