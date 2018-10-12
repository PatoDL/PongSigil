#include "jugador.h"

#include "juego.h"
#include "bola.h"
#include "screenjuego.h"

namespace Juego
{
	namespace Gameplay
	{
		namespace Jugador
		{
			struct Color
			{
				float first;
				float second;
				float third;
				float fourth;
			};

			Paleta jugador1;
			Paleta jugador2;

			int topeArribaJugador;
			int topeAbajoJugador;

			void moverJugadores()
			{
				float movJug = 500.0f*slGetDeltaTime();
				
				if (slGetKey(SL_KEY_UP))
				{
					jugador2.sprite.y -= movJug;
				}
				if (slGetKey(SL_KEY_DOWN))
				{
					jugador2.sprite.y += movJug;
				}
				if (cantJugs == 2)
				{
					if (slGetKey('w'))
					{
						jugador1.sprite.y -= movJug;
					}
					if (slGetKey('s'))
					{
						jugador1.sprite.y += movJug;
					}


					if (jugador1.sprite.y <= topeArribaJugador)
					{
						jugador1.sprite.y = topeArribaJugador;
					}
					if (jugador1.sprite.y >= topeAbajoJugador)
					{
						jugador1.sprite.y = topeAbajoJugador;
					}
				}
				if (jugador2.sprite.y <= topeArribaJugador)
				{
					jugador2.sprite.y = topeArribaJugador;
				}
				if (jugador2.sprite.y >= topeAbajoJugador)
				{
					jugador2.sprite.y = topeAbajoJugador;
				}
			}

			void limitarPaletas()
			{
				topeArribaJugador = Bola::topeArriba + Bola::bola.radio / 2;
				topeAbajoJugador = (screenHeight - screenHeight / 6) - Bola::bola.radio / 2;
			}

			void reiniciarPaletas()
			{
				jugador1.sprite.x = (float)screenWidth / 30;
				jugador1.sprite.y = (float)screenHeight / 2 - jugador1.sprite.height / 2;
				jugador2.sprite.x = (float)screenWidth - screenWidth / 18;
				jugador2.sprite.y = (float)screenHeight / 2 - jugador2.sprite.height / 2;
			}

			void dibujarJugadores()
			{
				if (cantJugs == 2)
				{
					slSetForeColor(1.0f, 0.0f, 0.0f, 1.0f);
				}
				else
				{
					slSetForeColor(0.0f,0.0f,1.0f,1.0f);
				}
				slRectangleFill( jugador1.sprite.x,jugador1.sprite.y ,  jugador1.sprite.width,jugador1.sprite.height);
				slSetForeColor(1.0f, 0.0f, 0.0f, 1.0f);
				slRectangleFill( jugador2.sprite.x,jugador2.sprite.y ,  jugador1.sprite.width,jugador1.sprite.height);
			}

			void moverIA()
			{
				int sector = GetRandomValue(-50, 50); //esta variable define en que parte de la paleta va a impactar la pelota

				if (jugador1.sprite.y != Bola::bola.pos.y - jugador1.sprite.height / 2)
				{
					if (Bola::bola.pos.y < jugador1.sprite.y + sector)
					{
						jugador1.sprite.y -= 1.2;
					}
					else if (Bola::bola.pos.y > jugador1.sprite.y + jugador1.sprite.height / 2)
					{
						jugador1.sprite.y += 1.2;
					}
				}

				if (jugador1.sprite.y <= topeArribaJugador)
				{
					jugador1.sprite.y = topeArribaJugador;
				}
				if (jugador1.sprite.y >= topeAbajoJugador)
				{
					jugador1.sprite.y = topeAbajoJugador;
				}
			}
		}
	}
}