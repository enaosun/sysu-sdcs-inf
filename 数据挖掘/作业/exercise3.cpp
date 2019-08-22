#include <bits/stdc++.h>
using namespace std;

#define COUNT 200

double get_result(double x , double y ){
	double e;
	e=((y*y*exp((-1)*y*y)+pow(x,4)*exp((-1)*x*x)))/(x*exp((-1)*x*x));		return e;
}

int main(){
	srand(time(NULL));
	double sum ;
	double result ;  
	for(int j = 0 ; j < 20 ; j++){
		for (int i = 0 ; i < COUNT ;i++){
			double x = (double)rand()/RAND_MAX*2+2;
			double y = (double)rand()/RAND_MAX*2-1;
			
			result = get_result(x,y);
			sum += result;
		}
	
		double fina;
		fina = sum/(COUNT*20)*4;
		cout << fina << endl;
	} 
	return 0;
}
