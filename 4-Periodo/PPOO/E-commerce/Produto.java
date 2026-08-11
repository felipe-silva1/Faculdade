public class Produto
{
    private int id,qntdEstoque;
    private String nome;
    private double preco;

    public Produto (int id, String nome, double preco, int qntdEstoque)
    {
        this.id = id;
        this.nome = nome;
        this.setPreco(preco);
        this.setQntdEstoque(qntdEstoque);
    }
    public int getId()
    {
        return id;
    }
    public void setId(int id)
    {
        this.id = id;
    }
    public String getNome()
    {
        return nome;
    }
    public void setNome(String nome)
    {
        this.nome = nome;
    }
    public double getPreco()
    {
        return preco;
    }
    public void setPreco(double preco)
    {
        this.preco = preco;
    }
    public int getQntdEstoque()
    {
        return qntdEstoque;
    }
    public void setQntdEstoque()
    {
        this.qntdEstoque = qntdEstoque;
    }
}