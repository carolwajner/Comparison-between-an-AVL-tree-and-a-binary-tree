# C Project: Dictionary Search with Binary and Balanced Binary Trees

This project consists of two separate programs. Each program reads the same input files but processes them differently. The first program uses a binary tree, while the second program uses a balanced binary tree. Both programs read a shuffled dictionary and a text input file, then output a simplified version of the text based on the dictionary.

## Programs

1. **Program 1: Binary Tree**
   - Files: `main4.c`, `arvores.c`, `arvores.h`
   
2. **Program 2: Balanced Binary Tree**
   - Files: `main5.c`, `arvores2.c`, `arvores2.h`

## Input Files

Both programs read the following input files:
- **Dictionary File**: A shuffled dictionary with words and their simplified versions, provided in the format `dicionario_shuf.txt`.
- **Input File**: A text file with the input text to be processed, provided in the format `entrada.txt`.
- **Output File**: The name of the output file where the results will be written.

## How to Run

You must provide the names of the dictionary file, input file, and output file in the terminal when running the programs.

### Running Program 1

```sh
gcc main4.c arvores.c -o program1
./program1 dicionario_shuf.txt entrada.txt saida.txt
```
### Running Program 2

```sh
gcc main5.c arvores2.c -o program2
./program2 dicionario_shuf.txt entrada.txt saida.txt
```

## Functionality

### Shared Functionality

Both programs perform the following tasks:

1. **Read the Shuffled Dictionary**:
   - Reads a dictionary file where each line contains a word and its simplified version.
   - Inserts each word into a respective tree (binary tree or balanced binary tree) in alphabetical order.

2. **Process the Input File**:
   - Reads an input text file.
   - For each word in the input file:
     - Searches for the word in the dictionary.
     - If found, writes the simplified version to the output file.
     - If not found, writes the original word to the output file.

3. **Calculate Metrics**:
   - Number of comparisons made during the tree traversal related to the input.
   - Number of rotations made (for the balanced binary tree).
   - Number of nodes in the tree.
   - Height of the tree.

### Specific to Program 1

- Uses a standard binary tree (`main4.c`, `arvores.c`, `arvores.h`).

### Specific to Program 2

- Uses a balanced binary tree (`main5.c`, `arvores2.c`, `arvores2.h`).

## Example

Given the dictionary `dicionario_shuf.txt` and input file `entrada.txt`, both programs will generate an output file `saida.txt` with the simplified text based on the dictionary. 
Metrics regarding the processing are also calculated and displayed.
