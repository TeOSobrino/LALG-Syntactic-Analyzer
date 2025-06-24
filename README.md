# LALG-Compiler
## Alunos
Téo Sobrino (12557192)
 
Miller Anancleto (13727954)

## Disciplina SCC0217 - Compiladores

## Uso 

### Clonar o repositório

```bash
git clone git@github.com:TeOSobrino/LALG-Compiler.git
cd LALG-Compiler
```

### Criar o executável do compilador 

Cria o arquivo executável do parser (lalgc) juntamente com os arquivos gerados pelo lexer (lex.yy.c) e parser (y.tab.c e y.tab.h).

```bash
make all
```

## Compilar um programa
Escreva seu programa .lalgc, ex: (/my/file/test.lalg) e use o seguinte comando, dentro da pasta com o binário do compilador  

```bash
./lalgc -i /my/file/test.lalg [-t arvore_saida_opcional]
```
O caminho para o arquivo de entrada deve ser especificado depois da flag -i (ou --input)

O arquivo de saída (opcional) é uma ASA. Para gerar este arquivo especifique a flag -t.
A ASA é gerada durante o parsing do código e representa a regras de derivação gramatical em uma visão de alto-nível.

### Caso ocorra algum problema para gerar o arquivo:

```bash
./lalgc -h
```
Exibe uma ajuda para o programa.

### Executar os testes:

#### De forma silenciosa:

Sem produzir arquivos de saída (árvores sintáticas), com exibição dos erros em tela apenas.
```bash
make test
```

#### De forma verbosa

Produzindo logs, tanto da saída (arquivo out[0-7].ast) quanto logs de possíveis erros de sintaxe (out[0-7].log) na pasta output
```bash
make test-output
```

## Criação de testes

### De forma integrada

Para criar arquivos personalizados, altera algum dos exemplos entre 0 e 7, ou crie um novo arquivo e modifique o range dos for loops no makefile (linha 22 para o silent e 47 para o verbose). Depois faça o teste usando os comandos descritos acima.

### De forma separada
Crie um arquivo de teste, ex: (/my/file/test.lalg) e use o seguinte comando, dentro da pasta com o executável 
```bash
./lalgc -i /my/file/test.lalg [-t arvore_saida_opcional]
```
O caminho para o arquivo de entrada deve ser especificado depois da flag -i (ou --input)

O arquivo de saída (opcional) é uma ASA. Para gerar este arquivo especifique a flag -t.
A ASA é gerada durante o parsing do código e representa a regras de derivação gramatical em uma visão de alto-nível.

## Limpar a pasta 

Remove a pasta output, o executável e os arquivos intermediários gerados pelo yacc e flex.
```bash
make clean
```
