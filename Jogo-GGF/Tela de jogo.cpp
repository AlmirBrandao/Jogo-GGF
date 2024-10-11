#include <raylib.h> // Inclui a biblioteca do Raylib.

//Genrenciamento de telas do jogo
typedef enum TelaDoJogo {
	MENU = 0,
	GAMEPLAY,
	CREDITOS
} TelaDoJogo;

int main(void)
{
	//Variáveis para as dimensões da janela do jogo.
	const int largura = 800;
	const int altura = 450;

	//Variáveis para controle de interatividade com o mouse.
	int mouseX, mouseY; // Coordenadas X e Y do mouse.
	bool BotaoIniciar = false; // Estado visual do botão "Iniciar Jogo".
	bool BotaoCredito = false; // Estado visual do botão "Créditos".
	bool BotaoMenu = false; // Estado visual do botão "Menu Inicial" na Tela de Créditos.
	bool BotaoSair = false; // Estado Visual do botão "Sair".

	//Definir a tela inicial como Menu
	TelaDoJogo TelaAtual = MENU;

	//Inicializa uma janela com as dimensões especificadas e título " Menu Inicial".
	InitWindow(largura, altura, "Menu Inicial");

	//Define a taxa de quadros para 60 FPS.
	SetTargetFPS(60);

	//Loop principal do jogo.
	while (!WindowShouldClose())
	{

		//Obtém a posição do mouse.
		mouseX = GetMouseX();
		mouseY = GetMouseY();

		// Lógica de interação com o menu principal.
		if (TelaAtual == MENU)
		{

			//Verifica se o mouse está sobre o texto "Iniciar Jogo".
			if (mouseX >= 340 && mouseX <= 460 && mouseY >= 180 && mouseY <= 200)
			{
				BotaoIniciar = true; // Ativ a aparência de destaque do botão.
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) // Verifica se o botão esquerdo do maouse foi pressionado.
				{
					//Muda para tela de jogo
					TelaAtual = GAMEPLAY;

				}
			}
			else
			{
				BotaoIniciar = false; // Desativa o detaque do botão caso o mouse não esteja sobre ele.
			}

			//Verifica se o mouse está sobre o texto "Crédito".
			if (mouseX >= 355 && mouseX <= 460 && mouseY >= 200 && mouseY <= 220)
			{
				BotaoCredito = true;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					// Muda para tela de Créditos
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
					//Fecha a janela do Jogo
					CloseWindow();

					return 0; // Encerra o programa
				}
			}
			else
			{
				BotaoSair = false;
			}

		}
		else
		{
			//Lógica da Tela de Crédito
			if (TelaAtual == CREDITOS)

				//Verifica se o mouse está sobre o texto "Menu inicial" da tela de créditos.
				if (mouseX >= 340 && mouseX <= 460 && mouseY >= 300 && mouseY <= 340)
				{
					BotaoMenu = true;
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
					{
						//Retorna para tela de Menu.
						TelaAtual = MENU;
					}
				}
				else
				{
					BotaoMenu = false;
				}
		}

		//Inicio o bloco de desenho na tela.
		BeginDrawing();

		//Limpa a tela com uma cor especificada (Preta).
		ClearBackground(BLACK);

		//Desenha o conteúdo do menu
		if (TelaAtual == MENU)
		{
			// Título do Menu.
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
			//Desenha a tela do jogo (limpando o fundo da tela do jog com a cor verde escura).
			ClearBackground(DARKGREEN);
			DrawText("Imagina que você esta jogando nessa tela.", 180, 50, 20, BLACK);
		}
		else if (TelaAtual == CREDITOS)
		{
			//Desenha a tela de Créditos (limpando o fundo da tela de crédito com cor branca).
			ClearBackground(WHITE);
			DrawText("Créditos", 350, 100, 20, BLACK); // Título da tela de Créditos.
			DrawText("Desenvolvedores:", 300, 140, 20, BLACK); // Testo de créditos com os nomes dos desenvolvedores.
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

		//Finaliza o bloco de desenho.
		EndDrawing();
	}

	// Encerra e fecha a janela após o saída do loop principal. 
	CloseWindow();

	return 0;

}