#ifndef ACTOR_H
#define ACTOR_H

// including header files and libraries
#include "library.h"
#include "book.h"
#include "config.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace Actor
{
	// defining add_new function - used to add new entry to the database
	void add_new()
	{
		// declared objects of two classes
		Library lib;
		Book bk;
		int opt;
		cout<<"1. Add new library staff details"<<endl;
		cout<<"2. Add new book details"<<endl;
		cout<<"> ";
		cin>>opt;  // getting option
		ofstream file;   // declared object of output file stream class

		switch(opt)   // handling user selection
		{
			case 1:
				file.open(MAIN_FILE_1, ios::binary|ios::app);   // opening binary file in append mode
				lib.get();  // getting data from user
				file.write((char*)(&lib), sizeof(Library));   // writing data to file
				file.close();   // closing output file stream
				break;
			case 2:
				file.open(MAIN_FILE_2, ios::binary|ios::app);   // opening binary file in append mode
				bk.get();  // getting data from user
				file.write((char*)(&bk), sizeof(Book));   // writing data to file
				file.close();   // closing output file stream
				break;
		}
	}

	// defining delete_existing function - used to delete entry by id
	void delete_existing()
	{
		// declared objects of two classes
		Library lib;
		Book bk;
		int opt, id;
		bool found = false;
		cout<<"1. Delete from library staff details"<<endl;
		cout<<"2. Delete from book details"<<endl;
		cout<<"> ";
		cin>>opt; // getting option
		cin.ignore();  // ignoring input stream buffer
		ifstream file;  // input file stream to read binary file
		ofstream temp;   // output file stream to write temporary data
		switch(opt)  // handling user input
		{
			case 1:
				cout<<"enter staff id : ";
				cin>>id;  // getting id
				cin.ignore();   // ignoring input stream buffer
				file.open(MAIN_FILE_1, ios::binary);  // opening library staff db
				temp.open(TEMP_FILE, ios::binary);   // opening temp file with overwrite mode
				file.seekg(0, ios::beg);  // taking get cursor to begining
				while(file.read((char*)(&lib), sizeof(Library)))  // iterating loop while file cursor reaches end of file with cluster size = size of class Library
				{
					if(lib.is_ID(id))
					{	
						found = true; // setting to true
						continue;   // skipping write to temp if id exists
					}
					temp.write((char*)(&lib), sizeof(Library));  // writing to db file
				}
				file.close();  // closing file stream				
				temp.close(); // closing temporary file stream (actually output file stream)
				remove(MAIN_FILE_1);
				rename(TEMP_FILE, MAIN_FILE_1);
				// displaying message
				if(found)
				{
					cout<<"[!] Record has been successfully deleted";
				}
				else
				{
					cout<<"[!] OOPS !! ID not found";
				}
				break;
			case 2:
				cout<<"enter book id : ";
				cin>>id;  // getting id
				cin.ignore();   // ignoring input stream buffer
				file.open(MAIN_FILE_2, ios::binary);  // opening book staff db
				temp.open(TEMP_FILE, ios::binary);   // opening temp file with overwrite mode
				file.seekg(0, ios::beg);  // taking get cursor to begining
				while(file.read((char*)(&bk), sizeof(Book)))  // iterating loop while file cursor reaches end of file with cluster size = size of class Book
				{
					if(bk.is_ID(id))
					{	
						found = true; // setting to true
						continue;   // skipping write to temp if id exists
					}
					temp.write((char*)(&bk), sizeof(Book));  // writing to db file
				}
				file.close();  // closing file stream				
				temp.close(); // closing temporary file stream (actually output file stream)
				remove(MAIN_FILE_2);
				rename(TEMP_FILE, MAIN_FILE_2);
				// displaying message
				if(found)
				{
					cout<<"[!] Record has been successfully deleted";
				}
				else
				{
					cout<<"[!] OOPS !! ID not found";
				}
				break;
		}
	}

	void search_by_id()
	{
		// declared objects of two classes
		Library lib;
		Book bk;
		int opt, id;
		bool found;
		cout<<"1. Search From library staff details"<<endl;
		cout<<"2. Search From book details"<<endl;
		cout<<"> ";
		cin>>opt; // getting option
		cin.ignore();  // ignoring input stream buffer
		ifstream file;  // input file stream to read binary file
		switch(opt)  // handling user input
		{
			case 1:
				cout<<"enter staff id to search : ";
				cin>>id;  // getting id from user to search
				cin.ignore();  // ignoring input stream buffer
				file.open(MAIN_FILE_1, ios::binary);   // opening library staff db
				file.seekg(0, ios::beg);  // taking get cursor to begining
				while(file.read((char*)(&lib), sizeof(Library)))  // iterating loop while file cursor reaches end of file with cluster size = size of class Library
				{
					if(lib.is_ID(id))
					{
						found = true;  // setting found to true
						lib.show();  // calling show function
					}
				}
				file.close();  // closing file stream
				// displaying error message
				if(!found)				
				{
					cout<<"[!] "<<id<<" not found";
				}
				break;
			case 2:
				cout<<"enter book id to search : ";
				cin>>id;  // getting id from user to search
				cin.ignore();   // ignoring input stream buffer
				file.open(MAIN_FILE_2, ios::binary);   // opening book details db
				file.seekg(0, ios::beg);  // taking get cursor to begining
				while(file.read((char*)(&bk), sizeof(Book)))  // iterating loop while file cursor reaches end of file with cluster size = size of class Book
				{
					if(bk.is_ID(id))
					{
						found = true;  // setting found to true
						bk.show();  // calling show function
					}
				}
				file.close();  // closing file stream	
				// displaying error message
				if(!found)				
				{
					cout<<"[!] "<<id<<" not found";
				}			
				break;
		}
	}

	// defining delete_existing function - used to view all the data 
	void list_all_entries()
	{
		// declared objects of two classes
		Library lib;
		Book bk;
		int opt;
		cout<<"1. Show all library staff details"<<endl;
		cout<<"2. Show all book details"<<endl;
		cout<<"> ";
		cin>>opt; // getting option
		cin.ignore();  // ignoring input stream buffer
		ifstream file;  // input file stream to read binary file
		switch(opt)  // handling user input
		{
			case 1:
				cout<<"------------ Displaying Details For Library Staff ------------"<<endl;
				file.open(MAIN_FILE_1, ios::binary);   // opening library staff db
				file.seekg(0, ios::beg);  // taking get cursor to begining
				while(file.read((char*)(&lib), sizeof(Library)))  // iterating loop while file cursor reaches end of file with cluster size = size of class Library
				{
					lib.show();  // calling show function
				}
				file.close();  // closing file stream				
				break;
			case 2:
				cout<<"------------ Displaying Details For Books ------------"<<endl;
				file.open(MAIN_FILE_2, ios::binary);   // opening book details db
				file.seekg(0, ios::beg);  // taking get cursor to begining
				while(file.read((char*)(&bk), sizeof(Book)))  // iterating loop while file cursor reaches end of file with cluster size = size of class Book
				{
					bk.show();  // calling show function
				}
				file.close();  // closing file stream				
				break;
		}
	}

	// defining modify_existing_entry function - used to change existing data
	void modify_existing_entry()
	{
		// declared objects of two classes
		Library lib;
		Book bk;
		int opt, id;
		bool found = false;
		cout<<"1. Delete from library staff details"<<endl;
		cout<<"2. Delete from book details"<<endl;
		cout<<"> ";
		cin>>opt; // getting option
		cin.ignore();  // ignoring input stream buffer
		ifstream file;  // input file stream to read binary file
		ofstream temp;   // output file stream to write temporary data
		switch(opt)  // handling user input
		{
			case 1:
				cout<<"enter staff id : ";
				cin>>id;  // getting id
				cin.ignore();   // ignoring input stream buffer
				file.open(MAIN_FILE_1, ios::binary);  // opening library staff db
				temp.open(TEMP_FILE, ios::binary);   // opening temp file with overwrite mode
				file.seekg(0, ios::beg);  // taking get cursor to begining
				while(file.read((char*)(&lib), sizeof(Library)))  // iterating loop while file cursor reaches end of file with cluster size = size of class Library
				{
					if(lib.is_ID(id))
					{	
						found = true; // setting to true
						lib.modify(); // modifying details
					}
					temp.write((char*)(&lib), sizeof(Library));  // writing to db file
				}
				file.close();  // closing file stream				
				temp.close(); // closing temporary file stream (actually output file stream)
				remove(MAIN_FILE_1);
				rename(TEMP_FILE, MAIN_FILE_1);
				// displaying message
				if(found)
				{
					cout<<"[!] Record has been successfully modified";
				}
				else
				{
					cout<<"[!] OOPS !! ID not found";
				}
				break;
			case 2:
				cout<<"enter book id : ";
				cin>>id;  // getting id
				cin.ignore();   // ignoring input stream buffer
				file.open(MAIN_FILE_2, ios::binary);  // opening book staff db
				temp.open(TEMP_FILE, ios::binary);   // opening temp file with overwrite mode
				file.seekg(0, ios::beg);  // taking get cursor to begining
				while(file.read((char*)(&bk), sizeof(Book)))  // iterating loop while file cursor reaches end of file with cluster size = size of class Book
				{
					if(bk.is_ID(id))
					{	
						found = true; // setting to true
						bk.modify();   // modifying details
					}
					temp.write((char*)(&bk), sizeof(Book));  // writing to db file
				}
				file.close();  // closing file stream
				temp.close(); // closing temporary file stream (actually output file stream)
				remove(MAIN_FILE_2);
				rename(TEMP_FILE, MAIN_FILE_2);
				// displaying message
				if(found)
				{
					cout<<"[!] Record has been successfully modified";
				}
				else
				{
					cout<<"[!] OOPS !! ID not found";
				}
				break;
		}
	}
}

#endif