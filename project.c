///determine determinant....
//factorial........................
//square ........
// cube function........
int ccccc = 0;
#define DELAY 30000
#define max 100000
#define MAX 100000
#define pi 3.14159265
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
double mul();
double cubic();
int date();
double outflow();
double mix();
double radioactivedecay();
double power( double, int);
double exp( double );
int quadratic();
int nroot();
int checkvariable();
int ndegreeNHODE();
int poly_differentiation();
int decimalmultiply();
double cool();
int matrix();
float det(float[][100],float);
char * factorial();
void inverse();
void cofact(float [][100],float k);
void transpose(float [][100],float [][100],float);
void rev(char *, char * ); 
char * strminusone(char []);
int sub(char *,char *,char *);
double square();
char * powerbc();//argunment of the function not yet passed.....
char  * add(char *, char *);
char * additiondecimal();
char * multiply( char [], char []);
double cube();
double cube() {
	char a[MAX], b[MAX], res[max];
	char *c;
	printf("ENTER the number you want the cube of = \n");
	scanf("%s",a);
	strcpy(res, a);
	ccccc = 1;
	strcpy( b, a);
	c = multiply( a, b);
	strcpy( a, c);
	c = multiply( a , res);
	printf("%s\n",c);
	return 0.0;
}
double square(){
	char a[MAX], b[MAX];
	char *c;
	printf("ENTER the number you want the square of = \n");
	scanf("%s",a);
	ccccc = 1;
	strcpy( b, a);
	c = multiply( a, b);
	printf("%s\n",c);
	return 0.0;
}
void transpose(float n[100][100], float fac[100][100], float k){
	int i , j;
	float b[100][100], inverse[100][100], d;
	for(i = 0; i < k; i++){
		for(j = 0; j < k; j++){
			b[i][j] = fac[j][i];
		}
	}
	d = det(n,k);
	for(i = 0; i < k; i++){
		for(j = 0; j < k; j++){
			inverse[i][j] = b[i][j] / d;
		}
	}
	printf("the inverse of the matrix is\n");
	for(i = 0; i < k; i++){
		for(j = 0; j < k; j++){
			printf("%f  ",inverse[i][j]);
		}
		printf("\n");
	}
}
void cofact( float num[100][100], float k){
	float b[100][100], fac[100][100];
	int p, q, m, n, i, j;
	for(q = 0; q < k; q++){
		for(p = 0;p < k; p++){
			m = 0;
			n = 0;
			for(i = 0;i < k; i++){
				for(j = 0; j < k; j++){
					if(i != q && j != p){
						b[m][n] = num[i][j];
						if(n < (k - 2))
							n++;
						else {
							n = 0;
							m++;
						}
					}
				}
			}
			fac[q][p] = pow((-1), q+p) * det(b, k - 1);//pow of real bc clashes handle these cases
		}
	}
	transpose( num, fac, k);
}

void inverse(){
	float a[100][100], k, result;
	int i, j;
	printf("enter the order of matrix and enter the entries of the matrix\n");
	scanf("%f", &k);
	for(i = 0; i < k; i++){
			for(j = 0; j < k; j++){
				printf("Enter a%d%d=", i, j);
				scanf("%f", &a[i][j]);
			}
		}
	
	result = det(a,k);
	if(result == 0)
		printf("the inverse of the given matrix is not possible\n");
	else
		cofact( a, k);
}
float det(float a[100][100], float k){
	float s = 1, dete = 0, r[100][100];
	int i, j, m, n, c;
	if(k == 1){
		return a[0][0];
	}
	else {
		dete = 0 ;
		for(c = 0; c < k; c++){
			m = 0;n = 0;
			for(i = 0;i < k; i++){
				for(j = 0; j < k; j++){
					r[i][j] = 0;
					if(i != 0 && j != c){
						r[m][n] = a[i][j];
						if(n < (k - 2))
							n++;
						else{
							n = 0;
							m++;
						}
					}
				}
			}
			dete = dete + s * (a[0][c] * det( r, k - 1));
			s = ( -1 ) * s;
		}
	}
	return (dete);
}
int matrix(){
	int a[100][100], b[100][100], c[100][100];
	int r, c2, r1, c1, i, j, k, n, sum = 0;
	char aa;
	printf("enter the order of the matrixes A and the mode ie(+-*)\n");
	printf("for inverse enter 'i'\n");
	scanf("%d %c", &n, &aa);
	//chose the mode....
	if(aa == '+'){
		for(i = 0;i < n; i++){
			for(j = 0;j < n; j++){
				printf("Enter a%d%d=", i, j);
				scanf("%d", &a[i][j]);
			}
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				printf("Enter b%d%d=", i, j);
				scanf("%d", &b[i][j]);
			}
		}
		for(i = 0;i < n; i++){
			for(j = 0;j < n; j++){
				c[i][j] = a[i][j] + b[i][j];
			}
		}
		for(i = 0;i < n; i++){
			for(j = 0; j < n; j++){
				printf("%d    ", c[i][j]);
			}
			printf("\n");
		}
	}
	if(aa == '-'){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				printf("Enter a%d%d=", i, j);
				scanf("%d", &a[i][j]);
			}
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				printf("Enter b[%d][%d]=", i, j);
				scanf("%d", &b[i][j]);
			}
		}
		for(i = 0; i < n; i++){
			for(j = 0;j < n; j++){
				c[i][j] = a[i][j]-b[i][j];
			}
		}
		for(i = 0; i < n; i++){
			for(j = 0;j < n; j++){
				printf("%d    ", c[i][j]);
			}
			printf("\n");
		}
	}
	if(aa == '*'){
		//in multiplication of matrix rows and column may differ...
		printf("for multiplication rows and columns can differ hence\n");
		printf("enter the rows and column of both the matrixes\n");
		scanf("%d%d%d%d", &r, &c2, &r1, &c1);
		for(i = 0; i < r; i++){
			for(j = 0; j < c2; j++){
				printf("Enter a%d%d=", i, j);
				scanf("%d", &a[i][j]);
			}
		}
	
		for(i = 0;i < r1; i++){
			for(j = 0;j < c1; j++){
				printf("Enter b%d%d=", i, j);
				scanf("%d", &b[i][j]);
			}
		}
		for(i = 0; i < r; i++){
			for(j = 0; j < c1; j++){
				for(k = 0; k < r1; k++){
					sum = sum + a[i][k] * b[k][j];
				}
			c[i][j] = sum;
			sum = 0;
			}
		}
		for(i = 0;i < r; i++){
			for(j = 0; j < c2; j++){
				printf("%d    ", c[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
double div1(){
	char a[MAX];
	long int b;
	while(scanf("%s%ld", a, &b)){
		//only for integers ...remainder is in display
		long int remainder;
		static char quotient[MAX];
		long temp = 0;
		int i = 0, j = 0;
		i = 0;
		if(b == 0){
			goto infinity;
		}
		while(a[i]){
			if(a[i] < 48 || a[i]> 57){
				printf("Invalid positive integer: %s", a);
				return 1;
			}
			i++;
		}
		while(a[i]){
			temp = temp * 10 + (a[i] - 48);
			if(temp < b){
				quotient[j++] = 48;
			}
			else{
				quotient[j++] = (temp / b) + 48;;
				temp = temp % b;
			}
			i++;
		}
		quotient[j] = '\0';
		remainder = temp;
		printf("Quotient: %s / %ld  =  %s", a, b, quotient);
		printf ("\nRemainder: %ld", remainder);
		infinity:
			printf("the answer is infinity or not define\n");
	}
	return 0;
}//complexicity n ^ 2..
////reloook on this function some major cases not handles..............
double cubic(){
	int i;
	double a, b, c, d;
	printf("enter the cofficient of cubic equation in the form of a b c d \n");
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	if(a != 0 && a != 1.0){
		a = 1;
		b = b / a;
		c = c / a;
		d = d / a;
	}
	else
		quadratic();//the cubic cofficient of the equation is zero..... 
	double z1, z2, z3;//solution of the cubic equation,,,......
	double s, r, q, t, r1;//intermediate solution....
	r = (9 * b * c + 27 * d - 2 * b * b * b) / 54;
	q=( 3 * c - b * b ) / 9;
	d = q * q * q + r * r * r;
	r1 = r;
	r1 = r - sqrt(d);
	r = r + sqrt(d);
	s = pow( r , 1 / 3);//clashes with the real bc power function handle this cases..
	t = pow( r1, 1 / 3);
	printf("the solution is %lf", z1 = (-1) * (1 / 3) * b + s + t);
	printf("the second solution is %lf + %lf*i ", (-1) * (1 / 3) * b - 1 / 2 * (s + t), 1 / 2 * ( s - t ));
	printf("the third solution is  %lf - %lf*i ", ( - 1 ) * (1 / 3) * b - 1 / 2 * ( s + t ), 1 / 2 * ( s - t));
}
///if user needs date ...
int date(){
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s\n", asctime (timeinfo) );
  return 0;
}
char  *add(char *x, char *y){
		int i, j, k, sum, carry, l, a, b, c, d;
		char str3[MAX];
		a = strlen(x);
		b = strlen(y);
		k = 0;
		carry = 0;
		sum = 0;
		if(a == 1 && b == 1){
			sum = a + b;
			printf("sum is %d",(x[0] - '0') + (y[0] - '0'));
		}
		else {
			for(i = a - 1, j = b - 1; ; i--, j--) {
				if(x[i] == '.'){
					i--;
				}
				if(y[j] == '.'){
					j--;
				}
				c = x[i] - '0';
				d = y[j] - '0';
				if(j < 0) {
					d = 0;
				}
				if(i < 0) {
					c = 0;
				}
				if(i < 0 && j < 0) {
					break;
				}
				sum = c + d + carry;
				str3[k] = sum % 10 + '0';
				carry = sum / 10;
				k++;
			}
			for(l = k - 1, i = 0; l >= 0, i <= k - 1; l--, i++) {
				x[i] = str3[l];
			}
			x[i] = '\0';
			if(carry == 1){
				int ii, iik;
				ii = strlen (x);
				iik = ii;
				while(ii != 0){
					x[ii] = x[ii - 1];
					ii--;
				}
				x[0] = carry + '0';;
				x[iik+1] = '\0';
			}
			return x;
		}
}
char * additiondecimal() {
	char x[MAX];
	char y[MAX], z[MAX], w[MAX], *xx, *yy, *cc;
	int i, j, k, sum, carry, l=0, a, b, c, d, flag = 0, flag1 = 0;
	k = 0;
	carry = 0;
	sum = 0;
	scanf("%s%s", x, y); {
		a = strlen(x);
		l = a;
		b = strlen(y);
		if(a == 1&&b == 1){
			sum = a + b;
			printf("sum is %d\n",(x[0]-'0')+(y[0]-'0'));
			return NULL;
		}
		while(a != 0){
			if(x[a] =='.'){
				flag = 1;
				break;
			}
			a--;
		}
		while(b != 0){
			if(y[b] == '.'){
				flag1 = 1;
				break;
			}
			b--;
		}
		
		if(flag == 1){
			i = 0;
			l = strlen(x);
			while(i < l){
				if(x[i] == '.'){
					break;
				}
				i++;
			}
			i = i + 1;
			l = 0;
			a = strlen(x);
			while(i < a){
				z[l] = x[i];///z stores the value of the after decimal value of x .....
				i++;l++;
			}
			z[l] = '\0';
			l = strlen(x);
			i = 0;
			while(i < l){
				if(x[i] == '.'){
					break;
				}
				i++;
			}
			x[i+1] = '\0';
		}
		if(flag1 == 1){
			i = 0;
			l = strlen(y);
			while(i < l){
				if(y[i] == '.'){
					break;
				}
				i++;
			}
			i = i + 1;
			l = 0;
			a = strlen(y);
			while(i < a){
				w[l] = y[i];///w stores the value of the after decimal value of y .....
				i++;l++;
			}
			w[l] = '\0';
			l = strlen(y);
			i = 0;
			while(i < l){
				if(y[i] == '.'){
					break;
				}
				i++;
			}
			y[i + 1] = '\0';
		}
		if(flag == 0 && flag1 == 0){
			{
				a = strlen(x);
				b = strlen(y);
				if(b > a){
					xx = add( y, x);
				}
				else{
					xx = add( x, y);
				}
				printf("%s\n", xx);
				return NULL;
			}
		}
		else if(flag == 1 && flag1 == 0){
			xx = add(x, y);
			a = strlen (xx);
			xx[a] = '.';
			xx[a+1] = '\0';
			strcat(xx,z);
			printf(" %s \n",xx);
			return NULL;
		}
		else if(flag == 0 && flag1 == 1){
			xx = add(x,y);
			a = strlen (xx);
			xx[a] = '.';
			xx[a+1] = '\0';
			strcat(xx,w);
			printf("%s\n", xx);
			return NULL;
		}
		else if(flag == 1 && flag == 1) {
			xx = add(x,y);
			a = strlen(xx);
			xx[a] = '.';
			xx[a+1] = '\0';
			a = strlen(z);
			b = strlen(w);
			int ii;
			ii = a;
			if(a > b){
				a = a - b;
				while(a != 0){
					w[b] = '0';
					b++;
					a--;
				}
				w[b + 1] = '\0';
				yy = add(z, w);
				a = strlen(yy);
				b = strlen(z);
				if(a > b){
					cc[0] = yy[0];
					cc[1] = '\0';
					xx = add(xx,cc);
				}
				i = strlen(yy);
				int iik;
				if(i > ii){
					iik = strlen(xx);
					xx[iik - 1] = '\0';
					strcpy(x, xx);
					char aa[2];
					aa[0] = yy[0];
					aa[1] = '\0';
					xx = add(x,aa);
					iik = strlen(xx);
					xx[iik] = '.';
					xx[iik+1] = '\0';
					i = 0;
					iik = strlen(yy);
					while(i < iik){
						yy[i] = yy[ i + 1 ];
						i++;
					}
				}
				strcat( xx, yy);
				printf("%s\n",xx);
				return NULL;
			}
			else if(b > a){
				char tmp[110];
				strcpy( tmp, z);
				strcpy( z, w);
				strcpy( w, tmp);
				yy = add( z, w);
				a = strlen(yy);
				b = strlen(z);
				if(a > b){
					cc[0] = yy[0];
					cc[1] = '\0';
					xx = add( xx, cc);
				}
				i = strlen(yy);
				int iik;
				if(i > ii){
					iik = strlen(xx);
					xx[iik - 1] = '\0';
					strcpy( x, xx);
					char aa[2];
					aa[0] = yy[0];
					aa[1] = '\0';
					xx = add( x, aa);
					iik = strlen(xx);
					xx[iik] = '.';
					xx[iik+1] = '\0';
					i = 0;
					iik = strlen(yy);
					while(i < iik){
						yy[i] = yy[i + 1];
						i++;
					}
				}
				strcat(xx, yy);
				printf("%s\n", xx);
				return NULL;
			}
			/*else if(a == b){
				//yy=add(z,w);
				a = strlen(yy);
				continue;
				b=strlen(z);
				printf("%s", xx);
				if(a > b){
					cc[0] = yy[0];
					cc[1] = '\0';
				//	x=add(xx,cc);
				}
				strcat( xx, yy);
				/////this cas is a stand stilll.				
			}*///this case seg  faults sorry will be solved definitely
		}
	}
}
//same length of both decimal  not handled...
char * multiply(char a[],char b[]){
	static char mul[MAX];
	char c[MAX];
	char tmp[MAX];
	int l, l1;
	int i, j, k = 0, x = 0, y;
	long int r = 0;
	long sum = 0;
	l = strlen(a) - 1;
	l1 = strlen(b) - 1;
	for(i = 0; i <= l; i++){
		a[i] = a[i] - 48;
	}
	for(i = 0; i <= l1; i++) {
		b[i] = b[i] - 48;
	}
	for(i = l1; i >= 0; i--){
		r = 0;
		for(j = l; j >= 0; j--){
				tmp[k++] = (b[i] * a[j] + r) % 10;
				r = (b[i] * a[j] + r) / 10;
		}
		tmp[k++] = r;
		x++;
		for(y = 0; y < x; y++ ) {
			tmp[k++] = 0;
		}
	}
	k = 0;
	r = 0;
	for( i = 0 ; i < l + l1 + 2; i++){
		sum = 0;
		y = 0;
		for(j = 1; j <= l1 + 1; j++){
			if(i <= l + j){
				sum = sum + tmp[y + i];
			}
			y += j + l + 1;
		}
		c[k++] = (sum + r) % 10;
		r = (sum + r)/10;
	}
	c[k] = r;
	j = 0;
	for(i = k - 1; i >= 0; i--){
		mul[j++] = c[i] + 48;
	}
	mul[j] = '\0';
	return mul;
}
///multiplication function after partial submission pass argunment and return char * for expression... 
int decimalmultiply () {
	char a[MAX];
	char b[MAX];
	char cc[MAX], d[MAX];
	char *c;
	int flag, flag1, x, y;
	int i , j, j1;
	if(ccccc != 1){
		scanf( "%s" , a);
		scanf( "%s" , b);
	}
	x = strlen(a);
	y = strlen(b);
	i = 0;
	while( i < x ) {
		if ( a[i] == '.') {
			flag = 1;
			break;
		}
		i++;
	}
	i = 0;
	while( i < y ){
		if ( b[i] == '.'){
			flag1 = 1;
			break;
		}
		i++;
		
	}
	if ( flag == 1 && flag1 == 0 ){
		i = 0;
		int k;
		//char tmp;
		x = strlen(a);
		while ( i < x ){
			if ( a[i] == '.' ){
				break;
			}
			i++;
		}
		j = ( strlen(a) - i )-1;//decimal point from back.......set three as a reference please
		while( i < x ){
			
			a[i] = a[i+1];
			i++;
		}
		c = multiply(a,b);
		j = (strlen(c)-j);
		//tmp=c[j];
		k = strlen(c);
		while ( k >= j ) {
			c[k+1] = c[k];
			k--;
		}
		c[j] = '.';
		printf("%s\n", c);
		return 1;
	}
	else if( flag==0 && flag1==1 ){
		i = 0;
		int k;
		//char tmp;
		x = strlen(b);
		while( i < x ){
			if ( b[i] == '.' ){
				break;
			}
			i++;
		}
		j = ( strlen(b) - i )-1;//decimal point from back.......set three as a reference please
		while( i < x ){
			b[i] = b[i+1];
			i++;
		}
		c = multiply(a,b);
		j = (strlen(c)-j);
		//tmp=c[j];
		k = strlen(c);
		while( k >= j){
			c[k+1] = c[k];
			k--;
		}
		c[j] = '.';
		printf("%s\n", c);
		return 1;
	}
	else if(flag == 0 && flag1 == 0){
		c = multiply(a,b);
		printf("%s\n", c);
		return 1;
	}
	else if( flag==1 && flag1==1 ) {
		
		//a part to calculate the position of the decimal point.
		i = 0;
		int k;
		//char tmp;
		x = strlen(a);
		while(i < x){
			if(a[i] == '.'){
				break;
			}
			i++;
		}
		j = ( strlen(a) - i )-1;//decimal point from back.......set three as a reference please
		while(i < x){
			
			a[i] = a[i+1];
			i++;
		}
		//b part to calculate the position of the decimal point.;.;;;...;..;...;.;.;.;;;
		i = 0;
		x = strlen(b);
		while( i < x ){
			if(b[i] == '.'){
				break;
			}
			i++;
		}
		j1 = ( strlen(b) - i )-1;//decimal point from back.......set three as a reference please
		while(i < x){
			b[i] = b[i+1];
			i++;
		}
		c = multiply(a,b); 
		j = j + j1;
		k = strlen(c);
		while(k >= j){
			c[k+1] = c[k];
			k--;
		}
		c[j] = '.';
		printf("%s", c);
		return 1;
	}
	return 1;
}
//string reverse function needed
void rev(char *a, char *b){
	int l = strlen(a);
	int l1;
	for( l1 = 0; l1 < l; l1++)
		b[l1] = a[l - l1 -1];
	b[l] = '\0';
}
///subtraction function is added
int sub(char *a,char *b,char *ans) {
	char aa[MAX],bb[MAX];
	int l, s, tmp;
	int n = 0, h = 0, anss;
	l = strlen(a);
	s = strlen(b);
	int sign = 0;
	if(l < s){
		strcpy(ans, a);
		strcpy(a, b);
		strcpy(b, ans);
		//exchange the length also yaar
		tmp = l;
		l = s;
		s = tmp;
		sign = 1;
	}
	if(l == s){
		if(strcmp( a, b) < 0){
			strcpy( ans, a);
			strcpy( a, b);
			strcpy( b, ans);
			sign = 1;
			tmp = l;
			l = s;
			s = tmp;
		}
	}
	rev( a,aa);
	rev( b,bb);
	for( ; s < l; s++)
		bb[s] = '0';
	bb[s] = '\0';
	for( ; n < l;n++){
		anss = aa[n] - (bb[n] +h);
		if(anss < 0){
			h = 1;//bring to exct ascii
			ans[n] = 10 + anss + '0';
		}
		else{
			ans[n] = anss + '0';
			h = 0;
		}
	}
	for(n = l - 1;n > 0; n--){
		if (ans[n] != '0')
			break;
	}
	ans[n+1] = '\0';
	rev( ans, a);
	strcpy( ans, a);
	return sign;
}
//decimal subtraction function added
int decimalsubtraction(){
	char fir[MAX],sec[MAX],res[MAX];
	while(scanf("%s%s", fir, sec)) {
		int flag=0, flag1=0, j, a, min, i, ii, b;
		a = strlen(fir);
		b = strlen(sec);
		while(a != 0){
			if( fir[a] == '.' ){
				flag = 1;
				break;
			}
			a--;
		}
		int k = a, kk;
		a = a + 1;
		i = a;
		int c = a;
		a = strlen(fir) - a;
		int check = a;
		int w = a;
		int yy = a;
		while(b != 0){
			if(sec[b] == '.'){
				flag1 = 1;
				break;
			}
			b--;
		}
		b = b + 1;
		kk = b;
		int c1 = b;
		int rr =b;
		b = strlen(sec) - b;
		int check1 = b;
		int z = b;
		int ww = b;
		int oooo = b;
		if(flag == 1 && flag1 == 0) {
			ii = strlen(fir);///to remove the point 
			i = i - 1;
			while ( i < ii){
				fir[i] = fir[i + 1];
				i++;
			}///adding the zeross to the second number for subtraction
			ii = strlen (sec);
			k = strlen (fir) - k;
			while (k != 0) {
				sec[ii] = '0';
				ii++;
				k--;
			}
			sec[ii] = '\0';//now call minus function and store the ans in res
			int sign = sub(fir,sec,res);//now please cautialy li add the decimal point fromn BEHIND
			//get the poistion of the decimal point from behind
			a = strlen(res);
			// a case of 0. for that extract the ineger that is remaining after the decimal number..
			if(w == strlen(res) ){
				if (sign ==1 )
					printf("-");
				printf("0.%s \n",res);
				continue;
			}
			i = strlen (res);
			ii = strlen (res);
			while (yy != 0) {
				res[ii] = res[ii-1];
				ii--;
				yy--;
			}
			res[ii]='.';
			res[i+1]='\0';/////negative condition
			if(sign == 1 ){
				printf("\n-");
			}
			printf("%s\n", res);
			return 1; 
		}//yo case one finished .
		if(flag == 0 && flag1 == 1 ){
			a = strlen(sec);
			rr = rr-1;
			while(rr < a) {
				sec[rr] = sec[rr+1];
				rr++;
			}//removing the dot from the secongd number
			a = strlen(fir);//add the zero number in the first number
			// ww is the position of the decimal point in the second number
			while(ww != 0 ) {
				fir[a] = '0';
				ww--;
				a++;
			}
			sec[a] = '\0';
			int aa;
			aa = sub(fir, sec, res);
			if(z == strlen(res) ){
				if ( aa == 1 )
					printf("-");
				printf("0.%s \n",res);
				return 1;//if codes show error or segfaults remove this line
				continue;
			}
			a = strlen(res);//now we need the position of the decimal point but please remember from behind;
			while (oooo!=0) {
				res[a] = res[a-1];
				a--;
				oooo--;
			}
			res[oooo + 1] = '.';
			if ( aa == 1 ){
				printf("-");
			}
			printf("%s \n", res);
			return 1;
		}
		if(flag == 0 && flag1 == 0 ) {
			if(sub(fir, sec, res) == 1)
				printf("-");
			int len = strlen(res);
			printf("%s\n", res);
			return 1;
		}
		if(flag == 1 && flag1 == 1){
			///yeah done at last 2 cases to go  .........
			if ( check == check1 ){
				//removing both the dots in the given numbers but first fir[]
				c = c - 1;
				a = strlen (fir);
				while( c < a ) {
					fir[c] = fir[c + 1];
					c++;
				}
				b = strlen (sec);
				c1 = c1 - 1;
				while(c1 < b ) {
					sec[c1] = sec[c1 + 1];
					c1++;
				}
				//cleared the dots and now subtract the numbers....
				int aa;
				aa=sub(fir, sec, res);
				//now adding the decimal point in the answer....
				a = strlen (res);
				int bb = check;
				b = strlen(res);
				if (strlen(res) == 1 && res[0] == '0') {
					printf("0");
					return 1;
					continue;
				}
				if ( bb == strlen(res)){
					if ( aa == 1 )
						printf("-");
					printf("0.%s", res);
					return 1;
					continue;
				}
				while(check != 0) {
					res[a] = res[a-1];
					check--;
					a--;
				}
				res[b+1] = '\0';
				res[a]='.';
				if (aa == 1)
					printf("-");
				printf("%s ", res);
				return 1;
			}
			if ( check > check1 ) {
				//make the second number equal to the numbers zero
				int aa = check - check1 ;
				a = strlen (sec) ;
				while ( aa != 0 ) {
					sec[a] = '0';
					a++;
					aa--;
				}
				sec[a] = '\0';
				//removing the decimal points from both the numbers ..........
				c = c - 1;
				a = strlen (fir);
				while( c < a ) {
					fir[c] = fir[c+1];
					c++;
				}
				b = strlen (sec);
				c1 = c1 - 1;
				while(c1 < b ) {
					sec[c1] = sec[c1+1];
					c1++;
				}
				aa = sub (fir, sec, res);
				//special cases such as zero and little greater than zero and less than one.......
				if ( w > strlen(res)){
					//one more case head ache example 23.369 23.36
					a = strlen(res);
					a = w-strlen(res);
					b = 0;
					while(a != 0){
						fir[b] = '0';
						a--;
						b++;
					}
					fir[b] = '\0';
					strcat(fir, res);
					strcpy(res, fir);
					if ( aa == 1 )
						printf("-");
					printf("0.%s\n", res);
					return 1;
					continue;
				}
				if (strlen(res) == 1 && res[0] == '0') {
					printf("0");
					return 1;
					continue;
				}
				//now putting the decimal to that position for which check cause of the check.....
				a = strlen(res);
				b = strlen(res);
				while(check != 0) {
					res[a] = res[a-1];
					check--;
					a--;
				}
				res[b+1] = '\0';
				res[a] = '.';
				if ( aa == 1)
					printf("-");
				printf("%s\n",res);
				return 1;
			}
			else if ( check < check1 ) {
				///last case to gooooo.......
				int aa = check1 - check ;
				//adding zero to the next number.......
				a = strlen (fir) ;
				while ( aa != 0 ) {
					fir[a] = '0';
					a++;
					aa--;
				}
				fir[a] = '\0';
				//removing the dots...
				c = c - 1;
				a = strlen (fir);
				while( c < a ) {
					fir[c] = fir[c+1];
					c++;
				}
				b = strlen (sec);
				c1 = c1 - 1;
				while(c1 < b ) {
					sec[c1] = sec[c1+1];
					c1++;
				}
				//dots removed...
				aa = sub (fir,sec,res);
				if ( z > strlen(res)){
					//one more case head ache example 23.369 23.36
					a = strlen(res);
					a = z-strlen(res);
					b = 0;
					while(a != 0){
						fir[b] = '0';
						a--;
						b++;
					}
					fir[b] = '\0';
					strcat(fir, res);
					strcpy(res, fir);
					if ( aa == 1 )
						printf("-");
					printf("0.%s\n",res);
					return 1;
					continue;
				}
				a = strlen(res);
				b = strlen(res);
				while(check1 != 0) {
					res[a] = res[a-1];
					check1--;
					a--;
				}
				res[b+1] = '\0';
				res[a] = '.';
				if ( aa == 1)
					printf("-");
				printf("%s\n",res);
				return 1;
			}
		}
	}
	return 0;
}
//string digit minus one
char * strminusone(char a[]){
 	int i, j, k = 0;
	i = strlen(a) - 1;
	j = 0;
	int u = 0;
		while(a[i - j] == '0') {
			k++;
			j++;
		}
		if (k >= 1){
			while(k != 0) {
				a[i] = '9';
				k--;
				i--;
			}
			a[i] = a[i] - 1;
			if(a[0] == '0' && a[1] != '0'){
				u = strlen(a);
				k = 0;
				while(k < u) {
					a[k] = a[k+1];
					k++;
				}
			}
		}
		else {
			i = strlen(a) -1;
			a[i] = a[i] - 1;
		}
		u++;
}
///power function of unlimited digits not that of the math.h header file...
char * powerbc() {
	char a[MAX], b[MAX];
	char d[MAX];
	char cc[MAX];
	char *c,*dd;
	int u = 1, kk = 0, flag = 0, i = 0, j, k;
	// now handlng the case of decimal but of only base number. please
		scanf("%s%s", a, b);{
		k = 0;
		j = 0;
		///condition of real numbers...............
		while(a[j] != '.') {
			if(a[j + 1] == '.')
				flag = 1;
			j++;
		}
		j++;
		if(flag == 1){
			i = strlen (a);
			kk = j;
			kk = strlen(a)-kk;
			j = j - 1;
			while(j < i) {
				a[j] = a[j + 1];
				j++;
			}
		}
		k = 0;
		i = strlen(a);
		j = strlen(b);
		strcpy( d, a);
		strcpy( cc, a);
		strminusone(b);
		while(b[0] != '0') {
			u++;
			strcpy( a, d);
			c = multiply( cc, a);
			strcpy( cc, c);
			strminusone(b);
		}
		while(cc[i] == '0') {
			k++;
			i++;
		}
		i = 0;
		j = strlen(cc);
		while(j > 0) {
			cc[i] = c[k];
			j--;
			i++;
			k++;
		}
			/////////////////////////////////////////////////////decimal part
		u = (u) * kk;
		if (flag == 1) {
        		u = strlen(cc) - u;
        		k = strlen(cc);
        		while ( k >= u ) {
				cc[k + 1] = cc[k];
				k--;
			}
			cc[k + 1] = '.';///////////////////////////////hello.
			//printf("position of decimal point if you are searching %d\n",k+1);
		}
		i = 0;
		k = strlen(cc);;
		while(c[i] == '0'){
			i++;
		}
		kk = 0;
		while(k > 0) {
			cc[kk] = cc[kk + 1];
			kk++;
			k--;
		}
		printf("%s\n", cc);
		return NULL;
	}
}
///factorial function ....please dont clash with math.h lol.
char * factorial(char a[]) {
	char b[MAX];
	char d[MAX];
	char cc[MAX];
	char *c;
	int i=0,j,k;
	while(1){
		if( a[0] == '0' && a[1]=='\0'){
			a[0]='1';
			//return a;passed argunment will have the value ...\till then print
			printf("%s", a);
			return NULL;
		}
		else{
			strcpy(b,a);
			strminusone(b);
			strcpy(d,b);
			while(b[0]!='0'){
				c=multiply(a,b);
		
				i=0;
				k=0;
				/*while(c[i]=='0') {
						//by increasing the time complexity to n'square ..we prevented the memory wastage 	
						///created by multiply function generating zero at the begining ..
							///useful to counter the error of 	STACK SMASHING OR over flow of memory..	....
								///not exactly n square cause it does not detect zero in some cases....
					k++;
					i++;
				}
				i=0;
				j=strlen(c);
				if(k>0){
					while(j>0) {
						c[i]=c[k];
						j--;
						i++;
						k++;
					}
				}*/	
	
				strcpy(b,d);
				strcpy(a,c);
				strminusone(b);
				strcpy(d,b);
				i=0;
				k=0;
				while(c[i]=='0') {
					k++;
					i++;
				}
				i=0;
				j=strlen(c);
				while(j>0) {
					c[i]=c[k];
					j--;
					i++;
					k++;
				}
			}
				
		}
		strcpy(a,c);
			return a;
	}
}
/////EXTRA CODE Before deciding the topic of the project lol.....
double outflow() {
	printf("Enter the radius of the cylindrical tank and the small hole at the bottom of the tank in the same unit .\n");
	double R, r, A, a, c, h, t;
	scanf("%lf%lf", &R, &r);
	a = pi * r * r;
	A = pi * R * R;
	A = 13.28 * (a / A);
	printf("The general solution of the equation of the height is h(t) = (c - %lf*t)^2 ", A);
	//particular solution for the value of c in short.....
	printf("Enter the initial condition at h (0)\n");
	scanf("%lf", &h);
	c = sqrt(h);//math function
	printf("the time at which no water is left  %lf  hours\n", c / A / (60 * 60));
	printf("now the height at particular time .so enter the time");
	scanf("%lf", &t);
	t = (c - A * t) * (c - A * t);
	printf("therefore height is %lf \n ", t);
	return 1.0;
}
double cool() {
//for this law we need to know about the average temperature ,initial condition temperature and at known time t and temperature at that time t
	double k, t1, t2, t3, c, t, t4;
	printf("Enter the average temperature and   initial condition(temperature) at t=0");
	scanf("%lf%lf", &t1, &t2);
	c = t2 - t1;
	printf("enter the temperature at time t and the time t also");
	scanf("%lf%lf", &t3, &t);
	k = log((t3 - t1)/c) / t;
	printf("The general equation is  T(t)=%lf + %lfe^(%lf*t)", t1, c, k);
	printf("Enter the time t at which you want to find temperature through newtons law of cooling");
	scanf("%lf", &t4);
	{
		printf("T(%lf)=%lf\n", t4, t1 + c * exp(k * t4));
	}
}
double mix() {
	double store, c, inrate, incontent, outrate, k, y, t;
	//pending work use gnu to demonstrate the example.if possible....
	printf("Enter the no of gallons that the tank contains and also the outflow \n");
	scanf("%lf%lf", &store, &outrate);
	printf("Enter the rate of gallon the solution is added to the water and as enter the given salt per gallon\n");
	scanf("%lf%lf", &inrate, &incontent);
	k = outrate / store;
	printf("Enter the initial condition:y(0)..\n"); 
	scanf("%lf", &y);
	//constant generated while integrating...
	c = ((inrate * incontent)/k) - y;
	printf("the general equation is  y(t)= (%lf * %lf)/ %lf - %lf*e^(- %lf*t)\n now find the amount of solute at any time t.just enter the value of t", inrate, incontent, k, c, k);
	scanf("%lf", &t);{
	        k = inrate * incontent / k - c * exp( - outrate / store * t);
	        printf("the amount of salt at time %lf is %lf \n",t,k);
	}
	return 0.0;
}
double radioactivedecay() {
	double y, inp, c, t, k, t1;
	printf("please enter the initial condition     y(0) = ""initial value of decay\n");
	//if the initial condition is not expected please handle the case of non initial condition through if
	//here also if the initial condition is not handled then please handle that condition through if
	scanf("%lf", &inp);
	c = inp;
	printf("enter the specific condition at a particular time and value of the function at that time interval\n");
	scanf("%lf%lf", &t, &y);
	k = (-1) * 1 / t * log(y / c);
	printf("the equation of radioactivity is y(t)=%lf*e^(%lf * t) \n", c, k);
	printf("now find the decayed amount by entering the time ");
	scanf("%lf", &t1);
	{
		t1 = c * exp( k * t1 );
		printf("%lf\n", t1);
	}
	return 0.0;
}
double power(double x,int n) {
	double val = 1;
	int i;
		for(i = 1; i <= n; i++) {
		val = val * x;
	}
	return val;
}
int poly_differentiation() {
	//fo polynomials
	int a[50], i, n = 0, d[50], power;
	float in[10];
	printf("enter the order of the polynomial\n");
	scanf("%d", &n);
	for(i = n; i >= 0; i--){
		printf("enter the cofficient of x^%d  ", i);
		scanf("%d", &a[i]);
	}
	printf("the given polynomial is \n");
	for(i = n; i >= 0; i--) {
		if (a[i] > 0) {
			if(i != n) {
				printf("+");
			}
		}
		else if (a[i] < 0)
			printf(" - ");
		else 
			printf("  ");
		printf("%dx^%d", a[i], i);
	}
	//differentiate
		printf("\n derivative of the givemn polynomial is %d\n",n);
		for(i = n;i >= 1; i--) {
			if(a[i] < 0)
				printf(" - ");
			else if(a[i] > 0)
				printf(" + ");
			else
				printf("  ");
			printf(" %dx^%d", a[i] * i, i - 1);
		}
}
int nroot() {
	return 0;
}
int ndegreeNHODE() {
}
int quadratic() {
	int i;
	double a, b, c, d;
	printf("enter the cofficient of quadratic equation in the form of a b c  ");
	scanf("%lf%lf%lf", &a, &b, &c);
	d=sqrt(b*b-4*a*c);
	if((b * b - 4 * a * c) == 0)
		printf("\nthe solution is %lf", (double) (-1) * b / 2 * a);
	else if((b * b - 4 * a * c) < 0){
		d=sqrt((-1) * (b * b - 4 * a * c));
		printf("\nthe solution is X1 = %lf + %lfi .\nX2 = %lf + %lfi\n",((-1) * b) / (2 * a),d / (2 * a),((-1) * b) / (2 * a), d / (2 * a));
	}
	else 
		printf("\nthe solution is x1= %lf  and x2 =%lf\n",(-1)*b/2*a+d/2,(-1)*b/2*a-d/(2*a));
	//error cases not handled
	return 1;
}
//arithematic function addition......
//addition of bc
int main() {
	printf("bc 0.0.0.0\n");
	printf("Copyright 2016 Free Software Foundation, Inc.\n");
	printf("This is free software with ABSOLUTELY NO WARRANTY.\n");
	printf("Enter 111503050 for EXIT \n");
	date();
	int i,n;
	char * aa, a[MAX];
	double q, ret, val, facto, p, expo;
	int key;
	float aaa[100][100], k, result;
	int  j;
	while(scanf("%d", &key)){
		//switch case interface for partial submission
		switch (key){
			printf("ENTER THE KEY\n");
			case 1:
				quadratic();
				break;
			case 111503050://exit condition
				return 1;
			case 2:
				poly_differentiation();
				break;
			//nroot();
			case 3:
				printf("the exponential function of %lf  is %lf ",p,exp(p));	
				break;
			case 4:
				printf("Enter the data to find factorial = ");
				scanf("%s", a);
				aa = factorial(a);
				printf("%s\n", aa);
				break; 
			////TRIGNOMETRY FUNCTION. and please arrange the condition according to the user.
			case 5:
				printf("ENTER for sine.. ");
				scanf("%lf", &q);
				val = pi / 180;
				ret = sin(q * val);
				printf(" the sine of %lf is %lf\n",q,ret);
				break;
			case 6:
				printf("ENTER for cos   ");
				scanf("%lf", &q);
				val = pi / 180;
				ret = cos(q*val);
				printf("the cos of %lf is %lf ", q, ret);
				break;
			case 7:
				printf("ENTER for tan  ");
				scanf("%lf", &q);
				val = pi / 180;
				ret = tan(q * val);
				break;
			case 8:
				printf("ENTER for the cosec   ");
				scanf("%lf", &q);
				val = pi / 180;
				printf("cosec = %lf\n",1 / sin(q * val));
				break;
			case 9:
				printf("ENTER for sec   ");
				scanf("%lf", &q);
				val = pi / 180;
				printf("sec = %lf\n", 1 / cos(q * val));
				break;
			case 10:
				printf("ENTER for cot  ");
				scanf("%lf", &q);
				val = pi / 180;
				printf("cot = %lf\n", ret = 1 / tan(q * val));
				break;
			//end of trignometry function.
			//radioactivity :exponential decay....SOME APPLICATION
			case 11:
				radioactivedecay();
				break;
			case 12:
				mix();
			/*mixing problem....to tell the total concentration of solute example(salt)
			the overall concept is , there is solute in a tank .there is a tap which is open .simultaneously there is an inlet on top gives salt .to find the total concentration of salt in the tank at time t..facinating.the work of calculating is done on paper the final formulas are written in mix function.
			*/break;
			
			case 13:
			//Newton's law of cooling...
				cool();
				break;
			//problems related to the level (hieght of water level) at a given time t...when there is a hole in the cylindrical tank.....
			case 14:
				outflow();
				break;
			case 15:
				cubic();//logic is not clear answer is different fro expected..will be cleared.
				break;
			case 16:
				printf("ENTER two numbers and space in between for multiplication\n");
				decimalmultiply();     // argunment are requiredd thats why
				break;//here due to partial submission multiplication of only two numbers.
			//all cases handled..
			case 17:
				printf("ENTER two numbers and space in between for subtraction\n");
				decimalsubtraction();
				break;
			case 18:
				printf("ENTER teo numbers and space in between for addition \n");
				additiondecimal();
				break;
			case 19:
				printf("ENTER the base and the raise to part for power function\n");
				powerbc();//some cases could segfault
				break;
			case 20:
				printf("MATRIX OPERATIONS\n");
				matrix();
				break;
			case 21:
				printf("INVERSE OF MATRIX\n");
				inverse();
				break;
			
			case 22:
				square();
				break;
			case 23:
				cube();
				break;
			case 24:
				printf("enter the order of matrix and enter the entries of the matrix\n");
				scanf("%f", &k);
				for(i = 0; i < k; i++){
					for(j = 0; j < k; j++){
						printf("Enter a%d%d=", i, j);
						scanf("%f", &aaa[i][j]);
					}
				}
				result = det(aaa,k);
				printf("determinant is %lf\n", result);
				break;
			}
	}
	return 0;
}
