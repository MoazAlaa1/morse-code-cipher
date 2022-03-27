#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int getchoice() ;
string encryption(char x);
void Cipher(string message);
void morseToEnglish(int toGo);

int main ()
{
    string message ;
	int enter ;
	while(true)
    {
        cout << "\n Ahlan ya user ya habibi.\n"
               "What do you like to do today? \n"
                "1- Cipher a message \n"
                "2- Decipher a message \n"
                "3- End \n" ;
        cin >> enter ;
        if (enter==1)
        {
            cout << "Please enter the message to cipher: \n";
            cin.ignore();
            getline(cin,message) ;
            Cipher(message);
        }
        else if (enter==2)
        {
            morseToEnglish(0);

        }
        else if (enter==3)
        {
            break ;
        }
        else if (enter>3 || enter<0)
        {
            cout << "please choice from [1,2 or 3] \n" ;
        }
        else
            getchoice();
    }

	return 0;
}

int getchoice()
{
    int nchoice;
    cin >> nchoice;
    while(cin.good() == false)
    {
        cout << "ERROR, please Enter a valid input" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << " please Enter choice: ";
        cin >> nchoice;
    }

    return nchoice;
}

string encryption(char x)
{
	switch (x) {
	case 'a':
		return ".-";
	case 'b':
		return "-...";
	case 'c':
		return "-.-.";
	case 'd':
		return "-..";
	case 'e':
		return ".";
	case 'f':
		return "..-.";
	case 'g':
		return "--.";
	case 'h':
		return "....";
	case 'i':
		return "..";
	case 'j':
		return ".---";
	case 'k':
		return "-.-";
	case 'l':
		return ".-..";
	case 'm':
		return "--";
	case 'n':
		return "-.";
	case 'o':
		return "---";
	case 'p':
		return ".--.";
	case 'q':
		return "--.-";
	case 'r':
		return ".-.";
	case 's':
		return "...";
	case 't':
		return "-";
	case 'u':
		return "..-";
	case 'v':
		return "...-";
	case 'w':
		return ".--";
	case 'x':
		return "-..-";
	case 'y':
		return "-.--";
	case 'z':
		return "--..";
	case '1':
		return ".----";
	case '2':
		return "..---";
	case '3':
		return "...--";
	case '4':
		return "....-";
	case '5':
		return ".....";
	case '6':
		return "-....";
	case '7':
		return "--...";
	case '8':
		return "---..";
	case '9':
		return "----.";
	case '0':
		return "-----";
    case ' ':
        return "/";
	case '.':
        return ".-.-.-";
    case ',':
        return "--..--";
	case '?':
        return "..--..";
	case '!':
        return "..--.";
	case ':':
        return "---...";
	case '\"':
        return ".-..-.";
	case '=':
        return "-...-";
	default:
		cerr << "Found invalid character: " << x << ' '
			<< std::endl;

	}
}

void Cipher(string message)
{
	for (int i = 0; message[i]; i++)
		cout << encryption(message[i]) << ' ' ;
}

void morseToEnglish(int toGo)
{
	//declare constants and variables
	const string ENGLISH[45] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
								"k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
								"u", "v", "w", "x", "y", "z", " ", "1", "2", "3",
								"4", "5", "6", "7", "8", "9", "0", ".", ",", "?",
								"!", ":", "\"", "'", "="};
	const string MORSE[45] =   {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
								"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
								"..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".----", "..---",
								"...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
								".-.-.-", "--..--", "..--..", "..--.", "---...", ".-..-.", ".----.", "-...-"};
	string origPhrase = "";
	string newPhrase = "";
	string phrase = "";
	string temp = "";
	int space = 0;
	int run = 0;
	int location = 0;
	int kill = 0;

	//open file
	ofstream outFile;
	outFile.open("code.txt", ios :: app);

	cout << "Enter a word or a phrase in morse code, seperate each word by a space," << endl;
	cout << "a forward slash and another space ' / '. Seperate each letter by a single" << endl;
	cout << "space (press [enter] to exit): ";
	if (toGo == 0)
		cin.ignore(100,'\n');
	getline(cin, origPhrase);
	temp = origPhrase + " ";
	space = 0;

	if (outFile.is_open())
	{
		for (int x = 0; x < temp.length(); x += 1)
		{
			if (temp.substr(x, 1) == " ")
				space += 1;
		}
		//end for
		do
		{
			location = temp.find(" ", 0);
			for (int sub = 0; sub < 45; sub += 1)
			{
				if (temp.substr(0, location) == MORSE[sub])
				{
					phrase = ENGLISH[sub];
					newPhrase += phrase;
					temp.erase(0, location + 1);
					kill = 1;
					break;
				}
				if (sub == 45 && kill == 1)
				{
					phrase = temp.substr(0, location);
					newPhrase += phrase;
					temp.erase(0, location + 1);
				}
			}
			location = 0;
			space -= 1;
		}
		while (space > 0);
		cout << "--> " << newPhrase << endl << endl;
		outFile << origPhrase << '#' << newPhrase << endl;
	}
	else
		cout << "File could not be opened." << endl;

	outFile.close();
}
