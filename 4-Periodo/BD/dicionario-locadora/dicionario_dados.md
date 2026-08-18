# Título errado - Dicionário de dados: Sistema para locadoras

> Este título está errado por conta de ser genérico. Um dicionário de dados deve ser específico de um sistema E cliente.

# Título adequado: Dicionário de Dados do Banco de Dados para Locação de Veículos Automotores da Localiza / SA

## Histórico de versões

|Data|Autor|Versão|Comentários|
|----|-----|-------|--------|
|10/08/2026|Felipe Augusto|1.0.0|Versão inicial com a especificação das entidades: Locador, Veículo e Unidade|

## Entidades

A seguir são documentadas as entidades e seus dados (atributos) que serão necessárias para suportar todas as operações que o sistema de locação necessita.

### 1. Cliente

Descrição: Representar uma pessoa física ou jurídica (empresa) que aluga um ou mais veículos ao longo do tempo. É importante destacar que, clientes que nunca alugaram um veículo, devem ser representados.

Atributos:

| Nome | Tipo | Obrigatoriedade | Exemplos/ Comentários |
|------|------|-----------------|-----------------------|
| Código | Inteiro Único | Sim | São aceitos números de 1 a (inteiro longo maior possível), acrescidos de um em um. |
| Tipo | Lista literal e estática de valores | Sim | A lista é composta de apenas dois valores: Física (pessoa física) e jurídica (empresa). Não devem ser acrescentados valores futuros.|
| Documento| Par chave-valor| Sim | Chave é uma lista estática contendo:"CPF", "CPNJ", "Passaporte" (Pesquisar se o passaporte serve para emissão de um documento fiscal caso o cliente seja estrangeiro) Valor: Conteúdo textual do documento, com formatação própria. |
| Nome | String livre sem caracteres especiais | Sim | Este é um campo que armazenará pela primeira vez o nome do cliente. Após a emissão da primeira nota fiscal, o nome ou razão social da empresa é corrigodo com a receita federal. Sempre o nome será armazenado em maiúsculo para não ter variações ou problemas de formatação em relatórios e listas.|
