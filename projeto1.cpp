#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

// Função turno roda o dado e retorna o valor;
int turno() {
    unsigned seed = time(0);
    srand(seed);
    int dado;
    dado = 1 + rand() % 6;
    return dado;
}


int main() {
    // trilha das casas do mapa;
    vector<vector<int>> trilha_geral =
    {
        {683, 269},
        {683, 291},
        {684, 313},
        {684, 336},
        {685, 358},
        {685, 381},
        {722, 407},
        {759, 407},
        {796, 407},
        {833, 407},
        {870, 407},
        {907, 407},
        {913, 435},
        {919, 462},
        {880, 462},
        {841, 462},
        {802, 462},
        {763, 462},
        {724, 462},
        {690, 493},
        {691, 528},
        {692, 563},
        {693, 598},
        {694, 633},
        {695, 668},
        {649, 668},
        {604, 668},
        {605, 633},
        {606, 598},
        {607, 563},
        {608, 528},
        {609, 493},
        {575, 462},
        {536, 462},
        {497, 462},
        {458, 462},
        {419, 462},
        {380, 462},
        {386, 435},
        {392, 407},
        {429, 407},
        {466, 407},
        {503, 407},
        {540, 407},
        {577, 407},
        {614, 381},
        {615, 358},
        {615, 336},
        {616, 313},
        {616, 291},
        {617, 269},
        {650, 269},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0}
    };

    //vetor que guarda os valores dos dados do player atual na rodada;
    vector<int> dados;
    int dado;

    // iniciar as funções do allegro
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_install_audio(); 
    al_init_acodec_addon();
    al_reserve_samples(1); // reserva um espaço para os áudios;

    // Cria o display do jogo
    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, "Lutherum");

    //cria o audio no jogo;
    ALLEGRO_SAMPLE* song = al_load_sample("Lutherum_padrao.mp3");
    ALLEGRO_SAMPLE_INSTANCE* songInstance = al_create_sample_instance(song);
    al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

    ALLEGRO_FONT* font = al_load_font("font.ttf", 10, 0);
    ALLEGRO_FONT* fontM = al_load_font("font.ttf", 30, 0);
    ALLEGRO_FONT* fontC = al_load_font("font.ttf", 30, 0);
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

    ALLEGRO_BITMAP* sprite = al_load_bitmap("tabuleiro.png");
    ALLEGRO_BITMAP* ponto = al_load_bitmap("ponto.png");
    ALLEGRO_BITMAP* pontoam = al_load_bitmap("ouros.png");
    ALLEGRO_BITMAP* pontoaz = al_load_bitmap("espadas.png");
    ALLEGRO_BITMAP* pontovd = al_load_bitmap("paus.png");
    ALLEGRO_BITMAP* pontovm = al_load_bitmap("copas.png");
    ALLEGRO_BITMAP* dado1 = al_load_bitmap("dado1.png");
    ALLEGRO_BITMAP* dado2 = al_load_bitmap("dado2.png");
    ALLEGRO_BITMAP* dado3 = al_load_bitmap("dado3.png");
    ALLEGRO_BITMAP* dado4 = al_load_bitmap("dado4.png");
    ALLEGRO_BITMAP* dado5 = al_load_bitmap("dado5.png");
    ALLEGRO_BITMAP* dado6 = al_load_bitmap("dado6.png");
    ALLEGRO_BITMAP* carta_paladina = al_load_bitmap("carta_paladina.png");
    ALLEGRO_BITMAP* carta_guerreiro = al_load_bitmap("carta_guerreiro.png");
    ALLEGRO_BITMAP* carta_cleriga = al_load_bitmap("carta_cleriga.png");
    ALLEGRO_BITMAP* carta_druida = al_load_bitmap("carta_druida.png");
    ALLEGRO_BITMAP* carta_boa = al_load_bitmap("carta_boa.png");
    ALLEGRO_BITMAP* carta_ruim = al_load_bitmap("carta_ruim.png");



    // Cria eventos que o usuário pode interagir
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_play_sample_instance(songInstance);
    al_start_timer(timer);

    float frame = 0.f;
    int pos_x = 0;
    int pos_y = 0;
    int current_frame_y = 161;
    int soma = 0;
    int time = 0;
    int objective = 0; //quantidade total de casas que o peão vai andar;
    int numbers1 = 90; //variável de controle da animação do dado 1;
    int numbers2 = 90; //variável de controle da animação do dado 2;
    int numbers3 = 90; //variável de controle da animação do dado 3;
    bool next = true; //variável para saber se o turno de cada jogador acabou;
    bool retafinal = false; //quando o jogador atual possui ao menos um peão na seta;
    bool finded = false; //achar um peão do lado de fora do habitat;
    int objectivedado = 0; //igual à variável objective, mas isola o dado escolhido;
    int coefg; //coeficiente de diferença de tamanho dos peões amarelos;
    float coef; //coeficiente geral de diferença de tamanho;

    vector <int> dadosaux; //vetor auxiliar para saber quantos dados ainda estão disponíveis para escolha;

    class player {
        public:
            vector<int>trilha;
            vector<vector<int>>seta;
            vector<vector<int>>habitat;
            vector<int>peoes;



            void getValues(int cor) {
                this->peoes = { 56,57,58 };

                if (cor == 1) { //vermelho
                    this->seta = {
                        {650, 291},
                        {650, 313},
                        {650, 335},
                        {650, 357},
                        {650, 379}
                    };

                    this->trilha = {1, 52};

                    this->habitat = {
                        {732, 377},
                        {760, 360},
                        {787, 339}
                    };

                }
                else if (cor == 2) { //azul
                    this->seta = {
                        {875, 435},
                        {837, 435},
                        {799, 435},
                        {761, 435},
                        {723, 435},
                    };

                    this->trilha = {14, 12};

                    this->habitat = {
                        {808, 503},
                        {778, 529},
                        {747, 555}
                    };

                }
                else if (cor == 3) { //verde
                    this->seta = {
                        {649, 633},
                        {649, 598},
                        {649, 563},
                        {649, 528},
                        {649, 493},
                    };

                    this->trilha = {27, 25};

                    this->habitat = {
                        {566, 529},
                        {559, 579},
                        {552, 630}
                    };
                }
                else if (cor == 4) { //amarelo
                    this->seta = {
                        {424, 435},
                        {462, 435},
                        {500, 435},
                        {538, 435},
                        {576, 435},
                    };

                    this->trilha = {40, 38};

                    this->habitat = {
                        {510, 377},
                        {575, 377},
                        {580, 340}
                    };
                }
            }
            void changeValue(int peao, int newValue) {
                this->peoes[peao] = newValue;
            }
    };

    vector<player> players;
   
    player vermelho;
    player azul;
    player verde;
    player amarelo;

    vermelho.getValues(1);
    players.push_back(vermelho);
    azul.getValues(2);
    players.push_back(azul);
    verde.getValues(3);
    players.push_back(verde);
    amarelo.getValues(4);
    players.push_back(amarelo);

    int turnos = 0; // para saber de quem é a vez;
    int casa;
    bool card = false;
    int card_y = 720;
    bool type = false;
    int cardObjective = 0;

    while (true) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        al_draw_bitmap(sprite, 0, 0, 0); // impressão do tabuleiro;

        al_draw_scaled_bitmap(carta_paladina, 0, 0, 1488, 2078, 200, 20, 148, 207, 0);
        al_draw_scaled_bitmap(carta_cleriga, 0, 0, 1488, 2078, 950, 20, 148, 207, 0);
        al_draw_scaled_bitmap(carta_druida, 0, 0, 1488, 2078, 150, 470, 148, 207, 0);
        al_draw_scaled_bitmap(carta_guerreiro, 0, 0, 1488, 2078, 1000, 470, 148, 207, 0);


        //contadores de animação dos dados
        if (numbers1 < 90) {
            numbers1++;
        }
        if (numbers2 < 90) {
            numbers2++;
        }
        if (numbers3 < 90) {
            numbers3++;
        }
        
        if (dadosaux.size() > 1) { //caso ele tenha tirado um 6 e tenha mais de um dado para escolher
            al_draw_text(font, al_map_rgb(255, 255, 255), 100, 80, 0, "Selecione o Dado:");// imprime um texto
            
            for (int k = 0; k < dadosaux.size(); k++) {//imprime cada dado dentro do vetor auxiliar dos dados;
                if (dadosaux[k] == 1) { // impressão do dado obtido;
                    al_draw_scaled_bitmap(dado1, 90 * 200, 0, 200, 200, 20, 20 + k * 40, 40, 40, 2);
                }
                else if (dadosaux[k] == 2) {
                    al_draw_scaled_bitmap(dado2, 90 * 200, 0, 200, 200, 20, 20 + k * 40, 40, 40, 2);
                }
                else if (dadosaux[k] == 3) {
                    al_draw_scaled_bitmap(dado3, 90 * 200, 0, 200, 200, 20, 20 + k * 40, 40, 40, 2);
                }
                else if (dadosaux[k] == 4) {
                    al_draw_scaled_bitmap(dado4, 90 * 200, 0, 200, 200, 20, 20 + k * 40, 40, 40, 2);
                }
                else if (dadosaux[k] == 5) {
                    al_draw_scaled_bitmap(dado5, 90 * 200, 0, 200, 200, 20, 20 + k * 40, 40, 40, 2);
                }
                else if (dadosaux[k] == 6) {
                    al_draw_scaled_bitmap(dado6, 90 * 200, 0, 200, 200, 20, 20 + k * 40, 40, 40, 2);
                }
            }
        }
        if (dados.size() > 0) { // Imprime o primeiro dado;
            if (dados[0] == 1) {
                al_draw_scaled_bitmap(dado1, numbers1 * 200, 0, 200, 200, 1160, 240, 120, 120, 0);
            }
            if (dados[0] == 2) {
                al_draw_scaled_bitmap(dado2, numbers1 * 200, 0, 200, 200, 1160, 240, 120, 120, 0);
            }
            if (dados[0] == 3) {
                al_draw_scaled_bitmap(dado3, numbers1 * 200, 0, 200, 200, 1160, 240, 120, 120, 0);
            }
            if (dados[0] == 4) {
                al_draw_scaled_bitmap(dado4, numbers1 * 200, 0, 200, 200, 1160, 240, 120, 120, 0);
            }
            if (dados[0] == 5) {
                al_draw_scaled_bitmap(dado5, numbers1 * 200, 0, 200, 200, 1160, 240, 120, 120, 0);
            }
            if (dados[0] == 6) {
                al_draw_scaled_bitmap(dado6, numbers1 * 200, 0, 200, 200, 1160, 240, 120, 120, 0);
            }

        }
        if (dados.size() > 1) { // Imprime o segundo dado, caso exista;
            if (dados[1] == 1) {
                al_draw_scaled_bitmap(dado1, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 2);
            }
            if (dados[1] == 2) {
                al_draw_scaled_bitmap(dado2, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 2);
            }
            if (dados[1] == 3) {
                al_draw_scaled_bitmap(dado3, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 2);
            }
            if (dados[1] == 4) {
                al_draw_scaled_bitmap(dado4, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 2);
            }
            if (dados[1] == 5) {
                al_draw_scaled_bitmap(dado5, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 2);
            }
            if (dados[1] == 6) {
                al_draw_scaled_bitmap(dado6, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 2);
            }
        }
        if (dados.size() > 2) { // Imprime o terceiro dado, caso exista;
            if (dados[2] == 1) {
                al_draw_scaled_bitmap(dado1, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 2);
            }
            if (dados[2] == 2) {
                al_draw_scaled_bitmap(dado2, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 2);
            }
            if (dados[2] == 3) {
                al_draw_scaled_bitmap(dado3, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 2);
            }
            if (dados[2] == 4) {
                al_draw_scaled_bitmap(dado4, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 2);
            }
            if (dados[2] == 5) {
                al_draw_scaled_bitmap(dado5, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 2);
            }
            if (dados[2] == 6) {
                al_draw_scaled_bitmap(dado6, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 2);
            }
        }

        coef = 0.03; // Instanciando os coeficientes;
        
        //Cada for imprime os peões em suas localizações;
        for (int peao = 0; peao < 3; peao++) {
            coefg = (trilha_geral[players[0].peoes[peao]][1] >= 439) ? 60 + coef * (trilha_geral[players[0].peoes[peao]][1] - 439) : 60 - coef * (439 - trilha_geral[players[0].peoes[peao]][1]);
            
            if (players[0].peoes[peao] > 55) {
                al_draw_scaled_bitmap(pontovm, 0, 0, 200, 200, players[0].habitat[peao][0] - (coefg * 0.4), players[0].habitat[peao][1] - (coefg * 0.6), coefg, coefg, 0);
            }
            else if (players[0].peoes[peao] > 51) {
                casa = players[0].peoes[peao] - 51;
                al_draw_scaled_bitmap(pontovm, 0, 0, 200, 200, players[0].seta[casa][0] - (coefg * 0.4), players[0].seta[casa][1] - (coefg * 0.6), coefg, coefg, 0);
            }
            else {
                al_draw_scaled_bitmap(pontovm, 0, 0, 200, 200, trilha_geral[players[0].peoes[peao]][0] - (coefg * 0.4), trilha_geral[players[0].peoes[peao]][1] - (coefg * 0.6), coefg, coefg, 0);
            }
        }
        for (int peao = 0; peao < 3; peao++) {
            coefg = (trilha_geral[players[1].peoes[peao]][1] >= 439) ? 60 + coef * (trilha_geral[players[1].peoes[peao]][1] - 439) : 60 - coef * (439 - trilha_geral[players[1].peoes[peao]][1]);
            if (players[1].peoes[peao] > 55) {
                al_draw_scaled_bitmap(pontoaz, 0, 0, 200, 200, players[1].habitat[peao][0] - (coefg * 0.4), players[1].habitat[peao][1] - (coefg * 0.6), coefg, coefg, 0);
            }
            else if (players[1].peoes[peao] > 51) {
                casa = players[1].peoes[peao] - 51;
                al_draw_scaled_bitmap(pontoaz, 0, 0, 200, 200, players[1].seta[casa][0] - (coefg * 0.4), players[1].seta[casa][1] - (coefg * 0.6), coefg, coefg, 0);
            }
            else {
                al_draw_scaled_bitmap(pontoaz, 0, 0, 200, 200, trilha_geral[players[1].peoes[peao]][0] - (coefg * 0.4), trilha_geral[players[1].peoes[peao]][1] - (coefg * 0.6), coefg, coefg, 0);
            }
        }
        for (int peao = 0; peao < 3; peao++) {
            coefg = (trilha_geral[players[2].peoes[peao]][1] >= 439) ? 60 + coef * (trilha_geral[players[2].peoes[peao]][1] - 439) : 60 - coef * (439 - trilha_geral[players[2].peoes[peao]][1]);
            if (players[2].peoes[peao] > 55) {
                al_draw_scaled_bitmap(pontovd, 0, 0, 200, 200, players[2].habitat[peao][0] - (coefg * 0.4), players[2].habitat[peao][1] - (coefg * 0.6), coefg, coefg, 0);
            }
            else if (players[2].peoes[peao] > 51) {
                casa = players[2].peoes[peao] - 51;
                al_draw_scaled_bitmap(pontovd, 0, 0, 200, 200, players[2].seta[casa][0] - (coefg * 0.4), players[2].seta[casa][1] - (coefg * 0.6), coefg, coefg, 0);
            }
            else {
                al_draw_scaled_bitmap(pontovd, 0, 0, 200, 200, trilha_geral[players[2].peoes[peao]][0] - (coefg * 0.4), trilha_geral[players[2].peoes[peao]][1] - (coefg * 0.6), coefg, coefg, 0);
            }
        }
        for (int peao = 0; peao < 3; peao++) {
            coefg = (trilha_geral[players[3].peoes[peao]][1] >= 439) ? 60 + coef * (trilha_geral[players[3].peoes[peao]][1] - 439) : 60 - coef * (439 - trilha_geral[players[3].peoes[peao]][1]);
            if (players[3].peoes[peao] > 55) {
                al_draw_scaled_bitmap(pontoam, 0, 0, 200, 200, players[3].habitat[peao][0] - (coefg * 0.4), players[3].habitat[peao][1] - (coefg * 0.6), coefg, coefg, 0);
            }
            else if (players[3].peoes[peao] > 51) {
                casa = players[3].peoes[peao] - 51;
                al_draw_scaled_bitmap(pontoam, 0, 0, 200, 200, players[3].seta[casa][0] - (coefg * 0.4), players[3].seta[casa][1] - (coefg * 0.6), coefg, coefg, 0);
            }
            else {
                al_draw_scaled_bitmap(pontoam, 0, 0, 200, 200, trilha_geral[players[3].peoes[peao]][0] - (coefg * 0.4), trilha_geral[players[3].peoes[peao]][1] - (coefg * 0.6), coefg, coefg, 0);
            }
        }

        // Um if para imprimir de quem é o turno;
        if (turnos == 0) {
            al_draw_text(fontM, al_map_rgb(255, 255, 255), 1270, 10, ALLEGRO_ALIGN_RIGHT, "Vez do Vermelho");
        }
        else if (turnos == 1) {
            al_draw_text(fontM, al_map_rgb(255, 255, 255), 1270, 10, ALLEGRO_ALIGN_RIGHT, "Vez do Azul");
        }
        else if (turnos == 2) {
            al_draw_text(fontM, al_map_rgb(255, 255, 255), 1270, 10, ALLEGRO_ALIGN_RIGHT, "Vez do Verde");
        }
        else {
            al_draw_text(fontM, al_map_rgb(255, 255, 255), 1270, 10, ALLEGRO_ALIGN_RIGHT, "Vez do Amarelo");
        }

        if (card == true) {
            if (type) {
                al_draw_scaled_bitmap(carta_boa, 0, 0, 1488, 2078, 392, card_y, 496, 692, 0);
                al_draw_text(fontC, al_map_rgb(0, 0, 0), 640, card_y + 440, ALLEGRO_ALIGN_CENTER, "Avance 3 casas");
            }
            else {
                al_draw_scaled_bitmap(carta_ruim, 0, 0, 1488, 2078, 392, card_y, 496, 692, 0);
                al_draw_text(fontC, al_map_rgb(0, 0, 0), 640, card_y + 440, ALLEGRO_ALIGN_CENTER, "Volte 3 casas");
            }
            if (card_y > 14) {
                if (card_y - 40 < 14) {
                    card_y = 14;
                }
                else {
                    card_y -= 40;
                }
            }
        }

        //if pra verificar se o usuário apertar o enter;
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && card == true && cardObjective == 0) {
            if (type) {
                cardObjective = 3;
            }
            else {
                cardObjective = -3;
            }
            card = false;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && time > 15 && objective == 0 && card == false) {
            time = 0;
            if (next == true) { //se a vez do próximo player é verdadeira, ele reseta todas as variáveis de turno;
                next = false;
                finded = false;
                numbers1 = 90;
                numbers2 = 90;
                numbers3 = 90;
                objective = 0;
                objectivedado = 0;
                dados = {};
                dadosaux = {};
                card = false;
                card_y = 720;
            }
            dados = {};
            dado = turno(); //função turno sendo chamada, aqui que é gerado o número aleatório;
            dados.push_back(dado); //insere o dado no vetor dados;
            dadosaux.push_back(dado); //insere o dado no vetor dados auxiliar;

            //if condicionais para controlar as animações dos dados;
            if (dados.size() == 1) {
                numbers1 =  60;
            }
            if (dados.size() == 2) {
                numbers2 = 60;
            }
            if (dados.size() == 3) {
                numbers3 = 60;
            }

            if (dado != 6) { //if que verifica se o dado atual é diferente de 6, se sim, ele encerra a rolagem de dados;
                for (int j = 0; j < dadosaux.size(); j++) {//for que soma todos os valores no vetor dados;
                    soma = soma + dadosaux[j];
                }
            }
            else { //caso der 6, ele verifica se o jogador já tem 3 dados dentro do vetor;
                if (dadosaux.size() == 3) {
                    // aqui o usuário perde a vez, caso tire três 6 seguidos;
                    if (turnos == 3) {
                        turnos = 0;
                    }
                    else {
                        turnos++;
                    }
                    next = true;
                }
            }
            objective = soma;
            soma = 0;
        }
        if (cardObjective != 0 && card_y == 14) {
            if (cardObjective < 0) {
                players[turnos].changeValue(0, players[turnos].peoes[0] - 1);
                cardObjective++;
            }
            else {
                players[turnos].changeValue(0, players[turnos].peoes[0] + 1);
                cardObjective--;
            }
        }
        //caso objetivo seja maior que 0 e as animações estejam encerradas;
        if (objective > 0 && numbers1 == 90 && numbers2 == 90 && numbers3 == 90) {
            for (int pos = 0; pos < 3; pos++) { //verifica se tem peões do player atual na trilha;
                if (players[turnos].peoes[pos] < 56) {
                    finded = true;
                }
            }
            // caso ele encontre os peões;
            if (finded) {
                if (dadosaux.size() > 1) { //confere se o vetor dados possui mais de um dado para escolher;
                    al_wait_for_event(event_queue, &event); //aguarda a escolha;
                    if (event.keyboard.keycode == ALLEGRO_KEY_1 && objectivedado == 0) {
                        objectivedado = dadosaux[0];
                        dadosaux.erase(dadosaux.begin()); //erase apaga um valor da lista;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_2 && objectivedado == 0) {
                        objectivedado = dadosaux[1];
                        dadosaux.erase(dadosaux.begin() + 1); //erase apaga um valor da lista;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_3 && objectivedado == 0 && dadosaux.size() == 3) {
                        objectivedado = dadosaux[2];
                        dadosaux.pop_back(); //pop_back apaga o último valor da lista;
                    }
                    //caso ele escolha um valor, o peão vai andar;
                    else if (objectivedado > 0 && time > 15) {
                        time = 0;
                        if (players[turnos].peoes[0] == players[turnos].trilha[1]) {
                            players[turnos].changeValue(0, 52);
                        }
                        else if (players[turnos].peoes[0] == 51) {
                            players[turnos].changeValue(0, 0);
                        }
                        else {
                            players[turnos].changeValue(0, players[turnos].peoes[0] + 1);
                        }
                        
                        objectivedado--;
                        objective--;
                    }
                }
                else { //caso não haja mais de um dado para escolher, o peão anda automaticamente com o dado que sobrou;
                    if (time > 15) {
                        time = 0;
                        if (players[turnos].peoes[0] == players[turnos].trilha[1]) {
                            players[turnos].changeValue(0, 52);
                        }
                        else if (players[turnos].peoes[0] == 51) {
                            players[turnos].changeValue(0, 0);
                        }
                        else {
                            players[turnos].changeValue(0, players[turnos].peoes[0] + 1);
                        }
                        objective--;
                    }
                }
                //6.13.32.45. 7.14.33.46
                if (players[turnos].peoes[0] == 5 || players[turnos].peoes[0] == 12 || players[turnos].peoes[0] == 31 || players[turnos].peoes[0] == 44) {
                    card = true;
                    type = true;
                }
                if (players[turnos].peoes[0] == 6 || players[turnos].peoes[0] == 13 || players[turnos].peoes[0] == 32 || players[turnos].peoes[0] == 45) {
                    card = true;
                    type = false;
                }


                if (objective == 0) {
                    if (turnos == 3) {
                        turnos = 0;
                    }
                    else {
                        turnos++;
                    }
                    next = true;
                }
            }
            else { //caso não haja peão na trilha;
                if (find(dadosaux.begin(), dadosaux.end(), 6) != dadosaux.end()) {
                    dadosaux.erase(dadosaux.begin());
                    players[turnos].changeValue(0, players[turnos].trilha[0]);
                    objective = objective - 6;
                }
                else {
                    if (turnos == 3) {
                        turnos = 0;
                    }
                    else {
                        turnos++;
                    }
                    objective = 0;
                    next = true;
                }
            }
            
        }
        
        time++;

        //superior
        
        /*for (int i = 0; i < 6; i++) {// primeiro
            al_draw_bitmap(ponto, 650, 269 + i * 22.4, 0);
        }
        

        //Direita
        for (int i = 0; i < 6; i++) { // primeiro
            al_draw_bitmap(ponto, (918 - 38 * i) - 5, 435, 0);
        }
        
        //esquerda

        for (int i = 0; i < 6; i++) { //primeiro
            al_draw_bitmap(ponto, (391 + 38 * i) - 5, 435, 0);
        }
        

        //Baixo
        for (int i = 0; i < 6; i++) { // ultimo
            al_draw_bitmap(ponto, (654) - 5, 493 + i * 35, 0);
        }
        


        for (int i = 0; i < 6; i++) {
            al_draw_bitmap(ponto, 683 + 0.5 * i, 269 + i * 22.4, 0);
        }
        for (int i = 0; i < 6; i++) { // inverte
            al_draw_bitmap(ponto, (912 - 37 * i) - 5, 407, 0);
        }
        for (int i = 0; i < 6; i++) {
            al_draw_bitmap(ponto, (924 - 39 * i) - 5, 462, 0);
        }
        for (int i = 0; i < 6; i++) {
            al_draw_bitmap(ponto, (695 + i) - 5, 493 + i * 35, 0);
        }
        for (int i = 0; i < 6; i++) { //inverte
            al_draw_bitmap(ponto, (614 - i) - 5, 493 + i * 35, 0);
        }
        for (int i = 0; i < 6; i++) { //inverte
            al_draw_bitmap(ponto, (385 + 39 * i) - 5, 462, 0);
        }
        for (int i = 0; i < 6; i++) {
            al_draw_bitmap(ponto, (397 + 37 * i) - 5, 407, 0);
        }
        for (int i = 0; i < 6; i++) { //inverte
            al_draw_bitmap(ponto, 617 - 0.5 * i, 269 + i * 22.4, 0);
        }*/
        
        al_flip_display();

    }
    
    al_destroy_bitmap(dado1);
    al_destroy_bitmap(dado2);
    al_destroy_bitmap(dado3);
    al_destroy_bitmap(dado4);
    al_destroy_bitmap(dado5);
    al_destroy_bitmap(dado6);
    al_destroy_sample(song);
    al_destroy_sample_instance(songInstance);
    al_destroy_bitmap(sprite);
    al_destroy_bitmap(ponto);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}