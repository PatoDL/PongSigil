#include "menu.h"

#include "sl.h"
#include "juego.h"
#include "screenjuego/screenjuego.h"

namespace Juego
{
	namespace Menu
	{
		/*Music menuSong;

		void inicializarMusicaMenu()
		{
			menuSong = LoadMusicStream("res/audio/menu.ogg");
		}

		void cerrarMusicaMenu() 
		{
			UnloadMusicStream(menuSong);
		}

		void reproducirMusicaMenu()
		{
			PlayMusicStream(menuSong);
		}

		void pausarMusicaMenu()
		{
			PauseMusicStream(menuSong);
		}

		void recargarMusicaMenu()
		{
			UpdateMusicStream(menuSong);
		}

		void reanudarMusicaMenu()
		{
			ResumeMusicStream(menuSong);
		}
*/
		void chequearInputMenu()
		{
			if (slGetKey('2'))
			{
				estado = jugando;
				Gameplay::cantJugs = 2;
			}

			if (slGetKey('1'))
			{
				estado = jugando;
				Gameplay::cantJugs = 1;
			}

			if (slGetKey(' '))
			{
				estado = creditos;
			}
		}

		void mostrarPantallaInicio()
		{
			/*DrawText("Bienvenido al pong", screenWidth / 5, screenHeight / 3, screenHeight*screenWidth/9000, WHITE);
			DrawText("presione 1 para jugar contra la pc", screenWidth / 12, screenHeight / 2, screenHeight*screenWidth / 13500, WHITE);
			DrawText("presione 2 para dos jugadores", screenWidth / 12, screenHeight / 3 * 2, screenHeight*screenWidth / 13500, WHITE);
			DrawText("presione espacio para ver los creditos", screenWidth / 12, screenHeight / 5*4, screenHeight*screenWidth / 13500, WHITE);	
			DrawText("Pong v1.0", screenWidth / 15 * 13, 5, screenHeight*screenWidth / 27000, WHITE);*/
		}
	}
}
