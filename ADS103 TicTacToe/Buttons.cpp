#include "Buttons.h"

int Buttons::playerVsPlayerButton()
{
	return 0;
}

bool Buttons::playerVsAiButton(SDL_Event& event)
{
	SDL_Rect ButtonOne;
	ButtonOne.x = playerAiX;
	ButtonOne.y = playerAiY;
	ButtonOne.h = 91;
	ButtonOne.w = 466;

	event.button.button = SDL_BUTTON_LEFT;
	event.type == SDL_MOUSEBUTTONDOWN;

	if (event.button.x >= ButtonOne.x || event.button.x <= (ButtonOne.x + ButtonOne.w) &&
		event.button.y >= ButtonOne.y || event.button.y <= (ButtonOne.y + ButtonOne.h))
	{
		return true;
	}
}

Buttons::Buttons(SDL_Renderer* renderer)
{
}

Buttons::~Buttons()
{
}
