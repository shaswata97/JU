#include <stdio.h>
#include <stdlib.h>

double poly[8000][2];
int pos[400][2];
int free_pt=0;

int readPoly();
int exist(int c);
void writePoly(int p);
int isZero(int c);
double coeff(int c, int exp);
int add(int a, int b);
int sub(int a, int b);
int degMax(int c);
int degMin(int c);
int multc(int p, double c);
int mult(int a, int b);
int main(){
	int stop=0,res,ch2,flag,i;
	char ch;
	int res3[2],flag3[2];
	printf("Polynomials\n");
	do{
		flag=1;
		flag3[0]=1;
		flag3[1]=1;
		printf("Enter your choice\nA Enter a polynomial.\nB Add two polynomials.\nC Subtract two polynomials.\nD Multiply two polynomials.\nE Multiply a polynomial with a constant.\nF Check if a polynomial is zero or not.\nG Print the highest degree in a polynomial.\nH Print a polynomial\nI Exit\n");
		scanf("%c",&ch);
		switch(ch){
			case 'A':
			case 'a':
				res=readPoly();
				printf("Your polynomial is at %dth position\n.Printing your polynomial\n",(res+1));
				writePoly(res);
				break;
			case 'B':
			case 'b':
				printf("Polynomial 1 + Polynomial 2 \n");
				for(i=0;i<2;i++){
					printf("Polynomial %d\nEnter 1 to enter a new polynomial or 2 for an existing polynomial\n",(i+1));
					scanf("%d",&ch2);
					do{
						if(ch2==1){
							res3[i]=readPoly();
							break;
						}
						else if(ch2==2){
							printf("Enter position of polynomial\n");
							scanf("%d",&res3[i]);
							if(!(exist(res3[i]))){
								printf("Polynomial does not exist\n");
								flag3[i]=0;
								break;
							}
							else
								break;
						}
						else
						printf("Wrong choice. Enter again\n");
					}while(1);
				}
				if(flag3[0]==0 || flag3[1]==0)
					printf("All polynomials do not exist\n");
				else{
					int sum=add(res3[0],res3[1]);
					writePoly(sum);
				}
				break;
			case 'C':
			case 'c':
				printf("Polynomial 1 - Polynomial 2 \n");
				for(i=0;i<2;i++){
					printf("Polynomial %d\nEnter 1 to enter a new polynomial or 2 for an existing polynomial\n",(i+1));
					scanf("%d",&ch2);
					do{
						if(ch2==1){
							res3[i]=readPoly();
							break;
						}
						else if(ch2==2){
							printf("Enter position of polynomial\n");
							scanf("%d",&res3[i]);
							if(!(exist(res3[i]))){
								printf("Polynomial does not exist\n");
								flag3[i]=0;
								break;
							}
							else
								break;
						}
						else
						printf("Wrong choice. Enter again\n");
					}while(1);
				}
				if(flag3[0]==0 || flag3[1]==0)
					printf("All polynomials do not exist\n");
				else{
					int diff=sub(res3[0],res3[1]);
					writePoly(diff);
				}
				break;
			case 'D':
			case 'd':
				printf("Polynomial 1 * Polynomial 2 \n");
				for(i=0;i<=1;i++){
					printf("Polynomial %d\nEnter 1 to enter a new polynomial or 2 for an existing polynomial\n",(i+1));
					scanf("%d",&ch2);
					do{
						if(ch2==1){
							printf("%d",i);
							res3[i]=readPoly();
							printf("c1");
							break;
						}
						else if(ch2==2){
							printf("Enter position of polynomial\n");
							scanf("%d",&res3[i]);
							if(!(exist(res3[i]))){
								printf("Polynomial does not exist\n");
								flag3[i]=0;
								break;
							}
							else{
								printf("c3 %d\n",i);
								flag3[i]=1; 
								break;
							}
						}
						else
						printf("Wrong choice. Enter again\n");
					}while(1);
				}
				printf("c2");
				if(flag3[0]==0 || flag3[1]==0)
					printf("All polynomials do not exist\n");
				else{
					int pro=mult(res3[0],res3[1]);
					writePoly(pro);
				}
				break;
			case 'E':
			case 'e':
				printf("Enter 1 to check a new polynomial or 2 for an existing polynomial\n");
				do{
					scanf("%d",&ch2);
					if(ch2==1){
						res=readPoly();
						break;
					}
					else if(ch2==2){
						printf("Enter position of polynomial\n");
						scanf("%d",&res);
						if(!(exist(res))){
							printf("Polynomial does not exist\n");
							flag=0;
							break;
						}
						else
							break;
					}
					else
						printf("Wrong choice. Enter again\n");
				}while(1);
				if(flag==1){
					double c;
					printf("Enter constant\n");
					scanf("%lf",&c);
					int res2=multc(res,c);
					writePoly(res2);
				}
				break;
			case 'F':
			case 'f':
				printf("Enter 1 to check a new polynomial or 2 for an existing polynomial\n");
				do{
					scanf("%d",&ch2);
					if(ch2==1){
						res=readPoly();
						break;
					}
					else if(ch==2){
						printf("Enter position of polynomial\n");
						scanf("%d",&res);
						if(!(exist(res))){
							printf("Polynomial does not exist\n");
							flag=0;
							break;
						}
						else
							break;
					}
					else
						printf("Wrong choice. Enter again\n");
				}while(1);
				if(flag==1){				
					if(isZero(res))
						printf("Zero polynomial\n");
					else
						printf("Not a zero polynomial\n");
				}
				break;
			case 'G':
			case 'g':
				printf("Enter 1 to check a new polynomial or 2 for an existing polynomial\n");
				do{
					scanf("%d",&ch2);
					if(ch2==1){
						res=readPoly();
						break;
					}
					else if(ch==2){
						printf("Enter position of polynomial\n");
						scanf("%d",&res);
						if(!(exist(res))){
							printf("Polynomial does not exist\n");
							flag=0;
							break;
						}
						else
							break;
					}
					else
						printf("Wrong choice. Enter again\n");
				}while(1);
				if(flag==1)
					printf("Highest degree in polynomial = %d",degMax(res));
				break;
			case 'H':
			case 'h':
				printf("Enter 1 to check a new polynomial or 2 for an existing polynomial\n");
				do{
					scanf("%d",&ch2);
					if(ch2==1){
						res=readPoly();
						break;
					}
					else if(ch==2){
						printf("Enter position of polynomial\n");
						scanf("%d",&res);
						if(!(exist(res))){
							printf("Polynomial does not exist\n");
							flag=0;
							break;
						}
					}
					else
						printf("Wrong choice. Enter again\n");
				}while(1);
				if(flag==1)
					writePoly(res);
				break;
			case 'I':
			case 'i':
				printf("Thank you\n");
				stop=1;
				break;
			default:
				printf("Wrong choice\n");
			break;
		}
	}while(stop==0);
}

//function to read a polynomial and store it in the poly pool
int readPoly(){
	printf("Enter your polynomial.\nEnter highest degree in the polynimial\n");
	int n,i;
	double x;
	scanf("%d",&n);
	if(free_pt!=0){
	pos[free_pt][0]=pos[free_pt-1][1]+1;
	pos[free_pt][1]=pos[free_pt][0];
	}
	else
	{
		pos[free_pt][0]=0;
		pos[free_pt][1]=0;
	}
	for(i=n;i>=0;i--){ // reading and storing the polynomial in decreasing order
		printf("\nEnter coefficient of x^%d = ",i);
		scanf("%lf",&x);
		if(x!=0.0){
			poly[pos[free_pt][1]][0]=x;
			poly[pos[free_pt][1]][1]=i*1.0;
			pos[free_pt][1]++;
		}
	}
	if(pos[free_pt][1]==pos[free_pt][0]){
		poly[pos[free_pt][1]][0]=0;
		poly[pos[free_pt][1]][1]=0;
		pos[free_pt][1]++;
	}
	pos[free_pt][1]--;
	free_pt++;
	return (free_pt-1);
}

//function to check if c-th polynomial exists or not
int exist(int c){
	if(c<free_pt)
		return 1;
	else
		return 0;
}

//function to print p-th polynomial int poly pool
void writePoly(int p){
	int i;
	for(i=pos[p][0];i<=pos[p][1];i++){
		if(i!=pos[p][0] && poly[i][0]>0.0)
			printf("+");
		if(poly[i][1]>0){
			if(poly[i][0]==1.0)
				printf("x");
			else if(poly[i][0]>0.0)
				printf("%3.3fx",poly[i][0]);
			else
				printf("%3.3fx",poly[i][0]);
			if(poly[i][1]!=1.0)
				printf("^%d",(int)poly[i][1]);
		}
		else
		printf("%3.3f",poly[i][0]);		
	}
	printf("\n");
}

//function to check if the c-th polynomial in the poly pool is zero or not
int isZero(int c){
	if(c<free_pt && c>=0){
		if(pos[c][0]==pos[c][1] && poly[pos[c][0]][0]==0)
			return 1;
		else
			return 0;
	}
	else{
		printf("Polynomial does not exist");
		return 0;
	}
}

//function to return the coefficient of x^i of the c-th polynomial in the poly pool
double coeff(int c, int exp){
	int i;
	for(i=pos[c][0];i<=pos[c][1];i++){
		if(poly[i][1]==exp){
			return (poly[i][0]);
		}
	}
	return 0.0;
}

//function to get the highest degree of the c-th polynomial in the poly pool
int degMax(int c){
	int t=pos[c][0];
	return (poly[t][1]);
}

//function to add a-th and b-th polynomial in the poly pool
int add(int a, int b){
	int i,ca,cb,flag0=1;
	int bega=pos[a][0];
	int enda=pos[a][1];
	int begb=pos[b][0];
	int endb=pos[b][1];
	int p=pos[free_pt-1][1]+1; //denotes the start of the new polynomial
	int max=(poly[bega][1]>poly[begb][1])?poly[bega][1]:poly[begb][1]; //maximum of degree of the two polynomials 
	int min=(poly[enda][1]>poly[endb][1])?poly[enda][1]:poly[endb][1]; //minimum of degree of the two polynomials 
	pos[free_pt][0]=p;
	for(i=max;i>=min;i--){
		ca=coeff(a,i);
		cb=coeff(b,i);
		if((ca+cb)!=0.0){
			poly[p][0]=ca+cb;
			poly[p][1]=i;
			p++;
			flag0=0;
		}
	}
	if(flag0==1){// if resultant polynomial is zero
		pos[free_pt][1]=p; //denotes the end of the new polynomial
		poly[p][0]=0;
		poly[p][1]=0;
	}
	else
		pos[free_pt][1]=p-1;
	free_pt++;
	return (free_pt-1);
}

//function to subtract b-th polynomial from a-th polynomial in the poly pool
int sub(int a, int b){
	int i,ca,cb,flag0=1;
	int bega=pos[a][0];
	int enda=pos[a][1];
	int begb=pos[b][0];
	int endb=pos[b][1];
	int p=pos[free_pt-1][1]+1; //denotes the start of the new polynomial
	int max=(poly[bega][1]>poly[begb][1])?poly[bega][1]:poly[begb][1]; //maximum of degree of the two polynomials 
	int min=(poly[enda][1]>poly[endb][1])?poly[enda][1]:poly[endb][1]; //minimum of degree of the two polynomials  
	pos[free_pt][0]=p;
	for(i=max;i>=min;i--){
		ca=coeff(a,i);
		cb=coeff(b,i);
		if((ca-cb)!=0.0){
			poly[p][0]=ca-cb;
			poly[p][1]=i;
			p++;
			flag0=0;
		}
	}
	if(flag0==1){// if resultant polynomial is zero
		pos[free_pt][1]=p; //denotes the end of the new polynomial
		poly[p][0]=0;
		poly[p][1]=0;
	}
	else
		pos[free_pt][1]=p-1;
	free_pt++;
	return (free_pt-1);
}

//function to multiply the p-th polymomial in poly pool with constant with degree c
int multc(int p,double c){
	pos[free_pt][0]=pos[free_pt-1][1]+1;
	if(c==0.0 || isZero(p)){
		pos[free_pt][1]=pos[free_pt][0];
		poly[pos[free_pt][0]][0]=0;
		poly[pos[free_pt][0]][1]=0;
	}
	else{
		int i;
		for(i=pos[p][0];i<=pos[p][1];i++){
			poly[(pos[free_pt][0]-pos[p][0]+i)][0]=c*poly[i][0];  //multiplying coefficients by c
			poly[(pos[free_pt][0]-pos[p][0]+i)][1]=poly[i][1];    // storing exponents
		}
	}
	pos[free_pt][1]=pos[free_pt][0]+pos[p][1]-pos[p][0];
	free_pt++;
	return (free_pt-1);
}

//function to multiply a-th and b-th polynomial
int mult(int a,int b){
	printf("HI");
	if(isZero(a) || isZero(b)){ //if either is zero returning a zero polynomial
		printf("HI");
		pos[free_pt][0]=pos[free_pt-1][1]+1;
		pos[free_pt][1]=pos[free_pt][0];
		int p=pos[free_pt][0];
		poly[p][0]=0.0;
		poly[p][1]=0.0;
	}
	else{
		printf("Hi");
		int i,j,k=0;
		double sum;
		int bega=pos[a][0];
		int enda=pos[a][1];
		int begb=pos[b][0];
		int endb=pos[b][1];
		printf("Hi");
		int p=pos[free_pt-1][1]+1; //denotes the start of the new polynomial
		int max=(poly[bega][1]>poly[begb][1])?poly[bega][1]:poly[begb][1]; //maximum of degree of the two polynomials 
		int min=(poly[enda][1]>poly[endb][1])?poly[enda][1]:poly[endb][1]; //minimum of degree of the two polynomials 
		int na=pos[a][1]-pos[a][0]+1;// number of terms in a
		int nb=pos[b][1]-pos[b][0]+1;// number of terms in b
		printf("Hi");
		pos[free_pt][0]=p;
		//double new[na*nb][2];
		double** new=(double**)malloc((na*nb)*2*sizeof(int));
		for(i=0;i<na;i++){
			for(j=0;j<nb;j++){
				printf("%d %d",i,j);
				new[k][0]=poly[bega+i][0]*poly[begb+j][0];
				new[k][1]=poly[bega+i][1]+poly[begb+j][1];
				k++;
			}
		}
		for(i=max;i>=min;i--){
			sum=0.0;
			for(j=0;j<na*nb;j++){
				if(new[j][1]==i)
					sum+=new[j][0];
			}
			if(sum!=0.0){
				poly[p][0]=sum;
				poly[p][1]=i;
				p++;
			}
		}
	}
	free_pt++;
	return (free_pt-1);	
}