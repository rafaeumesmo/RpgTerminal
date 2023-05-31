 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void evento1() {
    printf("Você está andando pela floresta e encontra uma clareira misteriosa.\n");
    printf("Deseja explorar a clareira?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    printf("3. Voltar\n");

    int escolha;
    scanf("%d", &escolha);
    printf("\n");

    switch (escolha) {
        case 1:
            printf("Você adentra a clareira e ouve alguem chamando seu nome... e sai correndo na direcao\n");
            break;
        case 2:
            printf("Você decide nao explorar a clareira e continua procurando por Lanti pela floresta.\n");
            break;
        case 3:
            printf("Você decide voltar e continuar procurando pela floresta.\n");
            break;
        default:
            printf("Escolha uma opcão válida.\n");
            break;
            printf("\n");
    }
}

// Funcão para o evento 2
void evento2(int alinhamento) {
    printf("Você encontra um grupo de capangas e descobre que Lanti esta presa no castelo\n");
    printf("O que você deseja fazer?\n");
    printf("1. Lutar contra os capangas\n");
    printf("2. Negociar com os capangas\n");

    if (alinhamento == 1) {
        printf("3. Fugir pra salvar sua vida\n");
    }

    int escolha;
    scanf("%d", &escolha);
    printf("\n");

    switch (escolha) {
        case 1:
            printf("Você decide lutar contra os capangas, mas ainda eh muito fraco\n");
            break;
        case 2:
            printf("Você tenta negociar com os capangas, mas eles nao estão dispostos a ceder.\n");
            break;
        case 3:
            if (alinhamento == 1) {
            printf("Você decide fugir sem nem pensar em Lanti.\n");
            } else {
            printf("Você não pode escolher essa opcão com seu alinhamento.\n");
            }
            break;
    }
  printf("\n\n");
}
//jokenpo
void jogarJokenpo(int *vida) {
    int vitorias = 0;
    int jogadaJogador, jogadaComputador;

    printf("Voce parte em rumo ao castelo de Papilon...\n\nDo nada voce eh desafiado por um goblin misterioso na porta\na jogar Jokenpo com ele, valendo sua vida!\n\n");
    printf("Você precisa vencer duas vezes para passar deste desafio.\nperdera 10 de vida por erro\n");

    while (vitorias < 2) {
        printf("\nEscolha sua jogada:\n");
        printf("1. Pedra\n");
        printf("2. Papel\n");
        printf("3. Tesoura\n");

        scanf("%d", &jogadaJogador);

        if (jogadaJogador < 1 || jogadaJogador > 3) {
            printf("Jogada inválida. Escolha uma opcão válida.\n");
            continue;
        }

        // Gerar jogada do computador pseudo-aleatoriamente
        srand(time(NULL));
        jogadaComputador = rand() % 3 + 1;

        printf("Computador escolheu: %d\n", jogadaComputador);

        // Verificar resultado da partida
        if (jogadaJogador == jogadaComputador) {
            printf("Empate! Tente novamente.\n");
        } else if ((jogadaJogador == 1 && jogadaComputador == 3) ||
                   (jogadaJogador == 2 && jogadaComputador == 1) ||
                   (jogadaJogador == 3 && jogadaComputador == 2)) {
            printf("Você venceu essa partida!\n");
            vitorias++;
        } else {
            printf("Você perdeu essa partida!\n");
            *vida -= 10;
            if (*vida <= 0) {
                printf("Seus pontos de vida chegaram a 0.\n");
                printf("   _____                         ____                 \n");
                printf("  / ____|                       / __ \\                \n");
                printf(" | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n");
                printf(" | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|\n");
                printf(" | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n");
                printf("  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   \n");
                return;
            }
        }
    }

    printf("Parabéns! Você venceu o desafio do Jokenpo!\n\nagora esta pronto para enfrentar o Jere e\nacabar com todo essa caus! que ele fez vc passar\n\nVoce vai precisar vencer eles nas charadas para salvar Lanti(enter)\n\n");
  getchar();
}

// Funcão para o evento 3
void evento3(int prof) {
    printf("Você sai correndo e entra em uma caverna escura.\n");
    printf("O que você deseja fazer?\n");
    printf("1. Explorar a caverna\n");
    printf("2. Voltar\n");

    if (prof == 3) {
        printf("3. Dar uma cambalhota e correr pra longe\n");
    } else if (prof == 1) {
        printf("3. Empunhar a espada e vai batalhar com os capangas\n");
    }

    int escolha;
    scanf("%d", &escolha);
    printf("\n");

    switch (escolha) {
        case 1:
            printf("Você decide explorar a caverna, mas nao acha nada!\n");
            break;
        case 2:
            printf("Você decide voltar e continuar sua jornada.\n");
            break;
        case 3:
            if (prof == 3) {
                printf("Você dá uma cambalhota!\n");
            } else if (prof == 1) {
                printf("Você empunha sua espada e entra em uma batalha épica contra os capangas!\n");
            }
            break;
        default:
            printf("Escolha uma opcão válida.\n");
            break;
    }
}
    //charadas
    typedef struct {
    const char *pergunta;
    const char *respostas[3];
    int respostaCorreta;
    } Pergunta;

void sortearPergunta(Pergunta *perguntas, int numPerguntas, int *perguntasSorteadas, int *numPerguntasSorteadas, int *vida, int *charadasCorretas) {
    // Verifica se ainda há perguntas disponíveis
    if (*numPerguntasSorteadas >= numPerguntas) {
        printf("Não há mais perguntas disponíveis.\n");
        return;
    }

    // Sorteia uma pergunta não repetida
    int perguntaSorteada;
    do {
        perguntaSorteada = rand() % numPerguntas;
    } while (perguntasSorteadas[perguntaSorteada]);

    // Marca a pergunta como sorteada
    perguntasSorteadas[perguntaSorteada] = 1;

    // Obtém a pergunta sorteada
    Pergunta perguntaAtual = perguntas[perguntaSorteada];

    // Exibe a pergunta
    printf("Pergunta: %s\n", perguntaAtual.pergunta);

    // Exibe as opcões de resposta na ordem original
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, perguntaAtual.respostas[i]);
    }

    // Aguarda a resposta do jogador
    int respostaUsuario;
    printf("Resposta: ");
    scanf("%d", &respostaUsuario);

    // Verifica se a resposta está correta
    if (respostaUsuario == perguntaAtual.respostaCorreta) {
        printf("Resposta correta!\n");
        (*charadasCorretas)++; // Incrementa o número de charadas corretas
    } else {
        printf("Resposta incorreta. A resposta correta era: %d\n", perguntaAtual.respostaCorreta);
        *vida -= 50; // Deduz 50 pontos de vida do jogador
        printf("Você perdeu 50 pontos de vida. Vida atual: %d\n", *vida);
    }

    printf("\n");
}

struct Personagem {
char nome[21];
int raca;
int alinhamento;
int prof;
int meta;
int meio;
char historia[401];
int porte;
};

int main() {
int opcao, escolha, vida = 100, personagemCriado = 0;
struct Personagem personagem;

    printf("******************************************************************************\n\n\n\n");
    printf("*****************                                            *****************\n\n");
    printf(" __________   ______   _________ __________ __        _______   _____      __\n");
    printf("|   ____   | /      * | ______  |__________|  |     /         *|     |    |  |\n");
    printf("|  |    |  |/ ______ *| |    |  |   |  |   |  |    |    ___    |  |   *   |  |\n"); 
    printf("|  |____|  |  |    |  | |____|  |   |  |   |  |    |   /   *   |  | *  *  |  |\n"); 
    printf("|_________/|  |____|  |________/    |  |   |  |    |  |     |  |  |  *  * |  |\n");
    printf("|  |       |  |    |  |  |          |  |   |  |    |  |     |  |  |   *  *|  |\n");
    printf("|  |       |  |    |  |  |       ___|  |___|  |____ *  *___/   |  |    *     |\n");
    printf("|__|       |__|    |__|___|     |__________|_________*_______/ |___|    |____|\n\n\n");
    printf("*****************************************************************************\n\n\n\n");

    printf("Bem-vindo!!! Ao Reino de Papilon\n\nOnde a aventura o aguarda em cada esquina. Prepare-se\npara enfrentar desafios emocionantes e perigosos enquanto\nse aventura em um reino de fantasia cheio de misterio e magia!\n\nComece sua jornada agora e torne-se um herói lendário em Papillon!\n\nEscolha uma opcao:\n");
    printf("1. Criar Personagem\n2. Iniciar Jogo\n3. Sair\n");

    while (1) {
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:

                printf("Criando personagem...\n\n");

                printf("Digite seu nick:\n");
                scanf("%s", personagem.nome);
                printf("\n");

                printf("Qual vai ser sua raca\n1. Humana\n2. Anã\n3. Elfica\n");
                scanf("%d", &personagem.raca);
                printf("\n");
                if (personagem.raca < 1 || personagem.raca > 3) {
                    printf("Escolha uma opcao valida...\n");
                    continue;
                }

                printf("Qual caminho irá seguir:\n1. Do Mal\n2. Neutro\n3. Do bem\n");
                scanf("%d", &personagem.alinhamento);
                printf("\n");
                if (personagem.alinhamento < 1 || personagem.alinhamento > 3) {
                    printf("Escolha uma opcao valida....\n");
                    continue;
                }

                printf("Sua profissão:\n1. Guerreiro\n2. Mago\n3. Ladino(pilantra)\n(se for do bem, não poderá escolher ladino)\n");
                scanf("%d", &personagem.prof);    
                printf("\n");
                if (personagem.alinhamento == 3 && personagem.prof == 3) {
                    printf("Escolha uma opcao valida...\n");
                    continue;
                }
                if (personagem.prof < 1 || personagem.prof > 3) {
                    printf("Escolha uma opcao valida....\n");
                    continue;
                }

                printf("Meta será:\n1. Governar Papilon\n2. Ficar rico\n3. Destruir o mal\n");
                scanf("%d", &personagem.meta);
                printf("\n");
                if (personagem.meta < 1 || personagem.meta > 3) {
                    printf("Escolha uma opcao valida....\n");
                    continue;
                }if (personagem.alinhamento == 1 && personagem.meta == 3) {
                    printf("Personagens malignos não podem ter a meta de destruir o mal. Por favor, escolha uma opcão válida.\n");
                    continue;
                }

                printf("Meio em que vive:\n1. Urbano\n2. Rural\n3. Tribal\n");
                scanf("%d", &personagem.meio);
                printf("\n");
                if (personagem.meio < 1 || personagem.meio > 3) {
                    printf("Escolha uma opcao valida....\n");
                    continue;
                } if (personagem.alinhamento == 3 && personagem.prof == 3 && personagem.meio == 3) {
                    printf("Ladinos não podem viver em meios tribais. Por favor, escolha uma opcão válida.\n");
                    continue;
                }

                printf("Digite uma pequena historia (maximo 400 linhas)\n");
                scanf("%s", personagem.historia);
                printf("\n\n");

                printf("Qual vai ser seu porte:(anoes nao podem escolher porte grande\n1. Grande\n2. Medio\n3. Pequeno\n");
                scanf("%d", &personagem.porte);
                printf("\n");
                if (personagem.porte < 1 || personagem.porte > 3) {
                    printf("Escolha uma opcao valida....\n");
                    continue;
                } if (personagem.raca == 2 && personagem.porte != 2 && personagem.porte != 3) {
                    printf("Anões só podem escolher porte médio ou pequeno. Por favor, escolha uma opcão válida.\n");
                    continue;
                }
              
                printf("E agora?\n1.Recriar Personagem\n2. Iniciar Jogo\n3. Sair\n");
                getchar();
                personagemCriado = 1;
                continue;

        case 2: 

        if (personagemCriado == 0) {
        printf("Você precisa criar um personagem antes de iniciar o jogo.\n\n");
        continue;
        } else {
        printf("Perfeito! Agora você está pronto para embarcar nesta aventura emocionante. Boa sorte!\n\n");
                       
       printf("Pressione Enter para comecar a play\n");
       getchar();
       scanf("%*c");
       printf("\n\n");

      //PEQUENA INTRODUcAO    
      printf("Antigamente Papilon era um castelo muito vitado por todas as regioes\nTodas as racas eram bem vindas no reino e todos vivam em harmonia\nMas apos a morte do rei que era um mestico tudo mudou...........(enter)\n");
      getchar();
      printf("O rei foi morto por uma criatura gigante q vive a redor do castelo\nNao sabemos como essa criatura chegou aqui, mas tudo indica\nque veio de uma maldicao........(enter)");
      getchar();

      
      //MAPA DO JOGO
      printf("MAPA DAS REGIOES\n\n");
      printf("*******************************************************************************\n");
      printf("      ^               ^^^   *     *                /^                /      ^ *\n");
      printf("     ^^^ ^           ^^|^^    *   *        /^     /  ^    /^        /        ^*\n");
      printf("    ^^|^^^^       ^       ^    *  *       /  ^   /DALAS  /  ^ /^   /          *\n");
      printf("  ^    ^^|^^     ^^^     ^^^   ____      /    ^/       ^/    /  ^ /     *******\n");
      printf(" ^^^              |     ^^|^^  ____     /      ^       /    /    ^     *      *\n");
      printf(" ^|^^                         *   **                       /         *        *\n");
      printf("   FLORESTA AQUARIUS         *      **                             *          *\n");
      printf("    ^             ^        *         ******************************           *\n");
      printf("   ^^^           ^^^     *               _____    /*    _____                 *\n");
      printf("  ^^|^^         ^^|^^  *                 | 0 |    ||    | 0 |                 *\n");
      printf("       ^             *                    | |    |  |    | |                  *\n");
      printf("      ^^^ ^        *                     |   | PAPILON  |   |                 *\n");
      printf("     ^^|^^^^      *                      | ||     __     || |                 *\n");
      printf("        ^^|^^    *  *********           |        |  |        |                *\n");
      printf("                *  *         *          |_______|____|_______|                *\n");
      printf("               ____          ****               |    |                        *\n");
      printf("   ^          ____    z          ***************|    |****************        *\n");
      printf("  ^^^        *  *    z                                                **      *\n");
      printf(" ^^|^^     *   *    z                                                   **    *\n");
      printf("         *   *     ||____             /z                                  **  *\n");
      printf("       *   *      |__||__|           |__|       BETTY BOOP   ^              ***\n");
      printf("      *   *                       ^                         ^^^               *\n");
      printf("     *   *           z   /~      ^^^                 z     ^^|^^              *\n");
      printf("    *    *         z    |__|    ^^|^^              z              /~          *\n");
      printf("  *       *     __||                          ____||             |__|         *\n");
      printf("*          *   |_||_|                        |__||_|                          *\n");
      printf("*******************************************************************************\n(enter)\n\n");
      getchar();

      printf("Cada regiao eh habitada por uma raca:\n******************************************************************\n\nEm Papilon: esta vazio, vivendo apenas a criatura nas aguas do castelo;\n\nNa floresta Aquarius: vivem os elfos dentro da mata;\n\nNas montanhas de Dalas: vivem os anoes\n\nEm Betty Boop: vivem os humanos e mestiços em um vilarejo\n\n*******************************************************************\n(enter)\n\n");
      getchar();
      printf("sabendo dissso, voce vai possuir 100 de vida,\nfaca com cuidado seus proximos passos!(enter)\n\n");
      getchar();

          //GAME PLAY
          printf("     Iniciando jogo\n");
          printf(".........................\n     precione enter\n");
          getchar();

           //PEQUENA NARRATIVA
      printf("Voce comeca sua jornada no vilarejo de Betty Boop onde vive sua melhor amiga Lanti,\numa mestica de ELFO/ANAO, uma pequenina de orelhas pontudas.\nVoces estao na casa de Lanti e o vilarejo comeca a ser atacado\nvoces fogem para a floresta\n\nmas....\n\nno caminho Lanti eh pega pelos capangas vindos do castelo...(enter)\n\n");
      getchar();
            // Evento 1
            evento1();

            // Evento 2 (baseado no alinhamento)
            int alinhamento = 1; // Supondo que o alinhamento seja mal
            evento2(alinhamento);

            // Evento 3 (baseado na profissão)
            int profissao = 3; // Supondo que a profissão seja Ladino
            evento3(profissao);
          
            //JOKENPO
            jogarJokenpo(&vida);

          //charadas
          srand(time(NULL));

        Pergunta perguntas[] = {
        {
            "Sou o princípio do fim e o fim do tempo. Sou um mistério que nunca foi resolvido. Quem sou eu?",
            {"O infinito", "O espaco", "O vazio"},
            1
        },
        {
            "Sou um enigma complexo, incompreensível para a mente humana. Alguns me estudam a vida inteira e nunca me compreendem. O que sou?",
            {"A consciência", "O universo", "O tempo"},
            2
        },
        {
            "Sou uma palavra de sete letras. Quando você me dá, você me quebra. Quando você me leva, você me deixa. Quem sou eu?",
            {"Silêncio", "Segredo", "Presente"},
            2
        },
        {
            "Sou um lugar onde você pode entrar, mas nunca sair. Sou escuro e assustador, cheio de enigmas e armadilhas. O que sou?",
            {"O abismo", "A mente", "O pesadelo"},
            1
        },
        {
            "Sou um fenômeno natural que ocorre apenas uma vez a cada dois anos. Sou tão raro que muitos não acreditam em minha existência. O que sou?",
            {"Um eclipse total", "Uma aurora boreal", "Uma chuva de meteoros"},
            3
        },
        {
            "Sou um quebra-cabeca matemático que desafia até os mais brilhantes. Minha solucão está além dos números e das equacões. O que sou?",
            {"O teorema de Fermat", "O paradoxo de Zenão", "O problema de P versus NP"},
            2
        },
        {
            "Sou um objeto que todos possuem, mas poucos realmente conhecem. Quanto mais você me usa, menos você me vê. O que sou?",
            {"A intuicão", "O tempo", "A memória"},
            3
        },
        {
            "Sou um enigma que só pode ser desvendado olhando para trás. Quem me resolve encontra a resposta para o futuro. O que sou?",
            {"A história", "O destino", "A sabedoria"},
            1
        },
        {
            "Sou uma forca invisível que molda o universo. Sou a causa de grandes fenômenos, mas minha verdadeira natureza ainda é um mistério. Quem sou eu?",
            {"A gravidade", "O amor", "A energia"},
            1
        },
        {
            "Sou um paradoxo que desafia a lógica e a razão. Existem diferentes versões de mim e todas parecem verdadeiras. O que sou?",
            {"A verdade", "A ilusão", "A contradicão"},
            2
        },
    };

    int numPerguntas = sizeof(perguntas) / sizeof(perguntas[0]);
    int perguntasSorteadas[numPerguntas];
    int numPerguntasSorteadas = 0;
    int vida = 100; // Pontos de vida inicial do jogador
    int charadasCorretas = 0; // Número de charadas corretas

    // Inicializa o array de perguntas sorteadas
    for (int i = 0; i < numPerguntas; i++) {
        perguntasSorteadas[i] = 0;
    }

    // Realiza os sorteios até não haver mais perguntas disponíveis, a vida do jogador chegar a 0 ou o jogador acertar 3 charadas
    while (numPerguntasSorteadas < numPerguntas && vida > 0 && charadasCorretas < 3) {
        sortearPergunta(perguntas, numPerguntas, perguntasSorteadas, &numPerguntasSorteadas, &vida, &charadasCorretas);
    }

    // Exibe o resultado final
    if (vida <= 0) {
        printf("Você perdeu todas as suas vidas.\n");
         printf("   _____                         ____                 \n");
         printf("  / ____|                       / __ \\                \n");
         printf(" | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n");
         printf(" | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|\n");
         printf(" | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n");
         printf("  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   \n");
      
    } else if (charadasCorretas >= 3) {
        printf("Parabéns! voce ganhou do Jere e salvou Lanti\nVocê ganhou o jogo com %d pontos de vida restantes.\nvoce pode seguir oq desejava fazer desde o inicio.... boa sorte", vida);
    } else {
        printf("Você não respondeu corretamente às charadas suficientes para ganhar o jogo.\n");
    }
        break;
        }
        case 3:
                printf("Saindo do jogo...\n");
                return 0;

                default:
                printf("Escolha uma opcao valida....\n");
                break;
        }
    }
    return 0;
}