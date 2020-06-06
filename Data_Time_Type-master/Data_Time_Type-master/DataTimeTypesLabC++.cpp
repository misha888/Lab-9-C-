// DataTimeTypesLabC++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;
void base();
void midle();
void hard();
/*
		 Тип данных – дата и время 
	Базовый уровень Задание: изучить набор функций, предназначенных для работы с данными типа дата и время. Написать программу реализации 
    индивидуального задания, представленного в таблице. Все указанные значения дат и времени вводить по формату ДДММГГГГ и ЧЧ:ММ:СС соответственно
*/

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	base();
	midle();
	hard();
}

void base()
{
/*
	1.Ввести четыре отдельных значения (часы, минуты, секунды и миллисекунды) и 
	объединить их в одно значение данных типа время.
	2. Написать программу любителям предсказаний, позволяющую для введенной даты 
	определить,  принадлежит ли она к високосному году, если это не так, то выдать 
	информацию о количестве лет до ближайшего високосного года.
*/
	cout << "\nLow task level: \n";
         struct tm *u;
  char s1[40] = { 0 }, s2[40] = { 0 };
  const time_t timer = time(NULL);
  u = localtime(&timer);
  strftime(s1, 80, "%d.%m.%Y %H:%M:%S ", u);
  printf("%s\n", s1);
  u->tm_mday += ADD_DAYS;
  time_t next = mktime(u);
  u = localtime(&next);
  strftime(s2, 80, "%d.%m.%Y %H:%M:%S ", u);
  printf("%s\n", s2);
	char s[40];
  char *tmp;
  for (int i = 0; i<40; i++) s[i] = 0;
  int length = strftime(s, 40, "%d.%m.%Y %H:%M:%S ", u);
  switch (u->tm_wday)
  {
    case 0: strcpy(s + length, " воскресенье"); break;
    case 1: strcpy(s + length, " понедельник"); break;
    case 2: strcpy(s + length, " вторник");     break;
    case 3: strcpy(s + length, " среда");       break;
    case 4: strcpy(s + length, " четверг");     break;
    case 5: strcpy(s + length, " пятница");     break;
    case 6: strcpy(s + length, " суббота");     break;
  }
  tmp = (char*)malloc(sizeof(s));
  strcpy(tmp, s);
	cout << "\nНажмите <Enter> чтобы продолжить: ";
	while (getchar() != '\n')
		continue;

}

void midle()
{
/*
Счетчик посещения сайта:
		- адрес открытой webстранички;
		- ip-адрес посетителя;
		- web-браузер посетителя; 
		- дата визита;
		- время визита;
Задача:
		- вывести информацию обо всех посещениях сайта с указанием дня посещения (1 - понедельник); 
		- ввести два значения времени и вывести сведения о посещении webстранички indexphp во введенный
		  временной интервал прошлого дня. 
*/
	cout << "\nMidel task level: \n";

	  time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "The UTC date and time is:"<< dt << endl;
	
	time_t now = time(0);

   cout << "Number of sec since January 1,1970:" << now << endl;

   tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << "Year" << 1970 + ltm->tm_year<<endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<<  ltm->tm_mday << endl;
   cout << "Time: "<< 1 + ltm->tm_hour << ":";
   cout << 1 + ltm->tm_min << ":";
   cout << 1 + ltm->tm_sec << endl;
	
    cout << "\nНажмите <Enter> чтобы продолжить: ";
    while (getchar() != '\n')
        continue;
}
struct Book;
struct Book
{
	string fio;
	string book_name;
	int    cost;
	int    count;
};
void CheckDigit(int& anydigit);

Book* FillStruct(Book* mas_book, int count)  //Всего лишь заполняет масив структур
{
	if (mas_book == nullptr)
		mas_book = new Book[count];
	for (size_t i = 0; i < count; i++)
	{
		mas_book[i].fio = "FIO" + to_string(i + 1);
		mas_book[i].book_name = "BooksName" + to_string(i + 1);
		mas_book[i].cost = 100 + rand() % 1000;
		mas_book[i].count = 1 + rand() % 100;
	}
	return mas_book;
}
void ShowBooks(Book* mas_books, int count)
{
	cout << "\nИнформация о всех книах: \n";
	for (size_t i = 0; i < count; i++)
	{
		printf("\nИнформация о %d книге: \n\t", i + 1);
		cout << mas_books[i].fio << " ";
		cout << mas_books[i].book_name << " ";
		cout << mas_books[i].cost << " ";
		cout << mas_books[i].count << "\n";
	}
}
Book* LoadFile(int count)  //Прочитать данные с файла
{
	ifstream f_in; f_in.open("database.bin", ios::binary | ios::in);
	Book* buffer = new Book[count];
	f_in.read((char*)buffer, count * sizeof(Book));
	f_in.close();
	return buffer;
}
void SaveFile(Book* mas_book, int count)
{
	ofstream f_out; f_out.open("database.bin", ios::binary | ios::out);
	int BufferSize = count * sizeof(Book);
	f_out.write((char*)mas_book, BufferSize);
	f_out.close();
}
int IsSetDiscount(int count) //Установление скидки если соблюдается условие 
{
	ifstream f_in; f_in.open("database.bin", ios::binary | ios::in);
	Book* buffer = new Book[count];
	f_in.read((char*)buffer, count * sizeof(Book));
	f_in.close();
	bool flag = false;
	for (size_t i = 0; i < count; i++)
	{
		if (buffer[i].fio[i] == 'K')
		{
			flag = true;
			for (size_t i = 0; i < count; i++)
			{
				printf("\nИнформация о %d книге: \n\t", i + 1);
				cout << buffer[i].fio << " ";
				cout << buffer[i].book_name << " ";
				cout << buffer[i].cost << " ";
				cout << buffer[i].count << "\n";
			}
		}
	}
	if (!flag)
		cout << "\nНет не одного автора фамилия которого начинается на <K>!!!\n";
	//SaveFile(buffer, count);
	return 0;
}
void CheckDigit(int& anydigit)
{
	while (true)
	{
		cin >> anydigit;
		if (!cin.good() || cin.fail())
		{
			cin.clear();
			cin.ignore(32567, '\n');
			cout << "\nВведите коректное числовое значение...\n";
			cout << "\nПовторите ввод: ";
		}
		break;
	}
}

void hard()
{
/*
		- ввести значение года и подсчитать количество всех посещений сайта за введенный год;
		- ввести значение даты и определить для нее ip-адрес и web-браузер последнего посетителя сайта;
		- упорядочить исходную информацию по дате посещения, создав для этого необходимое количество файлов,
		  где в качестве имени файла используется дата посещения, а содержимым является информация обо всех 
		  посещениях за эту дату.
*/
	cout << "\nHard task level: \n";
struct tm *u;
  char s1[40] = { 0 }, s2[40] = { 0 };
  const time_t timer = time(NULL);
  u = localtime(&timer);
  strftime(s1, 80, "%d.%m.%Y %H:%M:%S ", u);
  printf("%s\n", s1);
  u->tm_mday += ADD_DAYS;
  time_t next = mktime(u);
  u = localtime(&next);
  strftime(s2, 80, "%d.%m.%Y %H:%M:%S ", u);
  printf("%s\n", s2);
int count = 10;
	Book* mas_book = new Book[count];
	mas_book = FillStruct(mas_book, count);
	SaveFile(mas_book, count);
	mas_book = LoadFile(count);
	cout << "\nСодержимое файла до внесенных изминений: \n";
	cout << "\nВ файле хранится масив структур содержащих следущие поля: \n";
	cout << "\t-ФИО автора\n\t-название книги\n\t-цена за ед.\n\t-количетсво экзэмпляров";
	ShowBooks(mas_book, count);
	cout << "\nСодержимое файла после внесенных изминений: "
		 <<  "\nДанные про книги авторов, фамилия которых начинается с буквы “К”: \n";
	IsSetDiscount(count);
	Book* buffer = new Book[count];
	buffer = LoadFile(count);
	SaveFile(buffer, count);
	ShowBooks(buffer, count);
	cout << "\nНажмите <Enter> чтобы продолжить: ";
	while (getchar() != '\n')
		continue;
}
