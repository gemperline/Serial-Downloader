# Serial-Downloader

//  program to download files one at a time from the internet

Upon receiving the "wget" command from the user, this program will execute a series of downloading processes by forking parent processes to create child processes. 

Each child process will read the next URL from a text file, and subsequently download the URL file.

Each parent process will wait for its child process to complete and terminate before the parent may terminate. 

The download processes will occur one-at-a-time, and the program will terminate after all downloads are complete.
