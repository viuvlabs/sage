//Auto Genrated C++ file by Flick CLI
//None
#include<iostream>
#include<sageconfig.h>
#include<fmt/core.h>
#include<fmt/color.h>
int main(int argc,char*argv[])
{
  fmt::print(fmt::emphasis::bold|fmt::fg(fmt::color::blue),"{} ",Project::PROJECT_NAME);
  fmt::print(fmt::emphasis::faint|fmt::fg(fmt::color::white),"v{}\n",Project::VERSION_STRING);
  return 0;
}
