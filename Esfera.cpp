#include <allegro.h>

void Inicializar_Variables();
void Inicializar_Funciones();
int Inicializar_Graficos(int ancho, int alto);
void Dibujar_Esfera(int x, int y, int radio);

void Inicializar_Variables()
{
}

void Inicializar_Funciones()
{
     allegro_init();
     install_keyboard();
}

int Inicializar_Graficos(int ancho, int alto)
{
    if(set_gfx_mode(GFX_SAFE, ancho, alto, 0, 0) != 0)
    {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("No se ha conseguido inicializar el modo gráfico.\n\n%s", allegro_error);
        return 1;
    }
    return 0;
}

void Dibujar_Esfera(int x, int y, int radio)
{
     int i;
     
     for(i = radio; i > 0; i = i - 8)
         ellipse(screen, x, y, i, radio, palette_color[15]);
         
     for(i = radio; i > 0; i = i - 8)
         ellipse(screen, x, y, radio, i, palette_color[15]);
}

int main()
{
    Inicializar_Variables();
    Inicializar_Funciones();
    Inicializar_Graficos(500, 500);
    
    Dibujar_Esfera(250, 250, 100);
    
    readkey();
    return 1;
}
END_OF_MAIN();
