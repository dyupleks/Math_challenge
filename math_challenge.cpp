#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input = "1 1 + 1 + 1 +";
	//string input = "2 3 + 2 + 7 *";
	//string input = "2 7 * 2 + 3 +";
	int num[4];
	int k = 0;
	int operators[3];
	int p = 0;
	int total = 0;
	int total_ = 0;
	cout << "Input: " << input << endl;
	string str;

	//cout << "Detected numbers: " << endl;
	for (int i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]))
		{
			str = input[i];
			num[k] = stoul(str, 0, 10);
			//cout << num[k];
			k = k + 1;

		}

		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			operators[p] = input[i];
			p = p + 1;
			
		}
	}
	

	int total_multi = 0;
	int total_subst = 0;

	for (int i = 0; i < p; i++)
	{ 
		if (operators[i] == 42)  //42 is multiplication in ASCII table(decimal)
		{
			total_multi = num[i] * num[i + 1];
			num[i] = 0;
			num[i + 1] = 0;
		}
		if (operators[i] == 47)  // 47 is division in ASCII table (decimal)
		{
			total_subst = num[i] / num[i + 1];
			num[i] = 0;
			num[i + 1] = 0;
		}
	}
	int ss = size(num);
	
	for (int i = 0; i < ss; i+=2) 
	{
		if (operators[i] == 43) // 43 is plus in ASCII table(decimal)
		{
			total_ = total_ + num[i] + num[i+1];
		}
		if (operators[i] == 45) // 45 is minus in ASCII table(decimal)
		{
			total_ = total_ + num[i] - num[i+1];
		}
	}

	total = total_ + total_multi + total_subst; 

	cout << "Output: " << total << endl;




	
	

	
	
}