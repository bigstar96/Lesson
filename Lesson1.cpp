#include <iostream>

void PrintArray(int input[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << input[i] << " ";
    }

    std::cout << std::endl;
}
void Swap(int& value1, int& value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

// Quick Sort
// Time Complexity : O(c n log n) c = 상수, 최악의 경우 c가 n이 될 수도 있음
// Space Complexity : O(n)

void QuickSort(int input[],int left, int right)
{
    int i = left;
    int j = right;
    int pivot = input[(left + right) / 2];

    do
    {
        while (input[i] < pivot)
        {
            i++;
        }
        while (input[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            Swap(input[i], input[j]);
            i++;
            j--;
        }
    } while (i <= j);

    // base case & recursive case
    if (left < j)
    {
        QuickSort(input, left, j);
    }
    if (right > i)
    {
        QuickSort(input, i, right);
    }
    
}

int main()
{
    const int SIZE{ 5 };
    int array[SIZE]{ 8,7,2,3,1 };
    int tempArray[SIZE]{};

    // SORT
    //SequentialSort(array, SIZE);
    //SelectionSort(array, SIZE);
    //BubbleSort(array, SIZE);
    //InsertionSort(array, SIZE);
    //MergeSort(array, 0, SIZE - 1, tempArray);

    QuickSort(array, 0, SIZE-1);

    PrintArray(array, SIZE);
}