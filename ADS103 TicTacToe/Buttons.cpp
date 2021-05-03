#include "Buttons.h"

int Buttons::playerVsPlayerButton(SDL_Event& event)
{
	SDL_Rect ButtonTwo;
	ButtonTwo.x = playerVsPX;
	ButtonTwo.y = playerVsPY;
	ButtonTwo.h = 91;
	ButtonTwo.w = 634;

	if (event.button.x >= ButtonTwo.x && event.button.x <= (ButtonTwo.x + ButtonTwo.w) &&
		event.button.y >= ButtonTwo.y && event.button.y <= (ButtonTwo.y + ButtonTwo.h))
	{
		return true;
	}
	return false;
}

bool Buttons::playerVsAiButton(SDL_Event& event)
{
	SDL_Rect ButtonOne;
	ButtonOne.x = playerAiX;
	ButtonOne.y = playerAiY;
	ButtonOne.h = 91;
	ButtonOne.w = 466;

	if (event.button.x >= ButtonOne.x && event.button.x <= (ButtonOne.x + ButtonOne.w) &&
		event.button.y >= ButtonOne.y && event.button.y <= (ButtonOne.y + ButtonOne.h))
	{
		return true;
	}
	
	return false;
}

Buttons::Buttons(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

Buttons::~Buttons()
{
}
