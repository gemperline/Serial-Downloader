//CPSC 351: PROJECT 1
//TEAM: ADAM G.  &  VICTORIA T.

//**PROJECT INCOMPLETE**
//OUTPUT: Able to read file, able to get # of url counter, but does not proceed with the rest of the download.
//ISSUES:
//If I ignore the while loop that gets the # of urls and set a default value for the num of urls (ex: urlCount=5), it will download
//but it will download the first url and repeat the download for the same loop 
//Also, we need a way to get the children processes to execute execlp(----) where it takes in a distinct URL from the text?


//Parallel Downloader
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{

	// The Input File 
	ifstream inFile;
	string input;
	string url;
	int urlCounter = 0;

	// The command buffer 
	string cmdBuff;
	// The ID of the child process 
	pid_t childPid;

	// Keep running until the user has typed "exit"
	do 
	{
		// Prompt the user to enter the command 
		cerr << "cmd>";
		cin >> cmdBuff;

		// If the user did not enter exit 
		if (cmdBuff != "exit")
		{
			// If user enters 'wget', the program will open the urls.txt 
			// and check if it was opened successfully
			if (cmdBuff == "wget")
			{
				inFile.open("urls.txt");
				if (inFile.is_open())
				{
				cout << "URL file opened sucessfully ..." << endl;
				}
				else
				{
					cout << "ERROR: could not open file" << endl;
					exit(0);
				}

			//Loops through file and counts the number of urls in urls.txt
  //*ISSUE HERE: This gets the number of urls in the file but i think since this has getline,
 // the other while loop will not execute 
  
				 while (getline(inFile, url))
				{
					if(url.find( "http") != -1)
					 { urlCounter++; }
				}
				cout << "Number of URLS: " << urlCounter << endl;
				

				//Loops through the file
				while (inFile.is_open() && getline(inFile,url))
				{
					// Parent forks off the same number of children as the number of urls
					for (int i = 0; i < urlCounter; i++)
					{
						childPid = fork();

						// Check to make sure the child was successfully created 
						if (childPid < 0)
						{
							cout << "Fork failed";
						}
						else if (childPid == 0)
						{
				cout << "Child process was successfully created" << endl;
					cout << "URL read and passed: " << url << endl;
				execlp("/usr/bin/wget", cmdBuff.c_str(), url.c_str(), NULL);
						}
						//Parent process waits for all children processes to terminate
						else
						{
							wait(NULL);
							cout << "Child complete" << endl;
							//Closes file
						inFile.close();
						cout << "\n Data file closed ..." << endl;
						}
					}
				}
				//Closes file
				if(inFile.is_open())
				{
					inFile.close();
				 	cout << "\n Data file closed ..." << endl;
				}
			}
			else
			{
				cout << "ERROR: unexpected command" << endl;
			}
		}
		return 0;
	} while (cmdBuff != "exit");
}
