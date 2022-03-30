Implement a multi file program using 3 different files and header files as follow
* main.c - main code and calls functions from other source code files
    * Do not upload this file and hence no changes at user end is useful
* compute.c - implements functions to calculate sum, difference, division and multiplication of complex numbers
* compute.h - provides prototype for the below functions
    * complex_t is a typedef for structure which has 2 float numbers.
    * complex_t complex_sum(complex_t C1, complex_t C2)
    * complex_t complex_difference(complex_t C1, complex_t C2)
    * complex_t complex_multiply(complex_t C1, complex_t C2)
    * complex_t complex_divide(complex_t C1, complex_t C2)
        * note: return (0 + i0) if C2 is (0 + i0).

complex.h and main.c files contains all the required functions and header files and user need to implement compute.h and compute.c files only. 
Upload compute.h and compute.c file to submitty. Adding any other file will cause errors and losing of the score.


Score:
* This activity carries 10 marks
    * 1 - Successful Compilation
    * 1 - Correct output for Samples test case
    * 2 for each hidden test cases (4 hidden test cases)
* Full score can be achieved in first 3 submissions only
* Every submission after 3rd will deduct 2 marks for every new submission.
    * 4th submission deducts 2 marks from the score
    * 5th submission deducts 4 marks from the score
    ...
    * 8th submission deducts 8 marks from the score
    * 9the submission deducts 10 marks from the score

Timeline:
* The server runs on UTC timezone and hence the deadline on the server is shown as 6 hours additional.
* Refer to the submitty for deadline of this activity
