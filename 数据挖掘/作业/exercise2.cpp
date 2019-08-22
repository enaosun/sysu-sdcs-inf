#include <bits/stdc++.h>
using namespace std;
#define COUNT 1000

bool under_the_line(double x, double y){
	double num = x*x*x;
//	cout << num << endl;
	return y < num ;
} 

int main(){
	int sum = 0 ;
	srand(time(NULL));
	for (int i = 0 ; i < COUNT ;i++){
		double x = (double)rand()/RAND_MAX;
		double y = (double)rand()/RAND_MAX;
		if(under_the_line(x,y)){
			sum++;
		}
	}
	cout << sum << endl;
	double result = (double)sum/COUNT;
	cout << result << endl;

	return 0;
}
