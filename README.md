# cs136_l3_jb

Lab 3: Stack

Assignment Description:

Write a menu-driven program that determines if an expression is well-formed (balanced) using the stack data structure.

Specifications & Requirements:

Menu Options-

~~Process all expressions from a file at once.~~

~~Output the original expression.~~

~~Determine if an expression is well-formed (balanced).~~

~~Output the expression with only opening and closing symbols.~~

~~Option to quit.~~

Expression Rules-

~~Expressions may not exceed 60 characters.~~

~~If an expression is too long, issue an error message.~~

~~Expressions may contain any characters, including whitespace.~~

~~The language supports the following opening and closing symbols:~~

() (parentheses)

{} (curly brackets)

[] (square brackets)

<!-- X --> (HTML comments, where X is content)

/* X */ (C-style comments)

"X" (double-quoted strings)

'X' (single-character literals)

~~A well-formed expression has properly nested and matching opening/closing symbols.~~

Example (Balanced): (hkj hkj{hj shj})

Example (Not Balanced): (hkj hkj{)hj shj}

Output Format-

~~Display original expression.~~

~~Display expression with only opening and closing symbols, separated by spaces.~~

~~Present the output in a table format for readability.~~

Stack Implementation-

~~Implement a stack using an array-based approach.~~

~~Write the stack as a class.~~

~~A stack item can be a struct or class.~~

~~No constructors required.~~

File Handling-

~~Read expressions line by line from a file.~~

~~Store each line as a string.~~