#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Command
{
	std::string com;
	int val = 0;
};

 Command parse(std::string str)
{ 
	Command newCom;
	int i = 0;
	std::string number;

	while (str[i] != ' ')
	{
		newCom.com += str[i];
		i++;
	}

	while (i <= str.length())
	{
		number.push_back(str[i]);
			i++;
	}

	newCom.val = stoi(number);
	return newCom;
 }

int main()
{

	std::string path("inputTwo.txt");
	int depth = 0;
	int horPos = 0;
	int aim = 0;

	std::ifstream in(path); 
	std::vector<Command> commandList;
	Command c;

	std::string line;
	if (in.is_open())
	{
		while (getline(in, line))
		{
			commandList.push_back(parse(line));
		}
	}
		else std::cout << "File not found";
	in.close();     

	std::vector<Command>::const_iterator iter;
	iter = commandList.begin();
	/*while(iter != commandList.end())
	{
		if ((*iter).com == "forward")
			horPos += (*iter).val;
		else if ((*iter).com == "down")
			aim += (*iter).val;
		else aim -= (*iter).val;
		iter++;
	}*/

	while (iter != commandList.end())
	{
		if ((*iter).com == "forward")
		{
			horPos += (*iter).val;
			depth += aim * (*iter).val;
		}
		else if ((*iter).com == "down")
			aim += (*iter).val;
		else aim -= (*iter).val;
		iter++;
	}

	std::cout << depth*horPos<< "\n";
	system("pause");
	return 0;
}