class Usuario
{
  String nome;
  int idade;
  String? email;

  Usuario({
    required this.nome,
    required this.idade,
    this.email,
  });

  void resumo()
{
  print('Nome: $nome, Idade: $idade, Email: ${email ?? "Não informado"}');
}
}



void main()
{
  Usuario usuario1 = Usuario(nome: 'Felipe', idade: 18, email:'feaugustosantossilva@gmail.com');
  Usuario usuario2 = Usuario(nome: 'Thais', idade: 50);
  usuario1.resumo();
  usuario2.resumo();
}