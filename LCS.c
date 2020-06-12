#include<stdio.h>
#include<string.h>

int max(int a, int b)					//declaration of max function
{
	return(a>b?a:b);
}

int lcs(char *x,char *y, int m,int n)	//declaration of lcs function
{
	int mat[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				mat[i][j]=0;			//Setting values of first row and first column to zero
			}
			else if(x[i-1]==y[j-1])
			{
				mat[i][j] = mat[i-1][j-1] + 1;
			}
			else
			{
				mat[i][j] = max(mat[i][j-1],mat[i-1][j]);
			}
		}
	}
	return mat[m][n];					//return lcs length
}

int main()								//declaration of main function
{
	char x[] = "SANAF";				//declaration of First String
	char y[] = "SANA";				//declaration of Second String
	int m = strlen(x);
	int n = strlen(y);
	int ans = lcs(x,y,m,n);
	printf("First String is : %s\n",x);
	printf("Second String is : %s\n",y);
	printf("Length of Longest Common Subsequence is : %d",ans);
	return 0;
}

/* OUTPUT :-
 * First String is : SANAF
 * Second String is : SANA
 * Length of Longest Common Subsequence is : 4
 * */
