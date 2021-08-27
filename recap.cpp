#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int changeStringToNumber(string line)
{
	string temp = "";

	for(int i = 0; i < line.size(); i++)
	{
		if (line[i] == ',')
		{
			break;
		}
		else temp += line[i];
	}
	stringstream os(temp);
	int number = 0;
	os >> number;
	os.clear();
	return number;
}

int main()
{
	ifstream inputFile;
	inputFile.open("data.txt");
	int row = 0,index = 0;
	string line = "";

	while (getline(inputFile,line)) row++;
	inputFile.close();
	string*** arr = new string**[row];

	inputFile.open("data.txt");
	while (getline(inputFile,line))
	{
		arr[index] = new string*[1];
		arr[index++][0] = new string(line);
	}
	inputFile.close();

	for ( int i = 0; i < row - 1; i++)
	{
		for (int j = 0; j < row - i - 1; j++)
		{
			if (changeStringToNumber(*arr[j][0]) > changeStringToNumber(*arr[j+1][0]))
			{
				string* tmp = arr[j][0];
				arr[j][0] = arr[j+1][0];
				arr[j+1][0] = tmp;
			}
		}
	}
	for (int i = 0; i < row ; cout<<*arr[i][0]<<"\n",delete [] arr[i++]);
	delete [] arr;
	arr = NULL;
	return 0;
}