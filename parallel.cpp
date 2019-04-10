//CPSC 351: PROJECT 1
//TEAM: ADAM G.  &  VICTORIA T.

// A LINUX downloader tool that will create child processes by forking. 
// These processes result in parallel downloads from URL addresses.


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
 // *ISSUE HERE: This gets the number of urls in the file but i think since this has getline,
 // the other while loop will not execute

//*****// SOLVED: close the file read stream after counting the lines in File
//*****// this allows the read cursor to be reset to the beginning of file when
//*****// reopened.	-AG

				 while (getline(inFile, url))
				{
					if(url.find( "http") != -1)
					 { urlCounter++; }
				}
				cout << "Number of URLS: " << urlCounter << endl;
				//Closes file
							inFile.close();
							cout << "\n Data file closed ..." << endl;

//*****// CONTINUED: reopen the file, read cursor will start at beinning
				inFile.open("urls.txt");

					// Parent forks off the same number of children as the number of urls
					for (int i = 0; i < urlCounter; i++)
					{
						//Loops through the file
						if (inFile.is_open() && getline(inFile,url))
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
						}
					}
					//Parent process waits for ALL children processes to terminate
					wait(NULL);

				//Closes file
				inFile.close();
				cout << "\n Data file closed ..." << endl;

			}
			else
			{
				cout << "ERROR: unexpected command" << endl;
			}
		}
	} while (cmdBuff != "exit");

	return 0;
}
