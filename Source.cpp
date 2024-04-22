#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class LinkedList{
	class Node{
	public:
		string songTitle, Genre, Instrumentalness, Accousticness, Speechness, Loudness, Key, Energy, Danceability;
		int duration;

		Node* next;

		Node(string dance = "", string ene = "", string K = "", string loud = "", string sn = "", string acc = "", string ins = "", int d = 0, string G = "", string name = ""){
			Danceability = dance;
			Energy = ene;
			Key = K;
			Loudness = loud;
			Speechness = sn;
			Accousticness = acc;
			Instrumentalness = ins;
			duration = d;
			Genre = G;
			songTitle = name;
			next = NULL;
		}
	};
public:
	Node* head;
	Node* tail;
	LinkedList(){
		head = tail = NULL;
	}
	void displayname()
	{
		Node* temp = new Node();
		temp = head;
		int x = 0;

		while (temp->next != NULL)
		{
			cout << " Song Number : " << x << endl;
			cout << " Song Title: " << temp->songTitle << endl;
			cout << endl << endl;
			x++;
			temp = temp->next;
		}
	}

	void display_by_duration()
	{
		Node* temp = new Node();
		temp = head;
		int x = 0;

		while (temp->next != NULL)
		{
			cout << " Song Number : " << x << endl;
			cout << " Song Title : " << temp->songTitle << endl;
			cout << " Duration : " << temp->duration << endl << endl << endl;
			x++;
			temp = temp->next;
		}
	}

	void delete_at_any(int index)
	{
		int count = 0;
		Node* temp = new Node();
		Node* temp2 = new Node();
		temp = head;
		temp2 = head;
		Node* p = new Node();
		p = head;
		int end;
		while (temp2 != NULL) {
			temp2 = temp2->next;
			count++;

		}
		end = count;
		if (index == count) {
			delete_at_tail();
		}
		if (index == 0) {
			delete_at_head();
		}
		if (index > 0 && index < end) {
			count = 0;
			while (count < index - 1) {
				count++;
				p = p->next;
			}
			count = 0;
			while (count < index) {
				count++;
				temp = temp->next;
			}
			p->next = temp->next;
			displayname();

			cout << "Deleted Song :" << temp->songTitle << endl;
			delete temp;
		}
	}
	void delete_at_tail()
	{
		Node* temp = new Node();
		temp = head;
		Node* p = new Node();

		while (temp->next != tail)
		{
			temp = temp->next;
		}
		p = tail;
		displayname();
		cout << endl << "Deleted Song : "<< p->songTitle << endl;
		tail = temp;
		tail->next = NULL;

		delete p;
	}

	void delete_at_head()
	{
		Node* temp = new Node();
		temp = head->next;
		Node* p = new Node();
		p = head;
		head = temp;
		displayname();
		cout << endl << "Deleted Song :  " << p->songTitle << endl;
		delete p;
	}
	void Insert_at_anypoint(int count, string dance, string ene, string K, string loud, string sn, string acc, string ins, int d, string G, string name)
	{
		if (count != 0)
		{
			int x = 0;
			Node* temp = new Node();
			temp = head;
			Node* p = new Node();

			while (x < count)
			{
				temp = temp->next;
				x++;
			}
			p = temp->next;
			Node* t1 = new Node(dance, ene, K, loud, sn, acc, ins, d, G, name);
			temp->next = t1;
			t1->next = p;
		}
		else
		{
			Node* temp = new Node();
			temp = head;
			Node* p = new Node(dance, ene, K, loud, sn, acc, ins, d, G, name);
			p->next = temp;
			p = head;
		}

	}

	void insert_at_start(string dance, string ene, string K, string loud, string sn, string acc, string ins, int d, string G, string name)
	{
		Node* temp = new Node();
		temp = head;
		Node* p = new Node(dance, ene, K, loud, sn, acc, ins, d, G, name);
		p->next = temp;
		p = head;
	}

	void Insert_at_end(string dance, string ene, string K, string loud, string sn, string acc, string ins, int d, string G, string name)
	{
		if (head != NULL)
		{
			Node* temp = new Node(dance, ene, K, loud, sn, acc, ins, d, G, name);
			tail->next = temp;
			tail = temp;
			tail->next = NULL;
		}
		else
		{
			Node* temp = new Node(dance, ene, K, loud, sn, acc, ins, d, G, name);
			head = temp;
			tail = temp;
			head->next = NULL;
			tail->next = NULL;
		}
	}
	void sort_by_duration()
	{
		Node* temp = new Node();
		temp = head;
		Node* p = new Node();

		Node* t1 = new Node();

		string dance;
		string ene;
		string K;
		string loud;
		string sn;
		string acc;
		string ins;
		int d = 0;
		string G;
		string name;

		while (temp != NULL)
		{
			p = temp->next;
			while (p != NULL)
			{
				if (p->duration < temp->duration)
				{
					dance = temp->Danceability;
					ene = temp->Energy;
					K = temp->Key;
					loud = temp->Loudness;
					sn = temp->Speechness;
					acc = temp->Accousticness;
					ins = temp->Instrumentalness;
					d = temp->duration;
					G = temp->Genre;
					name = temp->songTitle;

					temp->Danceability = p->Danceability;
					temp->Energy = p->Energy;
					temp->Key = p->Key;
					temp->Loudness = p->Loudness;
					temp->Speechness = p->Speechness;
					temp->Accousticness = p->Accousticness;
					temp->Instrumentalness = p->Instrumentalness;
					temp->duration = p->duration;
					temp->Genre = p->Genre;
					temp->songTitle = p->songTitle;

					p->Danceability = dance;
					p->Energy = ene;
					p->Key = K;
					p->Loudness = loud;
					p->Speechness = sn;
					p->Accousticness = acc;
					p->Instrumentalness = ins;
					p->duration = d;
					p->Genre = G;
					p->songTitle = name;
				}
				p = p->next;
			}

			temp = temp->next;
		}


	}
	int Total_nodes()
	{
		int num = 0;
		int n = 2000;
		Node* temp = new Node();
		temp = head;
		while (temp->next != NULL)
		{
			num = num + 1;
			temp = temp->next;
		}
		cout << "Total Node : " << n << endl;
		return num;
	}

	void display()
	{
		Node* temp = new Node();
		temp = head;
		int x = 0;
		while (temp != NULL){
			cout << "Song Number :" << x << endl;
			cout << "Song Name :" << temp->songTitle << endl;
			cout << "Genre :" << temp->Genre << endl;
			cout << "Duration :" << temp->duration << endl;
			cout << "Instrumentalness :" << temp->Instrumentalness << endl;
			cout << "Acousticness :" << temp->Accousticness << endl;
			cout << "Speechness :" << temp->Speechness << endl;
			cout << "Loudness :" << temp->Loudness << endl;
			cout << "Key :" << temp->Key << endl;
			cout << "Energy :" << temp->Energy << endl;
			cout << "Danceability :" << temp->Danceability << endl;
			cout << endl << endl;
			x++;
			temp = temp->next;
		}
	}
	void search(int x)
	{
		Node* temp = new Node();
		temp = head;
		int a = 0;

		while (a != x)
		{
			a++;
			temp = temp->next;
		}
		cout << "Song Number :" << x << endl;
		cout << "Song Name :" << temp->songTitle << endl;
		cout << "Genre :" << temp->Genre << endl;
		cout << "Duration :" << temp->duration << endl;
		cout << "Instrumentalness :" << temp->Instrumentalness << endl;
		cout << "Acousticness :" << temp->Accousticness << endl;
		cout << "Speechness :" << temp->Speechness << endl;
		cout << "Loudness :" << temp->Loudness << endl;
		cout << "Key :" << temp->Key << endl;
		cout << "Energy :" << temp->Energy << endl;
		cout << "Danceability :" << temp->Danceability << endl;
		cout << endl << endl;
	}

	void sort_name()
	{
		LinkedList L;
		char name = 32;
		Node* temp = new Node();
		temp = head;

		while (name < 64)
		{
			while (temp != NULL)
			{
				if (temp->songTitle[0] == name)
				{
					L.Insert_at_end(temp->Danceability, temp->Energy, temp->Key, temp->Loudness, temp->Speechness, temp->Accousticness, temp->Instrumentalness, temp->duration, temp->Genre, temp->songTitle);
				}
				temp = temp->next;
			}
			temp = head;
			name += 1;
		}
		name = 64;
		temp = head;

		while (name < 126)
		{
			while (temp != NULL)
			{
				if (temp->songTitle[0] == name)
				{
					L.Insert_at_end(temp->Danceability, temp->Energy, temp->Key, temp->Loudness, temp->Speechness, temp->Accousticness, temp->Instrumentalness, temp->duration, temp->Genre, temp->songTitle);
				}
				temp = temp->next;
			}
			temp = head;
			name += 1;
		}

		head = L.head;
		tail = L.tail;

	}

	void Shuffle() {
		LinkedList L;
		Node* temp = new Node();
		temp = head;
		int c = 0;
		while (temp != NULL) {
			if (c == 3) {
				L.Insert_at_end(temp->Danceability, temp->Energy, temp->Key, temp->Loudness, temp->Speechness, temp->Accousticness, temp->Instrumentalness, temp->duration, temp->Genre, temp->songTitle);
				c = 0;
			}
			temp = temp->next;
			c = c + 1;
		}
		c = 0;
		temp = head;
		Node* p = new Node();
		p = L.head;
		int x = 0;
		while (p != NULL) {
			p = p->next;
			x = x + 1;
		}
		p = L.head;
		int count = 0;

		while (temp != NULL) {
			while (p != NULL) {
				if (p->songTitle != temp->songTitle && p->duration != temp->duration) {
					count++;
				}
				p = p->next;
			}
			p = L.head;
			if (count == x) {
				L.Insert_at_end(temp->Danceability, temp->Energy, temp->Key, temp->Loudness, temp->Speechness, temp->Accousticness, temp->Instrumentalness, temp->duration, temp->Genre, temp->songTitle);
				count = 0;
			}
			else {
				count = 0;
			}
			temp = temp->next;
			c += 1;



		}
		count = 0;
		temp = head;
		while (temp != NULL) {
			if (c == 2) {
				L.Insert_at_end(temp->Danceability, temp->Energy, temp->Key, temp->Loudness, temp->Speechness, temp->Accousticness, temp->Instrumentalness, temp->duration, temp->Genre, temp->songTitle);
				c = 0;
			}
			temp = temp->next;
			c += 1;



		}

		Node* t1 = new Node();
		t1 = L.head;

		head = L.head;
		tail = L.tail;
	}

	void Remove_Duplicates()
	{

		Node* temp = new Node();
		temp = head;
		Node* p = new Node();
		p = temp->next;

		for (int i = 1; i < 2000; i++)
		{
			int count = 0;

			for (int j = 0; (j < i) && (count == 0); j++)
			{
				if (temp->songTitle[i] != p->songTitle[j])
				{
					cout << "Distinct are Saved. " << endl;
				}
				else
				{
					count++;
					delete temp;
					cout << "Deleted Duplicates." << endl;
				}
				temp = temp->next;
				p = p->next;
			}

		}
		cout << "Duplicates are Deleted and Distinct Songs are Saved." << endl;
	}

	void displayfile()
	{
		ofstream of("Songs.txt");
		Node* temp = new Node();
		temp = head;
		int c = 0;
		while (temp != NULL) {
			c++;
			temp = temp->next;
		}
		of << c << endl;
		temp = head;
		for (int i = 0; i < c; i++) {
			of << "Song Name :" << temp->songTitle << endl;
			of << "Genre :" << temp->Genre << endl;
			of << "Duration :" << temp->duration << endl;
			of << "Instrumentalness :" << temp->Instrumentalness << endl;
			of << "Accousticness :" << temp->Accousticness << endl;
			of << "Speechness :" << temp->Speechness << endl;
			of << "Loudness :" << temp->Loudness << endl;
			of << "Key :" << temp->Key << endl;
			of << "Energy :" << temp->Energy << endl;
			of << "Danceability :" << temp->Danceability << endl;
			temp = temp->next;
		}
		of.close();
	}


	int presentMenu()
	{
		int Choice = 0;
		do {
			cout << "                 Songs Playlist Menu" << endl << endl
				<< "1  - Insert New Song" << endl
				<< "2  - Display file the Song" << endl
				<< "3  - Delete the song" << endl
				<< "4  - Sort Song According to Song Duration " << endl
				<< "5  - Sort Song According to Song's name initials" << endl
				<< "6  - Listen Songs" << endl
				<< "7  - Remove Duplicate Songs And Save" << endl
				<< "8  - Only Show Titles of Song" << endl
				<< "9  - Search Unique Songs Data in File" << endl
				<< "10 - Calculate Total Numbers of Nodes" << endl
				<< "11 - Shuffle the Playlist " << endl
				<< "0 - Exit" << endl
				<< endl << "Enter Your Choice (1-12) : ";
			cin >> Choice;

			if (Choice < 0 || Choice > 11)
				cout << endl << "Please enter a valid choice between 1 and 12" << endl;

		} while (Choice < 0 && Choice > 11);

		return Choice;
	}


};
int main()
{
	string buffer;
	LinkedList L1;
	int a;
	ifstream f("Songs Information.csv");
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, '\n');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, ',');
	getline(f, buffer, '\n');
	string dance;
	string energy;
	string key;
	string loudness;
	string speechness;
	string accousticness;
	string ins;
	string duration;
	string genre;
	string name;
	int count = 0;
	while (count < 200) {
		getline(f, dance, ',');
		getline(f, energy, ',');
		getline(f, key, ',');
		getline(f, loudness, ',');
		getline(f, speechness, ',');
		getline(f, accousticness, ',');
		getline(f, ins, ',');
		f >> a;
		getline(f, duration, ',');
		getline(f, genre, ',');
		getline(f, name, '\n');
		L1.Insert_at_end(dance, energy, key, loudness, speechness, accousticness, ins, a, genre, name);
		count++;
	}
	int Selection = 0;
	do {
		Selection = L1.presentMenu();
		if (Selection == 1) {
			cout << "Insert New Song" << endl;
			int choice;
			cout << "1.Insert At Start    " << endl;
			cout << "2.Insert At End      " << endl;
			cout << "3.Insert in Between " << endl;
			cout << "Select :  " << endl;
			cin >> choice;
			do {
				if (choice == 1)
				{
					cout << endl << "Enter Title : ";
					getline(cin, name);
					getline(cin, name);
					cout << endl;
					cout << "Enter Duration : ";
					cin >> a;
					cout << endl;
					cout << "Enter Danceability : " << endl;
					getline(cin, dance);
					getline(cin, dance);
					cout << endl;
					cout << "Enter Key : " << endl;
					getline(cin, key);
					cout << endl;
					cout << "Enter Genre : ";
					getline(cin, genre);
					cout << endl;
					cout << "Enter Accoustics : " ;
					getline(cin, accousticness);
					cout << endl;
					cout << "Enter Energy : ";
					getline(cin, energy);
					cout << endl;
					cout << "Enter Instrumentalness : ";
					getline(cin, ins);
					cout << endl;
					cout << "Enter Speechness : ";
					getline(cin, speechness);
					cout << endl;
					cout << "Enter Loudness : ";
					getline(cin, loudness);
					cout << endl;
					L1.insert_at_start(dance, energy, key, loudness, speechness, accousticness, ins, a, genre, name);
					L1.displayname();
				}
				else if (choice == 2)
				{
					cout << endl << "Enter Title : ";
					getline(cin, name);
					getline(cin, name);
					cout << endl;
					cout << "Enter Duration : ";
					cin >> a;
					cout << endl;
					cout << "Enter Danceability : " << endl;
					getline(cin, dance);
					getline(cin, dance);
					cout << endl;
					cout << "Enter Key : " << endl;
					getline(cin, key);
					cout << endl;
					cout << "Enter Genre : ";
					getline(cin, genre);
					cout << endl;
					cout << "Enter Accoustics : " ;
					getline(cin, accousticness);
					cout << endl;
					cout << "Enter Energy : ";
					getline(cin, energy);
					cout << endl;
					cout << "Enter Instrumentalness : ";
					getline(cin, ins);
					cout << endl;
					cout << "Enter Speechness : ";
					getline(cin, speechness);
					cout << endl;
					cout << "Enter Loudness : ";
					getline(cin, loudness);
					cout << endl;
					L1.Insert_at_end(dance, energy, key, loudness, speechness, accousticness, ins, a, genre, name);
					L1.displayname();
				}
				else if (choice == 3)
				{
					int x;
					cout << " Enter Number To Insert Song : " << endl;
					cin >> x;
					cout << endl << "Enter Title : ";
					getline(cin, name);
					getline(cin, name);
					cout << endl;
					cout << "Enter Duration : ";
					cin >> a;
					cout << endl;
					cout << "Enter Danceability : " << endl;
					getline(cin, dance);
					getline(cin, dance);
					cout << endl;
					cout << "Enter Key : " << endl;
					getline(cin, key);
					cout << endl;
					cout << "Enter Genre : ";
					getline(cin, genre);
					cout << endl;
					cout << "Enter Accoustics : ";
					getline(cin, accousticness);
					cout << endl;
					cout << "Enter Energy : ";
					getline(cin, energy);
					cout << endl;
					cout << "Enter Instrumentalness : ";
					getline(cin, ins);
					cout << endl;
					cout << "Enter Speechness : ";
					getline(cin, speechness);
					cout << endl;
					cout << "Enter Loudness : ";
					getline(cin, loudness);
					cout << endl;
					if (x != 0)
					{
						x = x - 1;
					}
					L1.Insert_at_anypoint(x, dance, energy, key, loudness, speechness, accousticness, ins, a, genre, name);
					L1.displayname();
				}
			} while (choice != 3);


		}
		else if (Selection == 2) {
		cout << endl << endl << endl;
		cout << "    ********************************" << endl;
		cout << "          Display file the Song" << endl;
			cout << endl;
			L1.display();
			cout << endl << endl;
		}
		else if (Selection == 3) {
			cout << "Delete the song " << endl;
			int choice;
			cout << "1.Delete At Start" << endl;
			cout << "2.Delete At End" << endl;
			cout << "3.Delete At End" << endl;
			cout << endl << endl;
			cout << " Select : " << endl << endl;
			cin >> choice;

			do {
				if (choice == 1)
				{
					cout << " Deleted From Start " << endl;
					L1.delete_at_head();
				}
				else if (choice == 2)
				{
					cout << " Deleted From End" << endl;
					L1.delete_at_tail();
				}
				else if (choice == 3)
				{
					int x;
					cout << "Enter Song Number: ";
					cin >> x;
					L1.delete_at_any(x);
				}
			} while (choice != 3);
		}
		else if (Selection == 4) {
			cout << "Sort Song According to Song Duration: " << endl;
			L1.sort_by_duration();
			L1.display_by_duration();

		}
		else if (Selection == 5) {
			cout << "Sort Song According to Songs Name: " << endl;
			L1.sort_name();
			L1.displayname();

		}
		else if (Selection == 6) {
			cout << "Listen Songs " << endl;
			int c;
			cout << " Enter MetaData : ";
			cin >> c;
			cout << " ***PLAYING*** " << endl;
			L1.search(c);
			int choice;
			cout << "1. PLAY NEXT            " << endl;
			cout << "2. PLAY SONG ON REPEAT " << endl;
			cout << "3. PLAY PREVIOUS       " << endl;
			cout << "Select : " << endl;
			cin >> choice;

			do {
				if (choice == 1)
				{
					cout << " PLAY NEXT SONG " << endl;
					c = c + 1;
					cout << " ***PLAYING*** " << endl;
					L1.search(c);
				}
				else if (choice == 2)
				{
					cout << " PLAY SONG ON REPEAT " << endl;
					c = c;
					cout << " ***PLAYING*** " << endl;
					L1.search(c);
				}
				else if (choice == 3)
				{
					cout << " PLAY PREVIOUS " << endl;
					c = c - 1;
					cout << " ***PLAYING*** " << endl;
					L1.search(c);
				}

			} while (choice != 3);

		}
		else if (Selection == 7) {
			cout << "Remove Duplicate Songs" << endl;
			L1.Remove_Duplicates();
		}

		else if (Selection == 8) {
			cout << "Show Titles of Song" << endl;
			L1.displayname();
		}
		else if (Selection == 9) {
			cout << "Search Unique Songs Data in File " << endl;
			int c;
			cout << " ENTER THE NUMBER OF SONG YOU WANT TO SEARCH: ";
			cin >> c;
			L1.search(c);
		}
		else if (Selection == 10) {
			cout << "Calculate Total Number Of Nodes " << endl;
			L1.Total_nodes();
		}
		else if (Selection == 11) {
			cout << "Shuffle the Playlist " << endl;
			L1.Shuffle();
			L1.displayname();
			cout << endl << endl;
		}
		else if (Selection == 0) {
		cout << endl << endl << "Program Closed" << endl << endl;
		exit(0);

		}

	} while (Selection != 12);

	return 0;
}