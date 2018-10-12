#include "juego.h"

#include <ctime>
#include <iostream>
#include "sl.h"
#include "screenjuego/screenjuego.h"
#include "menu/menu.h"
#include "gameover/gameover.h"
#include "creditos/creditos.h"
#include "screenjuego/bola.h"

namespace Juego
{

	Estado estado = menu;
	Estado estadoAnterior = menu;

	const int screenWidth = 900;
	const int screenHeight = 600;

	static void cambiarEstado();
	static void dibujarTodo();
	static void actualizar();
	static void chequearInput();
	static void actualizarMusica();
	static void inicializar();
	static void finalizar();

	void finalizar()
	{
		slClose();
#ifdef AUDIO
		Menu::cerrarMusicaMenu();
		Gameplay::Bola::cerrarSonidos();
		//CloseAudioDevice();
#endif
	}

	void actualizarMusica()
	{
		switch (estado)
		{
		case creditos:
			Creditos::actualizarCreditos();
			break;
		case gameover:
			Gameover::actualizarMusicaGameOver();
			break;
		case jugando:
			Menu::pausarMusicaMenu();
			break;
		case menu:
			if (estadoAnterior == menu)
			{
				Menu::reproducirMusicaMenu();
			}
			Menu::recargarMusicaMenu();
			break;
		}
	}

	void actualizar()
	{
		switch (estado)
		{
		case jugando:
			Gameplay::actualizarJuego();
			break;
		}
#ifdef AUDIO
		actualizarMusica();
#endif
	}

	void dibujarTodo()
	{
		//BeginDrawing();
		slSetBackColor(0.0f, 0.0f, 0.0f);
		switch (estado)
		{
		case menu:
			Menu::mostrarPantallaInicio();
			break;
		case jugando:
			Gameplay::dibujarJuego();
			break;
		case gameover:
			Gameover::mostrarGameOver();
			break;
		case creditos:
			Creditos::mostrarCreditos();
			break;
		}

		slRender();
	}

	void chequearInput() 
	{
		switch (estado)
		{
		case menu:
			Menu::chequearInputMenu();
			break;
		case jugando:
			Gameplay::chequearInputJugando();
			break;
		case gameover:
			Gameover::chequearInputGameover();
			break;
		case creditos:
			Creditos::chequearInputCreditos();
			break;
		}
	}

	void cambiarEstado() 
	{
		if (estado != estadoAnterior)
		{
			estadoAnterior = estado;

			switch (estado)
			{
			case jugando:
				Gameplay::iniciarGameplay();
				break;
			}
		}
	}

	void inicializar()
	{
		srand(time(0));

		//SetTargetFPS(60);

#ifdef AUDIO
		//InitAudioDevice();

		Menu::inicializarMusicaMenu();

		Gameplay::Bola::inicializarSonidos();
#endif
		slWindow(screenWidth, screenHeight, "pong", 0);

	}

	void ejecutarJuego()
	{
		inicializar();

		while (!slShouldClose())
		{
			cambiarEstado();

			chequearInput();

			actualizar();

			dibujarTodo();
		}

		finalizar();
	}
}