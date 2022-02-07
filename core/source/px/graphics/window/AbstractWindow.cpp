#include <stdexcept>
#include "px/graphics/window/AbstractWindow.hpp"
#include "px/exception/SDLException.hpp"

namespace px
{
AbstractWindow::AbstractWindow(const std::string &title, int width, int height)
{
    _window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    if (_window == nullptr)
    {
        throw SDLException();
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (_renderer == nullptr)
    {
        SDL_DestroyWindow(_window);

        throw SDLException();
    }

    setDisplayMode(WindowDisplayMode::WINDOWED);
}

AbstractWindow::~AbstractWindow()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

bool AbstractWindow::isOpen() const
{
    return _isOpen;
}

bool AbstractWindow::isVisible() const
{
    return SDL_GetWindowFlags(_window) & SDL_WINDOW_SHOWN;
}

bool AbstractWindow::isMaximized() const
{
    return SDL_GetWindowFlags(_window) & SDL_WINDOW_MAXIMIZED;
}

bool AbstractWindow::isMinimized() const
{
    return SDL_GetWindowFlags(_window) & SDL_WINDOW_MINIMIZED;
}

std::string AbstractWindow::getTitle() const
{
    return SDL_GetWindowTitle(_window);
}

int AbstractWindow::getWidth() const
{
    int value;

    SDL_GetWindowSize(_window, &value, nullptr);

    return value;
}

int AbstractWindow::getHeight() const
{
    int value;

    SDL_GetWindowSize(_window, nullptr, &value);

    return value;
}

WindowDisplayMode AbstractWindow::getDisplayMode() const
{
    WindowDisplayMode mode {WindowDisplayMode::WINDOWED};

    if (SDL_GetWindowFlags(_window) & SDL_WINDOW_FULLSCREEN_DESKTOP)
    {
        mode = WindowDisplayMode::BORDERLESS;
    }
    else if (SDL_GetWindowFlags(_window) & SDL_WINDOW_FULLSCREEN)
    {
        mode = WindowDisplayMode::FULLSCREEN;
    }

    return mode;
}

void AbstractWindow::clear()
{
    onClear();

    if (SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255) != 0)
    {
        throw SDLException();
    }

    if (SDL_RenderClear(_renderer) != 0)
    {
        throw SDLException();
    }
}

void AbstractWindow::refresh()
{
    onRefresh();

    SDL_RenderPresent(_renderer);
}

void AbstractWindow::maximize()
{
    onMaximize();

    SDL_MaximizeWindow(_window);
}

void AbstractWindow::minimize()
{
    onMinimize();

    SDL_MinimizeWindow(_window);
}

void AbstractWindow::show()
{
    onShow();

    SDL_ShowWindow(_window);
}

void AbstractWindow::hide()
{
    onHide();

    SDL_HideWindow(_window);
}

void AbstractWindow::close()
{
    _isOpen = false;
}

void AbstractWindow::setTitle(const std::string &value)
{
    onTitleChange(getTitle(), value);

    SDL_SetWindowTitle(_window, value.c_str());
}

void AbstractWindow::setWidth(int value)
{
    setSize(value, getHeight());
}

void AbstractWindow::setHeight(int value)
{
    setSize(getWidth(), value);
}

void AbstractWindow::setSize(int width, int height)
{
    onSizeChange(getWidth(), getHeight(), width, height);

    SDL_SetWindowSize(_window, width, height);
}

void AbstractWindow::setDisplayMode(WindowDisplayMode mode)
{
    onDisplayModeChange(getDisplayMode(), mode);

    switch (mode)
    {
        case FULLSCREEN:
            SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
            break;
        case BORDERLESS:
            SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            break;
        case WINDOWED:
            SDL_SetWindowFullscreen(_window, 0);
            break;
    }
}

void AbstractWindow::onInit()
{
}

void AbstractWindow::onClose()
{
}

void AbstractWindow::onClear()
{
}

void AbstractWindow::onRefresh()
{
}

void AbstractWindow::onShow()
{
}

void AbstractWindow::onHide()
{
}

void AbstractWindow::onMaximize()
{
}

void AbstractWindow::onMinimize()
{
}

void AbstractWindow::onTitleChange(const std::string &oldTitle, const std::string &newTitle)
{
}

void AbstractWindow::onSizeChange(int oldWidth, int oldHeight, int newWidth, int newHeight)
{
}

void AbstractWindow::onDisplayModeChange(WindowDisplayMode oldValue, WindowDisplayMode newValue)
{
}
}