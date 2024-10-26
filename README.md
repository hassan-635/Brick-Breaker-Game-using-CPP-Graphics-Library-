# Brick-Breaker-Game-using-CPP-Graphics-Library

## Note : put all the music files (having .wav) extension in the folder name "music files" to get music

This game was made as a First Semester Project of BSCS to give strong foundation to our fundamental programming concepts.

### Graphics Library : 
This game is built using Graphics library in C++ and it will not work without installing it.
To install Graphics library You can follow these steps : 

#### 1.Download and Install Code Blocks in your system :
As i used it in Codeblocks and find it easier to do so in Codeblocks than using other IDE's
Download it from here : https://www.codeblocks.org/downloads/binaries/

#### 2.Download And Extract Libraries :
Download and Extract libraries from here : 
https://drive.google.com/file/d/16xZBvFXf7yFjxwTpuyevK1KPuLgUeZFh/view

#### 3.Copy graphics.h and winbgim.h Files into the path :
Copy "graphics.h" and "winbgim.h" files to "include" folder of CodeBlocks directory.
Default location of this folder is ("C:\Program Files (x86)\CodeBlocks\MinGW\include\")

#### 4.Copy libgia.a File into thee path :
Copy "libbgi.a" to file to "lib" folder of CodeBlocks directory.
Default location of this folder is ("C:\Program Files (x86)\CodeBlocks\MinGW\lib\")

#### 5.Settings inside Codeblocks :
Open CodeBlocks and go to (Settings > Compiler > Linker Settings)

#### 6.Link libraries : 
Link Libraries (left), Click on "Add" button, then click "Browse" and select the "libbbgi.a"
file that you have copied in CodeBlocks directory..
Default location is (C:\Program Files (x86)\CodeBlocks\MinGW\lib\libbgi.a)
and then click "Open" button.

#### 7.Linker options Copy Paste following text :
Other linker option (right), copy the text below and paste there to the other linker option
##
    -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

#### 8.Enjoy :
Click "OK"
Now grab a cup of coffee 
And Enjoy the graphics library in C++


# NOTE
The graphics.h will work only in the program saved in ".cpp" format.

### To check the graphics.h is working or not
Create a new console application in ".cpp" format and copy the codes given below, paste the
file you created and click "Build and Run" button or click "F9" key from your keyboard..

## 
    #include<graphics.h>
    int main()
    {
      int gd=DETECT,gm;
      initgraph(&gd,&gm,"");
      circle(200,200,100);
      getch();
    }
