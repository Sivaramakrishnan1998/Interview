#include <cstdio>
#include <signal.h>

namespace {
  volatile sig_atomic_t quitok = false;
  void handle_break(int a) {
    if (a == SIGINT) quitok = true;
  }
}

int main () {
  struct sigaction sigbreak;ls
  
  sigbreak.sa_handler = &handle_break;
  sigemptyset(&sigbreak.sa_mask);
  sigbreak.sa_flags = 0;
  if (sigaction(SIGINT, &sigbreak, NULL) != 0) std::perror("sigaction");
  //...
}