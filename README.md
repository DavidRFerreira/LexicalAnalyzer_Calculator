# lexicalAnalyzer_Calculator

## Description
This is the implementation of a Lexical Analyser for expressions that we would expect from on a simple calculator. For that, I implemented an deterministic finite automaton (DFA) and therefore a transition table using the C language. <br />

## Compilers and Lexical Analysers
Compilers are fundamental to modern computing. They translate human-oriented programming languages into computer-oriented machine languages.<br />

A Lexical Analyser (or tokenizer) is the first phase in compiler designing. It takes a sequence of characters (like, for example, the code who write in your IDE) and returns a sequence of tokens. A token is a sequence of characters which represents a unit of information in the source program. <br />

Then, the Lexical Analyser "sends" the tokens to the Syntatic Analyser (or parser) that checks if the given input is in the correct syntax of the programming language in which the input which has been written. 

## A Lexical Analyser for a Calculator
The Lexical Analyser implemented takes a simple mathematic expression and returns the tokens present on that same expression, making the job of a potential/possible Syntatic Analyser (parser) much easier.

Basically, this algorithm returns the tokens present in a given input expression (operator, left parentheses, right parentheses, integer or float). 

## Deterministic Finite Automaton (DFA) and Transition Table Implemented

## Test 1 (input & output)

## Test 2 (input & output)

## Test 3 (input & output)
