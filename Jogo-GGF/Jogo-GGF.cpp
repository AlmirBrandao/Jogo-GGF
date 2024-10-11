#include <raylib.h> // Inclui a biblioteca do Raylib.

//Genrenciamento de telas do jogo
typedef enum TelaDoJogo {
	MENU = 0,
	GAMEPLAY,
	CREDITOS
} TelaDoJogo;

int main(void)
{
	//Variáveis das dimensões da tela.
	const int largura = 800;
	const int altura = 450;

	//Variáveis para controlar a interatividade
	int mouseX, mouseY;
	bool BotaoIniciar = false;
	bool BotaoCredito = false;
	bool BotaoMenu = false;
	bool BotaoSair = false;

	//Definir a tela inicial como Menu
	TelaDoJogo TelaAtual = MENU;

	//Inicializa e cria uma janela com título.
	InitWindow(largura, altura, "Menu Inicial");

	//Define a taxa de quadros em FPS
	SetTargetFPS(60);

	//Verifica se a janela pode ser fechada.
	while (!WindowShouldClose())
	{

		//Obtém a posição do mouse.
		mouseX = GetMouseX();
		mouseY = GetMouseY();

		//Lógica do Menu
		if (TelaAtual == MENU)
		{

			//Verifica se o mouse está sobre o texto "Iniciar Jogo".
			if (mouseX >= 340 && mouseX <= 460 && mouseY >= 180 && mouseY <= 200)
			{
				BotaoIniciar = true;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					//Vai para tela de jogo
					TelaAtual = GAMEPLAY;

				}
			}
			else
			{
				BotaoIniciar = false;
			}

			//Verifica se o mouse está sobre o texto "Crédito".
			if (mouseX >= 355 && mouseX <= 460 && mouseY >= 200 && mouseY <= 220)
			{
				BotaoCredito = true;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					// Vai para tela de Créditos
					TelaAtual = CREDITOS;

				}
			}
			else
			{
				BotaoCredito = false;
			}

			//Verifica se o mouse está sobre o texto "Sair".
			if (mouseX >= 375 && mouseX <= 460 && mouseY >= 220 && mouseY <= 240)
			{
				BotaoSair = true;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					//Fecha o Jogo
					CloseWindow();

					return 0;
				}
			}
			else
			{
				BotaoSair = false;
			}

		}
		else
		{
			//Lógica da Tela Crédito
			if (TelaAtual == CREDITOS)

				//Verifica se o mouse está sobre o texto "Menu inicial".
				if (mouseX >= 340 && mouseX <= 460 && mouseY >= 300 && mouseY <= 340)
				{
					BotaoMenu = true;
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						//Vai para tela de Menu
						TelaAtual = MENU;
					}
				}
				else
				{
					BotaoMenu = false;
				}
		}

		//Marca inicio de um bloco de desenho.
		BeginDrawing();

		//Limpa a tela com uma cor especificada.
		ClearBackground(BLACK);

		if (TelaAtual == MENU)
		{
			//Desenha o menu
			DrawText("Menu", 373, 160, 20, RAYWHITE);

			//Desenha o retângulo ao redor do texto "Iniciar Jogo" se o mouse estiver sobre ele.
			if (BotaoIniciar)
			{
				DrawRectangle(338, 178, 125, 25, DARKGREEN);
			}
			DrawText("Iniciar Jogo", 340, 180, 20, RAYWHITE);

			//Desenha o retângulo ao redor do texto "Crédito" se o mouse estiver sobre ele.
			if (BotaoCredito)
			{
				DrawRectangle(352, 198, 94, 25, DARKGREEN);
			}

			DrawText("Créditos", 355, 200, 20, RAYWHITE);

			//Desenha o retângulo ao redor do texto "sair" se o mouse estiver sobre ele.
			if (BotaoSair)
			{
				DrawRectangle(373, 218, 47, 25, DARKGREEN);
			}
			DrawText("Sair", 375, 220, 20, RAYWHITE);
		}
		else if (TelaAtual == GAMEPLAY)
		{
			//Desenha a tela do jogo
			ClearBackground(DARKGREEN);
			DrawText("Imagina que você esta jogando nessa tela.", 180, 50, 20, BLACK);
		}
		else if (TelaAtual == CREDITOS)
		{
			//Desenha a tela de Créditos
			ClearBackground(WHITE);
			DrawText("Créditos", 350, 100, 20, BLACK);
			DrawText("Desenvolvedores:", 300, 140, 20, BLACK);
			DrawText("Almir - Programação e Arte", 250, 160, 20, BLACK);
			DrawText("Hilberg - Arte", 320, 180, 20, BLACK);
			DrawText("Lucas - Programação", 280, 200, 20, BLACK);

			//Desenha o retângulo ao redor do texto "Menu Inicial" se o mouse estiver sobre ele.
			if (BotaoMenu)
			{
				DrawRectangle(336, 300, 124, 25, GRAY);
			}
			DrawText("Menu Inicial", 340, 300, 20, BLACK);
		}

		//Marca o fim de um bloco de desenho.
		EndDrawing();
	}

	//Fecha a janela
	CloseWindow();

	return 0;

}

