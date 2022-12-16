// You need to use https://copy.sh/brainfuck/ to run 
// this code.
  
/** Using different cells to store different numeric values
  * Cell 1 = 70; Cell 2 = 80; Cell 3 = 30
  * These base values can then be incremented or decremented
  * to store ASCII values of the characters we need to print */
++++++++++ //Cell 1 = 70(To run the loop 10 times)
[
>+++++++ // Cell 1 = 7*10 
>++++++++ // Cell 2 = 8*10
>+++ // Cell 3 = 3*10
<<<- // Setting the pointer back to cell 0 & decrement
] // end of loop
  
/**Final numeric values in each cell
   *Cell 0 = 0; Cell 1 = 70; Cell 2 = 80; Cell 3 = 30*/
  
// Moving from Cell 0 to Cell 1
>+.--..++++++. // Printing "GEEK"(ASCII 71, 69, 69 75)
  
// Moving from Cell 1 to Cell 2
>+++. // Printing "S"(ASCII 83)
  
// Moving from Cell 2 to Cell 3
>++. // Printing " "(ASCII 32)
  
// Moving the pointer back to Cell 1
<<-----. // Printing "F"(ASCII 70)
  
//Moving from Cell 1 to Cell 2
>----.+++. // Printing "OR"(ASCII 79, 82)
  
// Moving from Cell 2 to Cell 3
>. // Printing " "(ASCII 32)
  
//Moving from Cell 3 to Cell 1
<<+.--..++++++. //Printing "GEEK"(ASCII 71, 69, 69 75)
  
//Moving from Cell 1 to Cell 2
>+. //Printing "S"(ASCII 83)
