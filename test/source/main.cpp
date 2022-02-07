#include <iostream>

#include <px/exception/SDLException.hpp>
#include <SDL2/SDL.h>

#include "../header/TestWindow.hpp"

#define WINDOW_TITLE "SDL2"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        throw px::SDLException();
    }

    try
    {
        test::TestWindow window {WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT};

        window.onInit();

        SDL_Event event;

        while (window.isOpen())
        {
            if (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    window.close();
                }
                else if (event.type == SDL_KEYDOWN)
                {
                    if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
                    {
                        window.setTitle("Updated title");
                    }
                    else if (event.key.keysym.scancode == SDL_SCANCODE_UP)
                    {
                        window.setHeight(window.getHeight() - 10);
                    }
                    else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                    {
                        window.setHeight(window.getHeight() + 10);
                    }
                    else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                    {
                        window.setWidth(window.getWidth() - 10);
                    }
                    else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                    {
                        window.setWidth(window.getWidth() + 10);
                    }
                    else if (event.key.keysym.scancode == SDL_SCANCODE_0)
                    {
                        window.isVisible() ? window.hide() : window.show();
                    }
                    else if (event.key.keysym.scancode == SDL_SCANCODE_1)
                    {
                        window.isMaximized() ? window.minimize() : window.maximize();
                    }
                    else if (event.key.keysym.scancode == SDL_SCANCODE_2)
                    {
                        window.setDisplayMode(px::WindowDisplayMode::WINDOWED);
                    }
                    else if (event.key.keysym.scancode == SDL_SCANCODE_3)
                    {
                        window.setDisplayMode(px::WindowDisplayMode::BORDERLESS);
                    }
                    else if (event.key.keysym.scancode == SDL_SCANCODE_4)
                    {
                        window.setDisplayMode(px::WindowDisplayMode::FULLSCREEN);
                    }
                }
            }

            window.clear();
            window.refresh();
        }

        window.onClose();
    }
    catch (const px::SDLException &e)
    {
        std::cerr << "[ERROR]" << e.what() << '\n';
    }

    SDL_Quit();
}