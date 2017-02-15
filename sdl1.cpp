
#include <SDL.h>
SDL_Surface * ekran = NULL;
SDL_Surface * obraz = NULL;

int main( int argc, char * args[] )
{
	unsigned char * A, *B;
	FILE * ME = fopen("bitmapa.bmp", "r");
	FILE * YOU = fopen("bitmapa2.bmp", "w");
	fseek(ME, 0, SEEK_END);
	int Bits = ftell(ME);
	A = new unsigned char[Bits];
	B = new unsigned char[Bits];
	fseek(ME, 0, SEEK_SET);
	fread(A, 1, Bits, ME);
	fclose(ME);
    SDL_Init( SDL_INIT_EVERYTHING );
    ekran = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
    SDL_RWops * In = SDL_RWFromMem(A, Bits);
    SDL_RWops * Out = SDL_RWFromMem(B, Bits);
    //SDL_RWwrite(In, A, 1, Bits);
    obraz = SDL_LoadBMP_RW(In, 0);
    SDL_BlitSurface( obraz, NULL, ekran, NULL );
    SDL_Flip( ekran );
    SDL_SaveBMP_RW(obraz, Out, 1);
    fwrite(B, 1, Bits, YOU);
    fclose(YOU);
    SDL_Delay( 2000 );
    SDL_Quit();
    SDL_FreeSurface( obraz );
}
