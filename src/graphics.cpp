#include "graphics.hpp"
#include "globals.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Graphics::Graphics(const char *windowTitle)
{
	_window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0);
	SDL_SetWindowTitle(_window, windowTitle);
	_renderer = SDL_CreateRenderer(_window, -1, 0);
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
}

SDL_Surface *Graphics::loadImage(const std::string &path)
{
	if (!_spriteSheets.count(path))
	{
		_spriteSheets[path] = IMG_Load(path.c_str());
	}
	return _spriteSheets[path];
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *source, SDL_Rect *destination)
{
	SDL_RenderCopy(_renderer, texture, source, destination);
}

void Graphics::flip()
{
	SDL_RenderPresent(_renderer);
}

void Graphics::fillBackground()
{
	SDL_RenderClear(_renderer);
}

SDL_Renderer *Graphics::getRenderer() const
{
	return _renderer;
}

void Graphics::setRenderColor(Color color)
{
	SDL_SetRenderDrawColor(
		_renderer,
		color.getRed(),
		color.getGreen(),
		color.getBlue(),
		color.getAlpha()
	);
}