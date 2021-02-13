#include "input.hpp"

int input()
{
    std::string input;
    getline (std::cin, input);

    if (input == "quit")
    {
        return 1;
    }

    else if (input == "help")
    {
        std::cout << "1. help > yes yes, this is help ^-^" << std::endl;
        std::cout << "2. quit > this is quit :)" << std::endl;
        std::cout << "3. a1z26-decrypt > decrypting a1z26 cipher" << std::endl;
        std::cout << "4. caesar-decrypt > decrypting caesar's cipher" << std::endl;
        std::cout << "5. vigener-decrypt > decrypting vizhener cipher" << std::endl;
        std::cout << "6. morse-decrypt > decrypting morse cipher" << std::endl;
        std::cout << "7. a1z26-crypt > crypting a1z26 cipher" << std::endl;
        std::cout << "8. caesar-crypt > crypting caesar's cipher" << std::endl;
        std::cout << "9. vigener-crypt > crypting vizhener cipher" << std::endl;
        std::cout << "10. morse-crypt > crypting morse cipher" << std::endl;
    }

    else if (input == "a1z26-crypt")
    {
        std::cout << "registration" << std::endl;
        std::cout << "1. Separation between words is spaces." << std::endl;
        std::cout << "2. Symbols / * - + = # ! and so on, as well as numbers are NOT SUPPORTED. For now)" << std::endl;
        std::cout << "message: ";
        getline (std::cin, input);
        a1z26Crypt(input);
        std::cout << std::endl;
    }

   else if (input == "a1z26-decrypt")
    {
        std::cout << "registration" << std::endl;
        std::cout << "1. The separation between letters is a space." << std::endl;
        std::cout << "2. Separation between words is two spaces." << std::endl;
        std::cout << "message: ";
        getline (std::cin, input);
        a1z26Decrypt(input);
        std::cout << std::endl;
    }

    else if (input == "caesar-crypt")
    {
        std::cout << "registration" << std::endl;
        std::cout << "1. The code is entered in square brackets [(code)]. " << std::endl;
        std::cout << "2. There can be several codes in one sentence." << std::endl;
        std::cout << "For example: [y] Here the code y is used [x] And here is the code x" << std::endl;
        std::cout << "message: ";
        getline (std::cin, input);
        caesarCrypt(input);
        std::cout << std::endl;
    }

    else if (input == "caesar-decrypt")
    {
        std::cout << "registration" << std::endl;
        std::cout << "1. The code is entered in square brackets or in the style of my encoder. [(code)] or <further code: ROT(code)>" << std::endl;
        std::cout << "2. There can be several codes in one sentence." << std::endl;
        std::cout << "For example: [y] Here the code y is used [ROT1] And here is the code ROT1" << std::endl;
        std::cout << "message: ";
        getline (std::cin, input);
        caesarDecrypt(input);
        std::cout << std::endl;
    }

    else if (input == "vigener-crypt")
    {
        std::cout << "registration" << std::endl;
        std::cout << "1. First, enter the encryption key" << std::endl;
        std::cout << "2. Then the encrypted message" << std::endl;
        std::cout << "3. Numbers are not encrypted" << std::endl;
        std::cout << "4. Characters supported" << std::endl;
        std::cout << "5. Key without spaces" << std::endl;
        std::cout << "key: ";
        std::string key;
        getline (std::cin, key);
        std::cout << "message: ";
        getline (std::cin, input);
        vigenerCrypt(key, input);
        std::cout << std::endl;
    }

    else if (input == "vigener-decrypt")
    {
        std::cout << "registration" << std::endl;
        std::cout << "1. First, enter the encryption key" << std::endl;
        std::cout << "2. Then the encrypted message" << std::endl;
        std::cout << "3. Numbers are not encrypted" << std::endl;
        std::cout << "4. Characters supported" << std::endl;
        std::cout << "5. Key without spaces" << std::endl;
        std::cout << "key: ";
        std::string key;
        getline (std::cin, key);
        std::cout << "message: ";
        getline (std::cin, input);
        vigenerDecrypt(key, input);
        std::cout << std::endl; 
    }

    else // error messange
    {
        std::cerr << "Double-check your details, otherwise I don't know that :D" <<std::endl;
        std::cerr << "If there is command 'help' ;3" << std::endl;
    }

    return 0;

}