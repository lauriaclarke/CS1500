#include <iostream>
#include <string>
using namespace std;

void displayBook(int bookIndex, string titles[], string authors[], int isbns[],
		int bookCount);
int searchBooksByTitle(string title, string titles[], int bookCount);
int searchBooksByAuthor(string author, string authors[], int bookCount);
int searchBooksByIsbn(int isbn, int isbns[], int bookCount);

const int BOOK_COUNT = 10;

int main()
{
	int index;

	string titles[] =
	{ "Ender's Game", "Red Mars", "Dune", "Foundation", "Blade Runner",
			"Neuromancer", "Farenheit 451", "2001 A Space Odissey",
			"Forever War", "One Hundred Years of Solitud" };

	string authors[] =
	{ "Orson Scott Card", "Kim Stanley Robinson", "Frank Herbert",
			"Isaac Asimov", "Philip K. Dick", "William Gibson", "Ray Bradbury",
			"Arthur C. Clarke", "Joe Haldeman", "Gabriel Garcia Marquez" };

	int isbns[] =
	{ 123, 234, 345, 321, 432, 543, 654, 765, 876, 987 };

	displayBook(3, titles, authors, isbns, BOOK_COUNT);

	index = searchBooksByTitle("Dune", titles, BOOK_COUNT);
	displayBook(index, titles, authors, isbns, BOOK_COUNT);

	index = searchBooksByAuthor("Arthur C. Clarke", authors, BOOK_COUNT);
	displayBook(index, titles, authors, isbns, BOOK_COUNT);

	index = searchBooksByIsbn(987, isbns, BOOK_COUNT);
	displayBook(index, titles, authors, isbns, BOOK_COUNT);

//	getchar();
}

/***************************************************************************/
/***************************************************************************/

void displayBook(int bookIndex, string titles[], string authors[], int isbns[],
		int bookCount)
{
	if (bookIndex <= bookCount)
	{
		cout << titles[bookIndex] << ", " << authors[bookIndex] << ", "
				<< isbns[bookIndex] << "\n";
	}
	else
	{
		cout << "No book found. Please try again. \n\r";
	}
}


int searchBooksByTitle(string title, string titles[], int bookCount)
{
	for (int i = 0; i < bookCount; i++)
	{
		if (title == titles[i])
		{
			return i;
		}
	}
	return -1;
}

int searchBooksByAuthor(string author, string authors[], int bookCount)
{
	for (int i = 0; i < bookCount; i++)
	{
		if (author == authors[i])
		{
			return i;
		}
	}
	return -1;
}

int searchBooksByIsbn(int isbn, int isbns[], int bookCount)
{
	for (int i = 0; i < bookCount; i++)
	{
		if (isbn == isbns[i])
		{
			return i;
		}
	}
	return -1;
}
