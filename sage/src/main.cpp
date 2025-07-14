// Auto Genrated C++ file by Flick CLI
// None
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <cpr/cpr.h>
#include <fmt/base.h>
#include <fmt/color.h>
#include <fmt/core.h>
#include <raylib.h>
#include <sageconfig.h>

#include <cstdlib>
#include <filesystem>
#include <iostream>

#include <reproc++/reproc.hpp>
#include <string>
#include <vector>

#ifdef _WIN32
const std::string PRESET    = "windows";
const std::string EXTENTION = ".exe";
#else
const std::string PRESET    = "default";
const std::string EXTENTION = "";
#endif
std::vector<std::string> getArgs(int argc, char** argv)
{
    std::vector<std::string> args{};
    for (int i = 0; i < argc; ++i) args.push_back(argv[i]);
    return args;
};

bool compile()
{
    namespace fs = std::filesystem;
    if (fs::exists("build/" + PRESET))
    {
        return std::system(("cmake --build build/" + PRESET).c_str()) == 0;
    }
    else
    {
        if (int code = std::system(("cmake --preset " + PRESET).c_str()); code == 0)
        {
            return std::system(("cmake --build build/" + PRESET).c_str()) == 0;
        }
        else
        {
            return code;
        }
    }
}
bool run(std::string name)
{
    namespace fs = std::filesystem;
    if (fs::exists("build/" + PRESET + "/" + name + EXTENTION) &&
        (!fs::is_directory("build/" + PRESET + "/" + name + EXTENTION)))
    {
        auto path = fs::path("./build/" + PRESET + "/" + name + EXTENTION);
        return std::system((path.lexically_normal().string()).c_str());
    };
    if (fs::exists("build/" + PRESET + "/" + name + "/" + name))
    {
        auto path = fs::path("./build/" + PRESET + "/" + name + "/" + name + EXTENTION);
        return std::system((path.lexically_normal().string()).c_str());
    }
}

bool installPackages()
{
    namespace fs = std::filesystem;
    if (fs::exists("packages/requirement.txt"))
    {
        std::string cmdString(
            "conan install packages/requirement.txt --output-folder packages/install");
        return std::system(cmdString.c_str());
    }
    else
    {
        fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::rebecca_purple),
                   "error : failed to find packages/requirement.txt\n");
        return false;
    }
}

int main(int argc, char* argv[])
{
    auto args = getArgs(argc, argv);
    if (args.size() <= 1)
    {
        fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::blanched_almond),
                   "Available Commands : install, compile, run\n");
        InitWindow(400, 200, Project::PROJECT_NAME.data());
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(YELLOW);
            EndDrawing();
        };
    }
    for (const std::string& arg : args)
    {
        if (arg.find("compile") != std::string::npos)
        {
            compile();
        }
        else if (arg.find("run") != std::string::npos)
        {
            if (args.size() >= 3)
            {
                return run(args[2]);
            }
            else
            {
                std::cout << "you have to provide the app you want to run\n";
            }
            return 0;
        }
        else if (arg.find("install") != std::string::npos)
        {
            installPackages();
        }
    }
    return 0;
}
