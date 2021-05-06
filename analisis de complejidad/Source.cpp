#include <iostream>
#include <cmath>
using namespace std;

int main()
{
		//EX. 8
		int n, a;
		cout << "Enter n = ";
		cin >> n;
		for (int i = 1; i <= floor(n / 2); i++)
		{
			a = n - i;
		}
		cout << " a = " << a << endl;

		/*
		Enter n = 10
		a = 5
		*/	return 0;
}


	/*EX. 6*/
	//int a, n;

	//cout << "Enter n: ";
	//cin >> n;
	//for (int i = 3; i <= n - 1; i++)
	//	a = 3 * n + 2 * i - 1;

	//cout << "a = " << a << endl;
	///*
	//Enter n: 5
	//a = 22
	//*/

	////EX. 7
	//int max;
	//int a[] = { 1, 3, 4, 5, 9 };
	//int n;
	//cout << "Enter n: ";
	//cin >> n;


	//max = a[1];
	//for (int i = 2; i <= n; i++)
	//{
	//	if (max < a[i])
	//		max = a[i];
	//}

	//cout << "Max = " << max << endl;

	///*
	///*Enter n: 5
	//Max = 9
	//*/

//	EX. 8
	//int n, a;
	//cout << "Enter n = ";
	//cin >> n;
	//for (int i = 1; i <= floor(n / 2); i++)
	//{
	//	a = n - i;
	//}
	//cout << " a = " << a << endl;

	///*
	//Enter n = 10
	//a = 5
	//*/

//	//	EX. 9
//int n, a;
//cout << "Enter n: ";
//cin >> n;
//
//for (int i = 1; i < n; i++)
//{
//	for (int j = 1; j <= 2 * n; j++)
//	{
//		a = 2 * n + i * j;
//	}
//}
//cout << "a = " << a << endl;
//
///*Enter n: 12
//a = 288*/
//

//	//EX. 10
	//int n, x; 
	//int a[] = { 2, 4, 7, 8, 9, 10 }, b[] = { 1, 2, 3, 4, 5, 6 };


	//cout << "Enter n: ";
	//cin >> n;


	//for (int k = 2; k <= n; k++)
	//{
	//	for (int j = 1; j <= 3*n; j++)
	//	{
	//		x = a[k] - b[j];
	//	}
	//}
	//cout << " x = " << x << endl;
	///*Enter n: 3
 //x = 4
	//*/

	////	EX. 11
	//int k, n, x;
	//int a[] = { 2, 3, 4, 5, 6, 7, 8 }, b[] = { 1, 5, 9, 10, 15, 20 };

	//cout << "Enter n: ";
	//cin >> n;

	//for (int k = 1; k <= n-1; k++)
	//{
	//	for (int j = 1; j <= k + 1; j++)
	//	{
	//		x = a[k] + b[j];
	//	}
	//}
	//cout << " x = " << x << endl;
	///*Enter n: 3
	// x = 14
	//*/

//	ex 12 
//	int max = 0, n;
//	int a[] = { 1, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
//
//
//	cout << "Enter n: ";
//	cin >> n;
//
//
//	for (int k = 1; k <= n-1; k++)
//	{
//		max = a[k];
//		for (int i = k + 1; i <= n; i++)
//		{
//			if (max < a[i])
//				max = a[i];
//		}
//		a[k] = max;
//	}
//	cout << "max = " << max << endl;
//
//	/*Enter n: 5
//max = 9*/

//	//	EX. 13
//	int n, temp;
//	int a[] = { 5, 4, 7, 8, 8, 4, 1, 2, 4, 6 };
//	int size = sizeof(a) / sizeof(*a);
//	cout << "Enter n: ";
//	cin >> n;
//	
//	for (int i = 1; i <= n - 1; i++)
//	{
//		for (int j = i; j <= n; j++)
//		{
//			if (a[j] > a[i])
//			{
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < size; i++)
//		cout << "Index: " << i << ": " << a[i] << endl;
//	cout << endl;
//
///*
//Enter n: 5
//Index: 0: 5
//Index: 1: 8
//Index: 2: 8
//Index: 3: 7
//Index: 4: 4
//Index: 5: 4
//Index: 6: 1
//Index: 7: 2
//Index: 8: 4
//Index: 9: 6
//*/

	//// EX 14
//	int s, n;
//	int t = 0;
//	int a[] = { 1, 4, 8, 5, 6, 7, 4 };
//	cout << "Enter n: ";
//	cin >> n;
//
//		for (int i = 1; i <= n; i++)
//		{
//			s = 0;
//			for (int j = 1 ; j <= i; j++)
//			{
//				s = s + a[j];
//			}
//			t = t + pow(s, 2);
//		}
//
//		cout << "s = " << s << endl;
//		cout << "t = " << t << endl;
//
//		/*Enter n: 6
//s = 34
//t = 3034*/

//	//	EX 15
//	int r = 0;
//	int p, q;
//	int n, c[] = { 2, 4, 7, 8, 9, 10 };
//
//	cout << "Enter n: ";
//	cin >> n;
//
//	for (int i = 1; i <= n - 1; i++)
//	{
//		p = 1;
//		q = 1;
//
//		for (int j = i + 1; j <= n; j++)
//		{
//			p = p * c[j];
//			q = q * pow(c[j], 2);
//		}
//		r = p + q;
//	}
//	cout << "p = " << p << endl;
//	cout << "q = " << q << endl;
//	cout << "r = " << r << endl;
//
///*
//Enter n: 3
//p = 8
//q = 64
//r = 72
//*/

//	//	EX 16
//	int t = 0, s, n, r;
//	cout << "Enter n: ";
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		s = 0;
//		for (int j = 1; j <= i - 1; j++)
//		{
//			s = s + j * (i - j + 1);
//		}
//		r = pow(s, 2);
//	}
//	cout << "s = " << s << endl;
//	cout << "r = " << r << endl;
//
///*
//Enter n: 5
//s = 30
//r = 900
//*/

//	//	EX 17
//	int n, a = 0;
//	cout << "Enter n: ";
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= (i + 1) / 2; j++)
//		{
//			a += (n-i) * (n - j);
//		}
//	}
//	cout << "a = " << a << endl;
//
//	/*Enter n: 8
//a = 320*/