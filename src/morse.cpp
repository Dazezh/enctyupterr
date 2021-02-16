#include "morse.hpp"

std::string morseCrypt (std::string input)
{
    const char *letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    std::string morseLetters[26] = {"*-", "-***", "-*-*", "-**", "*", "**-*", "--*", "****", "**", "*---", "-*-", "*-**", "--", "-*", "---", "*--*", "--*-", "*-*", "***", "-", "**-", "***-", "*--", "-**-", "-*--", "--**"};

    for (int i = 0; i < input.size(); i++)
    {
        if (isalpha(input[i]))
        {
            for (int z = 0; z < 26; z++)
            {
                if (input[i] == *letters[z])
                {
                    std::cout << morseLetters[z] << " ";
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

std::string morseDecrypt (std::string input)
{
    const char *letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    std::string morseLetters[26] = {"*-", "-***", "-*-*", "-**", "*", "**-*", "--*", "****", "**", "*---", "-*-", "*-**", "--", "-*", "---", "*--*", "--*-", "*-*", "***", "-", "**-", "***-", "*--", "-**-", "-*--", "--**"};
    std::string temp;

    for (int i = 0; i != input.size(); i++)
    {   
        if (input[i] == *"*" || input[i] == *"-")
        {
            temp += input[i];
        }
        else if (input[i] == *" " && input[i + 1] == *" ")
        {
            std::cout << " ";
            i++;
        }
        else if (input[i] != *" ")
        {
            std::cout << input[i];
        }

        if (isspace(input[i + 1]) || i == input.size() - 1)
        {
           for (int z = 0; z < 27; z++)
           {
               if (z == 26 && (input[i] == *"*" || input[i] == *"-"))
               {
                   std::cerr << " Ops! Symbol " << temp << " not found!" << std::endl;
                   throw -1;
               }
               
               if (temp == morseLetters[z])
               {
                   std::cout << letters[z];
                   temp.clear();
                   break;
               }
           }
        }
    }

    return input;
}