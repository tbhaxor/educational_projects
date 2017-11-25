#ifndef ACTOR_H
#define ACTOR_H

// including header files and libraries
#include "library.h"
#include "book.h"
#include "config.h"
#include <iostream>

namespace Actor
{
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
				file.open(MAIN_FILE_1, ios::binary || ios::app);   // opening binary file in append mode
				lib.get();  // getting data from user
				file.write((char*)(&lib), sizeof(Library));   // writing data to file
				file.close();   // closing output file stream
				break;
			case 2:
				file.open(MAIN_FILE_2, ios::binary || ios::app);   // opening binary file in append mode
				bk.get();  // getting data from user
				file.write((char*)(&bk), sizeof(Book));   // writing data to file
				file.close();   // closing output file stream
				break;
		}

	}
}

#endif