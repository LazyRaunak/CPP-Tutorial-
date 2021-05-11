#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string text;
    cout << "Please enter a string to make Pyramid" << endl;
    cin >> text;
 
    for (int i = 0; i < text.length(); ++i)
    {
        string temp(text.length() - 1 - i, ' '); // adding spaces
        temp += text.substr(0, i + 1); // adding the required characters
 
        cout << temp; // Printing actual string
 
        // Printing in reverse
        for (int j = temp.length() - 2; j >= 0; --j) 
        {
            cout << temp.at(j);
        }
        cout << endl;
    }
}

/*----------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>

int main()
{
    std::string letters{};

    std::cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
    getline(std::cin, letters);

    size_t num_letters = letters.length();

    int position {0};

    // for each letter in the string
    for (char c: letters) {

        size_t num_spaces = num_letters - position;
        while (num_spaces > 0) {
            std::cout << " ";
            --num_spaces;
        }

        // Display in order up to the current character
        for (size_t j=0; j < position; j++) {
            std::cout << letters.at(j);
        }

        // Display the current 'center' character
        std::cout << c;

        // Display the remaining characters in reverse order
        for (int j=position-1; j >=0; --j) {
            // You can use this line to get rid of the size_t vs int warning if you want
            auto k = static_cast<size_t>(j);
            std::cout << letters.at(k);
        }

        std::cout << std::endl; // Don't forget the end line
        ++position;
    }

    return 0;
}