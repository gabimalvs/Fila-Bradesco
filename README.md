# Fila Virtual - Sistema de Atendimento Online Bradesco

Objetivo

Desenvolver um sistema de fila FIFO (First In, First Out) para atendimento online no Bradesco, com um foco específico para atender idosos de forma priorizada. O sistema deve organizar os clientes por idade, com os mais velhos sendo atendidos primeiro.
Descrição

Este projeto implementa uma fila virtual utilizando o conceito de TAD (Tipo Abstrato de Dados) de fila, com uma lista duplamente encadeada. A fila será ordenada utilizando o algoritmo de Bubble Sort, priorizando a idade dos clientes.
Especificações:

    Fila Duplamente Encadeada: Implementação do TAD fila usando uma lista duplamente encadeada (fila.h e fila.c).
    Leitura de Arquivo: As idades dos clientes serão lidas de um arquivo chamado clientes.txt, onde cada linha contém a idade de um cliente.
    Ordenação: A fila será ordenada pela idade de forma decrescente (maior para menor).
    Processo de Atendimento: Os clientes serão atendidos em ordem de prioridade (idosos primeiro). Cada cliente removido da fila terá sua idade impressa no terminal.
    Gerenciamento de Memória: A memória será liberada ao remover clientes da fila.

Passos para Implementação:

    Ler as idades dos clientes a partir do arquivo clientes.txt e inseri-los na fila.
    Ordenar a fila de forma decrescente por idade.
    Atender os clientes, removendo-os da fila, e imprimir a idade de cada cliente atendido.
    Liberar a memória após o atendimento de cada cliente.

Requisito:

    Algoritmo de Ordenação: O único algoritmo permitido para ordenação é o Bubble Sort.
