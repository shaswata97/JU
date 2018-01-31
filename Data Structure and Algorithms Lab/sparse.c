#include <stdio.h>
#include <stdlib.h>

double mat[8000][3];
int pos[400];
int free_pt=0;

int readMat();
int inMat(int p,int i,int j);
void writeMat(int p);
int multC(int p, double c);
int add(int p1,int p2);
int mult(int p1,int p2);
int transpose(int p);
int main(){
	int ch,pos1,pos2,res,flag=1;
	printf("Enter your choice\n");
	while(flag==1){
		printf("1.Enter a matrix\n2.Add 2 matrices\n3.Multiply a matrix with a constant\n4.Multiply 2 matrices\n5.Transpose of a matrix\n6.Stop\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				pos1=readMat();
				printf("Your matrix is\n");
				writeMat(pos1);
				break;
			case 2:
				printf("Enter position of 2 matrices\n");
				scanf("%d",&pos1);
				printf("matrix 1\n");
				writeMat(pos1);
				scanf("%d",&pos2);
				printf("matrix 2\n");
				writeMat(pos2);
				res=add(pos1,pos2);
				printf("resultant matrix \n");
				writeMat(res);
				break;
			case 3:
				printf("Enter position of a matrix\n");
				scanf("%d",&pos1);
				printf("Your matrix\n");
				writeMat(pos1);
				printf("Enter a constant\n");
				double c;
				scanf("%lf",&c);
				res=multC(pos1,c);
				printf("resultant matrix\n");
				writeMat(res);
				break;
			case 4:
				printf("Enter positon of 2 matrices\n");
				scanf("%d",&pos1);
				printf("matrix 1\n");
				writeMat(pos1);
				scanf("%d",&pos2);
				printf("matrix 2\n");
				writeMat(pos2);
				res=mult(pos1,pos2);
				printf("resultant matrix %d\n",res);
				writeMat(res);
				break;
			case 5:
				printf("Enter position of a matrix\n");
				scanf("%d",&pos1);
				printf("Your matrix\n");
				writeMat(pos1);
				res=transpose(pos1);
				printf("resultant matrix\n");
				writeMat(res);
				break;
			case 6:
				flag=0;
				printf("Thank you!");
				break;
			default:
				printf("Wrong choice\n");
		}
	}
}


int readMat(){
	int r,c,p,x,y,i,ch=1;
	double val;
	printf("Enter number of rows and columns\n");
	scanf("%d",&r);
	scanf("%d",&c);
	p=free_pt;
	if(free_pt==0)
		pos[0]=0;
	else
		pos[free_pt]=pos[free_pt-1]+mat[pos[free_pt-1]][2]+1;
	mat[pos[free_pt]][0]=r*1.0;
	mat[pos[free_pt]][1]=c*1.0;
	mat[pos[free_pt]][2]=0;
	i=pos[free_pt]+1;
	do{
		printf("Enter coordinates of non zero value\n");
		scanf("%d",&x);
		scanf("%d",&y);
		if(x<0 || x>=r || y<0 || y>=c){
			printf("Incorrect coordinates\n");
		}
		else{
			printf("Enter value\n");
			scanf("%lf",&val);
			if(val==0.0)
				printf("Enter non zero value\n");
			else{
				mat[i][0]=x*1.0;
				mat[i][1]=y*1.0;
				mat[i][2]=val;
				i++;
				mat[pos[free_pt]][2]++;
			}
		}
		printf("Enter 0 to stop or any other number to continue\n");
		scanf("%d",&ch);
	}while(ch!=0);
	free_pt++;
	return (free_pt-1);
}

//to check if (i,j)-th element is in p-th matrix
int inMat(int p,int i,int j){
	int x=pos[p]+1, y=x+mat[x-1][2], res=-1,k;
	for(k=x;k<=y;k++){
		if(mat[k][0]==i && mat[k][1]==j){
			res=k;
			break;
		}
	}
	return res;
}

//to print the matrix
void writeMat(int p){
	int x=pos[p];
	int r=(int)mat[x][0];
	int c=(int)mat[x][1];
	int i,j,res=-1;
	double z=0*1.0;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			res=inMat(p,i,j);
			if(res!=-1)
				printf("%lf   ",mat[res][2]);
			else
				printf("%lf   ",z);
		}
		printf("\n");
	}
}

//multiply a matrix with a constant
int multC(int p, double c){
	int start=pos[p];
	int startNew=pos[free_pt-1]+mat[pos[free_pt-1]][2]+1;
	int i=0;
	mat[startNew][0]=mat[start][0];
	mat[startNew][1]=mat[start][1];
	if(c==0.0){
		mat[startNew][2]=0.0;
	}
	else{
		mat[startNew][2]=mat[start][2];
		for(i=1;i<=mat[start][2];i++){
			mat[startNew+i][0]=mat[start+i][0];
			mat[startNew+i][1]=mat[start+i][1];
			mat[startNew+i][2]=c*mat[start+i][2];
		}
	}
	pos[free_pt]=startNew;
	free_pt++;
	return (free_pt-1);
}

//adding 2 matrices
int add(int p1, int p2){
	int start1=pos[p1];
	int start2=pos[p2];
	int start3=pos[free_pt-1]+mat[pos[free_pt-1]][2]+1;
	int r1=(int)mat[start1][0];
	int r2=(int)mat[start2][0];
	int c1=(int)mat[start1][1];
	int c2=(int)mat[start2][1];
	printf("%d  %d  %d  %d\n",r1,c1,r2,c2);
	if(r1!=r2 || c1!=c2){
		printf("Dissimilar dimensions\tExiting\n");
		return -1;
	}
	else{
		pos[free_pt]=start3;
		mat[start3][0]=mat[start1][0];
		mat[start3][1]=mat[start1][1];
		mat[start3][2]=0;
		int x=0,i,res;
		for(i=start1+1;i<=start1+mat[start1][2];i++){
			res=inMat(p2,mat[i][0],mat[i][1]);
			if(res!=-1 && mat[res][2]!=-mat[i][2]){
				mat[start3][2]++;
				x++;
				mat[start3+x][0]=mat[i][0];
				mat[start3+x][1]=mat[i][1];
				mat[start3+x][2]=mat[res][2]+mat[i][2];
			}
			else if(res==-1){
				mat[start3][2]++;
				x++;
				mat[start3+x][0]=mat[i][0];
				mat[start3+x][1]=mat[i][1];
				mat[start3+x][2]=mat[i][2];
			}
		}
		for(i=start2+1;i<=start2+mat[start2][2];i++){
			if(inMat(start3,mat[i][0],mat[i][1])==-1){
				mat[start3][2]++;
				x++;
				mat[start3+x][0]=mat[i][0];
				mat[start3+x][1]=mat[i][1];
				mat[start3+x][2]=mat[i][2];
			}
		}
		free_pt++;
		return (free_pt-1);
	}
}

//multiplying two matrices
int mult(int p1, int p2){
	int start1=pos[p1];
	int start2=pos[p2];
	int start3=pos[free_pt-1]+mat[pos[free_pt-1]][2]+1;
	if(mat[start1][1]!=mat[start2][0]){
		printf("Incorrect dimensions\tExiting!!!\n");
		return -1;
	}
	else{
		mat[start3][0]=mat[start1][0];
		mat[start3][1]=mat[start2][1];
		if(mat[start1][2]==0.0 || mat[start2][2]==0.0)
			mat[start3][2]==0.0;
		else{
			int k=0,n=(int)(mat[start1][0]*mat[start2][1]);
			double** new=(double**)malloc(n*sizeof(double*));
			for(k=0;k<n;k++)
				new[k]=(double*)malloc(3*sizeof(double));
			for(k=0;k<n;k++){
				new[k][0]=0.0;
				new[k][1]=0.0;
				new[k][2]=0.0;
			}
			int i=0,j=0,res,res2,x=0;
			for(i=start1+1;i<=start1+mat[start1][2];i++){
				res=inMat(p2,mat[i][1],mat[i][0]);
				if(res!=-1){
					for(j=0;j<x;j++){
						if(new[j][0]==mat[i][0] && new[j][1]==mat[res][1]){
							break;
						}
					}
					if(j==x){
						//printf("%d  %d  %d  %d  %d\n",new[j][0],x,mat[i][0],res,mat[res][1]);
						new[j][0]=mat[i][0];
						//printf("Hi6\n");
						new[j][1]=mat[res][1];
						//printf("Hi7\n");
						new[j][2]=mat[i][2]*mat[res][2];
					}
					else{
						new[j][2]+=mat[i][2]*mat[res][2];
						//printf("Hi9\n");
					}
					x++;
					//printf("Hi0\n");
				}
			}
			mat[start3][2]=x;
			//printf("Hi11\n");
			for(i=0;i<x;i++){
				mat[start3+1+i][0]=new[i][0];
				//printf("Hi12\n");
				mat[start3+1+i][1]=new[i][1];
				//printf("Hi13\n");
				mat[start3+1+i][2]=new[i][2];
				//printf("Hi14\n");
			}
		}
		pos[free_pt]=start3;
		//printf("Hi15\n");
		free_pt++;
		return (free_pt-1);
	}	
}

//transposing a matrix
int transpose(int p){
	int start=pos[p];
	int startNew=pos[free_pt-1]+mat[pos[free_pt-1]][2]+1;
	int i=0;
	mat[startNew][0]=mat[start][0];
	mat[startNew][1]=mat[start][1];
	mat[startNew][2]=mat[start][2];
	for(i=1;i<=mat[start][2];i++){
		mat[startNew+i][0]=mat[start+i][1];
		mat[startNew+i][1]=mat[start+i][0];
		mat[startNew+i][2]=mat[start+i][2];
	}
	pos[free_pt]=startNew;
	free_pt++;
	return (free_pt-1);
}