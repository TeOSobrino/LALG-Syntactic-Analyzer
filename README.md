# LALG-Compiler
## Alunos
Téo Sobrino (12557192)
 
Miller Anancleto

## Disciplina SCC0217 - Compiladores
## Uso 

```bash
make all
./lalgc -i <arquivo_de_entrada> [ -t [arquivo_de_saída]] 
```
O caminho para o arquivo de entrada deve ser especificado depois da flag -i (ou --input)

O arquivo de saída (opcional) é uma ASA. Para gerar este arquivo especifique a flag -t.
A ASA é gerada durante o parsing do código e representa a regras de derivação gramatical em uma visão de alto-nível.

## TODO:
Mais comentários, melhorar a documentação, fazer mais testes, melhorar as mensagens de erros, talvez usar cores, melhorar o estilo, etc.
