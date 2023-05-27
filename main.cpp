#include <SDL.h>
#include <iostream>
#include <windows.h>
#include "grafika_.h"
#include "texture_.h"
#include "parser.h"
#include "config.h"

using namespace std;
//#define MEMDEBUG

/*! \mainpage GMML gráf leírónyelv és fordító alkalmazás
 *
 * \section Bemutató
 *
 * Gráfok egyszerű és gyors megjelenítése grafikus felületen. A gráfok létrehozására a GMML leírónyelv szolgál.
 * Példa:
 * \image html "gmml_pelda.png"
 *
 * Majd ezt a fájlt SDL2-vel jeleníti meg grafikusan.
 * Példa:
 * \image html "render_pelda.png"
 */

/**
 *
 * Ez a programrész felel a többi objektum összehangolt működéséért.
 * Először dedikál egy konzolt a logolásra. Majd létrehozza a konfig objektumot, ami betölti
 * a program konfigurációit. Ezután létrehozza a parser objektumot, ami le fogja fordítani a '.gmml' fájlt.
 * A grafika objektum elkészítése után megvizsgálja, hogy az SDL inicializálható-e, ha igen akkor ezt meg is teszi a
 * grafika objektum segítségével. Ezután példányosítja a heterogén kollekciót, amit a parser segítségével fel is tölt.
 * Vár a felhasználóra, hogy bezárja a grafikus ablakot, majd a konzolt is bezárja egy gomb lenyomása után.
 * Ezek után az ebben a függvényben dinamikusan foglalt memóriaterületeket felszabadítja és leállítja a programot
 *
 * @param argc
 * @param argv
 * @return 0
 */
int main(int argc, char *argv[])
{
    #ifdef MEMDEBUG
        int *t = new int(5);
    #endif
    AllocConsole();
    freopen("CONOUT$", "wt", stdout);
    freopen("CONOUT$", "w", stderr);
    freopen("CONIN$", "rt", stdin);
    Config *config = new Config("config.txt");
    Parser *parser = new Parser();
    parser->Load();
    int winX = 750;
    int winY = 750;
    string *title = new string("Gombócz Márton - FSES6T");
    SDL_Color backgroundColor = {255,255,255,100};

    // returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "error initializing SDL: %s\n" << SDL_GetError() << endl;
    }
    Grafika *grafika = new Grafika(title->c_str(),winX,winY, backgroundColor);
    TextureList *textures = new TextureList(grafika->renderer);

    grafika->setBackgroundColor(config->getBackgC());

    parser->Parse(textures,config);

    textures->render();
    Grafika::await();

    system("pause");
    FreeConsole();
    delete config;
    delete textures;
    delete parser;
    delete grafika;
    delete title;
    return 0;
}
