# Project for Algorithms and Data Structures a.a. 2019-2020
The aim of the project is to implement an highly efficient text editor ( in time (ms) and space (RAM usage) ), with a multiple undo/redo feature. The program utilizes the command line interface and works with textual input commands.

## Input commands


The program accepts the following inputs:

- (ind1, ind2)c:  changes the text present on the lines between ind1 and ind2 (extremes
included). The text following the command must be a number of
lines equal to ind2-ind1 + 1. ind1 must actually be either an address
present in the text, or the first address after the last line present
in the text (or 1 if the text is still empty).
- (ind1, ind2)d: deletes the lines between ind1 and ind2 (extremes included), by moving
upwards the lines following that of address ind2 (if there are any).
Deleting a line that does not exist in the text has no effect.
- (ind1, ind2)p: prints the lines between ind1 and ind2 (or between ind1 and the end of the text
if ind2 does not match any address in the text). For each non-existing row  between ind1 and ind2 (included) the editor prints
a line containing only the dot character.
- (number)u: undo a number of commands (c or d) equal to the one specified in parentheses (an integer strictly greater than zero). A sequence of consecutive undo commands
cancels a number of steps equal to the sum of the steps specified in each of them. If the number of commands to be canceled is 
higher than that of the commands executed, all steps are canceled.
The execution of a text modification command (c, d) after an undo
cancels the effects of the permanently canceled commands. Note that in the
number of commands to cancel the no-effects commands (for example deleting a block of lines that
do not exist) are also counted.
- (number) r: cancels the effect of undo for a number of commands equal to the starting number
from the current version. The number must be
an integer strictly greater than zero. We therefore have that a sequence
of commands like
10u
5r
is equivalent to the 5u command only. Similarly, the sequence
12u
3r
2u
7r
is equivalent to the 4u command. If the number of commands to be redo is greater than those currently canceled, it is performed
the maximum number of redos possible.
- q: finishes the execution of the editor.

## Example

### Input: 
1,2c<br />
first line<br />
second line<br />
.<br />
2,3c<br />
new second line<br />
third row<br />
.<br />
1,3p<br />
1,1c<br />
new first line<br />
.<br />
1,2p<br />
2,2d<br />
4,5p<br />
1,3p<br />
4,5d<br />
1,4p<br />
3u<br />
1,6p<br />
1r<br />
1,3p<br />
q<br />


### Output:
first line<br />
new second line<br />
third row<br />
new first line<br />
new second line<br />
.<br />
.<br />
new first line<br />
third row<br />
.<br />
new first line<br />
third row<br />
.<br />
.<br />
first line<br />
new second line<br />
third row<br />
.<br />
.<br />
.<br />
new first line<br />
new second line<br />
third row<br />
