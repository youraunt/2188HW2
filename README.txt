*******************************************************
*  Name      :	Brice Allen          
*  Student ID:	107452188                 
*  Class     :  CSC 2421           
*  HW#       :  2                
*  Due Date  :  Feb. 10, 2020
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program "2188HW2" implements the kSMall algorithm.
The user provides an integer which represents the kth 
Smallest integer in an unsorted array. This program was 
an exercise to teach about recursion. 
A high level look of the algorithm is as follows:
1. Select a pivot item in the array (zero in our case)
2. Partition the items in the array about the pivot item, selected in step 1.
3. Recursively apply the strategy to one of the partitions 
(because the kth smallest item will be in either one or the other.)

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from the user.

Name:  functions.h
   Contains the prototypes for the class function.

Name: function.cpp
   Defines and implements the functions class for implementing a kSmall object.
   This class provides routines recursively call kSmall, 


   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 4.4.2.  It was 
   compiled, run, and tested on gcc csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip 2188HW1

   Now you should see a directory named homework with the files:
	main.cpp
	functions.h
	functions.cpp
	makefile
	Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd 2188HW2 

    Compile the program by:
    % make

3. Run the program by:
   % ./2188HW2

4. Delete the obj files, executables, and core dump by
   %./make clean
