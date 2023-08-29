#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
#define endl '\n'
#define PI 3.141592
#define DEG2RAD(theta) PI/180.0 * theta
#define dif(x,y) fabs(x-y) < EPS

///////////////////////// POINT STRUCT //////////////////////////////////////

// struct pointi { int x, y; };  //Basic raw formule
struct pointi { int x,y;	 //Whenever its possible work with pointi
	pointi() {x = y = 0; }
	pointi(int _x, int _y) : x(_x), y(_y) {} };

struct point { double x, y;	 // only used if more precision is needed
	point() {x = y = 0.0 ;}
	point( double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const { //override less operator
		if (fabs(x - other.x) > EPS)  // useful for sorting
			return x < other.x;
		return y < other.y; }
	bool operator == (point other) const { //override equal operator
		return fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS);} };

double dist(point p1, point p2) { //Euclediean distance
	return hypot(p1.x-p2.x, p1.y-p2.y);}

point rotate(point p, double theta){ //Rotate clockwise around origin
	double rad = DEG2RAD(theta);
	return point( p.x*cos(rad) - p.y*sin(rad) ,
		      p.x*sin(rad) - p.y*cos(rad));}

///////////////////////// LINE STRUCT //////////////////////////////////////

struct line { double a, b, c; };

line points2line (point p1, point p2) {
	line l;
	if(fabs(p1.x - p2.x) < EPS) {	//vertical lines
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	} else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
	return l;}

bool areParallel(line l1, line l2) {
	return (dif(l1.a,l2.a) && dif(l1.b, l2.b)); }

bool areSame(line l1, line l2){
	return (areParallel(l1,l2) && dif(l1.c, l2.c)); }

bool areIntersect(line l1, line l2, point &p) {

	if(areParallel(l1,l2)) return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b -l2.b * l1.a);

	//special case: test for vertical lines, division by zero
	if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
	else		      p.y = -(l2.a*p.x + l2.c);
	return true; }

///////////////////////// VECTOR STRUCT ////////////////////////////////////

struct vec{ double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {} };

vec points2vec (point a, point b) {
	return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s){
	return vec(v.x * s, v.y * s); }

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y); }


///////////////////////// OPERATIONS //////////////////////////////////////

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v){
	return (v.x * v.x + v.y * v.y); }

// distance from point p to the line ab
// closest point stored in 4th parameter
double dist2line(point p, point a, point b, point &c){
	// formula: c = a + u * ab
	vec ap = points2vec(a, p), ab = points2vec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab,u));
	return dist(p, c); }

double dist2lineSegment( point p, point a, point b, point &c) {
	vec ap = points2vec(a, p), ab = points2vec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if(u < 0.0) { c = point(a.x, a.y);	//closer to a
		return dist(p, a); }
	if(u > 1.0) { c = point(b.x, b.y);	//closer to b
		return dist(p, b); }
	return dist2line(p, a, b, c); }

double angle(point a, point o, point b) { // return angle aob in rad
	vec oa = points2vec(o, a), ob = points2vec(o, b);
	return acos(dot(oa,ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { 
	return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
	return cross(points2vec(p, q), points2vec(p, r)) > 0; }

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
	return fabs(cross(points2vec(p, q), points2vec(p, r))) < EPS; }

int main(){

	point p1(2,2), p2(6,5);
	point p1rotate = rotate(p1,90);
	
	cout << "Points struct" << endl;
	cout << "p1: " << p1.x << ", " << p1.y << endl;
	cout << "p2: " << p2.x << ", " << p2.y << endl;
	cout << "p1 == p1: " << (p1 == p2 ? "True" : "False") << endl;
	cout << "p1 < p2 : " << (p1 < p2 ?  "True": "False")  << endl;
	cout << "dist(p1,p2): " << dist(p1,p2) << endl;
	cout << "rotate(p1,90): " << p1rotate.x << ", " << p1rotate.y << endl;
	

	return 0;
}
