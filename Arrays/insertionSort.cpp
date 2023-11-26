#include <iostream>
using namespace std;

void sort(int nums[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int insert = nums[i];
        int j = i - 1;
        while(j >= 0)
        {
            if (nums[j] > insert)
            {
                nums[j + 1] = nums[j];
            }
            else
            {
                break;
            }
            j-=1;
        }
        nums[j + 1] = insert;
    }
}

void display(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    int nums[7] = {5, 11, 2, 21, 7, 10, 37};
    cout << "Given Array : " << endl;
    display(nums, 7);
    cout << "Sorted Array : " << endl;
    sort(nums, 7);
    display(nums, 7);
    return 0;
}