#include "caesar.hpp"

std::string caesarCrypt(std::string input) // encryption algorithm caesar
{
    const char *arrayOfAbc[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int code = 0; // variable for code

    for (int i = 0; i < input.size(); i++)
    {
        
        if (input[i] == *"[" && input[i + 2] == *"]") //parsing the string to draw a conclusion about the code used [<code>]
        {
            for (int z = 0; z < 26; z++)
            {
                if (input[i + 1] == *arrayOfAbc[z])
                {
                    code = z;
                    std::cout << "<further code: ROT" << code << "> ";
                    i += 2;
                }
            }
        }
        else if (input[i] == *"[" && (input[i + 5] == *"]" || input[i + 6] == *"]")) //parsing the string to draw a conclusion about the code used [ROT<code>]
        {
            std::string temp;
            char symbol;
            symbol = input[i + 4];
            temp = symbol;
            if (input[i + 5] != *"]")
            {
                symbol = input[i + 5];
                temp += symbol;
            }
            code = stoi(temp);
            if (code > 25)
            {
                std::cerr << " (Hey, hey, hey! Do not lie to me! There is no such shift! Next, I will use the ROT0 shift |^-^|) ";
                code = 0;
            }
            std::cout << "<further code: ROT" << code << "> ";
            i += 6;
        }

        else if (input[i] == *" ")
        {
            std::cout << " ";
        }

        else
        {
            for (int z = 0; z < 27; z++)
            {
                if (z == 26) // if a character does not match an array of letters (from 0 to 25), then this is a character and we output it
                {
                    std::cout << input[i];
                    break;
                }

                if (input[i] == *arrayOfAbc[z])
                {
                    z += code;
                    if (z > 25)
                    {
                        std::cout << arrayOfAbc[z - 26];
                        break;
                    }
                    else 
                    {
                        std::cout << arrayOfAbc[z];
                        break;
                    }
                }
            }
        }
    }
    return input;
}

std::string caesarDecrypt(std::string input) // decryption algorithm caesar
{
    const char *arrayOfAbc[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int code = 0; // variable for code

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == *"[" && input[i + 2] == *"]") //parsing the string to draw a conclusion about the code used [<code>]
        {
            for (int z = 0; z < 26; z++)
            {
                if (input[i + 1] == *arrayOfAbc[z])
                {
                    code = z;
                    i += 2;
                }
            }
        }
        else if (input[i] == *"[" && (input[i + 5] == *"]" || input[i + 6] == *"]")) //parsing the string to draw a conclusion about the code used [ROT<code>]
        {
            
            
            std::string temp;
            char symbol;
            symbol = input[i + 4];
            temp = symbol;
            if (input[i + 5] != *"]")
            {
                symbol = input[i + 5];
                temp += symbol;
            }
            code = stoi(temp);
            if (code > 25)
            { 
                std::cerr << " (Hey, hey, hey! Do not lie to me! There is no such shift! Next, I will use the ROT0 shift |^-^|) ";
                code = 0;
            }
            i += 6;
        }
        
        else if (input[i] == *" ")
        {
            std::cout << " ";
        }

        else
        {
            for (int z = 0; z < 27; z++)
            {
                if (z == 26) // if a character does not match an array of letters (from 0 to 25), then this is a character and we output it
                {
                    std::cout << input[i];
                    break;
                }

                if (input[i] == *arrayOfAbc[z])
                {
                    z -= code;
                    if (z < 25 && z >= 0)
                    {
                        std::cout << arrayOfAbc[z];
                        break;
                    }
                    else 
                    {
                        std::cout << arrayOfAbc[z + 26];
                        break;
                    }
                }
            }
        }

    }
    
    return input;
}