# Solitaire

```
                    (1)   (2)   (3)   (4)   (5)   (6)   (7)
                     --    --    --    --    --    --    --          --
     --             |2C|  |--|  |--|  |--|  |--|  |--|  |--|        |**| (0)
(24)|AC|             --   |2E|  |--|  |--|  |--|  |--|  |--|         --
     --                    --   |3E|  |--|  |--|  |--|  |--|         --
                                 --   |KO|  |--|  |--|  |--|        |**| (0)
                                       --   |QC|  |--|  |--|         --
                                             --   |6E|  |--|         --
                                                   --   |AE|        |**| (0)
                                                         --          --
                                                                     --
                                                                    |**| (0)
                                                                     --
```

## Ideias

### - Movimentação de um conjunto de cartas entre as pilhas

- Achar o indice da carta topo do conjunto
  - Modificar a funcao do cara para retornar o indice do numero desejado

```
enquanto numero != numero_desejado:
    empilha(pilha_aux, desempilha(pilha_original));

enquanto pilha_aux != vazia:
    empilha(pilha_desejada, desempilha(pilha_aux));

```

> Ex:
>
> ```
> 10
> 9  <- Movimentar do 9 pra baixo
> 8
> 7
> 6
>
> Ficaria:
>
> Pilha Original: 10
>
> Pilha nova: 9, 8, 7, 6
> ```
