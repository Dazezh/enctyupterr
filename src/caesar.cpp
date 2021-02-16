#include "caesar.hpp"

std::string caesarCrypt(std::string input) // encryption algorithm caesar
{
    const char *letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int code = 0; // variable for code

    for (int i = 0; i < input.size(); i++)
    {
        
        if (input[i] == *"[" && input[i + 2] == *"]") //parsing the string to draw a conclusion about the code used [<code>]
        {
            for (int z = 0; z < 26; z++)
            {
                if (input[i + 1] == *letters[z])
                {
                    code = z;
                    std::cout << "<further code: ROT" << code << "> ";
                    i += 2;
                }
            }
        }
        else if (input[i] == *"r" && input[i + 1] == *"o" && input[i + 2] == *"t" && input[i + 3] == *":") //parsing the string to draw a conclusion about the code used ROT:<code>
        {
            std::string temp;
            char symbol;

            symbol = input[i + 4];
            temp = symbol;

            if (isdigit(input[i + 5])) // if the number does not end with 1 characters, then add the second
            {
                symbol = input[i + 5];
                temp += symbol;
            }

            code = stoi(temp);

            if (code > 25 || isdigit(input[i + 6])) // if code > 25 and the number does not end with 2 characters, then there is no such ROT
            {
                std::cerr << "Hey, hey, hey! Do not lie to me! There is no such shift! Next, I will no encrypting |^-^|" << std::endl;
                throw -1;
                
            }

            std::cout << "<further code: ROT" << code << "> ";
            i += 6;
        }

        else if (isspace(input[i])) // if space that space :|
        {
            std::cout << " ";
        }

        else // if no space and no code thah letters or number so or character
        {
            for (int z = 0; z < 27; z++)
            {
                if (z == 26) // if a character does not match an array of letters (from 0 to 25), then this is a character and we output it
                {
                    std::cout << input[i];
                    break;
                }

                if (input[i] == *letters[z])
                {
                    z += code; // number letters + shift
                    if (z > 25) 
                    {
                        std::cout << letters[z - 26];
                        break;
                    }
                    else 
                    {
                        std::cout << letters[z];
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
    const char *letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int code = 0; // variable for code

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == *"[" && input[i + 2] == *"]") //parsing the string to draw a conclusion about the code used [<code>]
        {
            for (int z = 0; z < 26; z++)
            {
                if (input[i + 1] == *letters[z])
                {
                    code = z;
                    i += 2;
                }
            }
        }
        else if (input[i] == *"r" && input[i + 1] == *"o" && input[i + 2] == *"t" && input[i + 3] == *":") //parsing the string to draw a conclusion about the code used ROT:<code>
        {
            std::string temp;
            char symbol;

            symbol = input[i + 4];
            temp = symbol;

            if (isdigit(input[i + 5])) // if the number does not end with 1 characters, then add the second
            {
                symbol = input[i + 5];
                temp += symbol;
            }

            code = stoi(temp);

            if (code > 25 || isdigit(input[i + 6])) // if code > 25 and the number does not end with 2 characters, then there is no such ROT
            {
                std::cerr << "Hey, hey, hey! Do not lie to me! There is no such shift! Next, I will no encrypting |^-^|" << std::endl;
                throw -1;
                
            }

            i += 6;
        }
        
        else if (isspace(input[i])) // if space that space :|
        {
            std::cout << " ";
        }

        else // if no space and no code thah letters or number so or character
        {
            for (int z = 0; z < 27; z++)
            {
                if (z == 26) // if a character does not match an array of letters (from 0 to 25), then this is a character and we output it
                {
                    std::cout << input[i];
                    break;
                }

                if (input[i] == *letters[z])
                {
                    z -= code; // number letters - shift
                    if (z < 25 && z >= 0)
                    {
                        std::cout << letters[z];
                        break;
                    }
                    else 
                    {
                        std::cout << letters[z + 26];
                        break;
                    }
                }
            }
        }
    }
    
    return input;
}