// You need to use https://ciopy.sh/brainfuck/ to run 
// this code.
  
/** Using different cells to store different numeric values
  * Cell 1 = 80; Cell 2 = 100; Cell 3 = 110
  * These base values can then be incremented or decremented
  * to store ASCII values of the characters we need to print */
++++++++++ //Cell 1 = 80(To run the loop 10 times)
[
>++++++++ // Cell 1 = 8*10 
>++++++++++ // Cell 2 = 10*10
>+++++++++++ // Cell 3 = 11*10
<<<-
]
  
/**Final numeric values in each cell
   *Cell 0 = 0; Cell 1 = 80; Cell 2 = 100; Cell 3 = 110*/
  
// Moving from Cell 0 to Cell 1
>+++. // Printing "S"(ASCII 83, 99, 111,111,108)
//Moving Cell 1 to Cell 2
>-. // Printing "c"(Ascii 99)
>++..---. // Printing "ool"(ascii value of o is 111 and l is 108)
