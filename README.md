Authoring: 
  Ashley Biscoe
  CMSC 313 2:30 Mon/Wed
Purpose of Software:
  Simulate a matrix library with matrix functions such as addition, subtraction, multiplication (both matrix and scalar), and transpose in both the C++ and C languages.
Files:
  matrix_library.cpp : The C++ version of the programmed matrix library.
  matrix_library.c : The C version of the programmed matrix library.
Build Instructions:
  For matrix_library.cpp: 
    Compile: g++ -Wall matrix_library.cpp -o matrix_library
    Run: ./matrix_library
  For matrix_library.c:
    Compile: gcc matrix_library.c -o matrix_l
    Run: ./matrix_l
Testing Methodology:
  I calculated the output of the provided equation. I then compared the outputs of my program after each operation to the calculated solutions to make sure each function performs the calculations correctly. To view   the outputs, I coded a print function to display the arrays in matrix form.
Additional Information:
  Matrices must be coded into main, the program does not ask the user for matrices.
