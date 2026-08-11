class Veiculo {
  String renavam;
  String chassi;
  String? marca;
  int? anoFabricacao;
  Veiculo(this.renavam,this.chassi);
  bool ehIgual(Veiculo outro){
    if(this.renavam == outro.renavam && this.chassi == outro.chassi){
      return true;
    }
    return false;
  }
  @override
  bool operator ==(Object other){
      if (identical(this, other) ||
      (other is Veiculo &&
          this.renavam == other.renavam &&
          this.chassi == other.chassi)){
            return true;
          }
          return false;
  }
}

void main(){
  // quando instanciamos classes nossas, por padrao, cada instancia ocupará lugares diferentes de memória, mesmo que os dados sejam identicos
  //Veiculo v1 = Veiculo('123', 'ABC');
  Veiculo v1 = Veiculo('456', 'BCD');
  v1.marca = 'Honda';

  Veiculo v2 = Veiculo('456', 'BCD');
  v2.marca = 'Toyota';
  // comparando igualdade (e isso é subjetivo no Dart) por padrão você está comparando enderecos de alocacao.
  // CUIDADO: retire o override para comparar enderecos
  if(v1 == v2){
    print('Mesmo endereco.');
  }else{
    print('Enderecos diferentes.');
  }

  if(v1.ehIgual(v2)){
    print('É o mesmo veículo de acordo com o metodo equals.');
  }
  else{
    print('Não é o mesmo veículo de acordo com o metodo equals.');
  }

  // DEPOIS DE SOBREESCRER O == 
  if(v1 == v2){
    print('Mesmos veículos (em conteúdo).');
  }else{
    print('Não são os mesmos veículos ou objetos.');
  }
}
/*
void main(){
  // entendendo comparações
  // String interning
  String a = 'oi';
  String b = 'oi';
  // a função identical compara referencias de memoria de das instancias
  bool mesmaRef = identical(a, b);
  if(mesmaRef){
    print('Strings iguais e mesma referencia');
  }else{
    print('Strings diferentes');
  }
}
*/