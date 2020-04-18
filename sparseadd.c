#include<stdio.h>

void main(){
	int a[20][20],b[20][20],sa[15][3],sb[15][3],sc[30][3],m,n,i,j,k;
	
	printf("\nEnter order of matrix(m*n) :");
	scanf("%d %d",&m,&n);
	
	//INPUT MATRIX 1
	printf("\nEnter elements of Matrix 1\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	//INPUT MATRIX 2
	printf("Enter elements of Matrix 2\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	// GENERATE SPARSE 1
	k=1;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]!=0){		// ENTER DATA OF ELEMENT IF ELEMENT!=0
				sa[k][0]=i;
				sa[k][1]=j;
				sa[k][2]=a[i][j];
				k++;
			}
		}
	}
	
	//specifying details of sparse matrix in first row
	sa[0][0]=m;
	sa[0][1]=n;
	sa[0][2]=k-1;
	
	
	//GENERATE SPARSE 2
	k=1;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(b[i][j]!=0){
				sb[k][0]=i;
				sb[k][1]=j;
				sb[k][2]=b[i][j];
				k++;
			}
		}
	}
	sb[0][0]=m;
	sb[0][1]=n;
	sb[0][2]=k-1;
	
	//Display Sparse Matrices
	printf("\nSparse Matrix 1\nRow\tColumn\tvalue\n");
	for(i=0;i<=sa[0][2];i++){
		for(j=0;j<=2;j++){
			printf("%d\t",sa[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\nSparse Matrix 2\nRow\tColumn\tvalue\n");
	for(i=0;i<=sb[0][2];i++){
		for(j=0;j<=2;j++){
			printf("%d\t",sb[i][j]);
		}
		printf("\n");
	}
	
	
	//add sparse matrix 1 & 2
	
	
	i=1;//for sparse matrix 1
	j=1;//for sm2
	k=1;//for sm sum
	
	
	// infinite loop that breaks when no elements are present in sm1 & sm2 to be transferred 
	// alternative for break (for(i=1,j=1;(i<=sa[0][2])||(j<=sb[0][2]);))
	
	for(;;){
		if(!((i==sa[0][2]+1)||(j==sb[0][2]+1))){
			if(sa[i][0]<sb[j][0]){		//row1<row2 enter first element
				sc[k][0]=sa[i][0];
				sc[k][1]=sa[i][1];
				sc[k][2]=sa[i][2];
				k++;
				i++;
			} else if(sa[i][0]>sb[j][0]){	//row1>row2 enter second element
				sc[k][0]=sb[j][0];
				sc[k][1]=sb[j][1];
				sc[k][2]=sb[j][2];
				k++;
				j++;
			}else {				//row1=row2 , compare columns
				if(sa[i][1]<sb[j][1]){		//col1<col2 enter first element
					sc[k][0]=sa[i][0];
					sc[k][1]=sa[i][1];
					sc[k][2]=sa[i][2];
					k++;
					i++;
				} else if(sa[i][1]>sb[j][1]){	//col1>col2 enter second element
					sc[k][0]=sb[j][0];
					sc[k][1]=sb[j][1];
					sc[k][2]=sb[j][2];
					k++;
					j++;
				} else {			//add both elements and enter
					sc[k][0]=sa[i][0];
					sc[k][1]=sa[i][1];
					sc[k][2]=sa[i][2]+sb[j][2];
					k++;
					i++;
					j++;
				}
			}
		}else if((i==sa[0][2]+1)){	// only second sparse matrix remains
			sc[k][0]=sb[j][0];
			sc[k][1]=sb[j][1];
			sc[k][2]=sb[j][2];
			k++;
			j++;
		} else {			// only first sparse matrix remains
			sc[k][0]=sa[i][0];
			sc[k][1]=sa[i][1];
			sc[k][2]=sa[i][2];
			k++;
			i++;
		}
		
		
		//printf("%d %d %d\t",sc[k][0],sc[k][1],sc[k][2]);
		if((i==sa[0][2]+1)&&(j==sb[0][2]+1)){
			break;
		}
	}
	
	//enter details of sum sparse matrix to first row
	sc[0][0]=m;
	sc[0][1]=n;
	sc[0][2]=k-1;
	
	
	//DISPLAY SUM SPARSE MATRIX
	printf("\nSparse Matrix Sum\nRow\tColumn\tvalue\n");
	for(i=0;i<=sc[0][2];i++){
		for(j=0;j<=2;j++){
			printf("%d\t",sc[i][j]);
		}
		printf("\n");
	}
	
}
