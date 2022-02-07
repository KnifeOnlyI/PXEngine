#ifndef PXENGINE_SDLEXCEPTION_HPP
#define PXENGINE_SDLEXCEPTION_HPP

#include <stdexcept>

#include <boost/format.hpp>
#include <SDL2/SDL.h>

namespace px
{
/**
 * Represent an SDL exception
 */
class SDLException : public std::runtime_error
{
public:

    /**
     * Create a new SDL exception
     */
    explicit SDLException() :
        runtime_error((boost::format("[SDL] %1%") % SDL_GetError()).str())
    {
    }

    [[nodiscard]] const char *what() const noexcept override
    {
        return std::runtime_error::what();
    }
};
}

#endif //PXENGINE_SDLEXCEPTION_HPP
