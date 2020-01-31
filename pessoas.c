#include <stdio.h>
#include <string.h>//importando a biblioteca string.h para uso de funções de manipulação de strings

//montando registro do tipo pessoa com os atributos descritos mais um ponteiro do mesmo tipo que aponta para o próximo elemento
typedef struct{
	int id, idade;
	char sexo[10], nome[50];
	float altura;
	struct Pessoa* prox;
} Pessoa;

int n = 0;//incrementa o id do registro
int registros = 0;//guarda a quantidade de registros da lista

//cria um nó vazio na lista para iniciá-la
Pessoa* criar_lista(){
	
	return NULL;
}

//verifica se o registro está vazio
int lista_vazia(Pessoa* pessoas){
	
	if(pessoas == NULL){
		
		return 1;
		
	}else{
		
		return 0;
		
	}
}

//exibe os registros da lista
void exibir_lista(Pessoa* pessoas){
	
	if(!lista_vazia(pessoas)){
		
		printf("\nId: %i", pessoas->id);
		printf("\nNome: %s", pessoas->nome);
		printf("\nSexo: %s", pessoas->sexo);
		printf("\nIdade: %i", pessoas->idade);
		printf("\nAltura: %.2f\n", pessoas->altura);
		
		exibir_lista(pessoas->prox);
		
	}
}

//cadastra um novo registro na lista
void inserir_pessoa(Pessoa** pessoas){
	int opc, erro;
	if(lista_vazia(*pessoas)){
		
		Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));
		
		printf("\nNome: ");
		gets(novo->nome);
		printf("\nSexo: \n1 - Masculino\n2 - Femenino\nOpcao: ");
		scanf("%i", &opc);
		erro = 1;
		do{
			switch(opc){
				case 1:
					strcpy(novo->sexo, "Masculino");//função para colocar a string(segundo parâmetro) na variável(primeiro parâmetro)
					erro = 0;
				break;
				case 2:
					strcpy(novo->sexo, "Femenino");
					erro = 0;
				break;
				default:
					printf("\nOpcao inválida, digite novamente: ");
					scanf("%i", &opc);
				break;
			}
		}while(erro == 1);
		
		printf("\nIdade: ");
		scanf("%i", &novo->idade);
		printf("\nAltura: ");
		scanf("%f", &novo->altura);
		
		novo->id = n + 1;
		n++;
		registros++;
		novo->prox = NULL;
		*pessoas = novo;
		
	}else{
		
		inserir_pessoa(&(*pessoas)->prox);
		
	}
}

//cadastra um novo registro na lista passando seus dados para a função
void insert_pessoa(Pessoa** pessoas, char nome[50], int sexo, int idade, float altura){
	
	if(lista_vazia(*pessoas)){
		
		Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));
		
		novo->id = n + 1;
		n++;
		registros++;
		strcpy(novo->nome, nome);
		
		switch(sexo){
			case 1:
				strcpy(novo->sexo, "Masculino");
			break;
			case 2:
				strcpy(novo->sexo, "Femenino");
			break;
			default:
				strcpy(novo->sexo, "Invalido");
				printf("\nSexo invalido!");
			break;
		}
		
		novo->idade = idade;
		novo->altura = altura;
		novo->prox = NULL;
		
		*pessoas = novo;
		
	}else{
		
		insert_pessoa(&(*pessoas)->prox, nome, sexo, idade, altura);
		
	}
}

//busca um registro pelo id e exibe seus dados
void getId(Pessoa* pessoas, int indice){
	
	if(!lista_vazia(pessoas)){
		
		if(pessoas->id == indice){
			
			printf("\nId %i encontrado!", indice);
			printf("\nNome: %s", pessoas->nome);
			printf("\nSexo: %s", pessoas->sexo);
			printf("\nIdade: %i", pessoas->idade);
			printf("\nAltura: %.2f\n", pessoas->altura);
			
		}else{
			
			getId(pessoas->prox, indice);
			
		}
		
	}else{
		
		printf("\nId nao encontrado!");
		
	}
}

//busca um registro pelo nome e exibe seus dados
void getNome(Pessoa* pessoas, char nome[50]){
	
	if(!lista_vazia(pessoas)){
		
		if(strcmp(pessoas->nome, nome) == 0){//função para fazer comparação de strings
			
			printf("\nId: %i", pessoas->id);
			printf("\nNome: %s", pessoas->nome);
			printf("\nSexo: %s", pessoas->sexo);
			printf("\nIdade: %i", pessoas->idade);
			printf("\nAltura: %.2f\n", pessoas->altura);
			
		}else{
			
			getNome(pessoas->prox, nome);
			
		}
		
	}else{
		
		printf("\nNome nao encontrado!");
		
	}
}

//busca os registros que possuem essa idade e exibe os dados de cada um
void getIdade(Pessoa* pessoas, int idade, int encontrado){
	
	if(!lista_vazia(pessoas)){
		
		if(pessoas->idade == idade){
			
			printf("\n\nId: %i", pessoas->id);
			printf("\nNome: %s", pessoas->nome);
			printf("\nSexo: %s", pessoas->sexo);
			printf("\nIdade: %i", pessoas->idade);
			printf("\nAltura: %.2f", pessoas->altura);
			
			encontrado++;
			
		}
			
			getIdade(pessoas->prox, idade, encontrado);
			
	}else{
		
		if(encontrado == 0){
			printf("\nNenhuma pessoa encontrada com essa idade!");
		}
		
	}
}

//altera o registro pelo id
void alterar_pessoa(Pessoa* pessoas, int indice){
	
	int opc, erro;
	
	if(!lista_vazia(pessoas)){
		
		if(pessoas->id == indice){
			
			printf("\nNome: ");
			gets(pessoas->nome);
			printf("\nSexo: ");
			printf("\n1 - Masculino");
			printf("\n2 - Femenino");
			printf("\nOpcao: ");
			scanf("%i", &opc);
			erro = 1;
			
			do{
				switch(opc){
					case 1:
						strcpy(pessoas->sexo, "Masculino");
						erro = 0;
					break;
					case 2:
						strcpy(pessoas->sexo, "Femenino");
						erro = 0;
					break;
					default:
						printf("\nOpcao invalida, digite novamente: ");
						scanf("%i", &opc);
					break;
				}
			}while(erro != 0);
			
			printf("\nIdade: ");
			scanf("%i", &pessoas->idade);
			printf("\nAltura: ");
			scanf("%f", &pessoas->altura);
			
		}else{
			
			alterar_pessoa(pessoas->prox, indice);
			
		}
		
	}else{
		
		printf("\nId nao encontrado!");
		
	}
}

//conta a quantidade de pessoas de determinado sexo
int count_sexo(Pessoa** pessoas, int sexo, int num){
	int opc;
	if(!lista_vazia(*pessoas)){
		
		if(strcmp(&(*pessoas)->sexo, "Masculino") == 0){
			opc = 1;
		}else if(strcmp(&(*pessoas)->sexo, "Femenino") == 0){
			opc = 2;
		}
		
		if(opc == sexo){
			num++;
		}
		
		num = count_sexo(&(*pessoas)->prox, sexo, num);
	}
	
	return num;
}

//exclui um registro pelo id
void excluir_pessoa(Pessoa** pessoas, int indice){
	
	if(!lista_vazia(*pessoas)){
		
		if((*pessoas)->id == indice){
			
			Pessoa* tmp = (*pessoas)->prox;
			
			free(*pessoas);
			
			*pessoas = tmp;
			
			registros--;
			
			printf("\nRegistro apagado com sucesso!");
			
		}else{
			
			excluir_pessoa(&(*pessoas)->prox, indice);
		}
	}else{
		
		printf("\nRegistro nao encontrado!");
		
	}
}

//exclui uma pessoa de determinado sexo
void excluir_sexo(Pessoa** pessoas, int sexo){
	
	if(!lista_vazia(*pessoas)){
		
		switch(sexo){
			case 1:
				if(strcmp(&(*pessoas)->sexo, "Masculino") == 0){
					Pessoa* tmp = (*pessoas)->prox;
					free(*pessoas);
					*pessoas = tmp;
					registros--;
			
				}else{
					excluir_sexo(&(*pessoas)->prox, sexo);
				}
			break;
			case 2:
				if(strcmp(&(*pessoas)->sexo, "Femenino") == 0){
					Pessoa* tmp = (*pessoas)->prox;
					free(*pessoas);
					*pessoas = tmp;
					registros--;

				}else{
					excluir_sexo(&(*pessoas)->prox, sexo);
				}
			break;
		}
	}
}

//conta a quantidade de pessoas que possuem determinada idade
int count_idade(Pessoa** pessoas, int idade, int num){

	if(!lista_vazia(*pessoas)){
		
		if((*pessoas)->idade == idade){
			
			num++;
			
		}
		
		num = count_idade(&(*pessoas)->prox, idade, num);
	}
	
	return num;
}

//conta a quantidade de pessoas com determinada altura
int count_altura(Pessoa** pessoas, float altura, int num){

	if(!lista_vazia(*pessoas)){
		
		if((*pessoas)->altura == altura){
			
			num++;
			
		}
		
		num = count_altura(&(*pessoas)->prox, altura, num);
	}
	
	return num;
}

//exclui uma pessoa com determinada idade
void excluir_idade(Pessoa** pessoas, int idade){

	if(!lista_vazia(*pessoas)){
		
		if((*pessoas)->idade == idade){
			
			Pessoa* tmp = (*pessoas)->prox;
			free(*pessoas);
			*pessoas = tmp;
			registros--;
			
		}else{
			
			excluir_idade(&(*pessoas)->prox, idade);
			
		}
		
	}

}

//exclui uma pessoa com determinada altura
void excluir_altura(Pessoa** pessoas, float altura){

	if(!lista_vazia(*pessoas)){
		
		if((*pessoas)->altura == altura){
			
			Pessoa* tmp = (*pessoas)->prox;
			free(*pessoas);
			*pessoas = tmp;
			registros--;
			
		}else{
			
			excluir_altura(&(*pessoas)->prox, altura);
			
		}
		
	}

}

//exclui todas as pessoas com determinado sexo
void excluir_sexos(Pessoa** pessoas, int sexo){
	
	int cont, num_sexo;
	
	num_sexo = 0;
	
	num_sexo = count_sexo(&(*pessoas), sexo, num_sexo);
	
	if(num_sexo > 0){
		
		printf("\nRegistros excluidos: %i", num_sexo);
	
		for(cont = 0; cont < num_sexo; cont++){
			excluir_sexo(&(*pessoas), sexo);
		}
	}else{
		
		printf("\nSexo nao encontrado!");
		
	}
}

//exclui todas as pessoas com determinada idade
void excluir_idades(Pessoa** pessoas, int idade){
	
	int cont, num_idade;
	
	num_idade = 0;
	num_idade = count_idade(&(*pessoas), idade, num_idade);
	
	if(num_idade > 0){
		printf("\nRegistros excluidos: %i", num_idade);
	
		for(cont = 0; cont < num_idade; cont++){
			excluir_idade(&(*pessoas), idade);
		}
	}else{
		printf("\nNenhuma pessoa com essa idade encontrada!");
	}
}

//exclui todas as pessoas com determinada altura
void excluir_alturas(Pessoa** pessoas, float altura){
	
	int cont, num_altura;
	
	num_altura = 0;
	num_altura = count_altura(&(*pessoas), altura, num_altura);

	if(num_altura > 0){
		printf("\nRegistros excluidos: %i", num_altura);
	
		for(cont = 0; cont < num_altura; cont++){
			excluir_altura(&(*pessoas), altura);
		}
	}else{
		printf("\nNenhuma pessoa com essa altura encontrada!");
	}
}

//limpa todos os registros da memória
Pessoa* limpar_lista(Pessoa* pessoas){
	
	if(!lista_vazia(pessoas)){
		pessoas = limpar_lista(pessoas->prox);
	}else{
		free(pessoas);
	}
	
	return NULL;
}

int main(){
	int opc, id, idade, sexo, encontrado;
	char nome[50];
	float altura;
	Pessoa* pessoas;
	
	pessoas = criar_lista();//inicializando a lista
	
	//colocando registros automaticamente na lista
	insert_pessoa(&pessoas, "Renato Rodrigues", 1, 24, 1.80);
	insert_pessoa(&pessoas, "Carla Morgado", 2, 35, 1.65);
	insert_pessoa(&pessoas, "Henrique Almeida", 1, 22, 1.74);
	insert_pessoa(&pessoas, "Karine dos Santos", 2, 24, 1.72);
	insert_pessoa(&pessoas, "Junior Nascimento", 1, 19, 1.80);
	
	do{
		printf("\n\nMenu");
		printf("\n1 - Cadastrar pessoa");
		printf("\n2 - Listar pessoas");
		printf("\n3 - Buscar pessoa");
		printf("\n4 - Alterar pessoa");
		printf("\n5 - Excluir pessoa");
		printf("\n0 - Sair");
		printf("\nOpcao: ");
		scanf("%i", &opc);
		
		getchar();//limpa buffer do teclado
		
		switch(opc){
			case 1:
				printf("\nCadastrar pessoa");
				inserir_pessoa(&pessoas);
			break;
			case 2:
				printf("\nExibir lista");
				if(registros > 0){
					exibir_lista(pessoas);
				}else{
					printf("\nNenhum registro encontrado!");
				}
			break;
			case 3:
				printf("\nBuscar pessoas");
				if(registros > 0){
					printf("\n1 - Buscar pelo id");
					printf("\n2 - Buscar pelo nome");
					printf("\n3 - Buscar pela idade");
					printf("\nOpcao: ");
					scanf("%i", &opc);
					
					getchar();
				
					switch(opc){
						case 1:
							printf("\nBuscar pelo id");
							printf("\nId: ");
							scanf("%i", &id);
							getId(pessoas, id);
						break;
						case 2:
							printf("\nBuscar pelo nome");
							printf("\nNome: ");
							gets(nome);
							getNome(pessoas, nome);
						break;
						case 3:
							printf("\nBuscar pela idade");
							printf("\nIdade: ");
							scanf("%i", &idade);
							
							encontrado = 0;
							getIdade(pessoas, idade, encontrado);
						break;
						default:
							printf("\nOpcao invalida!");
						break;
					}
				}else{
					printf("\nNenhum registro encontrado!");
				} 
			break;
			case 4:
				printf("\nAlterar pessoa");
				if(registros > 0){
					printf("\nId: ");
					scanf("%i", &id);
					
					getchar();
					
					alterar_pessoa(pessoas, id);
				}else{
					
					printf("\nNenhum registro encontrado!");
					
				}
			break;
			case 5:
				printf("\nExcluir registro");
				if(registros > 0){
					printf("\n1 - Pelo id");
					printf("\n2 - Pelo sexo");
					printf("\n3 - Pela idade");
					printf("\n4 - Pela altura");
					printf("\nOpcao: ");
					scanf("%i", &opc);
				
					getchar();
					
					switch(opc){
						case 1:
							printf("\nExcluir pelo id");
							printf("\nId: ");
							scanf("%i", &id);
							
							excluir_pessoa(&pessoas, id);
						break;
						case 2:
							printf("\nExcluir pelo sexo");
							printf("\n1 - para masculino");
							printf("\n2 - para femenino");
							printf("\nOpcao: ");
							scanf("%i", &sexo);
							
							switch(sexo){
								case 1:
									excluir_sexos(&pessoas, sexo);
								break;
								case 2:
									excluir_sexos(&pessoas, sexo);
								break;
								default:
									printf("\nOpcao invalida!");
								break;
							}
							
						break;
						case 3:
							printf("\nExcluir pela idade");
							printf("\nIdade: ");
							scanf("%i", &idade);
							excluir_idades(&pessoas, idade);
						break;
						case 4:
							printf("\nExcluir pela altura");
							printf("\nAltura: ");
							scanf("%f", &altura);
							excluir_alturas(&pessoas, altura);
						break;
					}
					
					
				}else{
					printf("\nNenhum registro encontrado!");
				} 
			break;
		}
	}while(opc != 0);
	
	pessoas = limpar_lista(pessoas);//limpando registros da memória
	
	free(pessoas);//apagando o início da lista
	
	return 0;
}
