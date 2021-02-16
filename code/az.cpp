#include "az.hpp"

std::string a1z26Crypt(std::string input) // encryption algorithm a1z26
{   
    const char *letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    for (int i = 0; i < input.size(); i++)
    {
        if (isalpha(input[i]))
        {
            for (int z = 0; z < 26; z++)
            {
                if (input[i] == *letters[z])
                {
                    std::cout << z + 1 << " ";
                }
            }
        }
        else
        {
            std::cout << input[i];
        }
    }
    
    return input;
}

std::string a1z26Decrypt(std::string input) // decryption algorithm a1z26
{
    const char *letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    
    std::string temp;
    char symbol;

    for (int i = 0; i < input.size(); i++)
    {   
        if (isdigit(input[i]))
        {
            symbol = input[i];
            temp += symbol; 
            if (input[i + 1] == *" " || i == input.size() - 1)
            {
                if (stoi(temp) < 26 && stoi(temp) > 0)
                {
                    std::cout << letters[stoi(temp) - 1];
                    temp = "";
                }
                else 
                {
                    std::cerr << " Hey, hey, hey |^-^| Don't fool me, only 26 letters :D " << std::endl;
                    throw -1;
                }
            }
        }
        else if (input[i] == *" " && input[i + 1] == *" ")
        {
            std::cout << " ";
        }
        else if (!isspace(input[i]) || input[i - 1] == *" ")
        {
            std::cout << input[i];
        }
    }

    return input;
}