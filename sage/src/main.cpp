//Auto Genrated C++ file by Flick CLI
//None

#include <fmt/base.h>
#include<sageconfig.h>
#include<fmt/core.h>
#include<fmt/color.h>
#include<cpr/cpr.h>
#include<reproc++/reproc.hpp>

int main(int argc,char*argv[])
{
  cpr::Response res=cpr::Get(cpr::Url("www.google.com"));
  if(res.status_code==200){
    fmt::println("ok!");
  }else{
    fmt::println("not ok!");
  }
  fmt::print(fmt::emphasis::bold|fmt::fg(fmt::color::blue),"{} ",Project::PROJECT_NAME);
  fmt::print(fmt::emphasis::faint|fmt::fg(fmt::color::white),"v{}\n",Project::VERSION_STRING);
  return 0;
}
