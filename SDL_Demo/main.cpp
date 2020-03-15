#include<SDL.h>
#include<iostream>

using namespace std;

int main(int argc, char* argv[]) 
{
	SDL_Window* window = nullptr;
	SDL_Surface* windowSurface = nullptr;
	SDL_Surface* imageSurface = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Video Initialization Error" << SDL_GetError() << endl;
	} 
	else 
	{
		window = SDL_CreateWindow("Arjun's Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << "Window Creation Error" << SDL_GetError() << endl;
		}
		else 
		{
			windowSurface = SDL_GetWindowSurface(window);
			imageSurface = SDL_LoadBMP("myBitmap.bmp");

			if (imageSurface == NULL)
			{
				cout << "Image Loading Error" << SDL_GetError() << endl;
			}
			else
			{
				SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
				SDL_UpdateWindowSurface(window);
				SDL_Delay(4000);
			}
		}
	}

	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	windowSurface = nullptr;
	SDL_Quit();

	return 0;
}