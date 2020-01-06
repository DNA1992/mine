#  C - Stacks, Queues - LIFO, FIFO
This document stores a simple description of each file in the  [monty](https://github.com/arvicrin/monty) repository.

## Files
[chooseopc.c:](https://github.com/arvicrin/monty/blob/master/chooseopc.c "chooseopc.c")
Choose the right opcode to be execute.

[intermonty.c:](https://github.com/arvicrin/monty/blob/master/intermonty.c "intermonty.c")
Interprete commands in monty code.

[linetoken.c:](https://github.com/arvicrin/monty/blob/master/linetoken.c "linetoken.c")
Tokenize (Phrase) a complete line.

[main.c:](https://github.com/arvicrin/monty/blob/master/main.c "main.c")
Inicialitize the interpreter.

[monty.h:](https://github.com/arvicrin/monty/blob/master/monty.h "monty.h")
Header of the project (here are all libraries and prototypes functions).

[opcodefun1.c](https://github.com/arvicrin/monty/blob/master/opcodefun1.c "opcodefun1.c")
Contain the functions: push, pall, pint, pop and swap.

- push: pushes an element to the stack
- pall: (print) prints all the values on the stack
- pint: prints the value at the top of the stack
- pop: removes the top element of the stack
- swap: swaps the top two elements of the stack

[opcodefun2.c](https://github.com/arvicrin/monty/blob/master/opcodefun2.c "opcodefun2.c")
Contain the functions: add, nop, sub, div and mul.

- add: adds the top two elements of the stack
- nop: doesn’t do anything
- sub: subtracts the top element of the stack from the second top element of the stack
- div: divides the second top element of the stack by the top element of the stack
- mul: multiplies the second top element of the stack with the top element of the stack

[opcodefun3.c](https://github.com/arvicrin/monty/blob/master/opcodefun3.c "opcodefun3.c")
Contain the functions: mod, com and pchar.

- mod: computes the rest of the division of the second top element of the stack by the top element of the stack
- com: treat this line as a comment (don’t do anything) if find a # at the beggining
- pchar: prints the char at the top of the stack

## Reference 
[Use extern to share variables between source files](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
[Difference between stack and queue data structures/](https://www.geeksforgeeks.org/difference-between-stack-and-queue-data-structures/)
## Autors
[Arturo Victoria Rincón](https://twitter.com/arvicrin)
