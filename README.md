<p align="center">
  <img alt="🔃edU" src="https://user-images.githubusercontent.com/62103572/182589849-2a5e6200-f7fd-434e-a9c8-6855ee4ea3f9.png">
  <img alt="GitHub commit activity" src="https://img.shields.io/github/commit-activity/y/EliaFantini/edU-command-line-text-editor-w-multiple-Un-Redo">
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/EliaFantini/edU-command-line-text-editor-w-multiple-Un-Redo">
  <img alt="GitHub code size" src="https://img.shields.io/github/languages/code-size/EliaFantini/edU-command-line-text-editor-w-multiple-Un-Redo">
  <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/EliaFantini/edU-command-line-text-editor-w-multiple-Un-Redo">
  <img alt="GitHub file count" src="https://img.shields.io/github/directory-file-count/EliaFantini/edU-command-line-text-editor-w-multiple-Un-Redo">
  <img alt="GitHub follow" src="https://img.shields.io/github/followers/EliaFantini?label=Follow">
  <img alt="GitHub fork" src="https://img.shields.io/github/forks/EliaFantini/edU-command-line-text-editor-w-multiple-Un-Redo?label=Fork">
  <img alt="GitHub watchers" src="https://img.shields.io/github/watchers/EliaFantini/edU-command-line-text-editor-w-multiple-Un-Redo?abel=Watch">
  <img alt="GitHub star" src="https://img.shields.io/github/stars/EliaFantini/edU-command-line-text-editor-w-multiple-Un-Redo?style=social">
</p>

EdU (*ed*itor with *U*ndo) is an highly efficient text editor (in time (ms) and space (RAM usage)), with a multiple undo/redo feature. The program utilizes the command line interface and works with textual input commands. This project was made as an assignment for Algorithms and Data Structures (2019-2020).

## Author
- [Elia Fantini](https://www.github.com/EliaFantini)
## Demo
<p align="left">
  <img src="https://user-images.githubusercontent.com/62103572/182596421-8dab82ee-64d8-4c48-8c00-6351123a364a.gif" alt="GIF demo"/>
</p>

## Installation

Download the repository and extract everything into a folder. The code has already been compiled as "runnable.exe", which can be run directly by double clicking it on any machine with a Windows OS. Otherwise, to compile and run the "code.c" file, type the following commands into a terminal or command prompt opened in the folder where you extracted the zip's content:
```bash
  gcc code.c -o runnable
  ./runnable
```
You can now use the text editor :keyboard:.

## How to use


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
![carbon (1)](https://user-images.githubusercontent.com/62103572/182599405-18fa058d-ae90-44e8-a224-b2e62690aa5e.png)
## 🛠 Skills
Basics of C ad standard libraries. Optimization of RAM usage and execution time with highly efficient data structures.

## 🔗 Links
[![portfolio](https://img.shields.io/badge/my_portfolio-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://github.com/EliaFantini/)
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/-elia-fantini/)

