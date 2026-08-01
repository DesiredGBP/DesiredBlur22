#include "tasks.h"
#include "gui.h"
#include "license_auth.h"

#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {
#ifdef WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    if (!licensing::authenticate()) {
        return 1;
    }

    std::vector<std::string> arguments(argv + 1, argv + argc);

    std::thread(tasks::run, arguments).detach();

    return gui::run();
}
