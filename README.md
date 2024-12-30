# Minishell (mnsh)

Minishell is a simple Bash executor and reader.

## Overview

Minishell is a lightweight shell implementation inspired by Bash, designed to execute and interpret shell commands.

### Process Flow

This flowchart provides an overview of both tokenization and parsing steps:

[Minishell Flowchart](https://miro.com/app/board/uXjVMVi2_R4=/?share_link_id=555534915885)

## Implementation

To achieve Minishell's functionality, we follow these key steps:

1. **Tokenization**: In general, we use Bash as a reference, particularly for splitting commands into tokens, handling whitespaces, and operators.
   - [Bash Manual - Basic Shell Features](https://www.gnu.org/software/bash/manual/bash.html#Basic-Shell-Features)

2. **Parsing**: We generate an abstract syntax tree (AST) using the Shunting Yard algorithm, which involves implementing our own stack and queue data structures.
   - [Shunting Yard Algorithm](https://brilliant.org/wiki/shunting-yard-algorithm/)
   - In the `srcs/utils/readinput.c`, there's a function that prints in the dot language format, producing a file named `treegraph.dot`. You can visualize this tree using [Graphviz](https://shorturl.at/YV47Z) or by installing the Graphviz extension if you're using VS Code.

3. **Execution**: The final step is traversing the AST recursively and evaluating whether each node represents an operator or a command.

### Additional Resources

- [Linux Pipes](https://tldp.org/LDP/lpg/node11.html): Learn more about handling pipes in Unix-like systems.
- [Signals](https://man7.org/linux/man-pages/man7/signal.7.html): Learn more about handling signals (SIGINT, SIGKILL).
- [I/O Multiplexing](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/): Learn about I/O operations.


## Usage

### Installation

1. Clone the repository:

```bash
git clone git@github.com:rghouzra/mnsh.git

cd mnsh
```

2. Compile the project:

```bash
mkdir build && cd build

cmake ..

make
```

