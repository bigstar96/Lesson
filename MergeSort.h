#pragma once
#include "MergeSort.h"

void PrintArray(int input[], int size);
void Swap(int& value1, int& value2);
void SequentialSort(int input[], int size);
void SelectionSort(int input[], int size);
void BubbleSort(int input[], int size);
void MyBubbleSort(int input[], int size);
void InsertionSort(int input[], int size);
void Merge(int input[], int start, int half, int end, int temp[]);
void MergeSort(int input[], int start, int end, int temp[]);
