#include "screenjuego.h"

#include "sl.h"
#include "juego.h"
#include "bola.h"
#include "jugador.h"
#include "gameover/gameover.h"
#include "puntaje.h"

namespace Juego
{
	namespace Gameplay
	{
		using namespace Bola;
		using namespace Jugador;

		int cantJugs;

		static void dibujarTablero();

		void chequearInputJugando()
		{
			moverJugadores();
			if (slGetKey(SL_KEY_ESCAPE))
			{
				estado = menu;
			}
		}

		void dibujarTablero()
		{
			slSetForeColor(1.0f, 1.0f, 1.0f, 1.0f);
			slRectangleFill(0, 80, screenWidth, 15);
			for (int i = 0; i < screenHeight; i += 130)
			{
				slRectangleFill(screenWidth / 2 - 5, i, 10, 90);
			}
		}

		void dibujarJuego()
		{
			dibujarTablero();

			Puntaje::dibujarPuntaje();

			dibujarBola();

			dibujarJugadores();
		}

		void iniciarGameplay()
		{	
			jugador1.puntaje = 0;
			jugador2.puntaje = 0;
			jugador1.sprite.width = screenWidth / 45;
			jugador1.sprite.height = screenHeight / 6;
			jugador2.sprite.width = screenWidth / 45;
			jugador2.sprite.height = screenHeight / 6;
			bola.radio = screenHeight * screenWidth / 54000;
			reiniciarBola();
			reiniciarPaletas();
			limitarPaletas();
		}

		void actualizarJuego()
		{
			if (estadoAnterior == gameover || estadoAnterior == menu)
			{
				iniciarGameplay();
			}

			if (cantJugs == 1)
			{
				moverIA();
			}

			chequeardirBola();

			chequearLimitesBola();

			colisionConJugadores();

			int p1Buffer = jugador1.puntaje;
			int p2Buffer = jugador2.puntaje;

			Puntaje::actualizarPuntaje();
			if (jugador1.puntaje != p1Buffer || jugador2.puntaje != p2Buffer)
			{
				reiniciarBola();
			}

			Gameover::chequearGameover();
		}
	}
}