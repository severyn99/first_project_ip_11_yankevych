	#include<iostream>
	#include<math.h>
	#define n 5
	

	using namespace std;
	
		class Matrix
	{
	private:
		int a[n][n];
		int sum;
		int i, j, k, c, max;
	public:
		void matrix_input();
		void matrix_output();
		void matrix_sorting();
		void raw_max_and_summation();
	};
	
		void Matrix::matrix_input()  //ввід матриці
	{
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << "Please, enter the element [" << i+1 << ";" << j+1 << "]";
				cin >> a[i][j];
				cout << endl;
			}
		}
	}
	
		void Matrix::matrix_output() //вивід матриці
	{
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (j == 0) cout << endl;
				cout << a[i][j] << "\t";
			}
		}
	}
	
	void Matrix::matrix_sorting() //сортування обміном
{
  for(j = 0; j < n; j++) {
   for(k = n-1; k >=0 ; k--) {
     for(i = 0; i < k; i++)	  {
 	    if(a[i][j] < a[i+1][j])  	{
	  	  c = a[i][j];
	      a[i][j] = a[i+1][j];
	      a[i+1][j] =c;
	  	}
	  }
   }
   
  }
 }
	
	 void Matrix::raw_max_and_summation() //найбільший елемент рядку і їх сума
	 {
	 cout << endl;
	 sum = 0;
	 for (i = 0; i < n; i++) {
	   max = -100;
		for (j = 0; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		cout << " Max element of raw " << i + 1 << " is " << max << endl;
		sum += max;
	 }
	 cout << " Sum of elements is " << sum;
 }

 int main() //головна функція
	{	Matrix A;
		A.matrix_input();
		cout << endl;
		cout << "Entered matrix:\n";
		A.matrix_output();
		cout << endl;
		A.matrix_sorting();
		cout <<"\nNew matrix:\n";
		A.matrix_output();
		cout << endl;
		A.raw_max_and_summation();
		cout << endl;
	}
	_getch()
	