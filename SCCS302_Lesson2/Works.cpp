#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "Works.h"

void ws11() {
	bool rng = false;
	int data[15][3], datar, datac, total[15],nbool;
	datar = sizeof(data) / sizeof(data[0]);
	datac = sizeof(data[0]) / sizeof(int);
	const char* subject[3]
		= { "Thai", "Math", "Com" };
	//Input Unit
	printf_s("Use Fixed Random Number [1=Yes/0=No] ? : ");
	scanf_s("%d",&nbool);
	rng = nbool;
	for (int i = 0;i < datar;i++) {
		for (int j = 0; j < datac; j++)
		{
			if (rng) {
				printf("Enter Score %s std-%d : ", subject[j], i + 1);
				data[i][j] = 10 + (rand() % 90);
				printf("%d\n", data[i][j]);
			}
			else {
				printf("Enter Score %s std-%d : ", subject[j], i + 1);
				scanf_s("%d", &data[i][j]);
				//printf("\n");
			}
		}
		printf("\n");
	}

	//List Unit
	printf_s("No.   Thai   Math   Com    Total\n");
	for (int i = 0; i < datar; i++)
	{
		if(i<9){ printf(" %d    ", i + 1); }else{ printf("%d    ", i + 1); }
		for (int j = 0; j < datac; j++)
		{
			if(i<9){ printf_s("%d     ", data[i][j]); }else{ printf_s("%d     ", data[i][j]); }
			if (j == 2) {
				total[i] = data[i][0] + data[i][1] + data[i][2];
				printf_s("%d", total[i]);
			}
		}
		printf_s("\n");
	}

	//Average Unit
	printf_s(
		"------Average Score------\n    Highest is %d\n    Lowest is %d\n-------------------------",
		arrhighest(total, 15), arrlowest(total, 15));
}

int arrlowest(int arr[], int size) {
	int lowest = arr[0];
	for (int i = 1; i < size; i++)
	{
		lowest = lowest > arr[i] ? arr[i] : lowest;
	}
	return lowest;
}

int arrhighest(int arr[], int size) {
	int lowest = arr[0];
	for (int i = 1; i < size; i++)
	{
		lowest = lowest < arr[i] ? arr[i] : lowest;
	}
	return lowest;
}

void test() {
	int arr[] = { 10,20,30,40,50,60 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
}

int arrsize(int arr[]) {
	return sizeof(arr) / sizeof(arr[0]);
}