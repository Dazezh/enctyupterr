#include "vigener.hpp"
#define numberOfLetters 26

std::string vigenerCrypt(std::string key, std::string input)
{
    bool encrypt = true; // variable for start encrypt 
    const char *arrayOfAbc[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    for (char i : key)
    {
        if ((isspace(i) || isdigit(i)) && encrypt)
        {
            std::cerr << "Hey! I said no spaces and only letters! I don’t play like that :(" << std::endl;
            std::cout << "I will not encrypt anything! I'm offended!" << std::endl;
            encrypt = false;
        }
    }

    if (encrypt == true)
    {
        int z = 0; // variable for key count
        
        for (int i = 0; i < input.size(); i++)
        {
            if (isalpha(input[i])) 
            {
                std::cout << arrayOfAbc[(input[i] + key[z]) % numberOfLetters];

                if (isalpha(key[z + 1]))
                {
                    z++;
                }
                else
                {
                    z = 0;
                }
            }

            if (!isalpha(input[i]))
            {
                std::cout << input[i];
            }
        }
    }
    
    return input;
    return key;
}

std::string vigenerDecrypt(std::string key, std::string input)
{
    bool decrypt = true; // variable for start decrypt 
    const char *arrayOfAbc[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    for (char i : key)
    {
        if ((isspace(i) || isdigit(i)) && decrypt)
        {
            std::cerr << "Hey! I said no spaces and only letters! I don’t play like that :(" << std::endl;
            std::cout << "I will not decrypt anything! I'm offended!" << std::endl;
            decrypt = false;
        }
    }

    if (decrypt) // if true
    {
        int z = 0; // variable for key count
        
        for (int i = 0; i < input.size(); i++)
        {
            if (isalpha(input[i])) 
            {
                std::cout << arrayOfAbc[(input[i] + numberOfLetters - key[z]) % numberOfLetters];

                if (isalpha(key[z + 1]))
                {
                    z++;
                }
                else
                {
                    z = 0;
                }
            }

            if (!isalpha(input[i]))
            {
                std::cout << input[i];
            }
        }
    }
    
    return key;
    return input;
}