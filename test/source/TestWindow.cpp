#include <iostream>
#include "../header/TestWindow.hpp"

namespace test
{
TestWindow::TestWindow(const std::string &title, int width, int height, bool debugClear, bool debugRefresh) :
    AbstractWindow(title, width, height), _debugClear {debugClear}, _debugRefresh {debugRefresh}
{}

void TestWindow::onInit()
{
    std::cout << "[WINDOW] Init\n";
}

void TestWindow::onClose()
{
    std::cout << "[WINDOW] Close\n";
}

void TestWindow::onClear()
{
    if (_debugClear)
    {
        std::cout << "[WINDOW] Clear\n";
    }
}

void TestWindow::onRefresh()
{
    if (_debugRefresh)
    {
        std::cout << "[WINDOW] Refresh\n";
    }
}

void TestWindow::onShow()
{
    std::cout << "[WINDOW] Show\n";
}

void TestWindow::onHide()
{
    std::cout << "[WINDOW] Hide\n";
}

void TestWindow::onMaximize()
{
    std::cout << "[WINDOW] Maximize\n";
}

void TestWindow::onMinimize()
{
    std::cout << "[WINDOW] Minimize\n";
}

void TestWindow::onTitleChange(const std::string &oldTitle, const std::string &newTitle)
{
    std::cout << "[WINDOW] Change title from `" << oldTitle << "` -> `" << newTitle << "`\n";
}

void TestWindow::onSizeChange(int oldWidth, int oldHeight, int newWidth, int newHeight)
{
    std::cout << "[WINDOW] Change size from `" <<
              oldWidth << ',' << oldHeight << "` -> `" <<
              newWidth << ',' << newHeight << "`\n";
}

void TestWindow::onDisplayModeChange(px::WindowDisplayMode oldValue, px::WindowDisplayMode newValue)
{
    std::cout << "[WINDOW] Change display mode from `" << oldValue << "` -> `" << newValue << "`\n";
}
}