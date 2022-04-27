#include <iostream>
#include <string>

int main()
{
    std::string word;
    /*while (std::cin >> word)
        std::cout << word << std::endl;
	*/
        
    std::string line;
    while (std::getline(std::cin, line))
		if (!line.empty())
			std::cout << line << std::endl;
		else
			break;
    

	system("pause");
    return 0;
}