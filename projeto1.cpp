#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>

using namespace std;

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
    

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();

    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);
    al_set_window_position(display, 200, 200);
    al_set_window_title(display, "Luther");

    ALLEGRO_FONT* font = al_load_font("font.ttf", 10, 0);
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 5.0);

    ALLEGRO_BITMAP* sprite = al_load_bitmap("tabuleiro.png");
    ALLEGRO_BITMAP* ponto = al_load_bitmap("ponto.png");
    ALLEGRO_BITMAP* pontoam = al_load_bitmap("pontoam.png");
    ALLEGRO_BITMAP* pontoaz = al_load_bitmap("pontoaz.png");
    ALLEGRO_BITMAP* pontovd = al_load_bitmap("pontovd.png");
    ALLEGRO_BITMAP* pontovm = al_load_bitmap("pontovm.png");

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    float frame = 0.f;
    int pos_x = 0;
    int pos_y = 0;
    int current_frame_y = 161;
    int x = 0;

    while (true) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_text(font, al_map_rgb(0, 0, 0), 5, 5, 0, "1" + 1);
        //al_draw_bitmap(sprite, 0, 0, 0);
        al_draw_bitmap(sprite, 0, 0, 0);
        if (x == 56) {
            x = 0;
        }
        al_draw_bitmap(pontoam, trilha_amarelo[x][0], trilha_amarelo[x][1], 1);
        al_draw_bitmap(pontovm, trilha_vermelho[x][0], trilha_vermelho[x][1], 1);
        al_draw_bitmap(pontovd, trilha_verde[x][0], trilha_verde[x][1], 1);
        al_draw_bitmap(pontoaz, trilha_azul[x][0], trilha_azul[x][1], 1);


        // MARCA플O DAS PONTES - PONTE ENTRE VERDE E VERMELHO
        
        al_draw_bitmap(ponto, 693 , 330, 1);
      
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
        x++;
    }

    al_destroy_bitmap(sprite);
    al_destroy_bitmap(ponto);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}