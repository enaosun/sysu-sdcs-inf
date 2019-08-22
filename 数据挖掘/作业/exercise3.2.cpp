#include <bits/stdc++.h>
using namespace std;

#define COUNT 500

double get_result(double x , double y ){
		
		double e;
		
		e =((y*y*exp((-1)*y*y)+pow(x,4)*exp((-1)*x*x)))/(x*exp((-1)*x*x));
	
		return e;
}

bool exit_under_fx(double z , double e){
	return z < e;
}

int main(){
	srand(time(NULL));
	for(int j = 0 ; j < 20 ; j++){
		int sum = 0;
		for(int i = 0 ; i < COUNT ; i++){
			double x = (double)rand()/RAND_MAX*2+2;
			double y = (double)rand()/RAND_MAX*2-1;
			double z = rand()%800000;
			double e = get_result(x,y);
			if(exit_under_fx(z,e)){
				sum++;
			}
			
		}
		double result = (double)sum/(double)COUNT*4*800000;
		cout << result<<endl;
	}
}
