#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int T, u, v, w, U, V, W;
	double a, b, c, d;
	unsigned long int x, y, z, X, Y, Z; 
	double volume;
	cin>>T;
	for(int testcase=0; testcase<T; testcase++){
		cin>>w>>v>>u>>U>>V>>W;
		X = (w-U+v)*(U+v+w);
		x = (U-v+w)*(v-w+U);
		Y = (u-V+w)*(V+w+u);
		y = (V-w+u)*(w-u+V);
		Z = (v-W+u)*(W+u+v);
		z = (W-u+v)*(u-v+W);
		a = sqrt(x*Y*Z);
		b = sqrt(y*Z*X);
		c = sqrt(z*X*Y);
		d = sqrt(x*y*z);
		// Heron type formula for volume of tetrahedron (Wikipedia)
		volume = sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d))/(192.0*u*v*w);
		cout<<fixed<<setprecision(4)<<volume<<"\n";
	}
	return 0;
}