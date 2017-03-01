#include "Window.h"
#include "playerChoice.h"
#include "TextBox.h"

Window::Window(TextBox body, playerChoice c) : text(body), choice(c) {}
Window::~Window() {}
