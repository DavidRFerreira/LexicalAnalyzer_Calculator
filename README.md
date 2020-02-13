# lexicalAnalyzer_Calculator

## Description
This is an implementation of a Lexical Analyser for expressions that we would expect from a simple calculator. For that, I implemented a deterministic finite automaton (DFA) and therefore a transition table using the C language. <br />
I used Dev-C++ as the IDE to develop this algorithm.

## Compilers and Lexical Analysers
Compilers are fundamental to modern computing. They translate human-oriented programming languages into computer-oriented machine languages.<br />

A Lexical Analyser (or tokenizer) is the first phase in compiler designing. It takes a sequence of characters (like, for example, the code which you write on your IDE) and returns a sequence of tokens. A token is a sequence of characters which represents a unit of information in the source program. <br />

Then, the Lexical Analyser "sends" those tokens to the Syntatic Analyser (or parser) that checks if the given input is in the correct syntax of the programming language in which the input has been written. 

<br />
## Further Reading <br />
Holub, A. (1990). Compiler Design in C. Prentice-Hall.<br />
Fischer, C., & LeBlanc, R. (1991). Crafting a Compiler With C. Pearson.

## A Lexical Analyser for a Calculator
The Lexical Analyser implemented takes a simple mathematical expression and returns the tokens present on that same expression, making the job of a potential/possible Syntatic Analyser (parser) much easier. <br />

Basically, this algorithm returns the tokens present in a given input expression (operator, left parentheses, right parentheses, integer or float). 

## Deterministic Finite Automaton (DFA) and Transitions Table Implemented
<br />

![AFD](https://github.com/DavidRFerreira/lexicalAnalyzer_Calculator/blob/master/images/DFA.png)
<br />
<br />
![Transitions Table](https://github.com/DavidRFerreira/lexicalAnalyzer_Calculator/blob/master/images/transitionsTable.png)
<br />
<br />

## Test 1 (input & output)
<br />
********* input.txt ********* <br />
123.43 + 123 * 4 <br />
<br />
<br />
********* output.txt ********* <br />
------------------------------------------------------<br />
INPUT EXPRESSION: 123.43 + 123 * 4<br />
<br />
RECOGNIZED TOKENS: <br />
Float   Operator   Integer   Operator   Integer <br /> 
<br />
<br />

## Test 2 (input & output)
<br />
********* input.txt ********* <br />
(4321 - 12.2) + dasd423 <br />
324 / 2 <br />
<br />
<br />
********* output.txt ********* <br />
------------------------------------------------------ <br />
INPUT EXPRESSION: (4321 - 12.2) + dasd423 <br />
<br />
RECOGNIZED TOKENS: <br />
Left-Parentheses   Integer   Operator   Float   Right-Parentheses   Operator   Invalid   Invalid   Invalid   Invalid   Integer <br />
------------------------------------------------------ <br />
INPUT EXPRESSION: 324 / 2 <br />
<br />
RECOGNIZED TOKENS: <br />
Integer   Operator   Integer   <br />

<br />
