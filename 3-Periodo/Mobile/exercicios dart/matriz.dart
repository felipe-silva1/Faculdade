List<List<int>> matriz = 
[
  [10,20,30],
  [40,50,60],
  [70,80,90],
];

int somaDiagonal(List<List<int>> m)
{
  int soma = 0;
  for(int i = 0;i < m.length; i++)
  {
    soma += m[i][i];
  }
  return soma;
}

int maiorValor(List<List<int>> m)
{
  int maior = m[0][0];
  for(int i = 0; i < m.length; i++)
  {
    for(int j = 0;j < m[i].length;j++)
    {
      if(m[i][j] > maior) maior = m[i][j];
    }
  }
  return maior;
}

void main()
{
  print('Soma da Diagonal: ${somaDiagonal(matriz)}');
  print('Maior Valor: ${maiorValor(matriz)}');
}