# estrutura-de-dados-2

## Integrantes


## Descrição geral
Conforme a especificação do trabalho, este repositório apresenta a implementação de vários algoritmos de ordenação. Para além da simples implementação, também há o estudo do comportamento algorítmico, a realização de análises heurísticas acerca de cada método de ordenação, a investigação de entradas adversariais e a comparação de desempenho entre os algoritmos implementados.

## Manual de compilação
### Pré-requisitos
Para a compilação deste projeto, é necessária apenas a instalação do compilador [GCC](https://www.gnu.org/software/gcc/) e o [Bash](https://www.gnu.org/software/bash/) (em um ambiente Windows, se o [Git](https://git-scm.com/) está instalado, é possível executar o comando `bash` para executar scrpits Shell).

### Clonar o repositório
```bash
git clone https://github.com/Sekqies/estrutura-de-dados-2.git
cd estrutura-de-dados-2
```

### Compilação
Para compilar o projeto, executa-se um pequeno script com as instruções de compilação.
* Windows
```bash
bash compile.sh
```
Ou, alternamente, o script alternativo [`compile.bat`](compile.bat).
```bat
./compile.bat
```
* Unix
```bash
./compile.sh
```
Ou, para compilar utilizando a ferramenta [Address Sanitizer](https://clang.llvm.org/docs/AddressSanitizer.html), executa-se o script [`sanitize.sh`](sanitize.sh).
```bash
./sanitize.sh
```

Assim, será produzido um arquivo executável `main` no diretório principal.

## Manual de execução
O programa é uma aplicação de terminal, a qual é executada de maneira análoga a comandos de bash. Para ler uma pequena mensagem de ajuda, é possível escrever `main --help`, ou simplesmente `main -h`.

### Especificação da entrada
Para especificar um vetor de entrada a ser ordenado, basta utilizar uma flag `-i <file>` ou `--input <file>`, em que `<file>` é o caminho a um arquivo contendo um vetor de números inteiros.

Na ausência de um arquivo (ou quando o caminho fornecido é `-`), o vetor é inserido manualmente.

A fim de especificar o tamanho do vetor a ser ordenado, é necessário inserir a flag `-t <tamanho>` ou `--tamanho <tamanho>`. Do contrário, o arquivo é lido por inteiro.

### Escolha do algoritmo de ordenação
Para especificar um algoritmo de ordenação particular, emprega-se a flag `-a <alg>` ou `--algoritmo <alg>`, em que `<alg>` é o algoritmo de ordenação escolhido.

Algoritmos quadráticos (O(n²)):

- `bubble` (Ordenação bolha);
- `insertion` (Ordenação por inserções);
- `selection` (Ordenação por seleção).

Algoritmos  linearítmicos (O(nlog n)):

- `merge` (Ordenação por mesclagem);
- `quick` (Quick-sort).

Outros algoritmos (não fundamentados em comparações):

- `counting` (Ordenação por contagem);
- `radix-bytewise` (Ordenação de raízes).

### Sistema adaptativo
Para adotar uma heurística que determina qual o algoritmo de ordenação implementar para cada entrada, emprega-se a flag `-A` ou `--adaptativo`. Por padrão, na ausência de um algoritmo especificado com a flag `-a`, adota-se a heurística adaptativa.

A heurística opera analisando o vetor de entrada e estudando as suas métricas, as quais são utilizadas para calcular uma pontuação para cada algoritmo de ordenação, a qual determina qual algoritmo de ordenação é mais adequado.

### Confronto entre algoritmos
Por fim, para comparar o desempenho entre múltiplos algoritmos de ordenação, utiliza-se a flag `-b` ou `--benchmark`, a qual ordena o vetor de entrada múltiplas vezes, utilizando-se cada algoritmo de ordenação.

## Estrutura do projeto
### Árvore de arquivos
```
.
├── README.md
├── compile.bat
├── compile.sh
├── main
├── main.exe
├── sanitize.sh
├── src
│   ├── generic_sort.c
│   ├── headers
│   │   ├── generic_sort.h
│   │   ├── input.h
│   │   ├── output.h
│   │   ├── sorts_alternative.h
│   │   ├── sorts_nlogn.h
│   │   ├── sorts_quadratic.h
│   │   └── utils.h
│   ├── input.c
│   ├── main.c
│   ├── output.c
│   ├── sorts_alternative.c
│   ├── sorts_nlogn.c
│   ├── sorts_quadratic.c
│   └── utils.c
└── testcases
    ├── data
    └── data2
```

### Scripts de compilação
O projeto possui dois scripts bash [`compile.sh`](compile.sh) e [`sanitize.sh`](sanitize.sh) no diretório, os quais produzem o executável `main`. O script [`compile.sh`](compile.sh) compila o projeto normalmente utilizando o compilador GCC, enquanto o script [`sanitize.sh`](sanitize.sh) (apenas Unix) adiciona flags de compilação adicionais `-fsanitize=address` e `-g`, as quais são úteis na depuração do programa para o tratamento de vazamentos de memória, com o emprego do [Address Sanitizer](https://clang.llvm.org/docs/AddressSanitizer.html).

### Arquivos de código-fonte e cabeçalho
Os arquivos de código-fonte C estão no diretório [`src/`](src/), os quais arquivos de cabeçalho correspondente em [`src/headers/`](src/headers/), com a declaração de suas funções, declarações de tipo e estruturas de dados relevantes. O programa é dividido em múltiplos de operação, divididos em cada arquivo de código-fonte:

* [`main.c`](src/main.c): Este arquivo contêm a função principal `main()` do programa, a qual recebe os argumentos passados pelo usuário e chama subrotinas de leitura da entrada e de teste de desempenho.

* [`input.c`](src/input.c): Este arquivo implementa as funções utilizadas na função principal `deal_with_flags()`, `read_file()` e `read_array()`, as quais interpretam os comandos do usuário, inicializam um vetor a partir de um arquivo e recebe um vetor definido manualmente pelo usuário, respectivamente.

* [`output.c`](src/output.c): Este arquivo implementa as funções `test_sort()` e `benchmark()`, empregadas na função principal. Enquanto a função `test_sort()` recebe um algoritmo de ordenação particular, a função `benchmark()` realiza testes com todos os algoritmos de ordenação implementados, e exibe uma tabela com as métricas de cada execução.

* [`generic_sort.c`](src/generic_sort.c): Este arquivo implementa a heurística do programa. A função `get_metrics()` analisa o array e retorna suas métricas em um dado composto `Metrics`, cuja definição encontra-se em `generic_sort.h`. Em seguida, em continuidade com a heurística, a função `choose_sort()` avalia o algoritmo de sort ideal para o vetor, conforme as pontuações fornecidas por cada função `radix_score()`, `count_score()`, `merge_score()` e `quick_sort_score()` (os demais algoritmos não são empregados).

* [`sorts_quadratic.c`](src/sorts_quadratic.c), [`sorts_nlogn.c`](src/sorts_nlogn.c) e [`sorts_alternative.c`](src/sorts_alternative.c): Estes arquivos possuem as respectivas implementações dos algoritmos de ordenação de respectiva complexidade. Os seus respectivos arquivos de cabeçalho possuem apenas a declaração de cada função respectiva.

* [`utils.c`](src/utils.c): Este arquivo possui múltiplas funções auxiliares empregadas nos demais arquivos. O seu arquivo de cabeçaçho respectivo [`utils.h`](src/utils.c) possui as definições de tipo `Sort` (tipo de ponteiro de função a um algoritmo de ordenação) e `enum SortMethod` e a definição dos contadores no escopo global `ctr_compare`, `ctr_assign`, `ctr_recursion_depth` e `ctr_recursion_call`, os quais são empregados para avaliar o desempenho dos algoritmos de ordenação. Por exemplo, as funções `assign()`, `swap()` e `compare_l()` definidas no arquivo são empregadas nos algoritmos de ordenação ao invés uma implementação direta, para atualizar os valores nos contadores.

### Casos de teste
O projeto também apresenta alguns arquivos contendo alguns vetores de teste já definidos na pasta [`testcases/`](testcases/).

## Exemplos
