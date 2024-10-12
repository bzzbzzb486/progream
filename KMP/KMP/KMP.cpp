#include<iostream>
#include<string>
using namespace std;

const int MAX_SIZE = 10;


void Next_Init(char* cmp_arr,int* next,int len)
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	while (i <= len)
	{
		if (j == 0 || cmp_arr[i] == cmp_arr[j])
		{
			next[++i] = ++j;
		}
		else
		{
			j = next[j];
		}
	}
}


int main()
{
	char cmp_arr[MAX_SIZE + 1] = "abaacaabab";
	int next[MAX_SIZE+1] = { 0 };
	string base_arr;
	cin >> base_arr;
	bool IsSame = false;
	int i = 0;
	int j = 0;
	int begin;
	Next_Init(cmp_arr,next,MAX_SIZE);

	while (i < base_arr.size())
	{
		if (base_arr[i] == cmp_arr[j] || j == 0)
		{
			i++;
			j++;
			if (j >= MAX_SIZE)
			{
				IsSame = true;
				begin = i - j;
			}
		}
		else
		{
			j = next[j];
		}
	}

	if (IsSame)
		cout << "The first postion is " << begin << endl;

	return 0;
}