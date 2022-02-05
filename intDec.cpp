#include <iostream>
#include <string.h>

typedef uint32_t uint; //max length of number 4294967295 digits

std::string reverseNumber(std::string num);
bool isGreaterOrEqual(std::string num1, std::string num2);
std::string addition(std::string num1, std::string num2);
std::string subtraction(std::string num1, std::string num2);

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: ./intDec number1 number2\n";
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		for (uint j = 0, length = strlen(argv[i]); j < length; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				std::cout << "Usage: ./intDec number1 number2\n";
				return 2;
			}
		}
	}
	std::string number1 = argv[1];
	std::string number2 = argv[2];
	std::cout << subtraction(number1, number2) << "\n";
	return 0;
}

std::string reverseNumber(std::string num)
{
	for (uint i = 0; i < num.size() / 2; i++)
	{
		char tmp = num[num.size() - 1 - i];
		num[num.size() - 1 - i] = num[i];
		num[i] = tmp;
	}
	return num;
}

bool isGreaterOrEqual(std::string num1, std::string num2)
{
	uint length;
	if (num1.size() < num2.size())
		length = num2.size();
	else
		length = num1.size();
	num1 = reverseNumber(num1);
	num2 = reverseNumber(num2);
	for (uint i = 0; i < length; i++)
	{
		if (i >= num1.size())
			num1 += 0 + '0';
		if (i >= num2.size())
			num2 += 0 + '0';
	}
	num1 = reverseNumber(num1);
	num2 = reverseNumber(num2);
	for (uint i = 0; i < num1.size(); i++)
	{
		if (num1[i] < num2[i])
			return false;
	}
	return true;
}

std::string addition(std::string num1, std::string num2)
{
	if (num1.size() < num2.size())
	{
		std::string tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	num1 = reverseNumber(num1);
	num2 = reverseNumber(num2);
	std::string sum = "";
	int memory = 0;
	for (uint i = 0; i < num1.size(); i++)
	{
		int digit1 = num1[i] - '0';
		int digit2;
		if (i < num2.size())
			digit2 = num2[i] - '0';
		else
			digit2 = 0;
		sum += (digit1 + digit2 + memory) % 10 + '0';
		memory = (digit1 + digit2 + memory > 9) ? 1 : 0;
		if (i == num1.size() - 1 && memory == 1)
			sum += memory + '0';
	}
	return reverseNumber(sum);
}

std::string subtraction(std::string num1, std::string num2)
{
	if (isGreaterOrEqual(num2, num1))
	{
		std::string tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	num1 = reverseNumber(num1);
	num2 = reverseNumber(num2);
	std::string difference = "";
	int memory = 0;
	for (uint i = 0; i < num1.size(); i++)
	{
		int digit1 = num1[i] - '0';
		int digit2;
		if (i < num2.size())
			digit2 = num2[i] - '0';
		else
			digit2 = 0;
		difference += (digit1 - digit2 - memory >= 0) ? (digit1 - digit2 - memory) + '0' : 10 + (digit1 - digit2 - memory) + '0';
		memory = (digit1 - digit2 - memory < 0) ? 1 : 0;
		if (difference[num1.size() - 1] == '0')
			difference.erase(num1.size() - 1, 1);
	}
	return reverseNumber(difference);
}
