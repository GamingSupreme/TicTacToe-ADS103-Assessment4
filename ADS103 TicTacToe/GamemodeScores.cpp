#include "GamemodeScores.h"

GamemodeScores::GamemodeScores()
{
	//load font with font size 16
	font = TTF_OpenFont("assets/arialbd.ttf", 40);
}

GamemodeScores::~GamemodeScores()
{
	if (textTexture != NULL)
		SDL_DestroyTexture(textTexture);

	TTF_CloseFont(font);
}

void GamemodeScores::setup(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void GamemodeScores::setText(string text)
{
	//only bother changing text if its different from before and not an empty string
	if (this->text != text && text != "")
	{
		//destroy old text texture before creating new one
		if (textTexture != NULL)
			SDL_DestroyTexture(textTexture);

		this->text = text;

		//build text texture using font and text string
		SDL_Color textColour = { 0,0,0,0 };
		//create surface out of our text
		SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), textColour);
		//convert surface to texture
		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		//delete surface properly
		SDL_FreeSurface(textSurface);

		//workout width and height of generated texture
		SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
		//workout how to centre them to screen
		textRect.x = 320 / 2 - textRect.w * 2;
		textRect.y = 240 / 2 - textRect.h * 2;

		//workout our box rectangle with some padding
		boxRect.x = textRect.x - 4;
		boxRect.y = textRect.y - 4;
		boxRect.w = textRect.w + 8;
		boxRect.h = textRect.h + 8;

	}
}

void GamemodeScores::draw()
{
	if (visible && textTexture != NULL && text != "")
	{
		//draw the box
		SDL_SetRenderDrawColor(renderer, 170, 170, 170, 255);
		SDL_RenderFillRect(renderer, &boxRect);

		//draw border
		SDL_SetRenderDrawColor(renderer, 170, 170, 170, 255);
		SDL_RenderDrawRect(renderer, &boxRect);

		//draw text to screen
		SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
	}
}
