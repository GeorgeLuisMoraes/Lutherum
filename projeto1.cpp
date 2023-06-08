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

// Fun��o turno roda o dado e retorna o valor;
int turno() {
    unsigned seed = time(0);
    srand(seed);
    int dado;
    dado = 1 + rand() % 6;
    return dado;
}


int main() {
    // trilha das casas do mapa;
    vector<vector<int>> trilha_amarelo =
    {
        {677, 109},
        {678, 138},
        {679, 167},
        {680, 196},
        {681, 225},
        {729, 257},
        {775, 257},
        {821, 257},
        {867, 257},
        {913, 257},
        {959, 257},
        {966, 289},
        {973, 327},
        {925, 327},
        {877, 327},
        {829, 327},
        {781, 327},
        {733, 327},
        {685, 365},
        {686, 402},
        {688, 443},
        {689, 486},
        {691, 533},
        {692, 582},
        {635, 582},
        {579, 582},
        {581, 533},
        {582, 486},
        {584, 443},
        {585, 402},
        {587, 365},
        {538, 327},
        {490, 327},
        {442, 327},
        {394, 327},
        {346, 327},
        {298, 327},
        {306, 289},
        {313, 257},
        {359, 257},
        {405, 257},
        {451, 257},
        {497, 257},
        {543, 257},
        {591, 225},
        {592, 196},
        {593, 167},
        {594, 138},
        {595, 109},
        {596, 80},
        {636, 80},
        {635, 109},
        {635, 138},
        {635, 167},
        {635, 196},
        {635, 225},
        {750,210},
        {740, 110},
        {910, 210}
    };
    // trilha das casas do mapa;
    vector<vector<int>> trilha_vermelho =
    {
        {925, 327},
        {877, 327},
        {829, 327},
        {781, 327},
        {733, 327},
        {685, 365},
        {686, 402},
        {688, 443},
        {689, 486},
        {691, 533},
        {692, 582},
        {635, 582},
        {579, 582},
        {581, 533},
        {582, 486},
        {584, 443},
        {585, 402},
        {587, 365},
        {538, 327},
        {490, 327},
        {442, 327},
        {394, 327},
        {346, 327},
        {298, 327},
        {306, 289},
        {313, 257},
        {359, 257},
        {405, 257},
        {451, 257},
        {497, 257},
        {543, 257},
        {591, 225},
        {592, 196},
        {593, 167},
        {594, 138},
        {595, 109},
        {596, 80},
        {636, 80},
        {676, 80},
        {677, 109},
        {678, 138},
        {679, 167},
        {680, 196},
        {681, 225},
        {729, 257},
        {775, 257},
        {821, 257},
        {867, 257},
        {913, 257},
        {959, 257},
        {966, 289},
        {918, 289},
        {871, 289},
        {824, 289},
        {777, 289},
        {730, 289},
        {760,390},
        {770, 550},
        {960, 390}
    };
    // trilha das casas do mapa;
    vector<vector<int>> trilha_verde =
    {
        {581, 533},
        {582, 486},
        {584, 443},
        {585, 402},
        {587, 365},
        {538, 327},
        {490, 327},
        {442, 327},
        {394, 327},
        {346, 327},
        {298, 327},
        {306, 289},
        {313, 257},
        {359, 257},
        {405, 257},
        {451, 257},
        {497, 257},
        {543, 257},
        {591, 225},
        {592, 196},
        {593, 167},
        {594, 138},
        {595, 109},
        {596, 80},
        {636, 80},
        {676, 80},
        {677, 109},
        {678, 138},
        {679, 167},
        {680, 196},
        {681, 225},
        {729, 257},
        {775, 257},
        {821, 257},
        {867, 257},
        {913, 257},
        {959, 257},
        {966, 289},
        {973, 327},
        {925, 327},
        {877, 327},
        {829, 327},
        {781, 327},
        {733, 327},
        {685, 365},
        {686, 402},
        {688, 443},
        {689, 486},
        {691, 533},
        {692, 582},
        {635, 582},
        {635, 533},
        {635, 486},
        {635, 443},
        {635, 402},
        {635, 365},
        {520,390},
        {510, 550},
        {320, 390}
    };
    // trilha das casas do mapa;
    vector<vector<int>> trilha_azul =
    {
        {359, 257},
        {405, 257},
        {451, 257},
        {497, 257},
        {543, 257},
        {591, 225},
        {592, 196},
        {593, 167},
        {594, 138},
        {595, 109},
        {596, 80},
        {636, 80},
        {676, 80},
        {677, 109},
        {678, 138},
        {679, 167},
        {680, 196},
        {681, 225},
        {729, 257},
        {775, 257},
        {821, 257},
        {867, 257},
        {913, 257},
        {959, 257},
        {966, 289},
        {973, 327},
        {925, 327},
        {877, 327},
        {829, 327},
        {781, 327},
        {733, 327},
        {685, 365},
        {686, 402},
        {688, 443},
        {689, 486},
        {691, 533},
        {692, 582},
        {635, 582},
        {579, 582},
        {581, 533},
        {582, 486},
        {584, 443},
        {585, 402},
        {587, 365},
        {538, 327},
        {490, 327},
        {442, 327},
        {394, 327},
        {346, 327},
        {298, 327},
        {306, 289},
        {353, 289},
        {400, 289},
        {447, 289},
        {494, 289},
        {542, 289},
        {530,210},
        {540, 110},
        {380, 210}
    };

    //vetor que guarda os valores dos dados do player atual na rodada;
    vector<int> dados;
    int dado;

    // iniciar as fun��es do allegro
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_install_audio(); 
    al_init_acodec_addon();
    al_reserve_samples(1); // reserva um espa�o para os �udios;

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

    // Cria eventos que o usu�rio pode interagir
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
    int objective = 0; //quantidade total de casas que o pe�o vai andar;
    int numbers1 = 90; //vari�vel de controle da anima��o do dado 1;
    int numbers2 = 90; //vari�vel de controle da anima��o do dado 2;
    int numbers3 = 90; //vari�vel de controle da anima��o do dado 3;
    bool next = true; //vari�vel para saber se o turno de cada jogador acabou;
    bool retafinal = false; //quando o jogador atual possui ao menos um pe�o na seta;
    bool finded = false; //achar um pe�o do lado de fora do habitat;
    int objectivedado = 0; //igual � vari�vel objective, mas isola o dado escolhido;
    int coefam; //coeficiente de diferen�a de tamanho dos pe�es amarelos;
    int coefaz; //coeficiente de diferen�a de tamanho dos pe�es azul;
    int coefvd; //coeficiente de diferen�a de tamanho dos pe�es verde;
    int coefvm; //coeficiente de diferen�a de tamanho dos pe�es vermelho;
    float coef; //coeficiente geral de diferen�a de tamanho;

    vector <int> dadosaux; //vetor auxiliar para saber quantos dados ainda est�o dispon�veis para escolha;
    
    vector<vector<int>> players = { // guarda a posi��o de cada pe�o;
        {56,57,58},
        {56,57,58},
        {56,57,58},
        {56,57,58}
    };

    int turnos = 0; // para saber de quem � a vez;

    while (true) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        al_draw_bitmap(sprite, 0, 0, 0); // impress�o do tabuleiro;

        //contadores de anima��o dos dados
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
                if (dadosaux[k] == 1) { // impress�o do dado obtido;
                    al_draw_scaled_bitmap(dado1, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 2);
                }
                else if (dadosaux[k] == 2) {
                    al_draw_scaled_bitmap(dado2, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 2);
                }
                else if (dadosaux[k] == 3) {
                    al_draw_scaled_bitmap(dado3, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 2);
                }
                else if (dadosaux[k] == 4) {
                    al_draw_scaled_bitmap(dado4, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 2);
                }
                else if (dadosaux[k] == 5) {
                    al_draw_scaled_bitmap(dado5, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 2);
                }
                else if (dadosaux[k] == 6) {
                    al_draw_scaled_bitmap(dado6, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 2);
                }
            }
        }
        if (dados.size() > 0) { // Imprime o primeiro dado;
            if (dados[0] == 1) {
                al_draw_scaled_bitmap(dado1, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 2);
            }
            if (dados[0] == 2) {
                al_draw_scaled_bitmap(dado2, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 2);
            }
            if (dados[0] == 3) {
                al_draw_scaled_bitmap(dado3, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 2);
            }
            if (dados[0] == 4) {
                al_draw_scaled_bitmap(dado4, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 2);
            }
            if (dados[0] == 5) {
                al_draw_scaled_bitmap(dado5, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 2);
            }
            if (dados[0] == 6) {
                al_draw_scaled_bitmap(dado6, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 2);
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
        coefam = (trilha_amarelo[players[0][0]][1] >= 290) ? 60 + coef * (trilha_amarelo[players[0][0]][1] - 290) : 60 - coef * (290 - trilha_amarelo[players[0][0]][1]);
        coefaz = (trilha_azul[players[3][0]][1] >= 290) ? 60 + coef * (trilha_azul[players[3][0]][1] - 290) : 60 - coef * (290 - trilha_azul[players[3][0]][1]);
        coefvd = (trilha_verde[players[2][0]][1] >= 290) ? 60 + coef * (trilha_verde[players[2][0]][1] - 290) : 60 - coef * (290 - trilha_verde[players[2][0]][1]);
        coefvm = (trilha_vermelho[players[1][0]][1] >= 290) ? 60 + coef * (trilha_vermelho[players[1][0]][1] - 290) : 60 - coef * (290 - trilha_vermelho[players[1][0]][1]);
        
        //Cada for imprime os pe�es em suas localiza��es;
        for (int peao = 0; peao < players[0].size(); peao++) {
            al_draw_scaled_bitmap(pontoam, 0, 0, 200, 200, trilha_amarelo[players[0][peao]][0] - (coefam * 0.4), trilha_amarelo[players[0][peao]][1] - (coefam * 0.6), coefam, coefam, 0);
        }
        for (int peao = 0; peao < players[0].size(); peao++) {
            al_draw_scaled_bitmap(pontovm, 0, 0, 200, 200, trilha_vermelho[players[1][peao]][0] - (coefvm * 0.4), trilha_vermelho[players[1][peao]][1] - (coefvm * 0.6), coefvm, coefvm, 0);
        }
        for (int peao = 0; peao < players[0].size(); peao++) {
            al_draw_scaled_bitmap(pontovd, 0, 0, 200, 200, trilha_verde[players[2][peao]][0] - (coefvd * 0.4), trilha_verde[players[2][peao]][1] - (coefvd * 0.6), coefvd, coefvd, 0);
        }
        for (int peao = 0; peao < players[0].size(); peao++) {
            al_draw_scaled_bitmap(pontoaz, 0, 0, 200, 200, trilha_azul[players[3][peao]][0] - (coefaz * 0.4), trilha_azul[players[3][peao]][1] - (coefaz * 0.6), coefaz, coefaz, 0);
        }

        // Um if para imprimir de quem � o turno;
        if (turnos == 0) {
            al_draw_text(fontM, al_map_rgb(255, 255, 255), 1270, 10, ALLEGRO_ALIGN_RIGHT, "Vez do Amarelo");
        }
        else if (turnos == 1) {
            al_draw_text(fontM, al_map_rgb(255, 255, 255), 1270, 10, ALLEGRO_ALIGN_RIGHT, "Vez do Vermelho");
        }
        else if (turnos == 2) {
            al_draw_text(fontM, al_map_rgb(255, 255, 255), 1270, 10, ALLEGRO_ALIGN_RIGHT, "Vez do Verde");
        }
        else {
            al_draw_text(fontM, al_map_rgb(255, 255, 255), 1270, 10, ALLEGRO_ALIGN_RIGHT, "Vez do Azul");
        }
        
        //if pra verificar se o usu�rio apertar o enter;
        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && time > 15 && objective == 0) {
            time = 0;
            if (next == true) { //se a vez do pr�ximo player � verdadeira, ele reseta todas as vari�veis de turno;
                next = false;
                finded = false;
                numbers1 = 90;
                numbers2 = 90;
                numbers3 = 90;
                objective = 0;
                objectivedado = 0;
                dados = {};
                dadosaux = {};
            }

            dado = turno(); //fun��o turno sendo chamada, aqui que � gerado o n�mero aleat�rio;
            dados.push_back(dado); //insere o dado no vetor dados;
            dadosaux.push_back(dado); //insere o dado no vetor dados auxiliar;

            //if condicionais para controlar as anima��es dos dados;
            if (dados.size() == 1) {
                numbers1 =  60;
            }
            if (dados.size() == 2) {
                numbers2 = 60;
            }
            if (dados.size() == 3) {
                numbers3 = 60;
            }

            if (dado != 6) { //if que verifica se o dado atual � diferente de 6, se sim, ele encerra a rolagem de dados;
                for (int j = 0; j < dados.size(); j++) {//for que soma todos os valores no vetor dados;
                    soma = soma + dados[j];
                }
            }
            else { //caso der 6, ele verifica se o jogador j� tem 3 dados dentro do vetor;
                if (dados.size() == 3) {
                    // aqui o usu�rio perde a vez, caso tire tr�s 6 seguidos;
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
        
        //caso objetivo seja maior que 0 e as anima��es estejam encerradas;
        if (objective > 0 && numbers1 == 90 && numbers2 == 90 && numbers3 == 90) {
            for (int pos = 0; pos < 3; pos++) { //verifica se tem pe�es do player atual na trilha;
                if (players[turnos][pos] < 56) {
                    finded = true;
                }
            }
            // caso ele encontre os pe�es;
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
                    else if (event.keyboard.keycode == ALLEGRO_KEY_3 && objectivedado == 0 && dados.size() == 3) {
                        objectivedado = dadosaux[2];
                        dadosaux.pop_back(); //pop_back apaga o �ltimo valor da lista;
                    }
                    //caso ele escolha um valor, o pe�o vai andar;
                    else if (objectivedado > 0 && time > 15) {
                        time = 0;
                        players[turnos][0] = players[turnos][0] + 1;
                        objectivedado--;
                        objective--;
                    }
                }
                else { //caso n�o haja mais de um dado para escolher, o pe�o anda automaticamente com o dado que sobrou;
                    if (time > 15) {
                        time = 0;
                        players[turnos][0] = players[turnos][0] + 1;
                        objective--;
                    }
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
            else { //caso n�o haja pe�o na trilha;
                if (find(dadosaux.begin(), dadosaux.end(), 6) != dadosaux.end()) {
                    dadosaux.erase(dadosaux.begin());
                    players[turnos][0] = 0;
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

        // MARCA��O DAS PONTES - PONTE ENTRE VERDE E VERMELHO

        al_draw_bitmap(ponto, 693, 330, 2);

        // FIM MARCA��O DAS PONTES - PONTE ENTRE VERDE E VERMELHO

        // MARCA��O DAS PONTES - PONTE ENTRE AMARELO E VERMELHO

        al_draw_bitmap(ponto, 690, 250, 2);

        // FIM MARCA��O DAS PONTES - PONTE ENTRE AMARELO E VERMELHO

        // MARCA��O DAS PONTES - PONTE ENTRE AMARELO E AZUL

        al_draw_bitmap(ponto, 582, 250, 2);

        // FIM MARCA��O DAS PONTES - PONTE ENTRE AMARELO E AZUL

        // MARCA��O DAS PONTES - PONTE ENTRE AZUL E VERDE

        al_draw_bitmap(ponto, 577, 330, 2);

        // FIM MARCA��O DAS PONTES - PONTE ENTRE AZUL E VERDE

        al_flip_display();

    }

    al_destroy_bitmap(dado1);
    al_destroy_bitmap(dado2);
    al_destroy_bitmap(dado3);
    al_destroy_bitmap(dado4);
    al_destroy_bitmap(dado5);
    al_destroy_bitmap(dado6);
    al_destroy_bitmap(sprite);
    al_destroy_sample(song);
    al_destroy_sample_instance(songInstance);
    al_destroy_bitmap(ponto);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}