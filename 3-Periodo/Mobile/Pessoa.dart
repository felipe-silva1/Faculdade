class Pessoa {
  final String nome;
  final double peso;
  final double altura;
  double? imc;
  Pessoa(this.nome,this.peso,this.altura){
    this._calcularImc();
  }
  
  void _calcularImc(){
    this.imc = this.peso / (this.altura * this.altura);
  }
}
