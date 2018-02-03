//Struct do cliente
struct Spessoa{
  int idade;
  char nome[30];
  long int cpf;
};

struct SDefeito{
    char CodDefeito;
    char Descricao[200];
};

//Struct do carro
struct Scadastro_carro{
  struct SDefeito defeito;
  struct Spessoa pessoa;
  int ano_carro;
  float valor_carro;
  char nome_carro[30];
  char cor_carro[30];
  char marca_carro[30];

};
typedef struct Scadastro_carro carro;

//cabeçalho das funções
void adiciona_cadastro(FILE *reg);
carro *aloca_memoria(int tam,carro *temp);
void apaga_tudo(FILE *reg);
int menu();
void lista_cadastros(FILE *reg);
void apaga_selecionado(FILE *entrada);
int contador_linhas(FILE *reg);

//cria o menu e retorna a opção desejada
int menu()
{
    int op = 0,
        i;
    FILE *reg;
    do
    {
        printf("|---------------------------------------------------------------|\n");
        printf("|                     CADASTRO OFICINA                          |\n");
        printf("|---------------------------------------------------------------|\n");
        printf("|\t[1] - Cadastrar Novo                                    |\n");
        printf("|\t[2] - Buscar por Cadastro                               |\n");
        printf("|\t[3] - Remover Todos os Cadastro                         |\n");
        printf("|\t[4] - Remover Um Cadastro                               |\n");
        printf("|\t[9] - Fechar Programa                                   |\n");
        printf("|\tDigite uma opção: ");

        printf("\t");
        fscanf(stdin,"%d",&op);

        switch(op)
        {
        case 1:
            adiciona_cadastro(reg);
            break;
        case 2:
            lista_cadastros(reg);
            system("pause");
            system("cls");
            break;
        case 3:
            apaga_tudo(reg);
            break;
        case 4:
            apaga_selecionado(reg);
            break;
        case 9:
            exit(0);
            break;
        default:
            system("cls");
            menu();
        }

    } while(op);

    return op;
}
//alocação de memoria retorna ponteiro
carro *aloca_memoria(int tam,carro *temp)
{
    //testa disponibilidade de memoria
    if(temp)
        temp = (carro*) malloc(tam * sizeof(carro));
    else
        exit(1);
    return temp;
}

//estrutura dinamica para adicionar cadastros e salvar no arquivo
void adiciona_cadastro(FILE *reg)
{
    int tam,i;
    system("cls");
    printf("|-----------------------------------------------------------------|\n");
    printf("|                            CADASTRO                             |\n");
    printf("|-----------------------------------------------------------------|\n\n");
    printf("\n\tDigite quantos cadastros deseja adicionar");
    printf("\t");
    fscanf(stdin,"%d",&tam);

    carro *x;
    x = aloca_memoria(tam,x);
    system("cls");

    //abre o arquivo para adicionar os dados
    reg = fopen("registro.txt","a+");
    //Verifica de abriu corretamente
    if(reg)
    {
        //loop para adição de dados
        for(i=0;i<tam;i++)
        {
            printf("|-----------------------------------------------------------------|\n");
            printf("|                            CADASTRO                             |\n");
            printf("|-----------------------------------------------------------------|\n");
            printf("\n\tCADASTRO %d\n\n",i+1);
            puts("\tDigite o modelo do carro");
            setbuf(stdin,NULL); //Limpa buffer do teclado
            printf("\t");
            gets(x[i].nome_carro);
            fprintf(reg,"\nModelo do carro              %s\n",x[i].nome_carro); //coloca no arquivo

            puts("\n\tDigite a cor do carro");
            setbuf(stdin,NULL);
            printf("\t");
            gets(x[i].cor_carro);
            fprintf(reg,"Cor do carro                 %s\n",x[i].cor_carro);

            puts("\n\tDigite a marca do carro");
            setbuf(stdin,NULL);
            printf("\t");
            gets(x[i].marca_carro);
            fprintf(reg,"Marca do carro               %s\n",x[i].marca_carro);

            puts("\n\tDigite o ano do carro");
            printf("\t");
            fscanf(stdin,"%d",&x[i].ano_carro);
            fprintf(reg,"Ano do carro                 %d\n",x[i].ano_carro);

            puts("\n\tDigite o valor do carro [em mil R$]");
            printf("\t");
            fscanf(stdin,"%f",&x[i].valor_carro);
            fprintf(reg,"Valor do carro               %.3f\n",x[i].valor_carro);


            puts("\n\tDigite o nome do proprietario");
            setbuf(stdin,NULL);
            printf("\t");
            gets(x[i].pessoa.nome);
            fprintf(reg,"Nome do proprietario         %s\n",x[i].pessoa.nome);

            puts("\n\tDigite a idade do proprietario");
            printf("\t");
            fscanf(stdin,"%d",&x[i].pessoa.idade);
            fprintf(reg,"Idade do proprietario        %d\n",x[i].pessoa.idade);

            puts("\n\tDigite o cpf do proprietario");
            printf("\t");
            fscanf(stdin,"%ld",&x[i].pessoa.cpf);
            fprintf(reg,"Cpf do proprietario          %d\n",x[i].pessoa.cpf);

            puts("\n\tDescreva o defeito do carro");
            printf("\t");
            fscanf(stdin,"%s",&x[i].defeito.Descricao);
            fprintf(reg,"Descrição do defeito          %s\n",x[i].defeito.Descricao);

            puts("\n\tCódigo do Defeito");
            printf("\t");
            fscanf(stdin,"%s",&x[i].defeito.CodDefeito);
            fprintf(reg,"Código do defeito             %s\n",x[i].defeito.CodDefeito);

            fprintf(reg,"\n");
            system("cls");
        }
    }
    else
        //se não abriu corretamente
        exit(1);
    //Fecha o arquivo
    fclose(reg);
    //Libera o ponteiro
    free(x);
}
//apaga todos os registros
void apaga_tudo(FILE *reg)
{
    //subcreve arquivos de registro por um em branco
    reg = fopen("registro.txt","w+");
    if(reg)
    {
        fclose(reg);
        puts("\n\tREGISTROS APAGADOS");
        system("pause");
        system("cls");
    }
    else
        exit(1);
}

void lista_cadastros(FILE *reg)
{
    system("cls");
    char c,
         conteudo_linha[200];
    int j=0,
        i=0;

    printf("|-----------------------------------------------------------------|\n");
    printf("|                   LISTANDO CADASTRO                             |\n");
    printf("|-----------------------------------------------------------------|\n");
    reg = fopen("registro.txt","r+");

    //conta quantidade de linhas para numerar na lista
    int linha = contador_linhas(reg);

    if (reg)

        for (i+0, j=1;!feof(reg),j<linha;i++,j++)
    {
        //registra o conteudo da linha na variavel coteudo_linha
        fgets(conteudo_linha,101,reg);
        //imprime  conteudo_linha com numeração antes das informações
        printf("%d  %s",j,conteudo_linha);
    }
    else
        exit(1);
    fclose(reg);
    //printf("\n");

}
void apaga_selecionado(FILE *entrada)
{
    system("cls");
    int i=0,
        num=0,
        linha=1;
    //armazena o conteudo da linha para depois reescrever
    char branco[200];

    //novo arquivo para fazer a troca dos arquivos
    FILE *saida;

    //um arquivo como entrada de dados e outro como saida, depois o original será deletado ou renomeado
    entrada = fopen("registro.txt","r+");
    saida = fopen("novo_registro.txt","w+");
    if(!entrada)
        exit(1);
    if(!saida)
        exit(1);
    //obter informação da linha
    lista_cadastros(entrada);
    puts("\n\tDigite a ordem do registro desejado");
    printf("\t");
    fscanf(stdin,"%d",&num);

    num = num + (9*num) - 8 +((num+1)-2);

    for(i=0;!feof(entrada);i++)
    {
        fgets(branco,201,entrada);

        //as 9 linhas do cadastro
        if(linha == num || (linha==num+1) || (linha==num+2) || (linha==num+3)
                        || (linha==num+4) || (linha==num+5) || (linha==num+6)
                        || (linha==num+7) || (linha==num+8) || (linha==num+9))
        {
            //troca linha por "branco"
            fputc(' ',saida);
            linha +=1;
            continue;
        }
        linha +=1;
        //reescreve linhas no arquivo de saida
        fputs(branco,saida);
    }
    fclose(entrada);
    fclose(saida);

    //deleta registro antigo
    unlink("registro.txt");
    //Renomeia para o antigo nome
    rename("novo_registro.txt","registro.txt");

    puts("\n\tCADASTRO APAGADO");
    system("pause");
    system("cls");
}

//função para contar linhas do arquivo
int contador_linhas(FILE *reg)
{
    char c;
    int num_linhas=0;

    reg=fopen("registro.txt","r+");

    while((c=fgetc(reg))!=EOF)
    {
        if(c=='\n') num_linhas++;
    }
    fclose(reg);
    return num_linhas;
}
