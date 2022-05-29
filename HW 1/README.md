# How to Use junk.sh
junk.sh creates a hidden directory called /.junk that contains recycled files, similar to the recycle bin in Windows.

## Arguments
If no argument is provided, a usage statement will be printed.\
-h: Displays help\
-l: Lists all of the recycled, or junked, files\
-p: Deletes all of the files inside /.junk\
[list of files]: Move those files, if they exist, into /.junk

## Function
If an existing file is listed as an argument, that file will move into the junk directory, making it recycled. If a file does not exist, then an error will be printed out.\
![Example](C:\Users\barry\OneDrive\Pictures\Screenshots\Example.png)

## WARNING
If your end-of-line sequence is not LF (e.g.: CR or CRLF), change it to LF because Bash does not recognize any other end of line sequence other than LF. You can change this by opening junk.sh in VS Code and go to the bottom right.\
![Bottom Right of VS Code](C:\Users\barry\OneDrive\Pictures\Screenshots\CRLF.png)

Click on CRLF and move to the top center of VS Code. Here, change the sequence to LF.\
![Top Center of VS Code](C:\Users\barry\OneDrive\Pictures\Screenshots\Selection.png)