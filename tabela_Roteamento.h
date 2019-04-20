#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM 18
///////////////////////////////////////////////////////////////////////////////////
typedef struct dados{
   char protocolo;
   char ip_destino[TAM];
   char mascara[TAM];
   int  metrica;
   char end_interface_saida[TAM];
}t_elem;

typedef struct no {
   t_elem dado;
   struct no *prox;
}tno;

typedef tno *tlista;

void criar (tlista *L) {
  L = NULL;
}
int vazia (tlista *L) {
  return (L == NULL);
}
////////////////////////////////////////////////////////////////////////////////////////////
int inserir (tlista *L, int pos, t_elem valor) {
  tlista p, novo;
  int n;

  if (*L == NULL) {
    if (pos != 1)
      return (0);

    novo = (tlista) malloc(sizeof(tno));
    if (novo == NULL)
      return (0);

    novo->dado.protocolo = valor.protocolo;
    novo->dado.metrica = valor.metrica;
    strcpy(novo->dado.ip_destino,valor.ip_destino);
    strcpy(novo->dado.mascara,valor.mascara);
    strcpy(novo->dado.end_interface_saida,valor.end_interface_saida);
    novo->prox = NULL;
    *L = novo;
    return (1);
  }
    if (pos == 1) {
      novo = (tlista) malloc(sizeof(tno));
    if (novo == NULL)
      return (0);

    novo->dado.protocolo = valor.protocolo;
    novo->dado.metrica = valor.metrica;
    strcpy(novo->dado.ip_destino,valor.ip_destino);
    strcpy(novo->dado.mascara,valor.mascara);
    strcpy(novo->dado.end_interface_saida,valor.end_interface_saida);
    novo->prox = *L;
    *L = novo;
    return (1);
   }

  p = *L;
  n = 1;

  while ((n < pos-1) && (p != NULL)) {
    p = p->prox;
    n++;
  }

  if (p == NULL)
    return (0);
  novo = (tlista) malloc(sizeof(tno));
  if (novo == NULL)
    return (0);

  novo->dado.protocolo =  valor.protocolo;
  novo->dado.metrica = valor.metrica;
  strcpy(novo->dado.ip_destino,valor.ip_destino);
  strcpy(novo->dado.mascara,valor.mascara);
  strcpy(novo->dado.end_interface_saida,valor.end_interface_saida);
  novo->prox = p->prox;
  p->prox = novo;
  return (1);

}
////////////////////////////////////////////////////////////////////////////////////////////////
int remover_val (tlista *L, t_elem elem) {
  tlista a, p;
  int n;
  if (vazia(*L))
    return (2);
  p = *L;
  n = 1;
  while (p != NULL) {
    if (!(strcmp(p->dado.ip_destino,elem.ip_destino)))
      break;
    a = p;
    p = p->prox;
    n++;
  }

  if (p == NULL)
    return (0);

  if (n == 1)
    *L = p->prox;
  else
    a->prox = p->prox;

  free(p);
  return (1);

}
