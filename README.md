# Sistemas Hardware-Software 2020/1

Este repositório contém atividades de acompanhamento usadas nas dinâmicas de handout do [repositório principal](https://github.com/insper/SistemasHardwareSoftware). Cada pasta corresponde a uma aula e os resultados dos exercícios do handout podem ser conferidos usando um corretor automático. Apesar do corretor verificar se a função solução faz o mesmo que a versão compilada que vocês receberam, isto não significa que o processo de engenharia reversa foi feito corretamente. Por outro lado, se houver algum teste falhando com certeza existe um problema.   

## Como usar esse repositório

As pastas neste repositório correspondem a aulas da disciplina e tem o mesmo nome de sua aula correspondente no [repositório principal](https://github.com/insper/SistemasHardwareSoftware). Os objetivos deste repositório são

1. permitir que um aluno detecte problemas em sua solução antes de chamar o professor;
1. permitir que um aluno verifique que sua solução retorna o mesmo resultado da função original; 
1. registrar o progresso de um aluno nos handouts;
1. registrar os exercícios feitos para efeito de nota; 

Por conta do item 3, **as soluções dos exercícios neste repositório não deverão ser publicadas por nenhum aluno.** Os itens abaixo explicam como a entrega destes exercícios serão feitas. 

### Passo 1 - respondendo exercícios

Para responder os exercícios basta entrar na pasta correspondente e procurar por arquivos do tipo *ex_solucao.c*. Abra o arquivo e escreva sua solução nele. Em vários exercícios é pedido que sua função tenha um nome no estilo *ex5_solucao* ao invés de somente *ex5*. 

Com sua solução implementada execute no terminal

> `$ make`

Se seu programa compilar você deverá ver algo parecido com o abaixo no terminal. 

```
Testando ex4:
OK  : Teste 1:
OK  : Teste 2
OK  : Teste 3:
OK  : Teste 4:
OK  : Teste 5:
```

Se houver algum teste com status `FAIL` então há problemas no seu programa. Você pode verificar com quais parâmetros o teste foi chamado usando o *gdb*. Quando tudo estiver ok faça um commit com os arquivos de solução.  

### Passo 2 - preparando o repositório de entrega de exercícios

Para entregar seus arquivos crie um repositório privado no github e convide o professor para fazer parte de seu repositório (usuário `igordsm`). Nos comandos abaixo substituia `seu_repo_url` pela url usada para clonar o repositório.

> `$ git remote add respostas seu_repo_url `

Toda vez que terminar um exercício você poderá enviá-los para o repositório privado usando o comando abaixo

> `$ git push respostas master` 

### Passo 3 - trabalhando nas próximas aulas

Sempre que novos exercícios forem disponibilizados você pode fazer

> `$ git pull`

para baixá-los em seu repositório local. Após fazer um commit com suas respostas pode executar 

> `$ git push respostas master` 

para enviá-los para o repositório privado.
  

