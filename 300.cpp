#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

struct vect{
	double x, y;
	vect(){}
	vect(double x, double y) : x(x), y(y){}
	vect operator + (vect const &T) const{return vect(x+T.x, y+T.y);}
	vect operator - (vect const &T) const{return vect(x-T.x, y-T.y);}
	vect operator * (double const &t) const{return vect(x*t, y*t);}
	double len(){return sqrt(x*x + y*y);}
	vect rot(double t) const{return vect(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));}
};

const double PI = acos(-1.);
int n, m;
vect p[600], u[10];

int main(){
	scanf("%d", &n);
	p[0] = vect(0, 0);
	m = 1;
	
	u[0] = vect(10, 0);
	FOR(i,1,5) u[i] = u[i-1].rot(2. * PI / 5.);
	
	FOR(i,0,n){
		p[m] = p[m-1] + u[4];
		p[m+1] = p[m] + u[0];
 		p[m+3] = p[m+1] + u[1];
		p[m+2] = p[m+3] + u[2];
		m += 4;
	}
	
	printf("%d\n", m);
	FOR(i,0,m) printf("%.12f %.12f\n", p[i].x, p[i].y);
	FOR(i,0,n){
	    int t = i * 4 + 1;
	    printf("%d %d %d %d %d\n", t, t+1, t+2, t+4, t+3);
	}
	
	FOR(i,0,n){
		int t = i * 4 + 1;
		printf("%d %d %d %d ", t, t+2, t+3, t+1);
	}
	FOD(i,n,0) printf("%d ", (i+1)*4 + 1);
	printf("1\n");

	return 0;
}