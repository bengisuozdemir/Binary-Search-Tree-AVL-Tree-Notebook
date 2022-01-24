#include <iostream>
//#include "bengisuozdemir_ozdemir_bengisu_hw2_AVLclass.h"
#include "bengisuozdemir_ozdemir_bengisu_hw2_BSTclass.h"
#include <sstream>
#include <fstream>
#include <chrono>
using namespace std;

struct Item
{
	string title;
	string info;
	Item(): title(), info() {}
	Item(string TITLE, string INFO): title(TITLE), info(INFO) {}
};
/*struct AVLnotebooks
{ 
	string title;
	AvlTree<Item> avltree;
};*/
struct BSTnotebooks
{
	string title;
	BinarySearchTree<Item> bsttree;
	BSTnotebooks(): title(), bsttree() {}
	BSTnotebooks(string _tt, BinarySearchTree<Item> bst): title(_tt), bsttree(bst) {}
};

int main()
{
	BinarySearchTree<BSTnotebooks> myBST;
	BinarySearchTree<Item> item;
	ifstream input;
	
	string fileName = "data.txt";
	input.open(fileName.c_str());
	string section_title, line;
	
	if(input.fail())
	{
		cout << "input failed"<<endl;
		return 0;
	}
	while(!input.eof())
	{
		bool end_of_line = true;
		getline(input,section_title);
		cout << section_title;
		while(end_of_line && getline(input, line))
		{
			string _title, _info;
			if(line[0] == '-')
			{
				int dash_index = line.find("-",1);
				_title = line.substr(1,dash_index);
				_info = line.substr(dash_index+1,line.length());
				Item tempItem(_title, _info);
				item.insert(tempItem);
				cout << _title << endl << _info << endl;
			}
			else
			{
				myBST.insert(BSTnotebooks(section_title, item));
				end_of_line = false;
			}
		}
	}
	int selection;
	cout << "MENU" << endl << "Please enter an input between [1 - 6]:" << endl << 
		"1- Display the sections [AVL]" << endl <<
		"2- Display the sections [BST]"<<endl<<
		"3- Select a section"<<"4- Add new section"<<endl<<
		"5- Delete a section"<<"6- Exit"<<endl<<
		"Input: ";
	cin>>selection;
	if(selection<1 || selection>6)
	{
		cout << "Invalid input, input is out of range!"<< endl;
		return 0;
	}
	if(selection == 1) //Your program should perform an inorder traversal over the AVL notebook and print the section titles in ascending order (alphabetically).
	{
	}
	else if(selection == 2) //Your program should perform an inorder traversal over the BST notebook and print the section titles in ascending order (alphabetically).
	{
	}
	else if(selection == 3) //The program will get a section title name from the user then it will search for the section with the same title, both in the AVL and BST notebooks. If there exists no such section your program will display an error. Else it will direct to the section menu to perform operations on the selected section.
	{
		string title;
		cout << "Enter a title for the item: ";
		cin>> title;
	}
	else if(selection == 4) //Get a title input from the user. If a section with the given title already exists in the notebook, display an error message. Else, create a new section with that title and insert it into the notebooks.
	{
		string newTitle;
		cout << "Enter a title for the item: ";
		cin>>newTitle;
	}
	else if(selection == 5) //Get a title input from the user. If a section with the given title does not exist in the notebook, display an error message. Else, remove the section with that title from the notebooks.
	{
		string title;
		cout << "Enter a title for the item: ";
		cin>>title;
	}
	else if(selection == 6) //Terminate the program.
	{
		cout << "Terminating..."<< endl;
		cout << "Program ended with exit code: 0" << endl;
		return 0;
	}
	return 0;
}