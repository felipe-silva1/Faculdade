void Ex01()
{
  print('Felipe Augusto dos Santos Silva');
  print('18 anos');
  print('Turma 101');
}

void Ex02()
{
  int a = 10;
  int b = 20;
  int soma = a + b;
  print('A soma de $a e $b é de: $soma');
  if (a > b)
  {
    print('$a é maior do que $b.');
  }
  else if(b > a)
  {
    print('$b é maior do que $a.');
  }
  else
  {
    print('Os números são iguais.');
  }
}
void Ex03()
{
  int n = 21;
  if(n % 2 == 0)
  {
    print('O número é par.');
  }
  else 
  {
    print('O número é impar.');
  }
}
void Ex04()
{
  int a = 3;
  int b = 1;
  int c = 2;
  int maior = a;
  if(b > maior)
  {
    maior = b;
  } 
  if(c > maior)
  {
    maior = c;
  } 
  print('O maior número é o $maior.');
}
void Ex05()
{
  double n1 = 7;
  double n2 = 5;
  if ((n1 >= 0 && n1 <= 10) && (n2 >= 0 && n2 <= 10))
  {
    double media = (n1 + n2) / 2;
    if(media == 10)
    {
      print('Parabéns! Média: $media.');
    }
    else if (media >= 8)
    {
      print('Ótimo! Média: $media.');
    }
    else if (media >= 5)
    {
      print('Aprovado! Média: $media.');
    }
    else
    {
      print('Reprovado! Média: $media.');
    }
  }
  else
  {
    print('Entre com notas válidas de 0 a 10.');
  }
}
void Ex06()
{
  int n = 10;
  for(int i = 1; i <= n; i++)
  {
    print(i);
  }
}
void Ex07()
{
  int n = 5;
  for(int i = 1; i <= 10; i++)
  {
    int res = i * n;
    print('$n * $i = $res');
  }
}

void Ex08()
{
  int soma = 0;
  final num = [1,2,3,4,5];
  for(final nums in num)
  {
    soma += nums;
  }
  print('A soma dos números é de: $soma.');
}
void Ex09()
{
  final lista1 = [1,2,3,4,5,6];
  var lista2;
  for(final num in lista1)
  {
    if(num % 2 == 0)
    {
      lista2.add(num);
    }
  }
  for(final num in lista2)
  {
    print(num);
  }
}
void main()
{
  Ex09();
}