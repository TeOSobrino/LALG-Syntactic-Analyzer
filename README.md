# LALG-Compiler
## Usage 

```bash
make all
./lalgc -i <input_file> [ -t [AST_output]] 
```
The input file must be passed after the flag -i (or --input).

The output file (optional) is an AST, to generate this file specify the '-t' flag.
The AST is generated when parsing the code and represents the rules being applied in a high-level fashion.

TODO:
Comments, Docs, Rewrite code and, maybe improve error mesages, colors, style, etc.
