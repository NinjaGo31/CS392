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
![Example](https://user-images.githubusercontent.com/56609280/170892299-4b179faa-ab84-4f0a-a01c-c479b7828486.png)

## WARNING
If your end-of-line sequence is not LF (e.g.: CR or CRLF), change it to LF because Bash does not recognize any other end of line sequence other than LF. You can change this by opening junk.sh in VS Code and go to the bottom right.\
![CRLF](https://user-images.githubusercontent.com/56609280/170892283-bd8d6405-fd61-4650-a24e-fb5f5e5f3688.png)

Click on CRLF and move to the top center of VS Code. Here, change the sequence to LF.\
![Selection](https://user-images.githubusercontent.com/56609280/170892294-885054cc-e813-4d63-9c3b-ecf8900d3e61.png)
