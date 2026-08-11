/*enum TipoDeCombustivel{
  gasolina,
  etanol,
  diesel,
  gnv,
  eletricidade
}*/
abstract class MeioDeTransporte{
  int id;
  String fabricante;
  String modelo;
  double capacidade;
  String combustivel;
  MeioDeTransporte(this.id,
  this.fabricante,
  this.modelo,
  this.capacidade,
  this.combustivel);
  void imprimir(){
    print('\nID: ${id}.');
    print('\nFabricante: ${fabricante}.');
    print('\nModelo: ${modelo}.');
    print('\nCapacidade de carga: ${capacidade}.');
    print('\nTipo de Combustível: ${combustivel}.');
  }
}

abstract class VeiculosTerrestres extends MeioDeTransporte{
  String placa;
  String chassi;
  String renavam;
  VeiculosTerrestres(int id, String fab, String mod,double cap, String comb, this.placa, this.chassi, this.renavam):super(id,fab,mod,cap,comb);
  @override
  void imprimir() {
    super.imprimir();
    print('\nPlaca: ${placa}.');
    print('\nChassi: ${chassi}.');
    print('\nRenavam: ${renavam}.');
  }
}

class Automovel extends VeiculosTerrestres{
  int numPortas;
  Automovel(int id, String fab, String mod, double cap, String comb, String pla, String cha, String ren, this.numPortas):super(id,fab,mod,cap,comb,pla,cha,ren);
  @override
  void imprimir(){
    super.imprimir();
    print('\nNúmero de Portas: ${numPortas}.');
  }
}
class Motocicleta extends VeiculosTerrestres{
  int cilindradas;
  Motocicleta(int id, String fab, String mod, double cap, String comb, String pla, String cha, String ren, this.cilindradas):super(id,fab,mod,cap,comb,pla,cha,ren);
  @override
  void imprimir(){
    super.imprimir();
    print('\nCilindradas: ${cilindradas}');
  }
}
class Aeronave extends MeioDeTransporte{
  double envergadura;
  Aeronave(int id, String fab, String mod, double cap, String comb, this.envergadura):super(id,fab,mod,cap,comb);
  @override
  void imprimir(){
    super.imprimir();
    print('\nEnvergadura: ${envergadura}');
  }
}
class Embarcacao extends MeioDeTransporte{
  int containers;
  Embarcacao(int id, String fab, String mod, double cap, String comb, this.containers):super(id,fab,mod,cap,comb);
  @override
  void imprimir(){
    super.imprimir();
    print('\nContainers: ${containers}');
  }
}

void main(){
  Automovel a1 = Automovel(1, 'Fiat', 'Argo', 0.7, 'Gasolina', 'A07TF1', 'B18RG2', 'C29SH3', 4);
  Motocicleta m1 = Motocicleta(1, 'Suzuki', 'Burgman', 0.1, 'Gasolina', 'D30TI4', 'E41UJ5', 'F52VK6', 80);
  Aeronave a2 = Aeronave(1, 'Boeing', '727', 100, 'Sei lá', 50);
  Embarcacao e1 = Embarcacao(1, 'sla', 'Titanic', 2000, 'alguma coisa ai', 1000);
  a1.imprimir();
  m1.imprimir();
  a2.imprimir();
  e1.imprimir();
}