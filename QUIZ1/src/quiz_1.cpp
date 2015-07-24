/*
 * quiz_1.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: lauriaclarke
 */

#include <iostream>
#include <cmath>

using namespace std;

//void encipher(char phrase[], char alphabet[], char cipher[], int l1, int l2);
int* mergeSortedArrays(int A[], int B[], int sizeA, int sizeB);
void displayIntArray(int arr[], int size);

int main()
{
	int* C;

	int A[] =
	{ 1, 5, 8, 12 };
	int B[] =
	{ 3, 6, 9, 11 };

	C = mergeSortedArrays(A, B, 4, 4);

	displayIntArray(C, 8);

	return 0;
}

int* mergeSortedArrays(int A[], int B[], int sizeA, int sizeB)
{
	int sizeC;
	int* C;
	int* D;
	int indexC = 0;
	int smallIndex;
	int largeIndex;

	if( sizeA < sizeB)
	{
		smallIndex = sizeA;
		largeIndex = sizeB;
		D = B;
	}
	else
	{
		smallIndex = sizeB;
		largeIndex = sizeA;
		D = A;
	}


	sizeC = sizeA + sizeB;
	C = new int[sizeC];

		for(int i = 0; i < smallIndex; i++)
		{
			if (A[i] <= B[i])
			{
				C[i+indexC] = A[i];
				C[i+indexC+1] = B[i];

				indexC++;
			}
			else
			{
				C[i+indexC] = B[i];
				C[i+indexC+1] = A[i];

				indexC++;
			}
		}


	//if(sizeA != sizeB)
	//{
		for(int k = (2 * smallIndex); k < sizeC; k++)
		{
          C[k] = D[k - smallIndex];
		}
	//}


	return C;
}



void displayIntArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] " << arr[i] << "\n";
	}
}






/*
 int main()
 {

 char phrase[] =
 { 'a', 'b', 's', 't', 'e', 'm', 'i', 'o', 'u', 's', '\0' };
 char alphabet[] =
 { 'a', 'e', 'i', 'o', 'u', '\0' };
 char cipher[] =
 { 'q', 'w', 'r', 't', 'y', '\0' };


 int A[] = { 1, 5, 8, 12 };
 int B[] = { 3, 6, 9, 11, 15, 45 };

 encipher(phrase, alphabet, cipher, 11, 6);
 mergeSortedArrays(A, B, 4, 6);

 return 0;
 }


 //////////////////////////////////////////////////////////////////////////////
 void encipher(char phrase[], char alphabet[], char cipher[], int l1, int l2)
 {
 for (int k = 0; k < l1; k++)
 {
 cout << phrase[k] << "\n";
 }

 for (int i = 0; i < l1; i++)
 {
 for (int j = 0; j < l2; j++)
 {
 if (alphabet[j] == phrase[i])
 {
 phrase[i] = cipher[j];
 }
 }
 }

 for (int l = 0; l < l1; l++)
 {
 cout << phrase[l] << "\n";
 }

 }

 */