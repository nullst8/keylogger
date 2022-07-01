#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define LOGFILE "/tmp/data"

int main(int argc, char *argv[]) {
  struct input_event ev;
  int file_desc = open("/dev/input/event3", O_RDONLY);
  FILE *fp = fopen(LOGFILE, "a");

  while (1) {
    read(file_desc, &ev, sizeof(ev));
    if ((ev.type == EV_KEY) && (ev.value == 0)) {
      printf("%d\n", ev.code);
    }
  }
  return 0;
}
