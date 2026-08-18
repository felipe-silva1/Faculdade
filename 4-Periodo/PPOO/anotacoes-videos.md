# Regras de Nomenclatura


## 1) Regras de atribuição

>Java é uma linguagem <b>case sensitive</b>, ou seja, o Java diferencia letras maiúsculas de minúsculas na hora de declarar classes, variáveis, métodos, etc. Por exemplo uma variável dia se difere de outra chamada Dia por mais que herdem o mesmo nome. <br>Por mais que o Java permita a declaração de duas instâncias de mesmo nome e tipo não é recomendado o fazer por boa prática, pois o programador pode confundir essas instâncias, o que pode gerar um resultado inesperado. <br>O contrário de case sensitive é o <b>case insensitive</b>, linguagens como Pascal não permitem a declaração de duas variáveis de mesmo nome mesmo que seja diferenciada por letras maiúsculas e minúsculas.<br> Por conta dessa propriedade do Java, fora criada uma convenção para que fosse padronizada a forma que o código é escrito, seguindo algumas <b>regras de nomenclatura</b>.

### 1.1) Classes, Interfaces ou Projetos

As palavras que formam o nome desses componentes devem ser justapostas, com iniciais maiúsculas e as demais letras minúsculas; ex: Programa, Data, BufferedReader;

### 1.2) Pacote (biblioteca)

As palavras que forma o nome desse componente devem ser separadaas por ponto (.) e escritas totalmente em minúsculo; ex: java.io, java.awt.event;

### 1.3) Variável ou Método

As palavras que formam o nome desses componentes seguem a regra 1, com a única diferença de ter a letra inicial da primeira palavra minúscula; ex: dia, mes, ano, setDia, setMes, setAno;

### 1.4) Constante

As palavras que forma o nome desse componente devem ser separadas por um sublinhada (_) e escritas totalmente em maúsculo; ex: MAX_VALUE, MIN_VALUE (que são constantes da classe Integer);

## 2) Regras de nomeação de métodos

### 2.1 Setters

A primeira palavra do nome de um método que altera valores armazenados num objeto devem ser "set" e o resto deve expressar o que é alterado; tais métodos são conhecidos como <b>Setters</b>; ex: setDia, setMes;

### 2.2 Getters

A primeira palavra do nome de um método que recupera um valor armazenado num objeto deve ser "get" e o resto deve expressar o que é recuperado; tais métodos são conhecidos como <b>Getters</b>; OBS: se o valor recuperado for do tipo boolean em vez de "get", usa-se "is"; ex: getDia, getMes, isBissexto;

# Tipos vs Classes Wraper

## 1) Tipos primitivos

O Java tem vários tipos primitivos de variáveis, segue a tabela completa deles:

|Tipos|Memória|Valores|
|-----|-------|-------|
|byte|1 byte|de -128 a 127|
|short|2 bytes|de -32768 a 32767|
|int|4 bytes|de -2147483648 a 2147483647|
|long|8 bytes|de -9223372036854775808 a 9223372036854775807|
|float|4 bytes|de -3.40282347e+38 a -1.40239846e-46, -0 e 0, de 1.40239846e-46 a 3.40282347e+38 além dos valores especiais: "not a number", "menos infinito" e "mais infinito".|
|double|8 bytes|de -1.79769313486231570e+308 a -4.9406564584126544e-324, -0 e 0, de 4.9406564584126544e-324 a 1.79769313486231570e+308, além dos valores especiais: "not a number", "menos infinito" e "mais infinito".|
|boolean|1 byte| false e true|
|char| 2 bytes| 65536 caracteres diferentes (UNICODE) Obs: 256 primeiros caracteres UNICODE coincidem com os 256 caracteres ASCII existentes|

## 2) Classes Wrapper

Classes Wrapper (ou classes embrulhadoras) é uma classe que dentro dela possui um atributo de tipo primitivo compativel com a sua classe.<br> Um valor guardado em uma Classe Wrapper é classificado como 'boxed'. <br>  Um valor guardado em tipo primitivo fora dessas classes são classificados como 'unboxed'.

> Byte ----> byte, Short -----> short, Integer ----> int, Long ----> long, Float ----> float, Double ----> double, Boolean ----> boolean, Character ----> char.

Em geral é recomendado o uso de tipos primitivos, a não ser que você queira ter acesso a métodos dessas classes wrapper, como por exemplo para transformar um caracter em maiúsculo.<br> Uma classe wrapper pode ser instânciada de duas formas que na maioria dos casos não se diferenciam; ex: Interger a = new Integer(7), Integer a = 7;
<br>A diferença se dá em casos que 1 ou mais classes wrapper tem valores identicos atribuida a elas, se as classes forem declaradas do primeiro jeito elas serão inicializadas em endereços de memória diferentes, portanto se fosse pedida uma comparação entre as duas classes usando "==" ela retornaria false, enquanto quando usado o método "equals' ela retornaria true.<br> No segundo caso isso aconteceria ao contrário, por as classes serem inicializadas no mesmo endereço de memória, se fossemos comparar elas usando "==" o programa retornaria true, enquanto ao usar "equals" ele retornaria false.
<br>A exceção dessa regra são Strings, como não são tipos primitivas tanto "==" quanto equals retornaram true contanto que as duas Strings comparadas sejam idênticas.