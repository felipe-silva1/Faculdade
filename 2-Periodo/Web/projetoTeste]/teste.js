const express = require('express');
const app = express();
const port = 3000;

app.get('/',(req,res) =>{
    res.send('Bem-vindo à página inicial!');
});

app.get('/sobre', (req,res) => {
    res.send('Está é a página sobre nós.');
});

app.get('/contato', (req,res) => {
    res.send('Entre em contato conosco.');
});

app.get('/produto', (req,res) => {
    const meuProduto = {
        id: 1,
        nome: 'Notebook',
        preco: 3500.00
    };
    res.json(meuProduto);
});

app.get('/usuarios', (req,res) =>{
    const meusUsuarios = [{id: 10,nome: 'Ana'},{id:11,nome: 'Carlos'}];
    res.json(meusUsuarios);
});

app.get('/ola/:nome', (req,res) =>{
    const nome = req.params.nome;
    res.send('Olá '+nome);
});

app.get('/calculadora/:operacao/:num1/:num2', (req,res) =>{
    const operacao = req.params.operacao;
    const n1 = parseInt(req.params.num1);
    const n2 = parseInt(req.params.num2);
    let resultado;
    switch (operacao) {
        case 'soma':
            resultado = n1 + n2;
            res.send('Soma: '+ resultado);
            break;
        case 'subtracao':
            resultado = n1 - n2;
            res.send('Subtração: '+resultado);
            break;
        case 'multiplicacao':
            resultado = n1 * n2;
            res.send('Multiplicação: '+resultado);
            break;
        case 'divisao':
            resultado = n1 / n2;
            res.send('Divisão: '+resultado);
            break;
        default:
            res.send('Operação inválida!');
            break;
    }
});

app.listen(port, () =>{
    console.log("Servidor rodando na porta "+port);
});