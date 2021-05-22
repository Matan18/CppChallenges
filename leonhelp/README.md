# Ajude o Leon

O desafio é da URI Online Judge, de número 2169, onde o dado o número de armas que o Leon está carregando, a quantidade de balas de cada arma, e a quantidade e tipo dos inimigos em uma fase, qual será o resultado, Leon sai de lá morto ou vivo?

Tabela de potência de armas

Arma | Potência
:---------: | :------:
HANDGUN | 2
RED9 | 3.5
BLACKTAIL | 3.5
MATILDA | 2
HANDCANNON | 60
STRIKER | 12
TMP | 1.2
RIFLE | 12

Tabela de resistência dos monstros

Monstros | Vida
:---------: | :------:
GANADOS     | 50
COBRAS      | 40
ZEALOT      | 75
COLMILLOS   | 60
GARRADOR    | 125
LASPLAGAS   | 100
GATLINGMAN  | 150
REGENERATOR | 250
ELGIGANTE   | 500
DR.SALVADOR | 350

## Regras extras
* Ao utilizar uma arma você gasta todas as balas daquela arma;
* Você recebe o máximo de balas que você pode usar;
* Tem que matar todos os monstros;

Exemplos de entrada

```
// entrada 1
3
MATILDA 14
STRIKER 99
HANDCANNON 67
2
ELGIGANTE 5
GATLINGMAN 9
575
// resultado 1
Missao completada com sucesso
// entrada 2
1
STRIKER 77
1
GATLINGMAN 9
375
// resultado 2
You Are Dead
// entrada 3
5
HANDGUN 3
RIFLE 83
BLACKTAIL 20
TMP 14
HANDCANNON 75
8
REGENERATOR 2
COBRAS 2
GARRADOR 9
ELGIGANTE 2
GATLINGMAN 9
ZEALOT 1
DR.SALVADOR 7
COLMILLOS 5
480
// resultado 3
You Are Dead
```

## Tentativas

### Primeira tentativa 

Eu somava a vida de todos os inimigos e ia gastando todas as balas da arma mais forte que estava disponível ([dumb.cpp](/leonhelp/memoknapsack.cpp))

Para isso eu criei 3 dicionários e um lista ordenada da arma mais forte para a mais fraca:
* Um dicionário me dizia com base no nome da arma, qual era a posição dessa arma na lista;
* Um dicionário me dizia com base no nome da arma, qual era a potência dessa arma;
* O último dicionário me dizia com base no nome do inimigo, qual era a vida dele;

Porém, nem sempre gastar a arma que da mais dano é eficiente, as vezes gastar outras combinações de armas pode ser melhor, o exemplo que conseguimos pensar foi

```
2
HANDCANNON 4
STRIKER 21
1
GANADOS 20
21
```
Nesse exemplo, gastar todas as balas da STRIKER vai matar todos os inimigos, mas se eu já tiver gastado a munição da HANDCANNON, eu não posso utilizar a STRIKER, pois vai passar do meu limite de balas

## Knapsack

Esse é um problema de knapsack
![](/assets/knapsack.png)

Nessa imagem, o intuito é pegar o maior número em valor ($), sem passar o máximo de peso (15Kg)

No desafio, o objeto é dar o maior dano, sem gastar o máximo de balas

Achei essa explicação e utilizei a lógica desse vídeo ([0-1 Knapsack Problem (Dynamic Programming)](https://www.youtube.com/embed/xOlhR_2QCXY)) para formar a reposta através de knapsack ([knapsack.cpp](/leonhelp/knapsack.cpp)), e utilizei o mesmo pra tentar otimizar o código através de [memoização](https://en.wikipedia.org/wiki/Memoization) ([memoknapsack.cpp](/leonhelp/memoknapsack.cpp))

