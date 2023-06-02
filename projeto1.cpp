#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

int turno() {
    unsigned seed = time(0);

    srand(seed);
    /*vector<int> dados;
    int dado;
    dado = 1 + rand() % 6;
    dados.push_back(dado);
    if (dado == 6) {
        dado = 1 + rand() % 6;
        dados.push_back(dado);
        if (dado == 6) {
            dado = 1 + rand() % 6;
            dados.push_back(dado);
            if (dado == 6) {
                dados = {};
            }
        }
    }
    return dados;*/
    int dado;
    dado = 1 + rand() % 6;
    return dado;
}


int main() {
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
        {635, 225}
    };
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
        {730, 289}
    };
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
        {635, 365}
    };
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
        {542, 289}
    };
    vector<int> dados;
    int dado;


    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, "Luther");

    ALLEGRO_FONT* font = al_load_font("font.ttf", 10, 0);
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

    ALLEGRO_BITMAP* sprite = al_load_bitmap("tabuleiro.png");
    ALLEGRO_BITMAP* ponto = al_load_bitmap("ponto.png");
    ALLEGRO_BITMAP* pontoam = al_load_bitmap("pontoam.png");
    ALLEGRO_BITMAP* pontoaz = al_load_bitmap("pontoaz.png");
    ALLEGRO_BITMAP* pontovd = al_load_bitmap("pontovd.png");
    ALLEGRO_BITMAP* pontovm = al_load_bitmap("pontovm.png");
    ALLEGRO_BITMAP* dado1 = al_load_bitmap("dado1.png");
    ALLEGRO_BITMAP* dado2 = al_load_bitmap("dado2.png");
    ALLEGRO_BITMAP* dado3 = al_load_bitmap("dado3.png");
    ALLEGRO_BITMAP* dado4 = al_load_bitmap("dado4.png");
    ALLEGRO_BITMAP* dado5 = al_load_bitmap("dado5.png");
    ALLEGRO_BITMAP* dado6 = al_load_bitmap("dado6.png");

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);

    float frame = 0.f;
    int pos_x = 0;
    int pos_y = 0;
    int current_frame_y = 161;
    int soma = 0;
    int time = 0;
    int objective = 0;
    int numbers1 = 90;
    int numbers2 = 90;
    int numbers3 = 90;
    bool next = true;
    bool retafinal = false;
    int objectivedado = 0;
    vector <int> dadosaux;
    vector<vector<int>> players = {
        {0},
        {0},
        {0},
        {0}
    };
    int turnos = 0;

    while (true) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        //al_clear_to_color(al_map_rgb(255, 255, 255));
        //al_draw_text(font, al_map_rgb(0, 0, 0), 5, 5, 0, "1" + 1);
        al_draw_bitmap(sprite, 0, 0, 0);
        if (numbers1 < 90) {
            numbers1++;
        }
        if (numbers2 < 90) {
            numbers2++;
        }
        if (numbers3 < 90) {
            numbers3++;
        }
        if (dadosaux.size() > 1) {
            al_draw_text(font, al_map_rgb(255, 255, 255), 100, 80, 0, "Selecione o Dado:");
            for (int k = 0; k < dadosaux.size(); k++) {
                if (dadosaux[k] == 1) {
                    al_draw_scaled_bitmap(dado1, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 1);
                }
                else if (dadosaux[k] == 2) {
                    al_draw_scaled_bitmap(dado2, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 1);
                }
                else if (dadosaux[k] == 3) {
                    al_draw_scaled_bitmap(dado3, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 1);
                }
                else if (dadosaux[k] == 4) {
                    al_draw_scaled_bitmap(dado4, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 1);
                }
                else if (dadosaux[k] == 5) {
                    al_draw_scaled_bitmap(dado5, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 1);
                }
                else if (dadosaux[k] == 6) {
                    al_draw_scaled_bitmap(dado6, 90 * 200, 0, 200, 200, k * 40, 120, 40, 40, 1);
                }
            }
        }
        if (dados.size() > 0) {
            if (dados[0] == 1) {
                al_draw_scaled_bitmap(dado1, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 1);
            }
            if (dados[0] == 2) {
                al_draw_scaled_bitmap(dado2, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 1);
            }
            if (dados[0] == 3) {
                al_draw_scaled_bitmap(dado3, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 1);
            }
            if (dados[0] == 4) {
                al_draw_scaled_bitmap(dado4, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 1);
            }
            if (dados[0] == 5) {
                al_draw_scaled_bitmap(dado5, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 1);
            }
            if (dados[0] == 6) {
                al_draw_scaled_bitmap(dado6, numbers1 * 200, 0, 200, 200, 0, 0, 80, 80, 1);
            }

        }
        if (dados.size() > 1) {
            if (dados[1] == 1) {
                al_draw_scaled_bitmap(dado1, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 1);
            }
            if (dados[1] == 2) {
                al_draw_scaled_bitmap(dado2, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 1);
            }
            if (dados[1] == 3) {
                al_draw_scaled_bitmap(dado3, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 1);
            }
            if (dados[1] == 4) {
                al_draw_scaled_bitmap(dado4, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 1);
            }
            if (dados[1] == 5) {
                al_draw_scaled_bitmap(dado5, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 1);
            }
            if (dados[1] == 6) {
                al_draw_scaled_bitmap(dado6, numbers2 * 200, 0, 200, 200, 80, 0, 80, 80, 1);
            }
        }
        if (dados.size() > 2) {
            if (dados[2] == 1) {
                al_draw_scaled_bitmap(dado1, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 1);
            }
            if (dados[2] == 2) {
                al_draw_scaled_bitmap(dado2, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 1);
            }
            if (dados[2] == 3) {
                al_draw_scaled_bitmap(dado3, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 1);
            }
            if (dados[2] == 4) {
                al_draw_scaled_bitmap(dado4, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 1);
            }
            if (dados[2] == 5) {
                al_draw_scaled_bitmap(dado5, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 1);
            }
            if (dados[2] == 6) {
                al_draw_scaled_bitmap(dado6, numbers3 * 200, 0, 200, 200, 160, 0, 80, 80, 1);
            }
        }



        if (players[turnos][0] == 56) {
            players[turnos][0] = 0;
        }

        al_draw_bitmap(pontoam, trilha_amarelo[players[0][0]][0], trilha_amarelo[players[0][0]][1], 1);
        al_draw_bitmap(pontovm, trilha_vermelho[players[1][0]][0], trilha_vermelho[players[1][0]][1], 1);
        al_draw_bitmap(pontovd, trilha_verde[players[2][0]][0], trilha_verde[players[2][0]][1], 1);
        al_draw_bitmap(pontoaz, trilha_azul[players[3][0]][0], trilha_azul[players[3][0]][1], 1);



        if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && time > 15 && objective == 0) {
            time = 0;
            if (next == true) {
                next = false;
                numbers1 = 90;
                numbers2 = 90;
                numbers3 = 90;
                dados = {};
                dadosaux = {};
            }
            dado = turno();
            dados = { 6,6,5 };
            dadosaux = { 6,6,5 };
            //dados.push_back(dado);
            //dadosaux.push_back(dado);
            if (dados.size() == 1) {
                numbers1 = 60;
            }
            if (dados.size() == 2) {
                numbers2 = 60;
            }
            if (dados.size() == 3) {
                numbers3 = 60;
            }
            if (dado != 6) {
                for (int j = 0; j < dados.size(); j++) {
                    soma = soma + dados[j];
                }
            }
            else {
                if (dados.size() == 3) {
                    if (turnos == 3) {
                        turnos = 0;
                    }
                    else {
                        turnos++;
                    }
                    dados = {};
                    dadosaux = {};
                }
            }
            objective = soma;
            /*if (players[turnos][0] + objective >= 56) {
                objective = 0;
                retafinal = true;
            }*/
            soma = 0;
        }
        if (objective > 0 && numbers1 == 90 && numbers2 == 90 && numbers3 == 90) {
            if (dadosaux.size() > 1) {
                if (event.keyboard.keycode == ALLEGRO_KEY_1 && objectivedado == 0) {
                    objectivedado = dadosaux[0];
                    dadosaux.erase(dadosaux.begin());
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_2 && objectivedado == 0) {
                    objectivedado = dadosaux[1];
                    dadosaux.erase(dadosaux.begin()+1);
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_3 && objectivedado == 0 && dados.size() == 3) {
                    objectivedado = dadosaux[2];
                    dadosaux.pop_back();
                }
                if (objectivedado > 0 && time > 15) {
                    time = 0;
                    players[turnos][0] = players[turnos][0] + 1;
                    objectivedado--;
                    objective--;
                }
                
            }
            else {
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
        time++;



        // MARCA플O DAS PONTES - PONTE ENTRE VERDE E VERMELHO

        al_draw_bitmap(ponto, 693, 330, 1);

        // FIM MARCA플O DAS PONTES - PONTE ENTRE VERDE E VERMELHO

        // MARCA플O DAS PONTES - PONTE ENTRE AMARELO E VERMELHO

        al_draw_bitmap(ponto, 690, 250, 1);

        // FIM MARCA플O DAS PONTES - PONTE ENTRE AMARELO E VERMELHO

        // MARCA플O DAS PONTES - PONTE ENTRE AMARELO E AZUL

        al_draw_bitmap(ponto, 582, 250, 1);

        // FIM MARCA플O DAS PONTES - PONTE ENTRE AMARELO E AZUL

        // MARCA플O DAS PONTES - PONTE ENTRE AZUL E VERDE

        al_draw_bitmap(ponto, 577, 330, 1);

        // FIM MARCA플O DAS PONTES - PONTE ENTRE AZUL E VERDE

        al_flip_display();

    }

    al_destroy_bitmap(sprite);
    al_destroy_bitmap(ponto);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}