# Batalha naval em linguagem C

Projeto realizado e utilizado como uma avaliação em uma disciplina do curso de Ciência da Computação onde era utilizada linguagem C para programação. 


### 📋 Pré-requisitos

1. Ter instalado em sua maquino um compilador da linguagem C.
2. Ter um IDE que possibilite codificar com a linguagem C.
3. Fazer download desse repositório com o código fonte.
4. Compilar o código em sua IDE e executa-lo.


## 📦 Desenvolvimento

Usando o code::blocks para desenvolvimento desse trabalho o mesmo foi escrito em linguagem C e o mesmo simula uma interface gráfica para que o jogo fique interativo para o usuário.  
Para jogar o mesmo cada usuário esconde seus barcos por vez, ou seja, um jogar esconde seus barcos e logo em seguida o outro jogador os procura, após o fim da procura o jogador que procurou os barcos esconde os seus barcos e o outro jogador os procura e no final é dados os pontos e o vendedor do jogo.


### Como Jogar

Para jogar o Jogo de batalha naval basta ter uma IDE que consiga compilar e executar códicos em Linguagem C, clone o reṕositório e abra com sua IDE o arquivo `batalhanaval.c` após o compile e execute para  jogar.

### Propósito do desenvolvimento

Jogo desenvolvido para servir como avalização em disciplina de Algoritmo II no segundo semestre de 2018.

### Funcionamento

O jogo pode ser jogado player vs máquina e player vs player que é o mais recomendado, o primeiro momento o jogo pede para que seja fornecido o nome dos jogadores ou jogador, logo após o jogo pede para que o jogador esconda seus Barcos sendo um Porta aviões de uma fragata e um submarino e claro o jodador que ira encontrar as enbarcações não pode ver o jogador escondendo os barcos, lembrando que o primeiro jogador esconde os barcos e o segundo jogar os encontra e logo após o segundo jogar esconde os barcos e o primeiro jogador os encontra e então quando os dois jogadores ja esconderam e encontraram as enbarcações o jogo mostra quem é o jogado vencedor.

| Embarcação    | Tamanho em colunas | Pontos |
| ------------- | ------------------ | ------ |
| Porta Avições | 3                  | 30     |
| Fragata       | 2                  | 20     |