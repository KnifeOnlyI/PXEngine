#include <iostream>
#include <boost/format.hpp>

#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        throw std::runtime_error((boost::format("SDL_Error : %1") % SDL_GetError()).str());
    }

    SDL_Window *window {
        SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN)
    };

    if (window == nullptr)
    {
        SDL_Quit();

        throw std::runtime_error((boost::format("SDL_Error : %1") % SDL_GetError()).str());
    }

    SDL_Renderer *renderer {SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)};

    if (renderer == nullptr)
    {
        SDL_DestroyWindow(window);
        SDL_Quit();

        throw std::runtime_error((boost::format("SDL_Error : %1") % SDL_GetError()).str());
    }

    SDL_Event event;

    while (true)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}