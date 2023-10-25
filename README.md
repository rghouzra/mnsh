# Minishell (mnsh)

Minishell is similar to a simple Bash executor and reader.

## Steps

In general, we use Bash as a reference, for example, when splitting with whitespaces and operators.

- [Bash Manual - Basic Shell Features](https://www.gnu.org/software/bash/manual/bash.html#Basic-Shell-Features)
- Generating an abstract syntax tree with the help of the Shunting Yard algorithm.
  - [Shunting Yard Algorithm](https://brilliant.org/wiki/shunting-yard-algorithm/)

The last step involves traversing our tree recursively and evaluating whether it's an operator or a command.
