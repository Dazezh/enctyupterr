#include "az.hpp"

std::string a1z26Crypt(std::string input) // encryption algorithm a1z26
{   
    const char *arrayOfAbc[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    for (int i = 0; i < input.size(); i++)
    {
        for (int z = 0; z < 26; z++)
        {
            if (input[i] == *arrayOfAbc[z])
            {
                std::cout << z + 1 << " ";
            }
        }

        if (input[i] == *" ")
        {
            std::cout << " ";
        }
    }
    
    return input;
}

std::string a1z26Decrypt(std::string input) // decryption algorithm a1z26
{
    const char *arrayOfAbc[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    
    std::string temp;
    char symbol;

    for (int i = 0; i < input.size(); i++)
    {   
        if (input[i] != *" ")
        {
            symbol = input[i];
            temp += symbol; 
            if (input[i + 1] == *" " || i == input.size() - 1)
            {
                if (stoi(temp) < 26 && stoi(temp) > 0 && !isalpha(symbol))
                {
                    std::cout << arrayOfAbc[stoi(temp) - 1];
                    temp = "";
                }
                else 
                {
                    std::cerr << " Hey, hey, hey |^-^| Don't fool me, only 26 letters :D " << std::endl;
                    break;
                }
            }
        }
        
        if (input[i] == *" " && input[i + 1] == *" ")
        {
            std::cout << " ";
        }
    }

    return input;
}