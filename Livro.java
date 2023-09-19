public class Livro {
	//atributos
	private long ISBN;
	private String titulo, autor_Principal, segundo_Autor, categoria, descricao;
	private int ano_Publicacao, quantidade_Paginas, quantidade_Avaliacoes;
	private double nota_Avaliacao;
	
	//construtor (default)
	public Livro() {
		this.ISBN=0;
		this.titulo="";
		this.autor_Principal="";
		this.segundo_Autor="";
		this.categoria="";
		this.descricao="";
		this.ano_Publicacao=0;
		this.quantidade_Avaliacoes=0;;
		this.nota_Avaliacao=0.0;
		this.quantidade_Paginas=0;
	}
	
	//construtor com dados
	public Livro(String titulo,String autor_Principal,int ano_Publicacao) {
		this();
		this.titulo = titulo;
		this.autor_Principal = autor_Principal;
		this.ano_Publicacao = ano_Publicacao;
	}
	
	//construtor completo
	public Livro(long ISBN,String titulo,String autor_Principal,String segundo_Autor,String categoria,String descricao,int ano_Publicacao,int quantidade_Avaliacoes,double nota_Avaliacao,int quantidade_Paginas) {
		this.ISBN = ISBN;
		this.titulo = titulo;
		this.autor_Principal = autor_Principal;
		this.segundo_Autor = segundo_Autor;
		this.categoria = categoria;
		this.descricao = descricao;
		this.ano_Publicacao = ano_Publicacao;
		this.quantidade_Avaliacoes = quantidade_Avaliacoes;
		this.nota_Avaliacao = nota_Avaliacao;
		this.quantidade_Paginas = quantidade_Paginas;
	}
	
	//metodos gets
	public long getISBN() {
		return ISBN;
	}
	
	public String getTitulo() {
		return titulo;
	}
	
	public String getAutorPrincipal() {
		return autor_Principal;
	}
	
	public String getSegundoAutor() {
		return segundo_Autor;
	}
	
	public String getCategoria() {
		return categoria;
	}
	
	public String getDescricao() {
		return descricao;
	}
	
	public int getAnoPublicacao() {
		return ano_Publicacao;
	}
	
	public int getQuantidadePaginas() {
		return quantidade_Paginas;
	}
	
	public double getNotaAvaliacao() {
		return nota_Avaliacao;
	}
	
	public int getQuantidadeAvaliacoes() {
		return quantidade_Avaliacoes;
	}
	
	//metodos sets
	public void setISBN(long ISBN) {
		this.ISBN = ISBN;
	}
	
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	
	public void setAutorPrincipal(String autor_Principal) {
		this.autor_Principal = autor_Principal;
	}
	
	public void setSegundoAutor(String segundo_Autor) {
		this.segundo_Autor = segundo_Autor;
	}
	
	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}
	
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	
	public void setAnoPublicacao(int ano_Publicacao) {
		this.ano_Publicacao = ano_Publicacao;
	}
	
	public void setQuantidadePaginas(int quantidade_Paginas) {
		this.quantidade_Paginas = quantidade_Paginas;
	}
	
	public void setNotaAvaliacao(double nota_Avaliacao) {
		this.nota_Avaliacao = nota_Avaliacao;
	}
	
	public void setQuantidadeAvaliacoes(int quantidade_Avaliacoes) {
		this.quantidade_Avaliacoes = quantidade_Avaliacoes;
	}
	
	public Livro clone() {
		Livro copia = new Livro();
		copia.setISBN(this.ISBN);
        copia.setTitulo(this.titulo);
        copia.setAutorPrincipal(this.autor_Principal);
        copia.setSegundoAutor(this.segundo_Autor);
        copia.setCategoria(this.categoria);
        copia.setDescricao(this.descricao);
        copia.setAnoPublicacao(this.ano_Publicacao);
        copia.setQuantidadePaginas(this.quantidade_Paginas);
        copia.setNotaAvaliacao(this.nota_Avaliacao);
        copia.setQuantidadeAvaliacoes(this.quantidade_Avaliacoes);
        return copia;
	}
	
	public Livro ler(Livro livro) {
		return livro;
	}
	
	public void imprimir() {
		//Para cada livro encontrado, escreva na saída padrão uma linha contendo as informações bibliográficas
		//do filme, com os dados do registro correspondente. A saída padrão deve obedecer o seguinte formato
		//(não incluir as chaves):
		//{autor principal}, {segundo autor}. {titulo}. {ano publicação}. ISBN: {isbn}.
		//exemplo:
		//Nívio Ziviani. Projeto De Algoritmos Com Implementações Em Pascal e C. 2010. ISBN: 9788522110506.
		if(segundo_Autor != "") {
			MyIO.println(autor_Principal + ", " + segundo_Autor + ". " + titulo + ". " + ano_Publicacao + ". ISBN: " + ISBN +".");
		}else {
			MyIO.println(autor_Principal + ". " + titulo + ". " + ano_Publicacao + ". ISBN: " + ISBN+".");
		}
	}
	
	public String toString() {
		return "Livro{" +
                "ISBN=" + ISBN +
                ", titulo='" + titulo + "\\|" +
                ", autorPrincipal='" + autor_Principal + "\\|" +
                ", segundoAutor='" + segundo_Autor + "\\|" +
                ", categoria='" + categoria + "\\|" +
                ", descricao='" + descricao + "\\|" +
                ", anoPublicacao=" + ano_Publicacao +
                ", quantidadePaginas=" + quantidade_Paginas +
                ", notaAvaliacao=" + nota_Avaliacao +
                ", quantidadeAvaliacoes=" + quantidade_Avaliacoes +
                '}';
	}
	
	public static void main(String[] args) {
		//MyIO.setCharset("UFT-8");
		//obtencao de dados:
		//O aluno(a) deve preencher um vetor de objetos da classe Livro com os dados dos diversos livros informados na entrada padrão (teclado - pub.in).
		//A primeira linha contém a quantidade de livros que devem ser armazenados em um vetor.
		//Cada uma das linhas seguintes apresenta os dados de um livro, separados pelo símbolo “|”. Os dados
		//possuem, em ordem, as seguintes informações:
		//• ISBN (long);
		//• titulo (String);
		//• autor principal (String);
		//• segundo autor (String);
		//• categoria (String);
		//• descricao (String);
		//• ano publicação (int);
		//• quantidade páginas (int);
		//• nota avaliação (double);
		
		int posicao=0;
		String linhaRecebida = MyIO.readLine();
		int quantidadeLivros = Integer.parseInt(linhaRecebida);
		//MyIO.println(quantidadeLivros);
		Livro[] arrayLivros = new Livro[quantidadeLivros];
		linhaRecebida = MyIO.readLine();
		//MyIO.println(linhaRecebida);
		
		while(!(linhaRecebida.equals("FIM"))) {
			
			String[] livro = linhaRecebida.split("\\|");
			//MyIO.println(" ");
			long ISBN = Long.parseLong(livro[0]);
			//MyIO.println(ISBN);
			String titulo = livro[1];
			//MyIO.println(titulo);
			String autor_Principal = livro[2];
			//MyIO.println(autor_Principal);
			String segundo_Autor = livro[3];
			//MyIO.println(segundo_Autor);
			String categoria = livro[4];
			//MyIO.println(categoria);
			String descricao = livro[5];
			//MyIO.println(descricao);
			int ano_Publicacao = Integer.parseInt(livro[6]);
			//MyIO.println(ano_Publicacao);
			int quantidade_Avaliacoes = Integer.parseInt(livro[9]);
			//MyIO.println(quantidade_Avaliacoes);
			double nota_Avaliacao = Double.parseDouble(livro[8]);
			//MyIO.println(nota_Avaliacao);
			int quantidade_Paginas = Integer.parseInt(livro[7]);
			//MyIO.println(quantidade_Paginas);
			arrayLivros[posicao] = new Livro(ISBN,titulo,autor_Principal,segundo_Autor,categoria,descricao,ano_Publicacao,quantidade_Avaliacoes,nota_Avaliacao,quantidade_Paginas);
			posicao++;
			linhaRecebida = MyIO.readLine();
		}
		linhaRecebida = MyIO.readLine();
		while(!(linhaRecebida.equals("FIM"))) {
			String livroPesquisa[] = linhaRecebida.split("\\;");
			
			String pesquisaTitulo = livroPesquisa[0];
			int pesquisaAno = Integer.parseInt(livroPesquisa[1]);
			String pesquisaAutor = livroPesquisa[2];
			
			for(Livro livroProcura : arrayLivros) {
				if( (livroProcura.getTitulo().equals(pesquisaTitulo)) && (livroProcura.getAnoPublicacao() == pesquisaAno) && (livroProcura.getAutorPrincipal().equals(pesquisaAutor))) {
					livroProcura.imprimir();
					linhaRecebida = MyIO.readLine();
				}
			}
		}
	}
}

	