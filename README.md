**DESCRIPTION**

In this project we measure and compare time spent with the execution of the given 10 functions with some number of threads. Execution is done over an array which is created in the beginning of the program and has length of N filled with integers between 1000 and 10000 which is given as program argument. Some of the given functions are:

- Min
- Max
- Range
- Median
- Harmonic Mean
- Interquartile Range

This implementation only allows for 1,5 or 10 thread. In 1 thread implementation there is no thread implementation and results are directly assigned to results array. In 5 thread implementation , 5 thread handles 2 function each then assign the results. In 10 thread implementation, each thread handles 1 function and assign result. In all implementations results are written to the results array with the fixed index in order to not mix the order of the results. After all threads finished the functions all results are written to the output file.

**FILE DESIGN**

There is 2 cpp 1 header and 1 Makefile. Main thread (main.cpp) file get arguments and according to these arguments create threads and measure time spent. Then print the results and duration(last line) to the output file. Another file(functions.cpp) includes all implementation of given functions and some methods which execute two functions. All function methods assign acquired result to results  array with the fixed index. Header file includes all variables,library import,macros and methods which are used for other cpp files. Makefile includes compilation and linking for cpp files with required flags.

**EXECUTION**

After execute make command Makefile creates an executable named “main.exe”. This executable takes 2 arguments. First one is length of array,second one is thread number. Results are written to the output file and duration is also written to last line. Also output file name differs with thread implementation is exist or not(output1.txt for no thread implementation, output2.txt for thread implementation).

Example Execution

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ./main.exe 10000  5

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  ./main.exe 2000  1

Note: All thread number parameters expect than 1,5,10 will be considered as 1 then no thread implementation will be executed.  

**CONCLUSION AND RESULTS**

I observed the time difference after execute program with some number of threads and array length.   10 or 5 thread implementation is nearly 2 times faster than no thread implementation and their execution times are close to each other. Normally we expect 5 times faster in 5 thread implementation and 10 times faster in 10 thread implementation but there is not. I think reasons can be improper functions, small numbers of N to observe time difference, random splitting of functions in 5 thread implementation(This causes unbalanced distribution of jobs). Also thread creations can get considerable amount of time.
