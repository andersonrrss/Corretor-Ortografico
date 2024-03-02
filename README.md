
# Corretor Ortográfico

Este exercício é um verificador ortográfico simples que verifica a ortografia de palavras em um arquivo de texto usando um dicionário pré-definido.

No geral, este exercício fornece uma implementação simples de um verificador ortográfico usando uma estrutura de dados de tabela hash do dicionário. Ele pode ser estendido para incluir outras funcionalidades, como sugestões para palavras mal escritas ou integração com um editor de texto.
## Compilação

Para compilar o código, digite isto no terminal

```
  gcc -Wall -Wextra -g3 dictionary.c speller.c -o speller
```

Para poder executá-lo digite
```
.\speller [dictionary] arquivo.txt
```

Expecificar um dicionário a ser usado é opcional, pois o código toma como padrão o `large.txt`.


## Arquivos

O programa contém os seguintes arquivos de código:

`speller.c`: O arquivo de implementação do código-fonte principal que contém a função main. Ele aceita dois argumentos de linha de comando: o caminho para o arquivo do dicionário e o caminho para o arquivo de texto a ser verificado. Se apenas um argumento for fornecido, ele usa um dicionário padrão.

`dictionary.h`: O arquivo de cabeçalho que declara as funções relacionadas à estrutura de dados do dicionário.

`dictionary.c`: O arquivo de implementação para a estrutura de dados do dicionário. Ele inclui funções para carregar o dicionário na memória, verificar se uma palavra está presente no dicionário, descarregar o dicionário da memória e determinar o tamanho do dicionário.
O projeto usa uma tabela hash para armazenar as palavras do dicionário, e a função de hash é baseada na primeira letra da palavra. A tabela hash tem 26 buckets, um para cada letra do alfabeto.

Ele também necessita do dicionário `large.txt` para funcionar de maneira padrão, e utiliza opcionalmente o `small.txt` se o usuário expecificar seu uso.
## Funções principais

O verificador ortográfico funciona lendo cada palavra no arquivo de texto e verificando se ela está presente no dicionário. Se a palavra não estiver presente, será considerada mal escrita e impressa no console. O verificador ortográfico também relata o número total de palavras no arquivo de texto, o número de palavras no dicionário e o número de palavras mal escritas.

- `bool check(const char *word)`: verifica se uma palavra está presente no dicionário. Ela faz isso calculando o valor de hash da palavra e verificando se a palavra existe no bucket correspondente da tabela hash.

- `bool load(const char *dictionary)`: carrega o dicionário em memória. Ela faz isso abrindo o arquivo do dicionário, alocando memória para cada palavra e adicionando-a à tabela hash.

- `unsigned int size(void)`: retorna o número de palavras no dicionário.

- `bool unload(void)`: descarrega o dicionário da memória. Ela faz isso percorrendo cada bucket da tabela hash e libertando a memória alocada para cada palavra.

- `unsigned int hash(const char *word)`: calcula o valor de hash de uma palavra. Ela faz isso convertendo a primeira letra da palavra em maiúscula e subtraindo o valor ASCII de 'A' para obter um índice entre 0 e 25.
## Autores

- [@andersonrrss](https://www.github.com/andersonrrss)

