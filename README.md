# Minishell (mnsh)

Minishell is a simple Bash executor and reader.

## Overview

Minishell is a lightweight shell implementation inspired by Bash, designed to execute and interpret shell commands.

### Process Flow

This flowchart provides an overview of both tokenization and parsing steps:

[Minishell Flowchart](https://miro.com/app/board/uXjVMVi2_R4=/?share_link_id=555534915885)

## Implementation

To achieve Minishell's functionality, we follow these key steps:

1. Tokenization: In general, we use Bash as a reference, particularly for splitting commands into tokens, handling whitespaces, and operators.
   - [Bash Manual - Basic Shell Features](https://www.gnu.org/software/bash/manual/bash.html#Basic-Shell-Features)

2. Parsing: We generate an abstract syntax tree (AST) using the Shunting Yard algorithm, which involves implementing our stack and queue data structures.
   - [Shunting Yard Algorithm](https://brilliant.org/wiki/shunting-yard-algorithm/)

3. Execution: The final step is traversing the AST recursively and evaluating whether each node represents an operator or a command.

### Additional Resources

- [Linux Pipes](https://tldp.org/LDP/lpg/node11.html): Learn more about handling pipes in unix like system.
- [signals](https://man7.org/linux/man-pages/man7/signal.7.html): Learn more about handling signals(SIGINT, SIGKILL).
- [I/O multiplexing](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/): learn about i/o operations.
