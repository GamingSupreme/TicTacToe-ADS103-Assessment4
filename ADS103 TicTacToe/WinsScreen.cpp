#include "WinsScreen.h"

WinsScreen::WinsScreen(SDL_Renderer* renderer)
{
	this->renderer = renderer;

	title = IMG_LoadTexture(renderer, "assets/Title.png");

}

WinsScreen::~WinsScreen()
{

	SDL_DestroyTexture(title);

}

void WinsScreen::update()
{
}

void WinsScreen::draw()
{
}

void WinsScreen::clearScreen()
{
}
