public class Usuario
{
    private int id;
    private String nome;
    private String email;
    private String senha;

    Usuario(int id, String nome, String email, String senha)
    {
        this.id = id;
        this.nome = nome;
        this.email = email;
        this.senha = senha;
    }

    public int getId()
    {
        return id;
    }
    void setId(int id) {
        this.id = id;
    }
    public String getNome() {
        return nome;
    }
    void setNome(String nome) {
        this.nome = nome;
    }
}