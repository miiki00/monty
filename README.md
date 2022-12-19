# Monty 0.98

# What is Monty ?

Monty is a simple interpreted [Stack-oriented scripting language](https://en.wikipedia.org/wiki/Stack-oriented_programming) with no capability of coditional decision making. It was a school project from our school ALX Holberton.<br>
Here is an example input output of the monty interpreter.
```
$ cat file      
push 121 # pushs an element to the top of the stack.
push 100
push 111
push 98
push 121
push 114
push 101
push 118
push 69
push 32
push 105
push 72
pstr # prints all the values from top to bottom with respective ascii value.
pall # print all the stack elements
add  # add the top two elements of the stack
mul  # multiplies the to two elements of the stack.
rotl # puts the top element of the stack at the end of the stack.
pall
rotr # puts the bottom element of the stack at the top of the stack
pall

$ monty file          
Hi Everybody
72 - Top of the stack 
105
32
69
118
101
114
121
98
111
100
121
69 - Top of the stack after the add, push, and rotl operator.
118
101
114
121
98
111
100
121
5664 - End of stack
5664 - Top of the stack after the rotr operation.
69
118
101
114
121
98
111
100
121

```

## Installation Guide

First clone the repo to your local machin by executing the folowing command in your terminal, assuming that you have git installed on your machine.
```
git clone https://github.com/miiki00/monty.git
```
After you have the source locally it is easy to build monty. You just have to have a C compiler on your machine. In this example I am using [gcc](https://gcc.gnu.org/).
```
cd monty/
gcc -std=gnu89 *.c -o monty
```
Then if you want to play with often you can add it to one of your $PATH environment so you don't have to go to the installed directory every time you want to execute monty<br>
> Tip: on most UNIX-like system `/usr/bin` is where most of your executables are stored on windows it may have a different step so feel free to scrap the internet a little
> When I mean monty I am talking about the executable and not the direcotry.
```
mv monty /path/to/one/of/your/path/environment/
```

You can also use it with out adding it to your path. here is how and also assuming you are in the directory where the executable is located.
```
./monty file
```
## Monty's operators/commands and Usage.

> NOTE: monty can only interpret one command perline any thing you put after a valid command will not be taken to account

### Manipulating the stack.

When monty startes interpreting a source file it startes with an empty stack so you have only two option to what you first line of your source file can be
the first pushing and element to the stack or changing the mode in which the stack operates on.<br>
The stack operated in to modes stack and queue. Stack(LIFO) mode is where both addition and deletion that happen on the stack takes place from one end (ie TOP, BOTTOM).<br>
The default is stack. Queue(FIFO) mode is where deletion happens at one end and addition happens from the other. you can go back and forth it's no problem for monty. In the case of monty when it's operating in Stack mode both addition and delition happen at the top of the stack. and in the case of Queue mod deletion takes place at the top of the stack and addition happens at the end of the stack.<br>

Here is some example input output of monty while operating in stack mode and queue mode.
```
$ cat file.m
stack # getting it to operate in stack mode (but it's not necessary in the case of stack as it's the default).
push 3 # you will see that thing will appear in revers order pushing while you are in stack mode.
push 2
push 1
pall # prints all the elements
pop # deleting elements.
pop
pop
pstr # printing new lines 
pstr
queue # getting it to operate in queue mode.
push 1 # in the case of queue things will appear in the same order they were pushed.
push 2
push 3
pall

$ monty file.m
1
2
3


1
2
3
```
Here is a complete list of monty commands/operators.

| Command | Description |
|:---	  |:---			|
| push	  | Adds an integer into the stacks top/bottom base on the mode you are in.<br>syntax: `push <integer>`. |
| pall    | Prints all the integers in the stack. |
| pop     | Delets the top element of the stack. |
| pint	  | Prints the top element of the stack. |
| swap	  | Swaps the index of top and the second top element. |
| add	  | Adds the top two elements and stors the sum at the second element and deletes the top element. |
| nop	  | Does nothing. |
| sub	  | Just like add but instead of adding it is for substracting the top element from the second element. |
| mul     | Just like add but instead of adding it is for multiplying the top two elements by each other. |
| div 	  | Just like add but instead of adding it is for dividing the second element by the top one. |
| mod     | Just like add but instead of adding it is for find the mod of the second element divided by the top. |
| pchar   | Prints the top element's corresponding assci value it it have one else error will be printed. |
| pstr	  | Prints the stack element's correspoonding assci value and it won't stop until NUll terminator is found, stack ends or value is out of range |
| rotl    | Takes the top element of the stack an puts it at the end. |
| rotr    | Takes the last element and puts it at the top. |
| stack   | The stack follow LIFO properties. (both addition and deletion takes place on one end) |
| queue   | The stack follows FIFO properties. (addition takes place at the rear of the stack and deletion takes place at the front of the stack.) |

## Authors
* [Emebet Worku](mailto:emuyoha21@gmail.com) : [@emutialx](https://github.com/emutialx/)
* [Mikias Abiy](mailto:mikiasabiy16@gmail.com) : [@miiki00](https://github.com/miiki00/)


### Thankyou for visiting !!!
